#include "Developer.h"

Developer::Developer(const char* name, int code, string email)
{
	
	int length = strlen(name);
	this->name = new char[length + 1];
//	strcpy_s(this->name, length+1, name);
	strcpy(this->name, name);
	/*memcpy(name, this->name, length);*/
	this->code = code;
	this->email = email;
}

Developer::Developer(const Developer& dev)
{

	int length = strlen(dev.name);
	this->name = new char[length + 1];
	memcpy(dev.name, this->name, length);	
	this->code = dev.code;
	this->email = dev.email;
}

Developer::~Developer()
{
	delete[] name;
}

void Developer::Print()
{
	cout << "Name: " << name << endl;
	cout << "Code: " << code << endl;
	cout << "Email: " << email << endl;
}

char* Developer::getName()
{
	return name;
}

int Developer::getCode()
{
	return code;
}

string Developer::getEmail()
{
	return email;
}
