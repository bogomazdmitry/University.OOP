
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	char s[] = "Минск БГУиР ";
	if ( ios::right & cout.flags())
	{
		cout.setf(ios::left);
	}
	else
	{
		cout.setf(ios::right);
	};
	cout << setw(30) << s << endl;

	if (cout.flags() & ios::showpos)
	{
		cout.unsetf(ios::showpos);
	}
	else
	{
		cout.setf(ios::showpos);
	}
	cout << "123165" << endl << 121213 << endl;
	
	return 0;
}


