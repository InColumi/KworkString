#include <iostream>
#include <string>
#include "String.h"

using namespace std;

int main()
{
	try
	{
		string a;
		cout << a.size() << endl;
		cout << a << endl;
		String b("Max");
		String c("Panav");

		c.pop(0);
		cout << c << endl;
	}
	catch(const std::exception& err)
	{
		cout << err.what() << endl;
	}
	system("pause");
	return 0;
}