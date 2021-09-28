#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "Application.h"

using namespace std;

class Game : public Application
{
private:
	bool online;
	string category;

public:	
	Game( string category, const char* appCode,const char* appName, float version, float price, Developer* developer);
	Game(const Game& g);
	void showData();
	void setOnLine();
	string getCategory();
	bool getOnline();
};

#endif
