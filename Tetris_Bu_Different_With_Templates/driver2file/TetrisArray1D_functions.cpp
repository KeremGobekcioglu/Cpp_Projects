#include "TetrisArray1D.h"
using namespace With_Array;


namespace With_Array
{
	ostream& operator<<(ostream &output, const TetrisArray1D& obj)
	{
		for(int i = 0; i<obj.size()/obj.width(); i++)
		{		
			for(int j = 0; j<obj.width(); j++)
					output<<obj.getboard()[i*obj.width() + j];
			output<<endl;
		}
		output<<endl;
		return output;
	}
}

void TetrisArray1D::print() const
{
	for(int i = 0; i<board_size/board_width; i++)
	{
		for(int j = 0; j<board_width; j++)
			cout<<board[i*board_width + j];
		cout<<endl;
	}
	cout<<endl;
}

TetrisArray1D::TetrisArray1D(int height, int width)
{
	if (height * width <= 0)
		throw "What the fuck !!!";
	board_size = height * width;
	board_width = width;
	board = new char[board_size];

	for (int i = 0; i < board_size; i++)
		board[i] = '.';

	// column_result_length = 0; // setting all my statics
	// column_previousresult_length = 0;
	// row_result_length = 0;
	// row_previousresult_length = 0;
}

TetrisArray1D &TetrisArray1D::operator=(const TetrisArray1D &obj)
{
	// char *temp = new char[obj.size()];
	if (board_size == 0)
	{
		board = new char[obj.size()];
		this->board_size = obj.size();
		return *this;
	}
	// this->board_size = obj.size();
	delete[] board;
	board = nullptr;
	this->board_size = obj.size();
	for(int i = 0; i<obj.size(); i++)
	{
		board[i] = obj.getboard()[i];
	}
	return *this;
}





void TetrisArray1D::draw() const
{
	cout << "\e[1;1H\e[2J";
	std::this_thread::sleep_for(std::chrono::milliseconds(50)); // other drawings are being made in move function
	// cout << *this << endl;
	print();
	cout << "endline for notation" << endl;
}

void TetrisArray1D::addnicely(const Tetromino &teto, int wheretoput) // this function adds the shape to its optimal position
{
	for (int i = 0; i < teto.getwhich().size(); i++)
		for (int j = wheretoput; j < wheretoput + teto.getwhich().at(0).size(); j++)
			board[i * board_width + j] = '.'; // deleting the first added tetro so they wont overleap
											  // 10 10 , ilk 3 satır silincek

	for (int i = 0; i < teto.getwhich().size(); i++)
		for (int j = wheretoput, z = 0; z < teto.getwhich().at(0).size() && j < this->board_width; j++, z++)
			board[i * board_width + j] = teto.getwhich().at(i).at(z);
}

void TetrisArray1D::deletefirstadded()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < this->board_width; j++)
			board[i*board_width + j] = '.'; // deleting the first added tetro so they wont overleap
}

void TetrisArray1D::add(const Tetromino &teto) // only add s to the top , i will have another add function too
{
	// boardın t den küçük olup olmadığını kontrol etmiyorum
	for (int i = 0; i < teto.getwhich().size(); i++)
		for (int j = (this->board_width / 2) - teto.getwhich().at(0).size() / 2, z = 0; j < this->board_width / 2, z < teto.getwhich().at(0).size(); j++, z++)
			board[i*board_width + j] = teto.getwhich().at(i).at(z);
	// cout<<"\033[" +to_string(teto.getwhich().size())+"A";
}

void TetrisArray1D::move(Tetromino &teto)
{
	for(int i = 0; i<teto.getwhich().size(); i++)
	{	
		for(int j = 0; j<this->board_width; j++)
		{	
			if(board[i*board_width + j] != '.')
			{	
				cout<<"Shape cant be added. Terminated."<<endl;
				exit(0);
			}
		}
	}
	char direction;
	int count;
	char whichway;
	int howmanysquare;
	cout << "Which direction you want to shape to be turned ('L' or 'R') and how many time it has to turn ?";
	cin >> direction;
	cin >> count;
	cout << endl;
	for (int i = 0; i < count; i++)
		teto.rotatewhichone(direction, teto);
	cout << "Which way ('L' or 'R') and how much space the shape has to move ?";
	cin >> whichway >> howmanysquare;
	(*this) += (teto); // adding the tetromino to the board
	numberofmoves++;
	cout << "Before moving" << endl;
	this->draw();
	deletefirstadded();
	while (1)
	{
		if (whichway == 'R' && howmanysquare + this->board_width / 2 + teto.getwhich().at(0).size() <= this->board_width)
			break;
		if (whichway == 'L' && this->board_width / 2 - howmanysquare >= 0)
			break;
		cout << "Out of borders , enter again =";
		cin >> howmanysquare;
		cout << endl;
	}
	(*this) += teto; // add(teto);
	char temp;
	int onlyone = 0;
	int getout = 0;
	if (whichway == 'R') // this section adds the tetromino the optimal posiiton
		addnicely(teto, howmanysquare + this->board_width / 2);
	else
		addnicely(teto, this->board_width / 2 - howmanysquare);
	cout << "Optimal position at top " << endl;
	this->draw();
	int flag = 0;
	int j;
	int y = 0;
	if (whichway == 'R') // it determines where i put my shape
		j = howmanysquare + this->board_width / 2;
	else
		j = this->board_width / 2 - howmanysquare;
	movedown(whichway,howmanysquare,teto,j);
	cout << "Final position" << endl;
	this->draw();
	writeToFile();
}

