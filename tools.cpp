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


#define MAX_ITERATIONS 10000000
#define H sqrt(DBL_EPSILON) 
#define H_SECOND sqrt(sqrt(DBL_EPSILON))
#include <python3.7m/Python.h>


std::string getexepath()
{
	#ifdef __linux__
 		char result[ PATH_MAX ];
  		ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
  		std::string s (result);
  		return s.substr(0,s.find_last_of("/\\")+1);
  	#else
  		char result[ MAX_PATH ];
  		return std::string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
  	#endif
}

void python_initialize(){
	Py_Initialize();
	PyRun_SimpleString("import sys");
	std::string path ("sys.path.append('"); 
	path.append(getexepath().c_str());
	path.append("')");
	PyRun_SimpleString(path.c_str());
}

PyObject *python_get_func(){
	PyObject *pName, *pModule;
	pName = PyUnicode_DecodeFSDefault("eval");
    	/* Error checking of pName left out */
    	pModule = PyImport_Import(pName);
    	Py_DECREF(pName);
    	return PyObject_GetAttrString(pModule, "eval_func");
}



/*
f: mathematical expression
x: point
calc f in x
*/
double evaluate(std::string f, double x){
	PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;
	
	pFunc = python_get_func();
   	 pArgs = PyTuple_New(2);
    	PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(f.c_str()));
   	PyTuple_SetItem(pArgs, 1, PyFloat_FromDouble(x));
    
    	pValue = PyObject_CallObject(pFunc, pArgs);
    	return PyFloat_AsDouble(pValue);
}

