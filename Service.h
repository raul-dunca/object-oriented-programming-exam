#pragma once
#include "Repo.h"

class Service
{
public:
	Service(Repo r) :r{ r }
	{

	}
	vector<Astronomer> get_all_astronomers_serv()
	{
		return this->r.get_all_astronomers();
	}
	vector<Star> get_all_stars_serv()
	{
		return this->r.get_all_stars();
	}
	void add_serv(Star s)
	{
		this->r.add_repo(s);
		ofstream g("stars.txt");
		vector<Star> sta = this->get_all_stars_serv();
		int i, j;
		/*for (i = 0; i < sta.size(); i++)
		{
			for (j = 0; j < sta.size(); j++)
			{

				if(sta[i].get_diameter()<sta[j].get_diameter())
				{
					swap(sta[i], sta[j]);
				}

			}
		}*/
		for (auto a : this->r.get_all_stars())
		{
			g << a.get_name() << ";" << a.get_constelatoin() << ";" << a.get_right_asc() << ";" << a.get_declination() << ";" << a.get_diameter() << endl;
		}
	}
	void update_serv(string name,Star s)

	{
		this->r.update_repo(name,s);
		ofstream g("stars.txt");
		for (auto a : this->r.get_all_stars())
		{
			g << a.get_name() << ";" << a.get_constelatoin() << ";" << a.get_right_asc() << ";" << a.get_declination() << ";" << a.get_diameter() << endl;
		}
	}

private:
	Repo r;
};