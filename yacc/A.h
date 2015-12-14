#ifndef __A_H__
#define __A_H__

#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

class A
{
public:
	string val;
	A(string str) : val(str) {}
	void display() {
		cout<<"insert into table: "<<val<<endl;
	}
};

#endif