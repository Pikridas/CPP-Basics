#ifndef APPSYSTEM_H
#define APPSYSTEM_H
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include "Developer.h"
#include "Application.h"
#include "Game.h"
#include "DeskApp.h"
#include "Evaluation.h"

using namespace std;

class AppSystem
{
private:
	list <Application *> applications;
	list <Developer *> developers;
public:
	AppSystem();
	void addApp(Application* app);//Thelei public inheritance gia na doulepsei
	void addDev( Developer *dev);
	void addEval( Evaluation ev,char* code);
	//Methodoi tropopoihshs dedomwnwn
	void setAppCode(char* appCode, char* newCode);
	void setAppName(char* appCode, char* newAppName);
	void setVersion(char* appCode,float newVersion);
	void setPrice(char* appCode, float newPrice);
	void setDev(const Developer newDev, char* appCode, int code);
	//Kakovoulos Kataskeuasths
	void delDeveloper(Developer dev);	
	//Anazhthsh dwrean efarmogwn kai kalon paixnidiwn
	list<Game*> findGoodGames();
	list<DeskApp*> findFreeApps();
	//Tupwma dedomenwn efarmogwn
	void AppSystemPrint(ostream& channel);	
	//Eggrafh kai diavasma dedomenwn apo arxeio
	void writeTofile(string name);
	void readFromFile(string name);
};
#endif