void TetrisArray1D::movedown(char whichway, int howmanysquare, Tetromino &teto, int columnposition)
{
	// shape will go down
	// i need a control function for preventing overlaps
	// i have to check below for overlaps
	int row = teto.getwhich().size() - 1; // the lower part of tetromino will go down first
	int flag = 0, control = 0;
	int temprow;
	int howmanyblocks = 0;
	for (row = teto.getwhich().size() - 1; row + 1< (board_size) / board_width && row >= 0;)
	{
		for (int tempcolumnposition = columnposition; tempcolumnposition < columnposition + teto.getwhich().at(0).size(); tempcolumnposition++)
		{
			// temprow = row+control;
			// cout << "icerdeyim" << endl;
			// if (board[((row + 1) * board_width) + tempcolumnposition] != '.')
				// break;
			if ((board[(row + 1) * board_width + tempcolumnposition] == '.'))
				swap(board[(row * board_width) + tempcolumnposition], board[((row + 1) * board_width) + tempcolumnposition]);
			else
				return;
		}
		--row, control++;
		if (control == teto.getwhich().size())
		{
			howmanyblocks++;
			cout << "control posiiton" << endl;
			row += teto.getwhich().size() + 1;
			cout << "board.size = " << this->board_size / this->board_width << " row = " << row << endl;
			// if (!controlspace(teto, row, columnposition)) // it will control the lower part
			// {
				setstring(whichway, howmanysquare, teto, howmanyblocks);
				// return;
				// break;
			// }
			control = 0;
			this->draw();
		}
	}
	setstring(whichway, howmanysquare, teto, howmanyblocks);
}

void TetrisArray1D::operator+=(Tetromino &teto)
{
	add(teto);
}

void TetrisArray1D::play(Tetromino objects[])
{
	tetro *forrand;
	forrand = new tetro[7];
	static int i = 0;
	forrand[0] = tetro::O; // tetro1;
	forrand[1] = tetro::L; // tetro2;
	forrand[2] = tetro::S; // tetro3;
	forrand[3] = tetro::J; // tetro4;
	forrand[4] = tetro::Z; // tetro5;
	forrand[5] = tetro::I; // tetro6;
	forrand[6] = tetro::T; // tetro7;
	cout << "Which shape you want to add (R for random , Q for quit) ?" << endl;
	char l;
	// int i = 0;
	srand(time(NULL));
	do
	{
		cin >> l;
		if (l != 'Z' && l != 'S' && l != 'T' && l != 'I' && l != 'O' &&
			l != 'L' && l != 'J' && l != 'R' && l != 'Q')
			cout << "Invalid input! Try again!!!" << endl;
	} while (l != 'Z' && l != 'S' && l != 'T' && l != 'I' && l != 'O' &&
			 l != 'L' && l != 'J' && l != 'R' && l != 'Q');
	if (l == 'Q')
	{
		cout << "Program is terminated!!!" << endl;
		exit(0);
	}
	else if (l == 'R')
	{

		int random = rand() % 7;
		objects[i] = (forrand[random]);
	}
	else if (l == 'O')
		objects[i] = (tetro::O);
	else if (l == 'I')
		objects[i] = (tetro::I);
	else if (l == 'T')
		objects[i] = (tetro::T);
	else if (l == 'J')
		objects[i] = (tetro::J);
	else if (l == 'L')
		objects[i] = (tetro::L); // I,O,T,J,L,S,Z
	else if (l == 'S')
		objects[i] = (tetro::S);
	else if (l == 'Z')
		objects[i] = (tetro::Z);
	// many++;
	animate(objects, i);
	i++;
}

void TetrisArray1D::animate(Tetromino objects[], int whichone)
{
	move(objects[whichone]); // this function does the job
	writeToFile();
}

bool TetrisArray1D::controlspace(Tetromino &teto, const int rowposition, const int columnposition) const // this function controls overlaps
{
	for (int i = 0; i < teto.getwhich()[0].size(); i++)
		if (!(teto.getwhich()[teto.getwhich().size() - 1][i] == '.' || board[((rowposition + teto.getwhich().size())*10) + columnposition + i] == '.'))
			return false;
	return true;
}

void TetrisArray1D::writeToFile()
{
	ofstream game("GameBoard.txt");
	for(int i = 0; i<board_size/board_width; i++)
	{
		for(int j = 0; j<board_width; j++)
			game<<board[i*board_width + j];
		game<<endl;
	}
	game.close();
}

void TetrisArray1D::readFromFile()
{
	ifstream game("GameBoard.txt");
	if(!game)
		throw "No txt";
	string linee;
	if(board != nullptr)
	{
		delete[] board;
		board = nullptr;
	}
	int newwsize = 0;
	int newwidth = 0;
	int newheigth = 0;
	while(getline(game,linee))
	{
		newheigth++;
		newwidth = linee.size();
	}
	newwsize = newwidth * newheigth;
	board = new char[newwsize];
	this->board_size = newwsize;
	this-> board_width = newwidth;
	game.clear();
	game.seekg(ios::beg);
	int i = 0;
	while(getline(game,linee))
	{
		for(int j = 0; j<board_width; j++)
			board[i*board_width + j] = linee[j];
		linee.clear();
		i++;
	}
	game.close();
	cout<<"Readed from file"<<endl;
	this->draw();
}
