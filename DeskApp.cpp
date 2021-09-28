#include "DeskApp.h"

DeskApp::DeskApp(list<string>array, const char* appCode, const char* appName, float version, float price, Developer* developer): Application( appCode, appName, version, price, developer)
{
	files = array;
	//files.push_back(".txt");
	//files.push_back(".docx");
	//files.push_back(".csv");
	//files.push_back(".pptx");
	//files.push_back(".xlsx");
}

DeskApp::DeskApp(const DeskApp& d) : Application(d)
{
	files = d.files;
}

list<string> DeskApp::getFiles()
{
	return files;
}

void DeskApp::showData()
{
	Application::showData();
	list <string>::iterator it;	
	cout << "Tupoi arxeiwn:" << endl;
	for (it = files.begin(); it != files.end(); it++)
	{		
		cout << *it << endl;
	}
	cout << endl;
}

