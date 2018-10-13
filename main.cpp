#include <iostream>
#include "tools.hpp"

int main (){
	python_initialize();			//Initialize Python interpreter
									//only required if using embedded Python

	std::cout.setf ( std::ios::fixed);	//display 20 digits on terminal, you won't be
	std::cout.precision(20);             //able to see precise output otherwise 
	
	std::string f;
	double x;
	
	std::cout<<"Inserisci la funzione "<<std::endl; 
	getline(std::cin, f); 				//read expression from stdin
	std::cout<<"Inserisci il punto in cui calcolare la funzione"<<std::endl;
	std::cin>>x;

	std::cout<<evaluate(f, x)<<std::endl;  //write evaluated function to stdout
}