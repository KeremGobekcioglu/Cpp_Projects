#include "UTIL_H.h"
vector<char> Os(2, 'O');
vector<vector<char>> Oshape(2, Os);

vector<char> Is(4, 'I');
vector<vector<char>> Ishape(1, Is);

vector<char> Ts(3, 'T');
vector<vector<char>> Tshape(2, Ts);

vector<char> Js(2, 'J');
vector<vector<char>> Jshape(3, Js);

vector<char> Ls(2, 'L');
vector<vector<char>> Lshape(3, Ls);

vector<char> Zs(3, 'Z');
vector<vector<char>> Zshape(2, Zs);

vector<char> Ss(3, 'S');
vector<vector<char>> Sshape(2, Ss);

ostream& operator<<(ostream& output, const vector<vector<char>> &obj)
{
	for(int i = 0; i<obj.size(); i++)
	{
		for(int j = 0; j<obj[0].size(); j++)
			output<<obj[i][j];
		output<<endl;
	}
	return output;
}

void Tetromino::nicefitprint() const
{
		cout<<nicefit<<endl;
}
void Tetromino::whichshapeprint() const	{
		cout<<whichshape<<endl;
}

void Tetromino::fix() const
{
	// vector<char> Os(2, 'O');
	// vector<vector<char>> Oshape(2, Os);

	// vector<char> Is(4, 'I');
	// vector<vector<char>> Ishape(1, Is);

	// vector<char> Ts(3, 'T');
	// vector<vector<char>> Tshape(2, Ts);
	Tshape[1][0] = '.';
	Tshape[1][2] = '.';

	// vector<char> Js(2, 'J');
	// vector<vector<char>> Jshape(3, Js);
	Jshape[0][0] = '.';
	Jshape[1][0] = '.';

	// vector<char> Ls(2, 'L'); //l'',l'',ll
	// vector<vector<char>> Lshape(3, Ls);
	Lshape[0][1] = '.';
	Lshape[1][1] = '.';

	// vector<char> Zs(3, 'Z');
	// vector<vector<char>> Zshape(2, Zs);
	Zshape[0][2] = '.';
	Zshape[1][0] = '.';

	// vector<char> Ss(3, 'S');
	// vector<vector<char>> Sshape(2, Ss);
	Sshape[0][0] = '.';
	Sshape[1][2] = '.';
}
void Tetromino::setter(vector<vector<char>> &shapenumber , const tetro &var)
{
	whichshape = shapenumber;
	settetro(var);
	static int uy = 0;
	vector<char> adam(40, ' ');
	vector<vector<char>> selam(4, adam);
	nicefit = selam;
	for (int i = 0; i < 4; i++) // adding the first shape to our final vector
		for (int j = 0; j < whichshape[0].size(); j++)
			if (i + 1 <= whichshape.size())
				nicefit[3 - i][j] = (whichshape[whichshape.size() - i - 1][j]);
	if (uy == 0) // setting the static
		set_result_length(whichshape[0].size());
	uy++;
}

const vector<vector<char>> Tetromino::getwhich() const
{
	return whichshape;
}

const vector<vector<char>> Tetromino::getnicefit() const
{
	return nicefit;
}

void Tetromino::rotatewhichone(char turn, Tetromino &teto) // my rotate function
{
	if (teto.whichshape.size() == 2 && teto.whichshape[0].size() == 2)
		return;
	if (teto.whichshape.size() == 1)
	{
		vector<char> topush_back(1, 'I');
		vector<vector<char>> neww(4, topush_back);
		teto.whichshape = neww;
		return;
	}
	else if (teto.whichshape.size() == 4)
	{
		vector<char> Is(4, 'I');
		vector<vector<char>> neww(1, Is);
		teto.whichshape = neww;
		return;
	}

	vector<vector<char>> neww;
	int i = 0, j = 0;
	if (teto.whichshape.size() == 2)
	{
		vector<char> topush_back(2, 'a'); // = {'a', 'a', 'a'};
		for (int i = 0; i < 3; i++)
			neww.push_back(topush_back);
	}
	else if (teto.whichshape.size() == 3)
	{
		vector<char> topush_back(3, 'a'); // = {'a', 'a', 'a'};
		for (int i = 0; i < 2; i++)
			neww.push_back(topush_back);
	}
	int size1 = teto.whichshape.size();
	int sizeinside = teto.whichshape[0].size();
	for (i = 0; i < size1; i++)
		for (j = sizeinside - 1; j >= 0; j--)
			neww[j][i] = teto.whichshape[i][j];
	if (turn == 'L')
	{
		for (i = 0; i < neww.size() / 2; i++)
		{
			char temp = 'p';
			for (j = 0; j < neww[i].size(); j++)
			{
				temp = neww[i][j];
				neww[i][j] = neww[neww.size() - i - 1][j];
				neww[neww.size() - i - 1][j] = temp;
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
				temp = neww[i][j];
				neww[i][j] = neww[i][neww[i].size() - j - 1];
				neww[i][neww[i].size() - j - 1] = temp;
			}
		}
	}
	teto.whichshape = neww;
}

