#ifndef SIGN_H
#define SIGN_H
#include<iostream>
#include <string>
#include "Check.h"
using namespace std;

class Sign {
	string fullname;
	string sign;
	int date[3];
public:
	Sign();
	Sign(string& n, string& sg, int d[3]);
	Sign(const Sign& S);
	~Sign();

	void change(); 
	bool operator> (const Sign& S); //оператор сравнения
	friend ostream& operator<< (ostream& stream, const Sign& S); //оператор вставки
	friend istream& operator>>(istream& in, Sign& s); //оператор извлечения

	void set_fullname(string& n);
	void set_sign(string& sg);
	void set_date(int d[3]);

	string get_fullname();
	string get_sign();
	int* get_date();
};

#endif 