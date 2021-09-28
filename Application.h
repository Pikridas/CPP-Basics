#ifndef APPLICATION_H
#define APPLICATION_H
#include <iostream>
#include <string.h>
#include <string>
#include <list>
#include "Developer.h"
#include "Evaluation.h"

using namespace std;

class Application
{
//Dhlwsh metavlhtwn
protected:
	char* appCode;
	char* appName;
	float version;
	float price;
	Developer *developer;
	list <Evaluation* > evaluations;
public:
	//Dhlwsh methodwn 
	Application(const char* appCode,const char* appName, float version, float price, Developer* developer);
	virtual ~Application();
	Application(const Application& a);
	void addEvaluation(Evaluation* ev);
	const char* getAppCode();
	const char* getAppName();
	float getVersion();
	float getPrice();
	Developer* getDeveloper();
	void setAppCode(char* appCode);
	void setAppName(char* appName);
	void setVersion(float version);
	void setPrice(float price);
	void setDeveloper(Developer* dev);
	virtual void showData();
	float findAverageEvaluation();
	list<Evaluation*> getListOfEvaluations();
};
#endif
