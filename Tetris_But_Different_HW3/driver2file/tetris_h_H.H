#ifndef tetris_h_H
#define tetris_h_H
#include "UTIL_H.h"

class Tetris
{

	private:
		vec2d board;
		static int column_result_length; // it will determine where will i put my shapes , column
		static int column_previousresult_length; // it is like control 
		static int row_result_length;
		static int row_previousresult_length;
	public:
		Tetris()
		{

		}
		Tetris(int height,int width);
		void add(const Tetromino &teto);
		void draw() const;
		void move(Tetromino &teto);
		void animate(Tetromino objects[],int whichone);
		void play(Tetromino objects[]);
		void otherprint(const vec2d &ak) const;
		void rotatewhichone(char turn,Tetromino &teto) const;
		void deneme(Tetromino &teto,Tetromino &willbeadd);
		void addnicely(const Tetromino &teto,int wheretoput);
		void deletefirstadded();
		void operator+=(Tetromino &teto);
		bool controlspace(Tetromino &teto,const int rowposition, const int columnposition) const;
};



#endif