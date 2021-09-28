/* Menelaos Pikridas / AM:141291 / EXAMHNO: 12o / Prog: PADA */
#include <iostream>
#include <list>
#include <string>
#include <cstring>
#include "Application.h"
#include "DeskApp.h"
#include "Developer.h"
#include "Evaluation.h"
#include "Game.h"
#include "AppSystem.h"

int main()
{
	string am = "Manos";
	string am1 = "141257";
	string am2 = "141269";
//	list <string> types  = { ".txt", ".docx" , ".csv" , ".pptx" };
	list <string> types  ;
	types.push_back(".txt"); 
	types.push_back(".docx");
	types.push_back(".csv");
	types.push_back(".pptx");	
//	list <string> types1 = { ".txt",".docx" ,".csv" ,".pptx",".xlsx" };
	list <string> types1 ;
	types1.push_back(".txt");
	types1.push_back(".docx");
	types1.push_back(".csv");
	types1.push_back(".pptx");
	types1.push_back(".xlsx");
	//Dhmiourgia Evaluations
	Evaluation* ev1 = new Evaluation(5, "Lampros", "Arketa kalh");
	Evaluation* ev2 = new Evaluation(6, "Mhxalhs", "Teleia");
	Evaluation* ev3 = new Evaluation(7, "Markos", "Apsogh");
	Evaluation* ev4 = new Evaluation(3, "Lampros", "Xalia");

	//Ghmiourgia kataskeuastwn gia tis efarmoges
	Developer* dev1 = new Developer("Dhmhtrhs", 1, "rigasand@gmail.com");
	Developer* dev2 = new Developer(am.c_str(), 2, "asdas@uniwa.gr");	
	Developer* dev3 = new Developer("Kwstas", 3, "kwstas@uniwa.gr");

	//Dhmiourgia Efarmogwn				
	DeskApp* desk = new DeskApp(types,"124", "Discord", 15.0, 0.0, dev2);
	DeskApp* desk1 = new DeskApp(types1, "125", "Viber", 15.0, 0.0, dev3);
	Game* g1 = new Game("FPP", "126", "WarZone", 14.0, 60.50, dev1);
	Game* g2 = new Game("FPS", "127", "Tetris", 14.0, 60.50, dev1);

	//Prosthkh Kritikwn stis efarmoges 
	desk->addEvaluation(ev1);
	desk1->addEvaluation(ev2);
	g1->addEvaluation(ev3);
	g1->addEvaluation(ev2);
	g2->addEvaluation(ev1);
	//Dhmiourgia kurias klashs
	AppSystem s1;
	
	//Prosthkh efarmogwn	
	s1.addApp(desk);
	s1.addApp(desk1);
	s1.addApp(g1);
	s1.addApp(g2);
	
	//Prosthkh Developers
	s1.addDev(dev1);
	s1.addDev(dev2);
	s1.addDev(dev3);

	//Emfanish efarmogwn
	//cout << "----------Emfanish Efarmogwn----------" << endl;
	//desk->showData();
	//desk1->showData();
	//g1->showData();
	s1.AppSystemPrint(cout);
	s1.writeTofile("input.txt");
	cout<< "--- Tupwma Apo Arxeio ---" << endl;
	s1.readFromFile("input.txt");
	return 0;
}
