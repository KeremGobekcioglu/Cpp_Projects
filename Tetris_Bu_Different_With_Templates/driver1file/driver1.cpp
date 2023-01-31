#include "TetrisVector.h"
#include "TetrisArray1D.h"
#include "TetrisAdapter.h"
#include "TetrisAdapter_functions.cpp"
using namespace With_Vector;
using namespace Abstraction;
using namespace With_Array;
using namespace With_Template;
int Tetromino::result_lengt;
int Tetromino::previousresult;
// int With_Vector::TetrisVector::column_result_length;
// int With_Vector::TetrisVector::column_previousresult_length;
// int With_Vector::TetrisVector::row_result_length;
// int With_Vector::TetrisVector::row_previousresult_length;

int main()
{
	cout<<"I wont test throw exception because program will end if i do it i will add an option if you want to test it"<<endl;
	cout<<"TEST PHASE IS OVER!!!!"<<endl;
	Tetromino forfix;
	forfix.fix();
	srand(time(NULL)); // for random shapes
	cout<<"Test phase 2 completed"<<endl;
	cout<<"Now testing the tetris functions"<<endl;
	TetrisVector testobject(10,16); // making the board
	testobject.draw(); // draw is okey it is working
	getchar(); // it is for not deleting the old test results
	Tetromino willbeadd = tetro::I;
	testobject.add(willbeadd); // add works too
	testobject.deletefirstadded();
	testobject += willbeadd; // += works too
	testobject.draw();
	cout<<endl;
	getchar(); // it is for not deleting the old test results
	testobject.addnicely(willbeadd,5); // it adds where i want to, i send an integer
	testobject.draw();
	testobject.deletefirstadded();
	testobject.draw(); // it is deleted
	getchar(); // it is for not deleting the old test results
	testobject.draw();
	cout<<endl<<endl<<endl;
	getchar(); // it is for not deleting the old test results
	// /* in play function i call animate function who calls fit function and fit function calls add functions */
	// /* PLAY function wants you to choose which one will be add*/
	// // you will see that int the other part driver2
	// /* i copied some functions from Tetromino to Tetris(rotatewhichone,otherprint) , i showed their work 
	// i'm not going to do it again it is above*/
	int i = 0;
	Tetromino *testobjects2;
	testobjects2 = new Tetromino[7];
	testobjects2[0]=(tetro::O); // MY constructor understands from tetros which shape will be added to my private vectors
	testobjects2[1]=(tetro::I); // also my setter calls in my constructor , and it sets the shapes and sets result length you can see it 
	testobjects2[2]=(tetro::L);
	testobjects2[3]=(tetro::Z);
	testobjects2[4]=(tetro::S);
	testobjects2[5]=(tetro::J);
	testobjects2[6]=(tetro::T);
	while(i<7)
	{	
		testobject.play(testobjects2); // random shapes , but 3 rotate , it is for showing
		cout<<endl;
		// it is for not deleting the old test results
		i++;
		/* i called only animate because it is test driver you won't play the game*/
	}
	// testobject.lastMove();
	cout<<"numberr of moves = "<<testobject.numberOfMoves()<<endl;
	i = 0;
	TetrisArray1D testobject3(10,11);
	testobject3.draw(); // draw is okey it is working
	getchar(); // it is for not deleting the old test results
	// Tetromino willbeadd = tetro::I;
	testobject3.add(willbeadd); // add works too
	testobject3.draw();
	cout<<endl;
	getchar(); // it is for not deleting the old test results
	testobject3.addnicely(willbeadd,7); // it adds where i want to, i send an integer
	testobject3.draw();
	testobject3.deletefirstadded();
	testobject3.draw(); // it is deleted
	getchar(); // it is for not deleting the old test results
	i = 0;
	while(i<7)
	{	
		testobject3.play(testobjects2); // random shapes , but 3 rotate , it is for showing
		cout<<endl;
		// it is for not deleting the old test results
		i++;
		/* i called only animate because it is test driver you won't play the game*/
	}
	// testobject3.lastMove();
	TetrisAdapter<vector<char>> testobject4(13,17);
	i = 0;
	testobject4.draw(); // draw is okey it is working
	getchar(); // it is for not deleting the old test results
	// Tetromino willbeadd = tetro::I;
	testobject4.add(willbeadd); // add works too
	testobject4.draw();
	cout<<endl;
	getchar(); // it is for not deleting the old test results
	testobject4.addnicely(willbeadd,7); // it adds where i want to, i send an integer
	testobject4.draw();
	testobject4.deletefirstadded();
	testobject4.draw(); // it is deleted
	i = 0;
	while(i<7)
	{	
		testobject4.play(testobjects2); // random shapes , but 3 rotate , it is for showing
		cout<<endl;
		// it is for not deleting the old test results
		i++;
		/* i called only animate because it is test driver you won't play the game*/
	}
	// testobject4.lastMove();
	TetrisAdapter<deque<char>> testobject5(10,10);
	i = 0;
	testobject5.draw(); // draw is okey it is working
	getchar(); // it is for not deleting the old test results
	// Tetromino willbeadd = tetro::I;
	testobject5.add(willbeadd); // add works too
	testobject5.draw();
	cout<<endl;
	getchar(); // it is for not deleting the old test results
	testobject5.addnicely(willbeadd,7); // it adds where i want to, i send an integer
	testobject5.draw();
	testobject5.deletefirstadded();
	testobject5.draw(); // it is deleted
	i = 0;
	while(i<7)
	{	
		testobject5.play(testobjects2); // random shapes , but 3 rotate , it is for showing
		cout<<endl;
		// it is for not deleting the old test results
		i++;
		/* i called only animate because it is test driver you won't play the game*/
	}
	// testobject5.lastMove();
	// testobject.writeToFile();
	
	TetrisVector fromfile(5,5); // size doesnt matter what s in the file will come
	fromfile.readFromFile();
	fromfile.draw();
	
	testobject3.writeToFile();
	
	TetrisArray1D fromfilee(10,10);
	fromfilee.readFromFile();
	fromfilee.draw();
	
	testobject4.writeToFile();
	
	TetrisAdapter<vector<char>> fromfileee(20,20);
	fromfileee.readFromFile();
	fromfileee.draw();

	TetrisAdapter<deque<char>> filee(9,9);
	filee.readFromFile();
	filee.draw();

	// cout<<"Testing throw exception ..."<<endl;
	// TetrisArray1D merhaba(10,10);
	// cout<<"A board has been made but I did not add any tetromino so if i ask last move , it will throw exception ..."<<endl;
	// merhaba.lastMove();
	// // you can test "play" function in driver2
	// cout<<"Test phases ended"<<endl;
	return 0;
}