Tetromino::Tetromino(tetro shape) // im sending my enumaretors to constructor and setting the vector
{
	if (shape == tetro::O)
		setter(Oshape , tetro::O); // objects=(tetro::O);

	else if (shape == tetro::I)
		setter(Ishape , tetro::I); // objects=(tetro::I);

	else if (shape == tetro::T)
		setter(Tshape, tetro::T); // objects=(tetro::T);

	else if (shape == tetro::J)
		setter(Jshape, tetro::J); // objects=(tetro::J);

	else if (shape == tetro::L)
		setter(Lshape , tetro::L); // objects=(tetro::L); // I,O,T,J,L,S,Z

	else if (shape == tetro::S)
		setter(Sshape, tetro::S); // objects=(tetro::S);

	else if (shape == tetro::Z)
		setter(Zshape , tetro::Z); // objects=(tetro::Z);
}

void Tetromino::print() const // regular printing function
{
	cout << whichshape << endl; // in vectorrr.h , i overloaded the operator
}

void Tetromino::otherprint(const vector<vector<char>> &ak) const
{
	cout << ak << endl; // in vectorrr.h , i overloaded the operator
}

void Tetromino::addtonicefit(Tetromino &teto)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = result_lengt, z = 0, k; j < 50, z < 20; j++, z++)
		{
			if (0 == teto.whichshape.size() - i - 1)
			{
				for (int z = 0; z < teto.whichshape[0].size(); z++)
					nicefit[4 - i - 1][j++] = (teto.whichshape[teto.whichshape.size() - i - 1][z]);
				i = 5; // hard exit
				break;
			}
			else if (teto.whichshape.size() >= i + 1 && z < teto.whichshape[i].size())
				nicefit[4 - i - 1][j] = (teto.whichshape[teto.whichshape.size() - i - 1][z]);
		}
	}
	previousresult = result_lengt;
	result_lengt += teto.whichshape.at(0).size();
}

int Tetromino::spacecontrol(Tetromino &teto) // this function controls space between shapes
{
	if (teto.whichshape.size() > 2)
	{
		char a = nicefit[nicefit.size() - 2].at(previousresult);
		char b = teto.whichshape[teto.whichshape.size() - 2][0];
		char c = nicefit[nicefit.size() - 1].at(previousresult);
		char d = teto.whichshape[teto.whichshape.size() - 1][0];
		char e = nicefit[nicefit.size() - 3].at(previousresult);
		char f = teto.whichshape[teto.whichshape.size() - 3][0];
		if (((a == ' ' && b != ' ') || (a != ' ' && b == ' ')) &&
			((c == ' ' && d != ' ') || (c != ' ' && d == ' ')) && ((e == ' ' && f != ' ') || (e != ' ' && f == ' ')))
			return 1;
	}
	if (teto.whichshape.size() > 1)
	{
		char a = nicefit[nicefit.size() - 2].at(previousresult);
		char b = teto.whichshape[teto.whichshape.size() - 2][0];
		char c = nicefit[nicefit.size() - 1].at(previousresult);
		char d = teto.whichshape[teto.whichshape.size() - 1][0];
		if (((a == ' ' && b != ' ') || (a != ' ' && b == ' ')) &&
			((c == ' ' && d != ' ') || (c != ' ' && d == ' ')))
			return 1;
	}
	else
	{
		char c = nicefit[nicefit.size() - 1].at(previousresult);
		char d = teto.whichshape[teto.whichshape.size() - 1][0];
		if (((c == ' ' && d != ' ') || (c != ' ' && d == ' ')))
			return 1;
	}
	return 0;
}

bool Tetromino::canfit(Tetromino &teto, char position /*left or right*/)
{
	static int i = 0;
	if (i == 0 && (teto.whichshape == Lshape || teto.whichshape == Jshape || teto.whichshape == Sshape))
		return true;
	if (i == 0 && teto.whichshape == Zshape)
	{
		rotatewhichone('R', teto);
		return true;
	}
	rotatewhichone(position, teto);
	i++;
	if (spacecontrol(teto))
		return true;
	return false;
}

void Tetromino::operator=(tetro shape)
{
	if (shape == tetro::O)
		setter(Oshape , tetro::O); // objects=(tetro::O);

	else if (shape == tetro::I)
		setter(Ishape , tetro::I); // objects=(tetro::I);

	else if (shape == tetro::T)
		setter(Tshape, tetro::T); // objects=(tetro::T);

	else if (shape == tetro::J)
		setter(Jshape, tetro::J); // objects=(tetro::J);

	else if (shape == tetro::L)
		setter(Lshape , tetro::L); // objects=(tetro::L); // I,O,T,J,L,S,Z

	else if (shape == tetro::S)
		setter(Sshape, tetro::S); // objects=(tetro::S);

	else if (shape == tetro::Z)
		setter(Zshape , tetro::Z); // objects=(tetro::Z);
}
/* I'm not testing the functions I don't use*/
/* I'M NOT USING ASCII ESCAPE CODES FOR THIS CODE BECAUSE YOU HAVE TOO SEE THE TEST RESULTS
IN DRIVER 2 I'M USING IT*/