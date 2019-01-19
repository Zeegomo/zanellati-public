#include <fstream>
#include <sstream> 
#include <vector>
#include <float.h>
#include <iostream>
#include <math.h>
#include <string>

//initialize python module
void python_initialize();

/*
f: mathematical expression
x: point
calc f in x
*/
double evaluate(std::string f, double x);

