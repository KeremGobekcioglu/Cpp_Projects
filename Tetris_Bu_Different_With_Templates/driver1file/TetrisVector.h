#ifndef Tetris_Vector
#define Tetris_Vector
#include "AbstractTetris.h"
using namespace Abstraction;

namespace With_Vector
{
	class TetrisVector : public Abstract_Tetris
	{
		private:
		vector<vector<char>> board;
		int numberofmoves = 0;
		// string lastmove = "";
	public:
		TetrisVector() = delete;
		TetrisVector(int height,int width);
		void add(const Tetromino &teto);
		friend ostream& operator<<(ostream &output, const vector<vector<char>> &obj);
		void play(Tetromino objects[]);
		void addnicely(const Tetromino &teto,int wheretoput);
		void deletefirstadded();
		bool controlspace(Tetromino &teto,const int rowposition, const int columnposition) const;
		
		~TetrisVector()
		{
			board.clear();
		}

		const int numberOfMoves() const
		{
			return numberofmoves;
		}
		
		void movedown(char whichway, int howmanysquare , Tetromino &teto, int columnposition);
		void move(Tetromino &teto);
		void animate(Tetromino objects[],int whichone);
		void draw() const;
		void writeToFile();
		void readFromFile();
		void operator+=(Tetromino &teto);
	};
}

#endif