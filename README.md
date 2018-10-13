# Zanellati
## Getting started
### Requirements
* C++ compiler (Linux/OS X - gcc, Windows - visual c++)
* Python (see [python.org](https://www.python.org/downloads/) or packet managers on linux). Rember to check the "Add Python to PATH" option when installing on Windows

### Unix
On Unix you have two choices: you can use Python embedded in C/C++ code or you can use the command line alternative (slower).

Embedded Python:

* Download or clone the **master** branch of the repository on your PC. If you are not familiar with git it is recommended to use the green '**Clone or Download**' button and click on '**Download ZIP**'
* Open the folder, you will find 4 files: **tools.cpp tools.hpp build.sh eval.py**. tools.cpp provides the function `double evaluate(string f, double x)` that can be used to evaluate arbitrary mathematical functions where f is the string representation of the expression and x is the value to assign to the variable 'x' used in the function. For example, `evaluate("pow(x, 5) +6", 15)` will calculate f(15) where f is "x^5 +6". In order to be able to use that in your C++ code you have to include '**tools.hpp**'.
* To compile with Python support use the build.sh script (type chmod u+x build.sh in terminal if not executable) specifying the files you want to build.
(es: `./build.sh main.cpp tools.cpp`). You can use all the flags you would use on gcc. This requires Python to be in the PATH.
* Please note that you have to initialize the Python interpreter first, you can do that with `python_initialize`, defined in tools.hpp

Python-CLI

* Download or clone the **python-cli** branch of the repository on your PC. If you are not familiar with git it is recommended to use the green '**Clone or Download**' button and click on '**Download ZIP**'
* Open the folder, you will find 3 files: **tools.cpp tools.hpp eval.py**. tools.cpp provides the function `double evaluate(string f, double x)` that can be used to evaluate arbitrary mathematical functions where f is the string representation of the expression and x is the value to assign to the variable 'x' used in the function. For example, `evaluate("pow(x, 5) +6", 15)` will calculate f(15) where f is "x^5 +6". In order to be able to use that in your c++ code you have to include '**tools.hpp**'. This requires Python to be in the PATH.
* To compile simply use a C/C++ compiler of your choice, like gcc.

### Windows (che il cielo ti strafulmini)
On Windows you can only use Python-CLI for now. Just follow the instructions for Linux as they are roughly the same.

## Example

### Embedded Python
```c++
#include <iostream>
#include "tools.hpp"

int main (){
	python_initialize();			//Initialize Python interpreter
						//only required if using embedded Python

	std::cout.setf ( std::ios::fixed);	//display 20 digits on terminal, you won't be
	std::cout.precision(20);             //able to see precise output otherwise 
	
	string f;
	double x;
	std::cout<<"Inserisci la funzione "<<std::endl; 
	getline(cin, f); 				//read expression from stdin
	
	std::cout<<evaluate(f, x)<<std::endl;  //write evaluated function to stdout
}
```
### Python_CLI

```c++
#include <iostream>
#include "tools.hpp"

int main (){
	std::cout.setf ( std::ios::fixed);	//display 20 digits on terminal, you won't be
	std::cout.precision(20);             //able to see precise output otherwise 
	
	string f;
	double x;
	std::cout<<"Inserisci la funzione "<<std::endl; 
	getline(cin, f); 				//read expression from stdin
	
	std::cout<<evaluate(f, x)<<std::endl;  //write evaluated function to stdout
}
```
