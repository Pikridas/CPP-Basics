#ifndef DEVELOPER_H
#define DEVELOPER_H
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Developer
{
private:
	char* name;
	int code;	
	string email;
public:
	Developer(const char* name, int code,string email);
	Developer(const Developer& dev);
	~Developer();
	void Print();
	char* getName();
	int getCode();
	string getEmail();	
};
#endif
