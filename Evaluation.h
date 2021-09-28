#ifndef EVALUATION_H
#define EVALUATION_H
#include <iostream>
#include <string>

using namespace std;

class Evaluation
{
private:
	float stars;
	string name;
	string comments;

public:	
	Evaluation(float stars, string name, string comments);
	Evaluation(const Evaluation& ev);
	float getStars();
	string getName();
	string getComments();
};

#endif
