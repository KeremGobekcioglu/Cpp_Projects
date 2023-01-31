#include "PfArray_Template.hpp"
using namespace PFArray;

template <typename T>
// this constructor initializes size and fills 0
Pf_Array_Template<T>::Pf_Array_Template(int cap)
{
	size = 0;
	capacity = cap;
	data = shared_ptr<T>(new T[capacity]);
	shared_ptr<T> ptr(new T[capacity]);
}

template <typename T>
// copy constructor
Pf_Array_Template<T>::Pf_Array_Template(const Pf_Array_Template &other)
{
	size = 0;
	capacity = other.capacity;
	data = shared_ptr<T>(new T[capacity]);
	for (int i = 0; i < other.size; i++)
		this->push_back(other[i]);
}

template <typename T>
// copy assignment operator
Pf_Array_Template<T> &Pf_Array_Template<T>::operator=(const Pf_Array_Template &other)
{
	if (this != &other)
	{
		Pf_Array_Template<T> temp;
		temp.capacity = other.capacity;
		for (int i = 0; i < other.size; i++)
			temp.push_back(other[i]);
		*this = move(temp);
	}
	return *this;
}

template <typename T>
// move constructor
Pf_Array_Template<T>::Pf_Array_Template(Pf_Array_Template &&other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.capacity = 0;
	other.size = 0;
	other.data = nullptr;
}

template <typename T>
// move assignment operator
Pf_Array_Template<T> &Pf_Array_Template<T>::operator=(Pf_Array_Template &&other)
{
	if (this != &other)
	{
		data = other.data;
		size = other.size;
		capacity = other.capacity;

		other.capacity = 0;
		other.data = nullptr;
		other.size = 0;
	}
	return *this;
}

template <typename T>
// used for_each for printing
void Pf_Array_Template<T>::print() const
{
	for_each(this->begin(), this->end(), [](const T &var)
			 { cout << var << " "; });
	cout << endl;
}

template <typename T>
// size will always increase
void Pf_Array_Template<T>::push_back(const T &var)
{
	if (size == capacity)
	{
		int oldsize = this->size;
		shared_ptr<T> newptr(new T[capacity *= 2]);
		int i = 0;
		for (; i < oldsize; i++)
			*(newptr.get() + i) = *(data.get() + i);
		data = nullptr;
		data = newptr;
		*(data.get() + i) = var;
	}
	*(data.get() + size) = var;
	++size;
}

template <typename T>
// it is faster , when size will be 0 , you won't be able to reach that indexes anymore
void Pf_Array_Template<T>::clear()
{
	size = 0;
}

template <typename T>
// I added this for finding which element will be erased
bool Pf_Array_Template<T>::operator!=(const T &var) const
{
	Iterator it = this->begin();
	for (; it != this->end(); it++)
	{
		if (*it == var)
			return false;
	}
	return true;
}

template <typename T>
// it will erase range of elements
void Pf_Array_Template<T>::erase(const Iterator &first, const Iterator &last)
{
	try
	{
		if (first.getter() > last.getter())
		{
			throw -1;
		}
		Pf_Array_Template<T> temp(this->capacity);
		Pf_Array_Template<T> temp2(this->capacity);
		Iterator it = first;
		for (; it != last; it++)
		{
			temp.push_back(*it);
		}
		for (int i = 0; i < this->size; i++)
		{
			if (temp != (*this)[i])
				temp2.push_back((*this)[i]);
		}
		*this = move(temp2);
	}
	catch (int a)
	{
		cout << "First iterator is greater than second iterator!!!" << endl
			 << "Try again!!!" << endl;
		exit(0);
	}
}

template <typename T>
// it will erase a particular element
void Pf_Array_Template<T>::erase(const Iterator &pos)
{
	try
	{
		if (pos.getter() < this->begin().getter())
			throw -1;
		else if (pos.getter() > this->end().getter())
			throw -2;
		Pf_Array_Template<T> temp(this->capacity);
		int flag = 0;
		for (int i = 0; i < this->size; i++)
		{
			if (!flag && *pos == (*this)[i])
				flag = 1;
			else
				temp.push_back((*this)[i]);
		}
		*this = move(temp);
	}
	catch (int a)
	{
		if (a == -1)
		{
			cout << "Iterator points an index before begin" << endl;
			exit(0);
		}
		cout << "Iterator points an index out of the bonds" << endl;
		exit(0);
	}
}