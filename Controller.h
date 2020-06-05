#pragma once
#include "Repository.h"
#include <string>
#include <vector>

using namespace std;

class controller
{
private:
	repository contr;

public:

	/*
	Konstructor.
	Braucht als Prameter einen Argument vom Typ repository.
	*/
	controller(repository repo);

	/*
	add Funktion
	Fuegt einen Element ins contr
	Parameter:
	string name
	int konzentrazion
	int preis
	*/
	void add(string name, int konzentrazion, int preis);

	/*
	remove Funktion
	Loescht einen Element aus contr
	Parameter:
	string name
	int konzentrazion
	int preis
	*/
	void remove(string name, int konzentrazion, int preis);

	/*
	knapp Funktion
	Gibt zurueck alle Medikamente, deren Anzahl kleiner als i (Parameter) it.
	Return von Typ: vector<med>
	Parameter: int 1
	*/
	vector<med> knapp(int i);

	/*
	Eigentlich habe ich ganz vergessen was das macht aber ich weiss, dass falls ich diesen loesche, geht 
	die 5te command nicht mehr. Also es bleibt hier. 
	P.S.: Entschuldigung, dass ich die letzten lab so spaet abgegeben habe, coronacation took a toll and I am
	really trying my best. Thank you for your understanding.
	*/
	vector<med> name(string elem);

	/*
	isempty Funktion
	Bestimmt ob mein contr leer it
	Return: bool
	*/
	bool isempty();
	
	/*
	size Funktion
	Bestimmt wie viele Elemente der contr hat
	Return: int
	*/
	int size();

	/*
	get Funktion
	Gibt zurueck den Element von Index i (Parameter) aus contr.
	Return: med
	Parameter: int i
	*/
	med get(int i);

	/*
	print Funktion
	*/
	void print();
};
