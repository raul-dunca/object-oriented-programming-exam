#pragma once
#include <string>
using namespace std;
class Astronomer
{
public:
	Astronomer(string n, string c) : name{ n }, constelation{ c }
	{

	}
	string get_name()
	{
		return this->name;

	}
	string get_constelatoin()
	{
		return this->constelation;
	}
private:
	string name;
	string constelation;

};

class Star
{
public:
	Star(string n, string c, int r, int d, double di):name {n},constelation{c},ra{r},dec{d},diameter{di}
	{
	}
	string get_name()
	{
		return this->name;
	}
	string get_constelatoin()
	{
		return this->constelation;
	}
	int get_right_asc()
	{
		return this->ra;
	}
	int get_declination()
	{
		return this->dec;
	}
	double get_diameter()
	{
		return this->diameter;
	}
	void set_name(string newname)
	{
		this->name = newname;
	}
	void set_ra(int newr)
	{
		this->ra = newr;
	}
	void set_dec(int newd)
	{
		this->dec = newd;
	}
	void set_diameter(double newdi)
	{
		this->diameter = newdi;
	}
private:
	string name;
	string constelation;
	int ra;
	int dec;
	double diameter;

};