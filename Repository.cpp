#include "Repository.h"

repository::repository() {}

void repository::add(med elem)
{
	for (int i = 0; i < repo.size(); i++)
		if (repo[i].get_name() == elem.get_name() && repo[i].get_preis() == elem.get_preis() && repo[i].get_konzentrazion() == elem.get_konzentrazion())
		{
			repo[i].inc();
			return;
		}
	repo.push_back(elem);
	sort();
}

bool repository::remove(med elem)
{
	for (int i = 0; i < repo.size(); i++)
		if (repo[i].get_name() == elem.get_name() && repo[i].get_preis() == elem.get_preis() && repo[i].get_konzentrazion() == elem.get_konzentrazion())
		{
			repo[i].dec();
			if (repo[i].get_menge() <= 0)
			{
				repo.erase(repo.begin() + i);
				sort();
			}
			return true;
		}
	return false;
}

med repository::get_elem(int i)
{
	if (i < repo.size())
		return this->repo[i];
	else
		throw exception();
}

int repository::size()
{
	return repo.size();
}

void repository::sort()
{
	if (!repo.empty())
		for (int i = 0; i < repo.size() - 1; i++)
			for (int j = 0; j < repo.size() - i - 1; j++)
				if (repo[j].get_preis() > repo[j + 1].get_preis())
					swap(repo[j], repo[j + 1]);
}

vector<med> repository::get_full()
{
	sort();
	return this->repo;
}

bool repository::isempty()
{
	return repo.empty();
}