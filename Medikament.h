#pragma once
#include <string>
using namespace std;

class med
{
private:
	string name;
	int konzentrazion;
	int menge;
	int preis;

public:

	/*
	Konstruktor
	Parameter:
	string name
	int konzentration
	int preis
	*/
	med(string name, int konz, int preis);

	/*
	Leerer Konstruktor ohner Parametern
	*/
	med();

	/*
	Getter fuer die Name.
	*/
	string get_name();
	
	/*
	Getter fuer die Konzentrazion.
	*/
	int get_konzentrazion();

	/*
	Getter fuer die Menge.
	*/
	int get_menge();

	/*
	Getter fuer den Prei.
	*/
	int get_preis();

	/*
	Setter fuer den Preis.
	*/
	void set_preis(int i);

	/*
	Hoehert die Menge.
	*/
	void inc();

	/*
	Verkleinert die Menge
	*/
	void dec();
};