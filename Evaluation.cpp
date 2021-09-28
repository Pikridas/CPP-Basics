#include "Evaluation.h"

Evaluation::Evaluation(float stars, string name, string comments)
{
	this->comments = comments;
	this->name = name;
	this->stars = stars;
}

Evaluation::Evaluation(const Evaluation& ev)
{
	this->comments = ev.comments;
	this->name = ev.name;
	this->stars = ev.stars;
}

float Evaluation::getStars()
{
	return stars;
}

string Evaluation::getName()
{
	return name;
}

string Evaluation::getComments()
{
	return comments;
}
