#include "AppSystem.h"

AppSystem::AppSystem()
{

}
//Prosthikh efarmogwn sthn lista me pointers opou deixnoun se efarmoges
void AppSystem::addApp(Application* app)
{
	applications.push_back(app);
}
//Prosthikh developer sthn lista me pointers opou deixnoun se developer
void AppSystem::addDev(Developer* dev)
{
	developers.push_back(dev);
}

//Prosthetoume mia axiologhsh enos xrhsth dinontas twn kwdiko ths efarmoghs kai thn kritikh
void AppSystem::addEval(Evaluation ev,char* code)
{	
	list <Application *>::iterator it;
	for (it = applications.begin(); it != applications.end(); it++)
	{
		if (strcmp(code ,(*it)->getAppCode())==0)
		{
			(*it)->addEvaluation(&ev);
		}
	}
}
//Eisagwgh new appCode se mia efarmogh 
void AppSystem::setAppCode(char* appCode, char* newCode)
{
	list <Application *>::iterator it;
	
	for (it = applications.begin(); it != applications.end(); it++)
	{
		if (strcmp(newCode , (*it)->getAppCode()) == 0)
		{
			cout << "This code already exists" << endl;
		}
		else if (strcmp(appCode , (*it)->getAppCode()) == 0)
		{
			(*it)->setAppCode(newCode);
			cout << "Code changed successfully!" << endl;
		}
		else
		{
			cout << "Code not found!" << endl;
		}
	}
}
//Eisagwgh new appName se mia efarmogh me suggekrimeno appCode
void AppSystem::setAppName(char* appCode, char* newAppName)
{
	list <Application *>::iterator it;

	for (it = applications.begin(); it != applications.end(); it++)
	{
		if (strcmp(appCode,(*it)->getAppCode())==0)
		{
			if (strcmp(newAppName, (*it)->getAppName()) == 0)
			{
				cout << "This name already exists" << endl;
			}
			else
			{
				(*it)->setAppName(newAppName);
				cout << "Name changed successfully!" << endl;
			}
		}
		else
		{
			cout << "Code not found!" << endl;
		}
	}
}
//Eisagwgh new Version se mia efarmogh me suggekrimeno appCode
void AppSystem::setVersion(char* appCode, float newVersion)
{
	list <Application *>::iterator it;

	for (it = applications.begin(); it != applications.end(); it++)
	{
		if (strcmp(appCode, (*it)->getAppCode()) == 0)
		{
				(*it)->setVersion(newVersion);
				cout << "Version changed successfully!" << endl;
		}

	}
}
//Eisagwgh new price se mia efarmogh me suggekrimeno appCode
void AppSystem::setPrice(char* appCode, float newPrice)
{
	list <Application *>::iterator it;

	for (it = applications.begin(); it != applications.end(); it++)
	{
		if (strcmp(appCode, (*it)->getAppCode()) == 0)
		{
			(*it)->setPrice(newPrice);
			cout << "Price changed successfully!" << endl;
		}
	}
}
//Eisagwgh Developer se mia efarmogh vash suggekrimenou appCode kai Developer code
void AppSystem::setDev(Developer newDev, char* appCode, int code)
{
	list <Application *>::iterator it;

	for (it = applications.begin(); it != applications.end(); it++)
	{
		if (strcmp(appCode, (*it)->getAppCode()) == 0)
		{
			if (code == (*it)->getDeveloper()->getCode())
			{
				(*it)->setDeveloper(&newDev);		
			}
			else
			{
				cout << "Wrong code!" << endl;
				break;
			}
		}	
	}
}
//Diagrafh efarmogwn vash enos kakovoulou Developer.
void AppSystem::delDeveloper(Developer dev)
{
	list <Application *>::iterator it;
	list <Developer *>::iterator it1;
	for (it = applications.begin(); it != applications.end(); it++)
	{
		if ((*it)->getDeveloper()->getCode() == dev.getCode())
		{
			applications.erase(it);
		}
	}
	for (it1 = developers.begin(); it1 != developers.end(); it1++)//Diagrafh kai apo thn lista me tous Developers
	{
		if ((*it1)->getCode() == dev.getCode())
		{
			developers.erase(it1);
		}
	}
}

