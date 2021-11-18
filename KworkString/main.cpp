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
		String c("Panov");

		cout << b.concat(c) << endl;
		cout << b.compare(String("Max")) << endl;

	}
	catch(const std::exception& err)
	{
		cout << err.what() << endl;
	}

	return 0;
}