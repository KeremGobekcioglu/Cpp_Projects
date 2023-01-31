#include"vectorrr.h"

void vec1d::operator=(const vec1d &obj) // overloading = operator
{
	delete[] this->ptr;
	this->ptr = new char[obj.capacitycolumn];
	this->capacitycolumn = obj.capacitycolumn;
	this->sizecolumn = 0;
	for (int i = 0; i < obj.sizecolumn; i++)
		(*this).pushback(obj.ptr[i]);
}

vec1d::vec1d()
{
	capacitycolumn = 20, sizecolumn = 0;
	ptr = new char[capacitycolumn];
}

vec1d::vec1d(int var)
{
	if (var <= 0)
		exit(-1);
	capacitycolumn = var;
	sizecolumn = 0;
	ptr = new char[var];
}

vec1d::vec1d(const vec1d &obj)
{
	this->capacitycolumn = obj.capacitycolumn;
	this->sizecolumn = obj.sizecolumn;

	this->ptr = new char[obj.capacitycolumn];
	for (int i = 0; i < this->capacitycolumn; i++)
		this->pushback(obj.ptr[i]);
}

void vec1d::pushback(char var)
{
	if (sizecolumn == capacitycolumn)
	{
		char *newptr = new char[this->capacitycolumn *= 2];
		for (int i = 0; i < this->sizecolumn; i++)
			newptr[i] = this->ptr[i];
		delete[] this->ptr;
		this->ptr = newptr;
	}
	if (sizecolumn < capacitycolumn)
		ptr[sizecolumn++] = var;
}

void vec1d::Resize(int var1)
{
	if (sizecolumn == 0 && var1 > 0) // it means vector is empty
	{
		ptr = new char[var1];
		capacitycolumn = var1, sizecolumn = 0;
	}
	else if (sizecolumn != 0 && var1 > 0)
	{
		char *newptr = new char[var1];
		for (int i = 0; i < var1; i++)
			newptr[i] = ptr[i];
		delete[] ptr;
		ptr = newptr;
		sizecolumn = var1;
		capacitycolumn = var1;
	}
	else
	{
		cout << "size cannot be less than or equal to 0 !!!" << endl;
		exit(-1);
	}
}

void vec1d::Resize(int var1, char var2)
{
	if (sizecolumn == 0 && var1 > 0) // it means vector is empty
	{
		ptr = new char[var1];
		for (int i = 0; i < var1; i++)
			this->pushback(var2);
		capacitycolumn = var1, sizecolumn = var1;
	}
	else if (sizecolumn != 0 && var1 > 0)
	{
		char *newptr = new char[var1];
		for (int i = 0; i < var1; i++)
			newptr[i] = var2;
		delete[] ptr;
		ptr = newptr;
		sizecolumn = var1;
		capacitycolumn = var1;
	}
	else
	{
		cout << "size cannot be less than or equal to 0 !!!" << endl;
		exit(-1);
	}
}


ostream &operator<<(ostream &anan, const vec1d &obj)
{
	for (int j = 0; j < obj.getcolumnsize(); j++)
		anan << obj.ptr[j];
	return anan;
}

ostream &operator<<(ostream &anan, const vec2d &obj)
{
	for (int i = 0; i < obj.getrowsize(); i++)
	{
		anan << obj.doubleptr[i];
		if (i != obj.getrowsize() - 1)
			anan << endl;
	}
	return anan;
}

vec2d::vec2d(int var, const vec1d &other)
{
	doubleptr = new vec1d[var];
	capacityrow = var;
	sizerow = var;
	for (int i = 0; i < var; i++)
		doubleptr[i] = other;
}

vec2d::vec2d(const vec2d &other)
{
	*this = other;
}

void vec2d::Resize(int var1, const vec1d &other)
{
	if (sizerow == 0 && var1 > 0) // it means vector is empty
	{
		doubleptr = new vec1d[var1];
		for (int i = 0; i < var1; i++)
			this->push(other);
		capacitycolumn = var1, sizecolumn = var1;
	}
	else if (sizerow != 0 && var1 > 0)
	{
		vec1d *newptr = new vec1d[var1];
		for (int i = 0; i < var1; i++)
			newptr[i] = other;
		delete[] doubleptr;
		doubleptr = newptr;
		sizerow = var1;
		capacityrow = var1;
	}
	else
	{
		cout << "size cannot be less than or equal to 0 !!!" << endl;
		exit(-1);
	}
}

vec2d::vec2d()
{
	capacityrow = 20;
	capacitycolumn = 20;
	sizerow = 0;
	sizecolumn = 0;
	doubleptr = new vec1d[capacityrow];
}

vec2d::vec2d(int var)
{
	if (var <= 0)
		exit(-1);
	capacityrow = var;
	sizerow = 0;
	doubleptr = new vec1d[capacityrow];
	for (int i = 0; i < capacityrow; i++)
		doubleptr[i].ptr = new char[capacitycolumn];
}

void vec2d::push(const vec1d &other)
{
	if (sizerow == capacityrow)
	{
		vec1d *newptr = new vec1d[this->capacityrow *= 2];
		for (int i = 0; i < this->sizerow; i++)
			newptr[i] = this->doubleptr[i];
		this->~vec2d();
		this->doubleptr = newptr;
	}
	if (sizerow < capacityrow)
	{
		doubleptr[this->sizerow] = other;
		sizerow += 1;
	}
}