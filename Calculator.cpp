/*
 * Calculator.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: navee
 */

#include "Calculator.h"
#include <iostream>

using namespace std;

double Calculator::expression()
{
	char cr;
	double next_term;

	cr = (cin>>ws).peek();

	if(cr == '+')
	{
		cin >> cr;
		next_term = term();
	}

	else	if(cr == '-')
	{
		cin >> cr;
		next_term = 0 - term();
		next_term = -next_term;
	}

	else
		{
		next_term = term();
		}

	cr = (cin>>ws).peek();
	while(cr == ('+' )|| cr == ('-' ))
	{
		if(cr == '+')
		{
			cin >> cr;
			next_term = next_term + term();
		}
		else if(cr == '-')
		{
			cin >> cr;
			next_term = next_term - term();
		}
		cr = (cin>>ws).peek();
	}
	return next_term;
}

double Calculator::term() throw(string)
{
	char cr;
	double next_Factor=factor();
	cr = (cin>>ws).peek();
	while(cr == ('*') || cr== ('/'))
	{
		if(cr == '*')
		{
			cin >> cr;
			next_Factor = next_Factor * factor();
		}
		else if(cr == '/')
		{
			cin >> cr;
			double fact=factor();
			if(fact ==0)
					{
				string str="";
						getline(cin,str);

						throw string("***** Division By Zero");
					}
			next_Factor = next_Factor /fact ;

		}
		cr = (cin>>ws).peek();
	}
return next_Factor;
}

double Calculator::factor() throw(string)
{
	char cr = (cin>>ws).peek();

	if(isdigit(cr))
	{
		double ans;
		cin >> ans;
		return ans;
	}

	if(cr == '(')
	{
		cin >> cr;
		double result = expression();

		cr = (cin>>ws).peek();
		if(cr != ')')
		{
			throw string("***** Missing )");
		}
		else
		{
			cin >> cr;
		}
		return result;
	}

	else
	{
		cr = (cin>>ws).peek();
		if(cr == '.')
		{
			return 1;
		}
		if(cr!='='){
		string str="";
		getline(cin,str);
		throw string("***** Unexpected %");
		return 0;
		}
	}
}
