#include "Game.h"

Game::Game(string category, const char* appCode,const char*appName,float version,float price,Developer* developer) : Application(appCode, appName, version, price, developer)
{
	this->online = false;
	this->category = category;
}

Game::Game(const Game& g) : Application(g)
{
	this->category = g.category;
	this->online = g.online;
}

void Game::showData()
{
	Application::showData();
	cout << "Category: " << category << endl;
	cout << "Online: " << online << endl;
	cout << endl;
}

void Game::setOnLine()
{
		online = true;
}

string Game::getCategory()
{
	return category;
}

bool Game::getOnline()
{
	return online;
}
