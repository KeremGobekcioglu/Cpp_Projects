#include "TetrisVector.h"
#include "TetrisArray1D.h"
#include "TetrisAdapter.h"
#include "TetrisAdapter_functions.cpp"
// #include "AbstractTetris.h"
using namespace With_Vector;
using namespace Abstraction;
using namespace With_Array;
using namespace With_Template;
int Tetromino::result_lengt;
int Tetromino::previousresult;

int main()
{
	cout << "TEST PHASE IS OVER!!!!" << endl;
	Tetromino forfix;
	forfix.fix();
	srand(time(NULL)); // for random shapes
	cout << "Enter the the size of your board : first height then width : (Do not enter less than 7 height and less than 4 width)" << endl;
	int height, width;
	cin >> height >> width;
	Tetromino *objects; // with this object i am going to use functions from Tetromino class
	objects = new Tetromino[100];
	char decision;
	cout << "Which board do you want : (V for vector, 1 for array1D, A for adaptor , T for throw exception test) ? = ";
	cin >> decision;
	if (decision == 'V')
	{
		TetrisVector board(height, width);
		decision = '.';
		cout << "Do you want to reload the old game : Y or N (If there is not , an exception will thrown ) ... ? = ";
		cin >> decision;
		if (decision == 'Y')
			board.readFromFile();
		else
			cout << "Fresh game !! " << endl;
		while (1)
			board.play(objects);
	}
	else if (decision == '1')
	{
		TetrisArray1D board(height, width);
		cout<<"Array 1D"<<endl;
		decision = '.';
		cout << "Do you want to reload the old game : Y or N (If there is not , an exception will thrown ) ... ? = ";
		cin >> decision;
		if (decision == 'Y')
			board.readFromFile();
		else
			cout << "Fresh game !! " << endl;
		while (1)
			board.play(objects);
	}
	else if (decision == 'A')
	{
		decision = '.';
		cout << "Which class do you want to use ? ( D for deque , V for 1d vector )";
		cin >> decision;
		if (decision == 'D')
		{
			TetrisAdapter<deque<char>> board(height, width);
			decision = '.';
			cout << "Do you want to reload the old game : Y or N (If there is not , an exception will thrown ) ... ? = ";
			cin >> decision;
			if (decision == 'Y')
				board.readFromFile();
			else
				cout << "Fresh game !! " << endl;
			while (1)
				board.play(objects);
		}
		else if (decision == 'V')
		{
			TetrisAdapter<vector<char>> board(height, width);
			decision = '.';
			cout << "Do you want to reload the old game : Y or N (If there is not , an exception will thrown ) ... ? = ";
			cin >> decision;
			if (decision == 'Y')
				board.readFromFile();
			else
				cout << "Fresh game !! " << endl;
			while (1)
				board.play(objects);
		}
		else if(decision == 'T')
		{
			cout<<"Creating an empty board for throw exception "<<endl;
			cout<<"I wont add a tetromino so there wont be any move "<<endl;
			TetrisVector test(10,10);
			test.lastMove();
		}
	}
	else
	{
		cout << "It was a simple choice ..." << endl
			 << "Program is terminated" << endl;
	}
	delete[] objects;
}