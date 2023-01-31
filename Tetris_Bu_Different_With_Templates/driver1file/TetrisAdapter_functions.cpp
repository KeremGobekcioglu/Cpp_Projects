#include "TetrisAdapter.h"
using namespace With_Template;

template<class T>
TetrisAdapter<T>::TetrisAdapter(int height, int width)
{
	if (height * width <= 0)
		throw "What!!!";
	board_size = height * width;
	board_width = width;
	for (int i = 0; i < board_size; i++)
		board.push_back('.');
}

template<class T>
void TetrisAdapter<T>::draw() const
{
	cout << "\e[1;1H\e[2J";
	std::this_thread::sleep_for(std::chrono::milliseconds(50)); // other drawings are being made in move function
	for(int i = 0; i<board_size/board_width; i++)
	{		
		for(int j = 0; j<board_width; j++)
				cout<<this->board.at(i*board_width + j);
		cout<<endl;
	}
	cout << "endline for notation" << endl;
}

template<class T>
void TetrisAdapter<T>::addnicely(const Tetromino &teto, int wheretoput) // this function adds the shape to its optimal position
{
	for (int i = 0; i < teto.getwhich().size(); i++)
		for (int j = wheretoput; j < wheretoput + teto.getwhich().at(0).size(); j++)
			board.at(i*board_width + j) = '.'; // deleting the first added tetro so they wont overleap
			//10 10 , ilk 3 satır silincek

	for (int i = 0; i < teto.getwhich().size(); i++)
		for (int j = wheretoput, z = 0; z < teto.getwhich().at(0).size() && j < this->board_width; j++, z++)
			board.at(i*board_width + j) = teto.getwhich().at(i).at(z);
}
template<class T>
void TetrisAdapter<T>::deletefirstadded()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < this->board_width; j++)
			board.at(i*board_width + j) = '.'; // deleting the first added tetro so they wont overleap
}
template<class T>
void TetrisAdapter<T>::add(const Tetromino &teto) // only add s to the top , i will have another add function too
{
	// boardın t den küçük olup olmadığını kontrol etmiyorum
	for (int i = 0; i < teto.getwhich().size(); i++)
		for (int j = (this->board_width / 2) - teto.getwhich().at(0).size() / 2, z = 0; j < this->board_width / 2, z < teto.getwhich().at(0).size(); j++, z++)
			board.at(i*board_width + j) = teto.getwhich().at(i).at(z);
	// cout<<"\033[" +to_string(teto.getwhich().size())+"A";
}
template<class T>
void TetrisAdapter<T>::move(Tetromino &teto)
{
	for(int i = 0; i<teto.getwhich().size(); i++)
	{	
		for(int j = 0; j<this->board_width; j++)
		{	
			if(board.at(i*board_width + j) != '.')
			{	
				cout<<"Shape cant be added. Terminated."<<endl;
				return;
			}
		}
	}
	// char direction;
	// int count;
	// char whichway;
	// int howmanysquare;
	char direction = 'R';
	int count = 3;
	char whichway = 'L';
	int howmanysquare = 1;
	// cout << "Which direction you want to shape to be turned ('L' or 'R') and how many time it has to turn ?";
	// cin >> direction;
	// cin >> count;
	// cout << endl;
	// cout << "Which way ('L' or 'R') and how much space the shape has to move ?";
	// cin >> whichway >> howmanysquare;
	(*this) += (teto); // adding the tetromino to the board
	cout << "Before moving" << endl;
	this->draw();
	deletefirstadded();
	for (int i = 0; i < count; i++)
		teto.rotatewhichone(direction, teto);
	for(int i = 0; i<teto.getwhich().size(); i++)
	{	
		for(int j = 0; j<this->board_width; j++)
		{	
			if(board.at(i*board_width + j) != '.')
			{	
				cout<<"Shape cant be added. Terminated."<<endl;
				return;
			}
		}
	}
	// while (1)
	// {
	// 	if (whichway == 'R' && howmanysquare + this->board_width / 2 + teto.getwhich().at(0).size() <= this->board_width)
	// 		break;
	// 	if (whichway == 'L' && this->board_width / 2 - howmanysquare >= 0)
	// 		break;
	// 	cout << "Out of borders , enter again =";
	// 	cin >> howmanysquare;
	// 	cout << endl;
	// }
	// (*this) += teto; // add(teto);
	char temp;
	int onlyone = 0;
	int getout = 0;
	if (whichway == 'R') // this section adds the tetromino the optimal posiiton
		addnicely(teto, howmanysquare + this->board_width / 2);
	else
		addnicely(teto, this->board_width / 2 - howmanysquare);
	cout << "Optimal position at top " << endl;
	this->draw();
	numberofmoves++;
	int flag = 0;
	int innerflag = 0;
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
template<class T>
//moves the shape down
void TetrisAdapter<T>::movedown(char whichway, int howmanysquare, Tetromino &teto, int columnposition)
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
			// }
			control = 0;
			this->draw();
		}
	}
	setstring(whichway, howmanysquare, teto, howmanyblocks);
}

template<class T>
void TetrisAdapter<T>::operator+=(Tetromino &teto)
{
	add(teto);
}
template<class T>
void TetrisAdapter<T>::play(Tetromino objects[])
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
	char l = 'R';
	// int i = 0;
	srand(time(NULL));
	// do
	// {
	// 	cin >> l;
	// 	if (l != 'Z' && l != 'S' && l != 'T' && l != 'I' && l != 'O' &&
	// 		l != 'L' && l != 'J' && l != 'R' && l != 'Q')
	// 		cout << "Invalid input! Try again!!!" << endl;
	// } while (l != 'Z' && l != 'S' && l != 'T' && l != 'I' && l != 'O' &&
	// 		 l != 'L' && l != 'J' && l != 'R' && l != 'Q');
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
template<class T>
void TetrisAdapter<T>::animate(Tetromino objects[], int whichone)
{
	move(objects[whichone]); // this function does the job
}

template<class T>

bool TetrisAdapter<T>::controlspace(Tetromino &teto, const int rowposition, const int columnposition) const // this function controls overlaps
{
	for (int i = 0; i < teto.getwhich()[0].size(); i++)
		if (!(teto.getwhich()[teto.getwhich().size() - 1][i] == '.' || board[((rowposition + teto.getwhich().size())*this->width()) + columnposition + i] == '.'))
			return false;
	return true;
}

template<class T>

void TetrisAdapter<T>::writeToFile()
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

template<class T>

void TetrisAdapter<T>::readFromFile()
{
	ifstream game("GameBoard.txt");
	if(!game)
		throw "No txt";
	string linee;
	int newwsize = 0;
	int newwidth = 0;
	int newheigth = 0;
	while(getline(game,linee))
	{
		newheigth++;
		newwidth = linee.size();
	}
	newwsize = newwidth * newheigth;
	this->board_size = newwsize;
	this-> board_width = newwidth;
	board.clear();
	game.clear();
	game.seekg(ios::beg);
	int i = 0;
	while(getline(game,linee))
	{
		for(int j = 0; j<board_width; j++)
			board.push_back(linee[j]);
		linee.clear();
		i++;
	}
	game.close();
	cout<<"Readed from file"<<endl;
	this->draw();
}
