#ifndef Tetris_Adapter
#define Tetris_Adapter
#include "AbstractTetris.h"
using namespace Abstraction;

namespace With_Template
{
	template <class T>
	class TetrisAdapter : public Abstract_Tetris
	{
	private:
		T board;
		int board_size;
		int board_width; 
		int numberofmoves = 0;
	public:
		TetrisAdapter() = delete;
		TetrisAdapter(int height, int width);
		void add(const Tetromino &teto);
		// friend ostream &operator<<(ostream &output, const TetrisAdapter<T> &obj);
		void play(Tetromino objects[]);
		void addnicely(const Tetromino &teto, int wheretoput);
		void deletefirstadded();
		bool controlspace(Tetromino &teto, const int rowposition, const int columnposition) const;
		void movedown(char whichway, int howmanysquare , Tetromino &teto, int columnposition);

		const int size() const 
		{ 
			return board_size;
		}

		const int width() const
		{
			return board_width;
		}

		const int numberOfMoves() const
		{
			return numberofmoves;
		}

		const T getboard() const
		{
			return board;
		}
		// ~TetrisVector() = delete;
		~TetrisAdapter()
		{
			// board.clear();
			cout<<"Destructor called for adapter class!!!"<<endl;
		}

		void move(Tetromino &teto);
		void animate(Tetromino objects[], int whichone);
		void draw() const;
		void writeToFile();							 // = 0;
		void readFromFile();							 // = 0
		void operator+=(Tetromino &teto);
	};

}

#endif