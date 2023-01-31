#ifndef AbstractTetris
#define AbstractTetris
#include "UTIL_H.h"
#include "fstream"
// #include <iostream>
// using namespace std;
namespace Abstraction
{

	class Abstract_Tetris
	{
		private:
			// tetro lastTetro;
			string lastmove = "";
		public:
		Abstract_Tetris()
		{
			cout<<"Default constructor for abstract class !"<<endl;
		}

		// tetro getlasttetro() {
		// 	return lastTetro;
		// };

		void setstring(char way, int count, const Tetromino &teto , int down)
		{
			if(lastmove.size() != 0)
				lastmove.clear();
			string whichway = "";
			// else
			// {
			// 	throw "There is not a lastMove !!! ";
			// }
			if(way == 'L')
				whichway += "Left";
			else
				whichway += "Right";
			if(teto.gettetro() == tetro::O)
			{
				lastmove += " Tetromino O goes ";
			}
			else if(teto.gettetro() == tetro::I)
			{
				lastmove += " Tetromino I goes ";
			}
			else if(teto.gettetro() == tetro::L)
			{
				lastmove += " Tetromino L goes ";
			}
			else if(teto.gettetro() == tetro::J)
			{
				lastmove += " Tetromino J goes ";
			}
			else if(teto.gettetro() == tetro::S)
			{
				lastmove += " Tetromino S goes ";
			}
			else if(teto.gettetro() == tetro::Z)
			{
				lastmove += " Tetromino Z goes ";
			}
			else if(teto.gettetro() == tetro::T)
			{
				lastmove += " Tetromino T goes ";
			}
			lastmove += whichway;
			lastmove +=  " for " + to_string(count) + " blocks ";
			lastmove +=  " and went down for " + to_string(down);
			cout<< lastmove <<endl;
		}
		const string& lastMove() const
		{
			string exception = "There is not a last move !!!\n";
			try{
			if(lastmove.size() != 0){}
			else
				throw exception;
			}
			catch(string throwen)
			{
				cout<<throwen;
			}
			cout<<"Last move is "<<endl<<lastmove<<endl;
			return lastmove;
		}
		virtual void animate(Tetromino objects[],int whichone) = 0;
		
		virtual void writeToFile() = 0;

		virtual void readFromFile() = 0;
		
		virtual void draw() const = 0;
		
		virtual void move(Tetromino &teto) = 0;
		
		// virtual const string lastMove() const = 0;
		
		virtual const int numberOfMoves() const = 0;
		
		virtual bool controlspace(Tetromino &teto,const int rowposition, const int columnposition) const = 0;
		
		virtual void operator+=(Tetromino &teto) = 0;
		
		virtual void add(const Tetromino &teto) = 0;
		
		virtual void play(Tetromino objects[]) = 0;
		
		virtual void addnicely(const Tetromino &teto,int wheretoput) = 0;
		
		virtual void deletefirstadded() = 0;

		// virtual void movedown(Tetromino &teto, int columnposition) = 0;
		
		virtual ~Abstract_Tetris() {};
	};
}

#endif