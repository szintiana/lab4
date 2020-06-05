#include "Controller.h"
#include <string>
#include <iostream>

using namespace std;

controller::controller(repository repo)
{
	this->contr = repo;
}
void controller::add(string name, int konzentrazion, int preis)
{
	med elem = med(name, konzentrazion, preis);
	contr.add(elem);
}

void controller::remove(string name, int konzentrazion, int preis)
{
	med elem = med(name, konzentrazion, preis);
	bool sem = contr.remove(elem);
	if (!sem)
		throw exception();
}

vector<med> controller::knapp(int i)
{
	vector<med> helper;
	for (int i = 0; i < contr.size(); i++)
		if (contr.get_elem(i).get_menge() <= i)
			helper.push_back(contr.get_elem(i));
	return helper;
}

vector<med> controller::name(string elem)
{
	vector<med> helper;
	for (int i = 0; i < contr.size(); i++)
		if (contr.get_elem(i).get_name().find(elem) != string::npos)
			helper.push_back(contr.get_elem(i));
	if (helper.size() > 1)
	{
		for (int i = 0; i < helper.size() - 1; i++)
			for (int j = 0; j < helper.size() - i - 1; j++)
				if (helper[j].get_name() > helper[j + 1].get_name())
					swap(helper[j], helper[j + 1]);
		return helper;
	}
	else
	{
		helper = this->contr.get_full();
		return helper;
	}
}

void controller::print()
{
	for (int i = 0; i < contr.size(); i++) 
		cout << contr.get_elem(i).get_name() << " x " << contr.get_elem(i).get_menge() <<  endl << contr.get_elem(i).get_konzentrazion() << "%" << endl << contr.get_elem(i).get_preis() << "$" << endl << endl;
}

bool controller::isempty()
{
	return contr.isempty();
}

int controller::size()
{
	return contr.size();
}

med controller::get(int i)
{
	return contr.get_elem(i);
}