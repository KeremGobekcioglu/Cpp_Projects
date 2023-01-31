#ifndef vectorrr_h
#define vectorrr_h
#include <iostream>
using namespace std;



class vec1d
{
protected: // my derived class vec2d has to access this variables so they are protected , not private
	int sizecolumn;
	int capacitycolumn;

public:
	char *ptr;
	vec1d();
	vec1d(int var);
	virtual const int size() const // derived class from vec1d will have this function to so it is virtual
	{
		return sizecolumn;
	}
	vec1d(int var, char element)
	{
		if (var <= 0)
			exit(-1);
		capacitycolumn = var;
		sizecolumn = var;
		ptr = new char[var];
		for (int i = 0; i < var; i++)
			this->ptr[i] = element;
	}
	const int getcolumnsize() const
	{
		return sizecolumn;
	}
	const int getcolumncapacity() const
	{
		return capacitycolumn;
	}
	const bool operator==(const vec1d &obj) const;
	const bool operator!=(const vec1d &obj) const;
	vec1d(const vec1d &obj);
	void operator=(const vec1d &obj);
	void operator=(char element)
	{
		this->ptr[sizecolumn++] = element;
	}
	void setsizecolumn(int var)
	{
		sizecolumn = var;
	}
	void increasesizecolumn()
	{
		sizecolumn += 1;
	}
	char &operator[](int idx)
	{

		if (!check(idx))
			exit(-1);
		return this->ptr[idx];
	}
	const char &operator[](int idx) const 
	{

		if (!check(idx))
			exit(-1);
		return this->ptr[idx];
	}
	bool check(int idx) const
	{
		if (idx < 0 || idx >= capacitycolumn)
		{
			cout << "!!!Out of borders in vec1d!!!" << endl;
			return false;
		}
		return true;
	}
	char &at(int idx) const
	{
		if (!check(idx))
			exit(-1);
		return this->ptr[idx];
	}
	void pushback(char var);
	void Resize(int var1, char var2);
	void Resize(int var1);
	friend ostream &operator<<(ostream &anan, const vec1d &obj);
	void clear()
	{
		delete[] ptr;
		ptr = nullptr;
	}
	virtual ~vec1d()
	{
		delete[] ptr;
		ptr = nullptr;
	}
};



class vec2d : public vec1d
{
private:
	int sizerow;
	int capacityrow;

public:
	void setsize(int var)
	{
		sizerow = var;
	}
	void increasesizerow()
	{
		sizerow += 1;
	}
	vec1d *doubleptr;
	vec2d();
	vec2d(int var);
	vec2d(const vec2d &other);
	virtual const int size() const
	{
		return sizerow;
	}
	vec2d(int var, const vec1d &other);
	void operator=(vec1d &obj)
	{
		(*this)[sizerow] = obj;
	}

	const int getrowsize() const
	{
		return sizerow;
	}
	const int getrowcapacity() const
	{
		return capacityrow;
	}
	vec1d &operator[](int idx)
	{
		if (!checkvec2d(idx))
			exit(-1);
		return this->doubleptr[idx];
	}
	bool checkvec2d(int idx) const
	{
		if (idx < 0 || idx >= capacityrow)
		{
			cout << "!!!Out of borders in vec2d!!!" << endl;
			return false;
		}
		return true;
	}
	const bool operator==(const vec2d &obj) const
	{
		if(obj.size() != this->size() || obj.doubleptr[0].getcolumncapacity() != this->doubleptr[0].getcolumncapacity()
		|| obj.getrowcapacity() != this->getrowcapacity() || obj.doubleptr[0].getcolumnsize() != this->doubleptr[0].getcolumnsize())
			return false;
		for(int i = 0; i<obj.size(); i++)
		{
			for(int j = 0; j<obj.getcolumnsize(); j++)
			{
				if(this->doubleptr[i].ptr[j] != obj.doubleptr[i].ptr[j])
					return false;
			}
		}
		return true;
	}
	const bool operator!=(const vec2d &obj) const
	{
		if(obj == *this)
			return false;
		return true;
	}
	vec1d &at(int idx) const
	{
		if (!checkvec2d(idx))
			exit(-1);
		return this->doubleptr[idx];
	}
	void setrowcapacity(int var)
	{
		capacityrow = var;
	}
	int setcapacity(int var);
	void push(const vec1d &other);
	void Resize(int var1, const vec1d &other);
	void operator=(const vec2d &other)
	{
		delete[] doubleptr;
		this->sizerow = 0; // other.sizerow;
		this->capacityrow = other.capacityrow;
		doubleptr = new vec1d[other.capacityrow];
		for (int i = 0; i < other.capacityrow; i++)
			doubleptr[i].ptr = new char[other.doubleptr[i].getcolumncapacity()];
		for (int i = 0; i < other.size(); i++)
		{
			this->doubleptr[i].setsizecolumn(0);
			for (int j = 0; j < other.doubleptr[i].size(); j++)
				this->doubleptr[i].pushback(other.doubleptr[i].ptr[j]);
			this->push(other.doubleptr[i]);
		}
	}
	friend ostream &operator<<(ostream &anan, const vec2d &obj);
	~vec2d()
	{
		delete[] doubleptr;
		doubleptr = nullptr;
	}
};

#endif