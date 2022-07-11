#pragma once
#include "Domain.h"
#include <vector>
#include <fstream>
#include <sstream>
class Repo
{
public:
	Repo()
	{
	
		ifstream f("astronomers.txt");
		string buffer;
		string n, c;
		while (getline(f, buffer))
		{
			stringstream ss(buffer);
			getline(ss, n, ';');
			getline(ss, c, ';');
			this->astronomers.push_back(Astronomer{ n,c });
		}

		ifstream r("stars.txt");
		string buffer2;
		string na, co,ra,dec,dia;
		while (getline(r, buffer2))
		{
			stringstream sss(buffer2);
			getline(sss, na, ';');
			getline(sss, co, ';');
			getline(sss, ra, ';');
			getline(sss, dec, ';');
			getline(sss, dia, ';');
			this->stars.push_back(Star{na,co,stoi(ra),stoi(dec),stod(dia)});
		}
		int i, j;

		//sort(this->stars.begin(), this->stars.end(), fct);
		
		char s1[20];
		char s2[20];
		for (i = 0; i < this->stars.size(); i++)
		{
			for (j = 0; j < this->stars.size(); j++)
			{
				
				strcpy(s1, this->stars[i].get_constelatoin().c_str());
				strcpy(s2, this->stars[j].get_constelatoin().c_str());
				if (strcmp(s1, s2) < 0)
				{
					swap(this->stars[i], this->stars[j]);
				}

			}
		}
		//delete s1;
		//delete s2;

	}
	vector<Astronomer> get_all_astronomers()
	{
		return this->astronomers;
	}
	vector<Star> get_all_stars()
	{
		return this->stars;
	}
	void add_repo(Star s)
	{
		this->stars.push_back(s);
	}
	void update_repo(string oldname,Star s)
	{
		for (int i = 0; i < this->stars.size(); i++)
		{
			if (this->stars[i].get_name() == oldname)
			{
				this->stars[i].set_name(s.get_name());
				this->stars[i].set_ra(s.get_right_asc());
				this->stars[i].set_dec(s.get_declination());
				this->stars[i].set_diameter(s.get_diameter());
				break;
			}
		}
	}
private:
	vector<Astronomer> astronomers;
	vector<Star> stars;
};