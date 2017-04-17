#include <iostream>
#include <string>
#include <limits>
using namespace std;

int getline()
{
	string tmp1, tmp2;
	int i;

	cin >> i;
	cin.ignore(255, '\n');
	getline(cin, tmp1);
	cin >> i;
	cin.ignore(255, '\n');
	getline(cin, tmp2);

	cout << i << endl;
	cout << "<" << tmp1 << ">" << endl << endl;
	cout << i << endl;
	cout << "<" << tmp2 << ">" << endl << endl;
	return 0;
}