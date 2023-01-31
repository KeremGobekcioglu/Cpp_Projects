#ifndef UTIL_H_H
#define UTIL_H_H
#include<time.h>
#include <chrono>
#include <thread> // it is for my vector class
#include"vectorrr.h"

enum class tetro
{
	I,
	O,
	T,
	J,
	L,
	S,
	Z
};

class Tetromino
{
private:
	vec2d whichshape; // my first vector
	static int result_lengt; 
	static int previousresult;
	vec2d nicefit; // result vector
public:
	friend class Tetris;
	void set_result_length(int a)
	{
		result_lengt = a;
		previousresult = a;
	};
	int getlengt() const { return result_lengt; };
	Tetromino(tetro shape);
	Tetromino()
	{
		
	}
	void fix() const;
	// void setnicefit(vec2d set)
	// {
	// 	cout<<"icerde miyi<"<<endl;
	// 	delete[] nicefit.doubleptr;
	// 	this->nicefit.setsize(0);// = 0; // other.sizerow;
	// 	this->nicefit.setrowcapacity(set.getrowcapacity());// = set.getrowcapacity();
	// 	nicefit.doubleptr = new vec1d[set.getrowcapacity()];
	// 	for (int i = 0; i < set.getrowcapacity(); i++)
	// 		nicefit.doubleptr[i].ptr = new char[set.doubleptr[i].getcolumncapacity()];
	// 	for (int i = 0; i < set.size(); i++)
	// 	{
	// 		this->nicefit.doubleptr[i].setsizecolumn(0);
	// 		for (int j = 0; j < set.doubleptr[i].size(); j++)
	// 			this->nicefit.doubleptr[i].pushback(set.doubleptr[i].ptr[j]);
	// 		this->nicefit.push(set.doubleptr[i]);
	// 	}
	// }
	void nicefitprint() const
	{
		cout<<nicefit<<endl;
	}
	void whichshapeprint() const
	{
		cout<<whichshape<<endl;
	}
	void operator=(tetro shape);
	void print() const;
	void otherprint(const vec2d &ak) const;
	bool canfit(Tetromino &teto, char position);
	void setter(vec2d &shapenumber);
	void bestfit(vec1d &objects);
	const vec2d getwhich() const;
	void rotatewhichone(char turn,Tetromino &teto);
	int spacecontrol(Tetromino &teto);
	void addtonicefit(Tetromino &teto);
	const vec2d getnicefit() const;
	~Tetromino()
	{
		result_lengt = -1;
		previousresult = -1;
		//whichshape.~vec2d();
		//nicefit.~vec2d();
	}
};


#endif
