#ifndef DESKAPP_H
#define DESKAPP_H
#include <iostream>
#include <string>
#include "Application.h"

using namespace std;

class DeskApp : public Application
{
private:
	list <string> files;	
public:
	DeskApp(list<string>array,const char* appCode, const char* appName, float version, float price, Developer* developer);
	DeskApp(const DeskApp& d);
	list<string> getFiles();
	void showData();
};

#endif
