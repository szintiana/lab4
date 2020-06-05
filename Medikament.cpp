#include "Medikament.h"

med::med(string name, int konz, int preis)
{
	this->name = name;
	this->konzentrazion = konz;
	this->preis = preis;
	this->menge = 1;
}

med::med()
{
	this->name = "";
	this->konzentrazion = 0;
	this->preis = 0;
	this->menge = 0;
}

string med::get_name()
{
	return this->name;
}

int med::get_preis()
{
	return this->preis;
}

int med::get_menge()
{
	return this->menge;
}

int med::get_konzentrazion()
{
	return this->konzentrazion;
}

void med::set_preis(int i)
{
	this->preis = i;
}

void med::inc()
{
	this->menge++;
}

void med::dec()
{
	this->menge--;
}