//Gia na kanoume dynamic_cast prepei h MAMA klash na exei toulaxiston mia virtual methodo h enan virtual Destructor
list<Game*>  AppSystem::findGoodGames()//Euresh Paixnidiwn pou exoun Meso Oro kritikwn > 4
{
	Game *game;
	list <Game*> games;
	list <Application *>::iterator it;	
	for (it = applications.begin(); it != applications.end(); it++)
	{
		game = dynamic_cast <Game*> (*it);	
		game->showData();
		if (game != NULL)
		{
			if ((*it)->findAverageEvaluation() > 4)
			{
				games.push_back(game);
			}
		}
	}
	return games;
}

list<DeskApp*> AppSystem::findFreeApps()//Euresh efarmogwn pou exoun kostos = 0.0 
{
	DeskApp* desk;
	list <Application*>::iterator it;
	list <DeskApp*> desks;
	for (it = applications.begin(); it != applications.end(); it++)
	{
		desk = dynamic_cast <DeskApp*> (*it);
		if (desk != NULL)
		{
			if ((*it)->getPrice() == 0.0)
			{
				desks.push_back(desk);
			}
		}
	}
	return desks;
}


void AppSystem::AppSystemPrint(ostream& channel)//Tupwma dedomenwn se dwthen kanali
{
	Game* game;
	DeskApp* desk;
	list <Application*>::iterator it;
	list <Evaluation*> eval;
	list <string> files;
	for (it = applications.begin(); it != applications.end(); it++)
	{
		game = dynamic_cast <Game*> (*it);
		if (game != NULL)
		{	
			channel << "---Games---" << endl;
			channel << "Code: " << game->getAppCode() << endl;
			channel << "Name: " << game->getAppName() << endl;
			channel << "Version: " << game->getVersion() << endl;
			channel << "Price: " << game->getPrice() << endl;
			if (game->getDeveloper() != NULL)
			{
				channel << "Developer: " << game->getDeveloper()->getName() << endl;
			}
			channel << "Category: " << game->getCategory() << endl;
			channel << "Online: " << game->getOnline() << endl;
			channel << endl;
			eval = game->getListOfEvaluations();
			list <Evaluation*>::iterator  it1;
			channel << "---Evaluations---" << endl;
			for (it1 = eval.begin(); it1 != eval.end(); it1++)
			{
				channel << "Name: " << (*it1)->getName() << endl;
				channel << "Comments: " << (*it1)->getComments() << endl;
				channel << "Stars: " << (*it1)->getStars() << endl;
				channel << endl;
			}
			channel << endl;
		}
		else
		{
			desk = dynamic_cast <DeskApp*> (*it);
			if (desk != NULL)
			{
				channel << endl;
				channel << "---Desk Aplications---" << endl;
				channel << "Code: " << desk->getAppCode() << endl;
				channel << "Name: " << desk->getAppName() << endl;
				channel << "Version: " << desk->getVersion() << endl;
				channel << "Price: " << desk->getPrice() << endl;
				channel << "Developer: " << desk->getDeveloper()->getName() << endl;
				channel << "Type of files" << endl;
				files = desk->getFiles();
				list<string>::iterator f1;
				int i = 1;
				for (f1=files.begin(); f1!=files.end(); f1++)
				{
					channel << i++ << ")Type: " << *(f1) << endl;
				}
				channel << endl;
				eval = desk->getListOfEvaluations();
				list <Evaluation*>::iterator  it2;
				channel << "---Evaluations---" << endl;
				for (it2 = eval.begin(); it2 != eval.end(); it2++)
				{
					channel << "Name: " << (*it2)->getName() << endl;
					channel << "Comments: " << (*it2)->getComments() << endl;
					channel << "Stars: " << (*it2)->getStars() << endl;
					channel << endl;
				}
				channel << endl;
			}
		}
	}

}
//Eggrafh dedomenwn se dwthen arxeio
void AppSystem::writeTofile(string name)
{
	fstream file;
	Game* game;
	DeskApp* desk;	
	list <Application*>::iterator it;
	list <Evaluation*> eval;
	list <string> files;
	
	try
	{
		file.open(name.c_str(), ios::in | ios::out | ios::app);
		AppSystemPrint(file);
	}
	catch (ofstream::failure e)
	{
		cout << "File was not Found!"<<endl;
		cout<<e.what();
	}
	file.close();
	
}
//Diavasma dedomenwn apo dwthen arxeio
void AppSystem::readFromFile(string name)
{
	fstream file(name.c_str(), ios::in | ios::out | ios::app);
	list <Application*>::iterator it;
	list <Evaluation*> eval;
	list <string> files;
	string line;
	
	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << '\n';
		}
		file.close();
	}
	else cout << "Unable to open file";
}


