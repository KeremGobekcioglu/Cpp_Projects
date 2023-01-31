#include "TetrisVector.h"
using namespace With_Vector;
// using namespace std;

// ostream& operator<<(ostream &outputt,const vector<vector<char>> &objj)
// {
// 	for(int i = 0; i<objj.size(); i++)
// 	{
// 		for(int j = 0; j<objj[0].size(); j++)
// 			outputt<<objj[i][j];
// 		outputt<<endl;
// 	}
// 	return outputt;
// }
ostream& operator<<(ostream& output, const vector<vector<char>> &obj);

// void TetrisVector::rotatewhichone(char turn, Tetromino &teto) const // my rotate function for TetrisVector class
// {
// 	if (teto.getwhich().size() == 2 && teto.getwhich()[0].size() == 2)
// 		return;
// 	if (teto.getwhich().size() == 1)
// 	{
// 		vector<char> topush_back(1, 'I');
// 		vector<vector<char>> neww(4, topush_back);
// 		teto.getwhich() = neww;
// 		return; // neww;
// 	}
// 	else if (teto.getwhich().size() == 4)
// 	{
// 		vector<char> Is(4, 'I');
// 		vector<vector<char>> neww(1, Is);
// 		teto.getwhich() = neww;
// 		return;
// 	}
// 	vector<vector<char>> neww;
// 	int i = 0, j = 0;
// 	if (teto.getwhich().size() == 2)
// 	{
// 		vector<char> topush_back(2, 'a'); // = {'a', 'a', 'a'};
// 		for (int i = 0; i < 3; i++)
// 			neww.push_back(topush_back);
// 	}
// 	else if (teto.getwhich().size() == 3)
// 	{
// 		vector<char> topush_back(3, 'a'); // = {'a', 'a', 'a'};
// 		for (int i = 0; i < 2; i++)
// 			neww.push_back(topush_back);
// 	}
// 	int size1 = teto.getwhich().size();
// 	int sizeinside = teto.getwhich()[0].size();
// 	for (i = 0; i < size1; i++)
// 		for (j = sizeinside - 1; j >= 0; j--)
// 			neww[j][i] = teto.getwhich()[i][j];
// 	if (turn == 'L')
// 	{
// 		for (i = 0; i < neww.size() / 2; i++)
// 		{
// 			char temp = 'p';
// 			for (j = 0; j < neww[i].size(); j++)
// 			{
// 				temp = neww[i][j];
// 				neww[i][j] = neww[neww.size() - i - 1][j];
// 				neww[neww.size() - i - 1][j] = temp;
// 			}
// 		}
// 	}
// 	else if (turn == 'R')
// 	{
// 		for (i = 0; i < neww.size(); i++)
// 		{
// 			char temp = 'p';
// 			for (j = 0; j < neww[i].size() / 2; j++)
// 			{
// 				temp = neww[i][j];
// 				neww[i][j] = neww[i][neww[i].size() - j - 1];
// 				neww[i][neww[i].size() - j - 1] = temp;
// 			}
// 		}
// 	}
// 	teto.getwhich() = neww;
// }

TetrisVector::TetrisVector(int width, int height)
{
	vector<char> iki(height, '.');
	vector<vector<char>> temporary(width, iki);
	board = temporary;		  // equaling the vectors
}

void TetrisVector::draw() const
{
	cout << "\e[1;1H\e[2J";
	std::this_thread::sleep_for(std::chrono::milliseconds(50)); // other drawings are being made in move function
	cout << board << endl;
	cout << "endline for notation" << endl;
}

void TetrisVector::addnicely(const Tetromino &teto, int wheretoput) // this function adds the shape to its optimal position
{
	for (int i = 0; i < teto.getwhich().size(); i++)
		for (int j = 0; j < board.at(0).size(); j++)
			board.at(i).at(j) = '.'; // deleting the first added tetro so they wont overleap

	for (int i = 0; i < teto.getwhich().size(); i++)
		for (int j = wheretoput, z = 0; z < teto.getwhich().at(0).size() && j < board.at(0).size(); j++, z++)
			board.at(i).at(j) = teto.getwhich().at(i).at(z);
}

void TetrisVector::deletefirstadded()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < board.at(0).size(); j++)
			board.at(i).at(j) = '.'; // deleting the first added tetro so they wont overleap
}

void TetrisVector::add(const Tetromino &teto) // only add s to the top , i will have another add function too
{
	// boardın t den küçük olup olmadığını kontrol etmiyorum
	for (int i = 0; i < teto.getwhich().size(); i++)
		for (int j = (board.at(0).size() / 2) - teto.getwhich().at(0).size() / 2, z = 0; j < board.at(0).size() / 2, z < teto.getwhich().at(0).size(); j++, z++)
			board.at(i).at(j) = teto.getwhich().at(i).at(z);
	// cout<<"\033[" +to_string(teto.getwhich().size())+"A";
}

