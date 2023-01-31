#ifndef UTIL_H_H
#define UTIL_H_H
#include<time.h>
#include <chrono>
#include <thread> // it is for my vector class
// #include"vectorrr.h"
#include <vector>
#include<iostream>
#include<list>
#include<deque>
#include<string>
using namespace std;
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
	vector<vector<char>> whichshape; // my first vector
	static int result_lengt; 
	static int previousresult;
	vector<vector<char>> nicefit; // result vector
	tetro lasttetro;
public:
	friend ostream& operator<<(ostream &output, const vector<vector<char>> &obj);
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
	const tetro& gettetro() const
	{
		return lasttetro;
	}

	void settetro(const tetro &var)
	{
		lasttetro = var;
	}
	// void setnicefit(vector<vector<char>> set)
	// {
	// 	cout<<"icerde miyi<"<<endl;
	// 	delete[] nicefit.doubleptr;
	// 	this->nicefit.setsize(0);// = 0; // other.sizerow;
	// 	this->nicefit.setrowcapacity(set.getrowcapacity());// = set.getrowcapacity();
	// 	nicefit.doubleptr = new vector<char>[set.getrowcapacity()];
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
	void nicefitprint() const;
	void whichshapeprint() const;
	void operator=(tetro shape);
	void print() const;
	void otherprint(const vector<vector<char>> &ak) const;
	bool canfit(Tetromino &teto, char position);
	void setter(vector<vector<char>> &shapenumber , const tetro &var);
	void bestfit(vector<char> &objects);
	const vector<vector<char>> getwhich() const;
	void rotatewhichone(char turn,Tetromino &teto);
	int spacecontrol(Tetromino &teto);
	void addtonicefit(Tetromino &teto);
	const vector<vector<char>> getnicefit() const;
	~Tetromino()
	{
		result_lengt = -1;
		previousresult = -1;
		//whichshape.~vector<vector<char>>();
		//nicefit.~vector<vector<char>>();
	}
};


#endif
