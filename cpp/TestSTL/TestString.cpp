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

void capacity() {

	string str;
	str.reserve(15);
	str = "Test string";
	cout << "size: " << str.size() << endl;
	cout << "length: " << str.length() << endl;
	cout << "capacity: " << str.capacity() << endl;
	cout << "max_size: " << str.max_size() << endl;
	cout << "empty: " << str.empty() << endl;

	string str1 = str;
	string str2 = str;
	str1.resize(5);
	str2.resize(15, 'a');
	cout << str1 << endl;
	cout << str2 << endl;

	str.clear();
	cout << "after clear, length: " << str.length() << endl;
	cout << "after clear, capacity: " << str.capacity() << endl;
	cout << "after clear, empty: " << str.empty() << endl;

}

void elementAccess() {
	string str("Test string");
	size_t i;
	for (i = 0; i < str.length(); i++) {
		if (i != 0) {
			cout << ", ";
		}
		cout << "'"<< str[i] << "'";
	}
	cout << endl;

	cout << str[1000] << endl; // no range check

	for (i = 0; i < str.length(); i++) {
		if (i != 0) {
			cout << ", ";
		}
		cout << "'"<< str.at(i) << "'";
	}
	cout << endl;

	try {
		cout << str.at(1000) << endl; // has range check
	} catch (exception & e) {
		cout << e.what() << endl;
	}
}
