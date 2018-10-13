#include <fstream>
#include <sstream> 
#include <vector>
#include <float.h>
#include <iostream>
#include <math.h>
#include <string>
#ifdef __linux__
#include <unistd.h>
#include <linux/limits.h>
#else
#include <windows.h>
#endif
//#include <python3.7m/Python.h>


#define MAX_ITERATIONS 10000000
#define H sqrt(DBL_EPSILON) 
#define H_SECOND sqrt(sqrt(DBL_EPSILON))
#define PYTHON "python"
#define PYTHON_FILE "eval.py"


std::string getexepath()
{
	#ifdef __linux__
 		char result[ PATH_MAX ];
  		/* ssize_t count = */readlink( "/proc/self/exe", result, PATH_MAX );
  		std::string s (result);
  		return s.substr(0,s.find_last_of("/\\")+1);
  	#else
  		char result[ MAX_PATH ];
  		return std::string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
  	#endif
}


std::string to_string_b(double value)
{
	char buffer[500] = {};
	sprintf(buffer, "%.100f", value);
	std::string s = buffer;
	return s;
}

std::string get_command(std::string f, double x ){
	std::string cmd (PYTHON); 
	return  cmd + " " PYTHON_FILE + " \"" +f + "\" " + to_string_b(x);

}


double evaluate(std::string f, double x){
    	std::string command = get_command(f, x);
	
	#ifdef __linux__
    		FILE *lsofFile_p = popen(command.c_str(), "r");
	#else
		FILE *lsofFile_p = _popen(command.c_str(), "r");
	#endif

  	if (!lsofFile_p){
    	return -1;
  	}

  	char buffer[1024];
  	fgets(buffer, sizeof(buffer), lsofFile_p);
  	
	#ifdef __linux__
		pclose(lsofFile_p);
	#else
		_pclose(lsofFile_p);
	#endif

  	std::string r(buffer);
  	return std::stod(r);
}
