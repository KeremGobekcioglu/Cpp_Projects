#ifndef Tetris_Array1D
#define Tetris_Array1D
#include "AbstractTetris.h"
using namespace Abstraction;

namespace With_Array
{
	class TetrisArray1D : public Abstract_Tetris
	{
	private:
		char *board;
		int board_size;
		int board_width;
		int numberofmoves = 0;
		string lastmove = "";
	public:
		TetrisArray1D() = delete;// { cout<<"Default TetrisArray1d constructor !!"<<endl; board_size = 0; }
		TetrisArray1D(int height,int width);
		void add(const Tetromino &teto);
		friend ostream& operator<<(ostream &output, const TetrisArray1D& obj);
		void play(Tetromino objects[]);
		void addnicely(const Tetromino &teto,int wheretoput);
		void deletefirstadded();
		TetrisArray1D& operator=(const TetrisArray1D& obj);
		
		void print() const;
		void movedown(char whichway, int howmanysquare , Tetromino &teto, int columnposition);
		const bool checkIDX(int idx) const
		{
			if(idx < 0 || idx > board_size)
				return false;
			return true;
		}
		const char& at(int idx) const
		{ 
			if(checkIDX(idx))
				return board[idx];
			throw "Out of indexes"; 
		}
		char& at(int idx)
		{ 
			if(checkIDX(idx))
				return board[idx];
			throw "Out of indexes"; 
		}
		const char* getboard() const
		{
			return board;
		}
		const int size() const 
		{ 
			return board_size;
		}
		const int width() const 
		{ 
			return board_width;
		}
		bool controlspace(Tetromino &teto,const int rowposition, const int columnposition) const;
		// ~TetrisVector() = delete;
		~TetrisArray1D()
		{
			if(board != nullptr)
			{
				delete[] board;
				board = nullptr;
			}
		}
		void move(Tetromino &teto);
		void animate(Tetromino objects[],int whichone);
		void draw() const;
		void writeToFile();
		void readFromFile();
		const string lastMove() const
		{
			if(lastmove.size() == 0)
				throw "There is not a move !!!";
			return lastmove;
		};
		const int numberOfMoves() const
		{
			return numberofmoves;
		};
		void operator+=(Tetromino &teto);
	};
}

#endif