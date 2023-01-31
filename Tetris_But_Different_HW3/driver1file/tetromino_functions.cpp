#include "UTIL_H.h"
vec1d Os(2, 'O');
vec2d Oshape(2, Os);

vec1d Is(4, 'I');
vec2d Ishape(1, Is);

vec1d Ts(3, 'T');
vec2d Tshape(2, Ts);

vec1d Js(2, 'J');
vec2d Jshape(3, Js);

vec1d Ls(2, 'L');
vec2d Lshape(3, Ls);

vec1d Zs(3, 'Z');
vec2d Zshape(2, Zs);

vec1d Ss(3, 'S');
vec2d Sshape(2, Ss);

void Tetromino::fix() const
{
	// vec1d Os(2, 'O');
	// vec2d Oshape(2, Os);

	// vec1d Is(4, 'I');
	// vec2d Ishape(1, Is);

	// vec1d Ts(3, 'T');
	// vec2d Tshape(2, Ts);
	Tshape[1][0] = '.';
	Tshape[1][2] = '.';

	// vec1d Js(2, 'J');
	// vec2d Jshape(3, Js);
	Jshape[0][0] = '.';
	Jshape[1][0] = '.';

	// vec1d Ls(2, 'L'); //l'',l'',ll
	// vec2d Lshape(3, Ls);
	Lshape[0][1] = '.';
	Lshape[1][1] = '.';

	// vec1d Zs(3, 'Z');
	// vec2d Zshape(2, Zs);
	Zshape[0][2] = '.';
	Zshape[1][0] = '.';

	// vec1d Ss(3, 'S');
	// vec2d Sshape(2, Ss);
	Sshape[0][0] = '.';
	Sshape[1][2] = '.';
}
void Tetromino::setter(vec2d &shapenumber)
{
	whichshape = shapenumber;
	static int uy = 0;
	vec1d adam(40, ' ');
	vec2d selam(4, adam);
	nicefit = selam;
	for (int i = 0; i < 4; i++) // adding the first shape to our final vector
		for (int j = 0; j < whichshape[0].size(); j++)
			if (i + 1 <= whichshape.size())
				nicefit.doubleptr[3 - i].ptr[j] = (whichshape.doubleptr[whichshape.size() - i - 1].ptr[j]);
	if (uy == 0) // setting the static
		set_result_length(whichshape[0].size());
	uy++;
}

const vec2d Tetromino::getwhich() const
{
	return whichshape;
}

const vec2d Tetromino::getnicefit() const
{
	return nicefit;
}

void Tetromino::rotatewhichone(char turn, Tetromino &teto) // my rotate function
{
	if (teto.whichshape.size() == 2 && teto.whichshape[0].size() == 2)
		return;
	if (teto.whichshape.size() == 1)
	{
		vec1d topush(1, 'I');
		vec2d neww(4, topush);
		teto.whichshape = neww;
		return;
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

Tetromino::Tetromino(tetro shape) // im sending my enumaretors to constructor and setting the vector
{
	if (shape == tetro::O)
		setter(Oshape); // objects=(tetro::O);

	else if (shape == tetro::I)
		setter(Ishape); // objects=(tetro::I);

	else if (shape == tetro::T)
		setter(Tshape); // objects=(tetro::T);

	else if (shape == tetro::J)
		setter(Jshape); // objects=(tetro::J);

	else if (shape == tetro::L)
		setter(Lshape); // objects=(tetro::L); // I,O,T,J,L,S,Z

	else if (shape == tetro::S)
		setter(Sshape); // objects=(tetro::S);

	else if (shape == tetro::Z)
		setter(Zshape); // objects=(tetro::Z);
}

void Tetromino::print() const // regular printing function
{
	cout << whichshape << endl; // in vectorrr.h , i overloaded the operator
}

void Tetromino::otherprint(const vec2d &ak) const
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
		setter(Oshape); // objects.push_back(tetro::O);

	else if (shape == tetro::I)
		setter(Ishape); // objects.push_back(tetro::I);

	else if (shape == tetro::T)
		setter(Tshape); // objects.push_back(tetro::T);

	else if (shape == tetro::J)
		setter(Jshape); // objects.push_back(tetro::J);

	else if (shape == tetro::L)
		setter(Lshape); // objects.push_back(tetro::L); // I,O,T,J,L,S,Z

	else if (shape == tetro::S)
		setter(Sshape); // objects.push_back(tetro::S);

	else if (shape == tetro::Z)
		setter(Zshape); // objects.push_back(tetro::Z);
}
/* I'm not testing the functions I don't use*/
/* I'M NOT USING ASCII ESCAPE CODES FOR THIS CODE BECAUSE YOU HAVE TOO SEE THE TEST RESULTS
IN DRIVER 2 I'M USING IT*/
