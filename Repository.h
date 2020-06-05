#pragma once
#include <vector>
#include <string>
#include "Medikament.h"

using namespace std;

class repository
{
private:
	vector<med> repo;

public:

	/*
	Konstructor.
	*/
	repository();

	/*
	isempty Funktion
	Bestimmt ob mein repo leer it
	Return: bool
	*/
	bool isempty();

	/*
	add Funktion
	Fuegt einen Element ins repo
	Parameter: med elem
	*/
	void add(med elem);

	/*
	remove Funktion
	Loescht einen Element aus repo
	Parameter: med elem
	*/
	bool remove(med elem);

	/*
	get Funktion
	Gibt zurueck den Element von Index i (Parameter) aus repo.
	Return: med
	Parameter: int i
	*/
	med get_elem(int i);

	/*
	get_full Funktion
	Gibt zurueck den ganzen repo.
	Return: vect<med>
	*/
	vector<med> get_full();

	/*
	size Funktion
	Bestimmt wie viele Elemente der repo hat
	Return: int
	*/
	int size();

	/*
	sort Funktion
	Sortiert underen repo.
	*/
	void sort();
};