void TetrisVector::move(Tetromino &teto)
{
	// readFromFile();
	// cout<<"readed from file "<<endl<<board<<endl;
	// exit(0);
	for(int i = 0; i<teto.getwhich().size(); i++)
	{	
		for(int j = 0; j<board.at(0).size(); j++)
		{	
			if(board.at(i).at(j) != '.')
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
	cout << "Before moving" << endl;
	this->draw();
	deletefirstadded();
	while (1)
	{
		if (whichway == 'R' && howmanysquare + board.at(0).size() / 2 + teto.getwhich().at(0).size() <= board.at(0).size())
			break;
		if (whichway == 'L' && board.at(0).size() / 2 - howmanysquare >= 0)
			break;
		cout << "Out of borders , enter again =";
		cin >> howmanysquare;
		cout << endl;
	}
	(*this) += teto; // add(teto);
	writeToFile();
	char temp;
	int onlyone = 0;
	int getout = 0;
	if (whichway == 'R') // this section adds the tetromino the optimal posiiton
		addnicely(teto, howmanysquare + board.at(0).size() / 2);
	else
		addnicely(teto, board.at(0).size() / 2 - howmanysquare);
	cout << "Optimal position at top " << endl;
	this->draw();
	numberofmoves++;
	int flag = 0;
	int j;
	int y = 0;
	if (whichway == 'R') // it determines where i put my shape
		j = howmanysquare + board.at(0).size() / 2;
	else
		j = board.at(0).size() / 2 - howmanysquare;
	movedown(whichway,howmanysquare,teto,j);
	cout<<"Final position"<<endl;
	this->draw();
	writeToFile();
}

void TetrisVector::movedown(char whichway, int howmanysquare , Tetromino &teto, int columnposition)
{
	// shape will go down
	// i need a control function for preventing overlaps
	// i have to check below for overlaps
	int row = teto.getwhich().size() - 1; // the lower part of tetromino will go down first
	int flag = 0 , control = 0;
	int temprow;
	int howmanyblocks = 0;
	// cout<<"board right now  = "<<endl;
	// cout<<board<<endl;
	for(row = teto.getwhich().size()-1; row+1<board.size() && row >= 0;)
	{
		for(int tempcolumnposition = columnposition; tempcolumnposition < columnposition + teto.getwhich()[0].size(); tempcolumnposition++)
		{	
			// temprow = row+control;
			// if(board.at(row+1).at(tempcolumnposition) != '.')
				// break;
			if(!(board.at(row + 1).at(tempcolumnposition) != '.'))
				swap(board.at(row).at(tempcolumnposition), board.at(row+1).at(tempcolumnposition));
			else
				return;
		}
		row-- , control++;
		if(control == teto.getwhich().size())
		{
			howmanyblocks++;
			row+=teto.getwhich().size()+1;
			cout<<"board.size = "<<board.size() << " row = "<<row<<endl;
			if(!controlspace(teto,row,columnposition)) // it will control the lower part
			{	
				setstring(whichway,howmanysquare,teto,howmanyblocks);
				return;
			}
			control = 0;
			this->draw();
		}
	}
	setstring(whichway,howmanysquare,teto,howmanyblocks);

}

void TetrisVector::operator+=(Tetromino &teto)
{
	add(teto);
}

void TetrisVector::play(Tetromino objects[])
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

void TetrisVector::animate(Tetromino objects[], int whichone)
{
	move(objects[whichone]); // this function does the job
	writeToFile();
}

bool TetrisVector::controlspace(Tetromino &teto, const int rowposition, const int columnposition) const
{
	if(rowposition + 1 >= board.size())
		return false;
	// if shape can add , it will return true
	for(int j = 0; j<teto.getwhich()[0].size(); j++)
		if((board[rowposition+1][columnposition + j] != '.' && teto.getwhich()[teto.getwhich().size()-1][j] != '.'))
			return false;
	return true;
}

void TetrisVector::writeToFile()
{
	ofstream game("GameBoard.txt");

	for(int i = 0; i<board.size(); i++)
	{	
		for(int j = 0; j<board.at(0).size(); j++)
			game << board.at(i).at(j);
		game << endl;
	}
	game.close();
}

void TetrisVector::readFromFile()
{
	ifstream game("GameBoard.txt");
	if(!game)
		throw "No txt";
	string linee;
	int i = 0;
	while(getline(game,linee))
	{
		for(int j = 0; j<board.at(0).size(); j++)
		{
			board.at(i).at(j) = linee[j];
		}
		linee.clear();
		i++;
	}
	game.close();
	cout<<"readed from file"<<endl;
	cout<<board<<endl;
}