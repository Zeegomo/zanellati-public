#include <fstream>
#include <sstream> 
#include <vector>
#include <float.h>
#include <iostream>
#include <math.h>
#include <string>
#include "tools.hpp"
using namespace std;


ifstream fin("input.txt");
ofstream fout("output.txt");
//int v[5010];

using namespace std;

int main() {
	//Py_setProgramName("eval_func");
	//python_initialize();
	cout.setf ( std::ios::fixed);
	cout.precision(20); 
	string f;
	int m;
	double a,b,tol;
	cout<<"Inserisci la funzione "<<endl;
	getline(cin, f);
	cout<<"Scegli il metodo (0: Bisezione, 1: Secante, 2: Newton)"<<endl;
	cin>>m;
	
	if (m == 2){
		cout<<"Inserisci il punto di partenza e la tolleranza"<<endl;
		cin>>a>>tol;
		pair<double , long long int> sol  = newton(f, a, tol);
		cout<<"Risultato: "<<sol.first<<endl;
		cout<<"N. di passaggi: "<<sol.second<<endl;
	}else if (m == 1) {
		cout<<"Inserisci i punti di partenza e la tolleranza"<<endl;
		cin>>a>>b>>tol;
		pair<double , long long int> sol  = secant(f, a, b,tol);
		cout<<"Risultato: "<<sol.first<<endl;
		cout<<"N. di passaggi: "<<sol.second<<endl;
	}else{

		cout<<"Insesci gli estremi dell'intervallo e la tolleranza"<<endl;
		cin>>a>>b>>tol;
		pair<double , long long int> sol  = bisection(f, a, b, tol);
		cout<<"Risultato: "<<sol.first<<endl;
		cout<<"N. di passaggi: "<<sol.second<<endl;
	}
}
