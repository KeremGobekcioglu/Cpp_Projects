#include "tetris_h_H.H"

void Tetris::rotatewhichone(char turn, Tetromino &teto) const // my rotate function for Tetris class
{
	if (teto.whichshape.size() == 2 && teto.whichshape[0].size() == 2)
		return;
	if (teto.whichshape.size() == 1)
	{
		vec1d topush(1, 'I');
		vec2d neww(4, topush);
		teto.whichshape = neww;
		return; // neww;
	}
	else if (teto.whichshape.size() == 4)
	{
		vec1d Is(4, 'I');
		vec2d neww(1, Is);
		teto.whichshape = neww;
		return;
	}

	vec2d neww;
	int i = 0, j = 0;
	if (teto.whichshape.size() == 2)
	{
		vec1d topush(2, 'a'); // = {'a', 'a', 'a'};
		for (int i = 0; i < 3; i++)
			neww.push(topush);
	}
	else if (teto.whichshape.size() == 3)
	{
		vec1d topush(3, 'a'); // = {'a', 'a', 'a'};
		for (int i = 0; i < 2; i++)
			neww.push(topush);
	}
	int size1 = teto.whichshape.size();
	int sizeinside = teto.whichshape[0].size();
	for (i = 0; i < size1; i++)
		for (j = sizeinside - 1; j >= 0; j--)
			neww.doubleptr[j].ptr[i] = teto.whichshape.doubleptr[i].ptr[j];
	if (turn == 'L')
	{
		for (i = 0; i < neww.size() / 2; i++)
		{
			char temp = 'p';
			for (j = 0; j < neww[i].size(); j++)
			{
				temp = neww.doubleptr[i].ptr[j];
				neww.doubleptr[i].ptr[j] = neww.doubleptr[neww.size() - i - 1].ptr[j];
				neww.doubleptr[neww.size() - i - 1].ptr[j] = temp;
			}
		}
	}
	else if (turn == 'R')
	{
		for (i = 0; i < neww.size(); i++)
		{
			char temp = 'p';
			for (j = 0; j < neww[i].size() / 2; j++)
			{
				temp = neww.doubleptr[i].ptr[j];
				neww.doubleptr[i].ptr[j] = neww.doubleptr[i].ptr[neww[i].size() - j - 1];
				neww.doubleptr[i].ptr[neww[i].size() - j - 1] = temp;
			}
		}
	}
	teto.whichshape = neww;
}

Tetris::Tetris(int width, int height)
{
	vec1d iki(height, '.');
	vec2d temporary(width, iki);
	board = temporary;		  // equaling the vectors
	column_result_length = 0; // setting all my statics
	column_previousresult_length = 0;
	row_result_length = 0;
	row_previousresult_length = 0;
}

void Tetris::draw() const
{
	cout << "\e[1;1H\e[2J";
	std::this_thread::sleep_for(std::chrono::milliseconds(50)); // other drawings are being made in move function
	cout << board << endl;
	cout << "endline for notation" << endl;
}

void Tetris::addnicely(const Tetromino &teto, int wheretoput) // this function adds the shape to its optimal position
{
	for (int i = 0; i < teto.whichshape.size(); i++)
		for (int j = 0; j < board.at(0).size(); j++)
			board.at(i).at(j) = '.'; // deleting the first added tetro so they wont overleap

	for (int i = 0; i < teto.whichshape.size(); i++)
		for (int j = wheretoput, z = 0; z < teto.whichshape.at(0).size() && j < board.at(0).size(); j++, z++)
			board.at(i).at(j) = teto.whichshape.at(i).at(z);
}

void Tetris::deletefirstadded()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < board.at(0).size(); j++)
			board.at(i).at(j) = '.'; // deleting the first added tetro so they wont overleap
}

void Tetris::add(const Tetromino &teto) // only add s to the top , i will have another add function too
{
	// boardın t den küçük olup olmadığını kontrol etmiyorum
	for (int i = 0; i < teto.whichshape.size(); i++)
		for (int j = (board.at(0).size() / 2) - teto.whichshape.at(0).size() / 2, z = 0; j < board.at(0).size() / 2, z < teto.whichshape.at(0).size(); j++, z++)
			board.at(i).at(j) = teto.whichshape.at(i).at(z);
	// cout<<"\033[" +to_string(teto.whichshape.size())+"A";
}

void Tetris::move(Tetromino &teto)
{
	for(int i = 0; i<teto.whichshape.size(); i++)
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
		rotatewhichone(direction, teto);
	cout << "Which way ('L' or 'R') and how much space the shape has to move ?";
	cin >> whichway >> howmanysquare;
	(*this) += (teto); // adding the tetromino to the board
	cout << "Before moving" << endl;
	this->draw();
	deletefirstadded();
	while (1)
	{
		if (whichway == 'R' && howmanysquare + board.at(0).size() / 2 + teto.whichshape.at(0).size() <= board.at(0).size())
			break;
		if (whichway == 'L' && board.at(0).size() / 2 - howmanysquare >= 0)
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
		addnicely(teto, howmanysquare + board.at(0).size() / 2);
	else
		addnicely(teto, board.at(0).size() / 2 - howmanysquare);
	cout << "Optimal position at top " << endl;
	this->draw();
	int flag = 0;
	int j;
	int y = 0;
	if (whichway == 'R') // it determines where i put my shape
		j = howmanysquare + board.at(0).size() / 2;
	else
		j = board.at(0).size() / 2 - howmanysquare;
	for (int i = teto.whichshape.size() - 1, z = i, c = 0; i + 1 < board.size() && i >= 0; c++) /*this part moves the shape to down */
	{
		if (c % teto.whichshape.size() == 0)
		{
			if (!controlspace(teto, y, j)) // ic ice gecebiliyor mu gecemiyor mu
				break;
			else
				y++;
		}
		for (int s = j; s < j + teto.whichshape.at(0).size(); s++)
		{
			if (!(board.at(i + 1).at(s) != '.'))
				swap(board.at(i).at(s), board.at(i + 1).at(s));
		}
		flag++, --i;
		if (flag == teto.whichshape.size()) // if all the parts of shape moves down , i increment the 'i' so i can find last row of my shape
		{
			i += teto.whichshape.size() + 1;
			flag = 0;
			cout << "moved 1 " << endl;
			this->draw();
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
	cout << "Final position" << endl;
	this->draw();
}

void Tetris::operator+=(Tetromino &teto)
{
	add(teto);
}

void Tetris::play(Tetromino objects[])
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

void Tetris::animate(Tetromino objects[], int whichone)
{
	move(objects[whichone]); // this function does the job
}

bool Tetris::controlspace(Tetromino &teto, const int rowposition, const int columnposition) const // this function controls overlaps
{
	for (int i = 0; i < teto.whichshape[0].size(); i++)
		if (!(teto.whichshape[teto.whichshape.size() - 1][i] == '.' || board.doubleptr[rowposition + teto.whichshape.size()].ptr[columnposition + i] == '.'))
			return false;
	return true;
}
