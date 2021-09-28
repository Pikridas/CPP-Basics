#include "Application.h"
//General Constructor
Application::Application(const char* appCode,const char* appName, float version, float price, Developer* developer)
{
	//Dhmiourgia dunamikou pinaka gia thn arxikopoihsh tou alfarithmitikou 
	int length = strlen(appCode);
	this->appCode = new char[length + 1];
//	strcpy_s(this->appCode, length+1, appCode);	
	strcpy(this->appCode,appCode);
	
	int length1 = strlen(appName);
	this->appName = new char[length1 + 1];
//	strcpy_s(this->appName, length1 + 1, appName);
	strcpy(this->appName, appName);
	/*memcpy(appName, this->appName, length);*/	

	this->version = version;
	this->price = price;
	this->developer = developer;
}
//Destructor
Application::~Application()
{
	delete[] appCode;
	delete[] appName;	
}
//Copy Constructor
Application::Application(const Application& a)
{
	int length = strlen(a.appCode);
	this->appCode = new char[length + 1];
	strcpy(this->appCode, a.appCode);

	int length1 = strlen(a.appName);
	this->appName = new char[length1 + 1];
	strcpy(this->appName, a.appName);
	/*memcpy(appName, this->appName, length);*/

	this->version = a.version;
	this->price = a.price;
	this->developer = a.developer;
}
//Prosthesh antikeimenwn tupou Evaluation sthn lista apo pointers 
void Application::addEvaluation(Evaluation* ev)
{
	evaluations.push_back(ev);
}

//Getters
const char* Application::getAppCode()
{
	return appCode;
}

const char* Application::getAppName()
{
	return appName;
}

float Application::getVersion()
{
	return version;
}

float Application::getPrice()
{
	return price;
}

Developer* Application::getDeveloper()
{
	return developer;
}

//Setters
void Application::setAppCode(char* appCode)
{
	if (this->appCode != NULL)
	{
		delete[] appCode;
	}
	else
	{
		int length = strlen(appCode);
		this->appCode = new char[length + 1];
		strcpy(this->appCode, appCode);
	}
}

void Application::setAppName(char* appName)
{
	if (this->appName != NULL)//An uparxei appName apoesmeuei ton xwro kai ftiaxnei kainourgio
	{
		delete[] appName;
	}
	else
	{
		int length = strlen(appName);
		this->appName = new char[length + 1];
		strcpy(this->appName,appName);
	}
	
}

void Application::setVersion(float version)
{
	this->version = version;
}

void Application::setPrice(float price)
{
	this->price = price;
}

void Application::setDeveloper(Developer* dev)
{
	this->developer = dev;
}

//Mathodos opou tupwnei ta dedomena enos antikeimenou typou Application
void Application::showData()
{
	cout << "---" << appName << "---" << endl;
	cout << "Code: " << appCode << endl;	
	cout << "Version: " << version << endl;
	cout << "Price: " << price << endl;
	cout << endl;	
	cout << "Developers data:" << endl;
	developer->Print();
	cout << endl;
}
//Methodos h opoia diatrexei thn lista me ta Evaluations kai upologizei ton moso oro olwn twn kritikwn 
float Application::findAverageEvaluation()
{
	float mo;
	float sum = 0.0;
	list <Evaluation *>::iterator it;
	for (it = evaluations.begin(); it != evaluations.end(); it++)
	{
		sum += (*it)->getStars();
	}
	return mo = sum/evaluations.size();
}

list<Evaluation*> Application::getListOfEvaluations()
{
	return	evaluations;
}

