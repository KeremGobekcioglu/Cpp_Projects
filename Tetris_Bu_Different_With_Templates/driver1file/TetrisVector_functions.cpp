#include "TetrisVector.h"
using namespace With_Vector;
// using namespace std;

ostream& operator<<(ostream& output, const vector<vector<char>> &obj);

TetrisVector::TetrisVector(int width, int height)
{
	if(height <= 0 || width <= 0)
		throw "What !!!";
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
				return ;
			}
		}
	}
	// char direction;
	// int count;
	// char whichway;
	// int howmanysquare;
	char direction = 'L';
	int count = 5;
	char whichway = 'L';
	int howmanysquare = 2;
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
		for(int j = 0; j<board.at(0).size(); j++)
		{	
			if(board.at(i).at(j) != '.')
			{	
				cout<<"Shape cant be added. Terminated."<<endl;
				return ;
			}
		}
	}
	// while (1)
	// {
	// 	if (whichway == 'R' && howmanysquare + board.at(0).size() / 2 + teto.getwhich().at(0).size() <= board.at(0).size())
	// 		break;
	// 	if (whichway == 'L' && board.at(0).size() / 2 - howmanysquare >= 0)
	// 		break;
	// 	cout << "Out of borders , enter again =";
	// 	cin >> howmanysquare;
	// 	cout << endl;
	// }
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
	// int flag = 0;
	int j;
	int y = 0;
	int innerflag = 0 , innerflag2 = 0;
	if (whichway == 'R') // it determines where i put my shape
		j = howmanysquare + board.at(0).size() / 2;
	else
		j = board.at(0).size() / 2 - howmanysquare;
	// movedown(teto,j);
	int row = teto.getwhich().size() - 1; // the lower part of tetromino will go down first
	int flag = 0 , control = 0;
	int temprow;
	// int columnposition = j;
	movedown(whichway,howmanysquare,teto,j);
	cout << "Final position" << endl;
	this->draw();
	writeToFile();
}
//moves the shape down
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

void TetrisVector::animate(Tetromino objects[], int whichone)
{
	move(objects[whichone]); // this function does the job
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
	if(board.size() != 0)
	{
		board.clear();
	}
	int newwsize = 0;
	int newwidth = 0;
	int newheigth = 0;
	while(getline(game,linee))
	{
		newheigth++;
		newwidth = linee.size();
	}
	// newwsize = newwidth * newheigth;
	// board = new char[newwsize];
	// this-> board_width = newwidth;
	vector<char> temp(newwidth,'.');
	vector<vector<char>> newwboard(newheigth,temp);
	board = newwboard;
	newwboard.clear();
	game.clear();
	game.seekg(ios::beg);
	i = 0;
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

// bool TetrisVector::controlspace(Tetromino &teto, const int rowposition, const int columnposition) const // this function controls overlaps
// {
	// for (int i = teto.getwhich().size() - 1, z = i, c = 0; i + 1 < board.size() && i >= 0; /*&& controlspace(teto,y,j)*/ c++) /*this part moves the shape to down */
	// {	
	// 	for (int s = j; s < j + teto.getwhich().at(0).size(); s++)
	// 	{
	// 		if (!(board.at(i + 1).at(s) != '.'))	
	// 			swap(board.at(i).at(s), board.at(i + 1).at(s));
	// 		// else
	// 			// innerflag2 = 1;
			
	// 	}
	// 	// if(innerflag2)
	// 		// break;
	// 	flag++, --i;
	// 	if (flag == teto.getwhich().size()) // if all the parts of shape moves down , i increment the 'i' so i can find last row of my shape
	// 	{
	// 		// if (!controlspace(teto, y, j)) // ic ice gecebiliyor mu gecemiyor mu
	// 	// if (c % teto.getwhich().size() == 0 )
	// 	// {
	// 		if(!controlspace(teto,i,j))
	// 			innerflag = 1;
	// 		// else
	// 			// y++;
	// 	// }
	// 		// 	innerflag = 1;
	// 	// 	cout<<"c = "<<c<<endl;
	// 	// 	if (!controlspace(teto, y, j)) // ic ice gecebiliyor mu gecemiyor mu
	// 	// 		innerflag = 1;
	// 	// 	else
	// 	// 		y++;
	// 	// 	cout<<"innerflag = "<<innerflag<<endl<<"  "<<endl;
	// 	// 	// cout<<"innerflag = "<<innerflag<<endl<<"  "<<endl;

	// 	// if(innerflag)
	// 	// 	break;
	// 		i += teto.getwhich().size() + 1;
	// 	if(innerflag)
	// 		i = board.size() + 5;
	// 		// y++;
	// 		// y = i;
	// 		flag = 0;
	// 		cout << "moved 1 " << endl;
	// 		this->draw();
	// 		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	// 	}
	// }