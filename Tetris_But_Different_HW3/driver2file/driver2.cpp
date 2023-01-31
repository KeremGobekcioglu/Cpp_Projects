#include "tetris_h_H.H"
int Tetromino::result_lengt;
int Tetromino::previousresult;
int Tetris::column_result_length;
int Tetris::column_previousresult_length;
int Tetris::row_result_length;
int Tetris::row_previousresult_length;

int main()
{
	cout<<"TEST PHASE IS OVER!!!!"<<endl;
	Tetromino forfix;
	forfix.fix();
	srand(time(NULL)); // for random shapes
	cout << "Enter the the size of your board : first height then width : (Do not enter less than 7 height and less than 4 width)" << endl;
	int height,width;
	cin>>height>>width;
	Tetromino *objects; // with this object i am going to use functions from Tetromino class
	objects = new Tetromino[50];
	Tetris other(height, width);
	while (1)
		other.play(objects); // Eventually this while will be breaked
	return 0;
}