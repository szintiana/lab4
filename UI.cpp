#include "UI.h"

using namespace std;

void menu()
{
	int command;
	int last_command;
	med last_add, last_remove;
	vector<int> undo_list, redo_list;
	vector<med> undo_add, undo_remove, redo_add, redo_remove;
	bool sem = true;
	repository repo = repository();
	controller contr = controller(repo);
	while (sem)
	{
		cout << "1. add elem\n2. show elems\n3. remove elem\n4. show knapp\n5. show meds\n6. prices\n7. undo\n8. redo\n9. quit\n your command: ";
		cin >> command;
		cout << endl;
		
		if (command == 1)
		{
			string name;
			int konz;
			int preis;
			cout << "name: ";
			cin >> name;
			cout << "konzentrazion: ";
			cin >> konz;
			cout << "pries: ";
			cin >> preis;
			cout << endl;
			contr.add(name, konz, preis);
			last_command = 1;
			undo_list.push_back(last_command);
			last_add = med(name, konz, preis);
			undo_add.push_back(last_add);
		}
		if (command == 3)
		{
			string name;
			int konz;
			int preis;
			cout << "name: ";
			cin >> name;
			cout << "konzentrazion: ";
			cin >> konz;
			cout << "pries: ";
			cin >> preis;
			cout << endl;
			contr.remove(name, konz, preis);
			last_command = 3;
			undo_list.push_back(last_command);
			last_remove = med(name, konz, preis);
			undo_remove.push_back(last_remove);
		}
		if (command == 2)
		{
			contr.print();
		}
		if (command == 4)
		{
			int knapp;
			cout << "anzahl kleiner als: ";
			cin >> knapp;
			cout << endl;
			vector<med> vect = contr.knapp(knapp);
			for (int i = 0; i < vect.size(); i++)
				cout << vect[i].get_name() << endl;
			cout << endl;
		}
		if (command == 5)
		{
			string medi;
			cout << "Medikament: ";
			cin >> medi;
			cout << endl;
			vector<med> vect = contr.name(medi);
			for (int i = 0; i < vect.size(); i++)
				if (vect[i].get_name().find(medi) != string::npos)
				cout << vect[i].get_name() << " x " << vect[i].get_menge() << endl << vect[i].get_konzentrazion() << "%" << endl << vect[i].get_preis() << "$" <<endl;
			cout << endl;
		}
		if (command == 6)
		{
			if (!contr.isempty())
			{
				int prev_val = -1;
				for (int i = 0; i < contr.size(); i++)
				{
					int val = contr.get(i).get_preis();
					if (prev_val != val)
					{
						cout << "--------------------" << endl << val << " $:" << endl << endl;
						prev_val = val;
					}
					cout << contr.get(i).get_name() << " x " << contr.get(i).get_menge() << endl << contr.get(i).get_konzentrazion() << "%" << endl << endl;
				}
			}
		}
		if (command == 7)
		{
			if (undo_list.empty())
				cout << "unmoeglich!" << endl << endl;
			else
			{
				int i = undo_list.back();
				if (i == 1)
				{
					contr.remove(undo_add.back().get_name(), undo_add.back().get_konzentrazion(), undo_add.back().get_preis());
					redo_add.push_back(undo_add.back());
					redo_list.push_back(undo_list.back());
					undo_add.pop_back();
					undo_list.pop_back();
				}
				if (i == 3)
				{
					contr.add(undo_remove.back().get_name(), undo_remove.back().get_konzentrazion(), undo_remove.back().get_preis());
					redo_remove.push_back(undo_remove.back());
					redo_list.push_back(undo_list.back());
					undo_remove.pop_back();
					undo_list.pop_back();
				}
			}
		}
		if (command == 8)
		{
			if (redo_list.empty())
				cout << "unmoeglich!" << endl << endl;
			else
			{
				int i = redo_list.back();
				if (i == 1)
				{
					contr.add(redo_add.back().get_name(), redo_add.back().get_konzentrazion(), redo_add.back().get_preis());
					undo_add.push_back(redo_add.back());
					undo_list.push_back(redo_list.back());
					redo_add.pop_back();
					redo_list.pop_back();
				}
				if (i == 3)
				{
					contr.remove(redo_remove.back().get_name(), redo_remove.back().get_konzentrazion(), redo_remove.back().get_preis());
					undo_remove.push_back(redo_remove.back());
					undo_list.push_back(redo_list.back());
					redo_remove.pop_back();
					redo_list.pop_back();
				}
			}
		}
		if (command == 9)
			sem = false;

	}
}