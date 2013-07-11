#include <string>
#include <iostream>
using namespace std;

#include "TestString.h"

void constructs() {
	string s1;
	string s5("Initial string");
	string s2(s5);
	string s3(s5, 8, 3);
	string s4(s5, 8);
	string s6(10, 'x');
	string s7a(10, 42);
	string s7b(s5.c_str(), s5.c_str() + 4);

	cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
	cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6: " << s6;
	cout << "\ns7a: " << s7a << "\ns7b: " << s7b << endl;

	string str1, str2, str3;
	str1 = "Test string: ";   // c-string
	str2 = 'x';               // single character
	str3 = str1 + str2;       // string

	cout << str3 << endl;

}

void iterators() {

	string str("Test string");
	string::iterator it;
	for (it = str.begin(); it < str.end(); it++) {
		cout << *it;
	}
	cout << endl;

	string::reverse_iterator rit;
	for (rit = str.rbegin(); rit < str.rend(); rit++) {
		cout << *rit;
	}
	cout << endl;

}
