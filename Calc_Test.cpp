#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "Calculator.h"

using namespace std;

int main()
{
	Calculator calci;
	char dot;
	double result;
	bool tester=true;
	cout << "Expression?" << endl;
	dot = (cin>>ws).peek();

	while(dot != '.')
		{
		try{
		result = calci.expression();
		cout << result <<endl<<endl;
		char cr = (cin>>ws).peek();
		if(cr=='%'){
		tester=false;
		}
		else tester=true;
		}
		catch(string s){
			cout<<s<<endl;
			cout << "Expression?" << endl;
			tester=false;
		}
		if(tester)
		{
			cout << "Expression?" << endl;
			dot = (cin>>ws).peek();
			if(dot=='='){
				char ch;
				cin>>ch;
				dot = (cin>>ws).peek();
			}
		}
		}
	cout << "Done!" <<endl;
}
