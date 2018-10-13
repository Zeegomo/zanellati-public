#include <fstream>
#include <sstream> 
#include <vector>
#include <float.h>
#include <iostream>
#include <math.h>
#include <string>
#include <python3.7m/Python.h>

//initialize python module
void python_initialize();

//return python function to evaluate mathematical expressions
PyObject *python_get_func();

/*
f: mathematical expression
x: point
calc f in x
*/
double evaluate(std::string f, double x);

