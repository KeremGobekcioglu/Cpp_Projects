#ifndef PFARRAY_TEMPLATE_hpp
#define PFARRAY_TEMPLATE_hpp
#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <algorithm>
#include <cstddef>
using namespace std;

//-std=c++11

namespace PFArray
{
    template <typename T>
    class Pf_Array_Template
    {
    private:
        shared_ptr<T> data;
        int size;
        int capacity;

    public:
        class Iterator
        {
        private:
            T *ptr;

        public:
            using value_type = T;
            using pointer = T *;
            using reference = T &;
            using difference_type = ptrdiff_t;
            using iterator_category = random_access_iterator_tag;


            Iterator() : ptr(nullptr)
            {
            }

            Iterator(T *ot) : ptr(ot)
            {
            }

            Iterator(const Iterator &other) : ptr(other.ptr)
            {
            }

            bool operator==(const Iterator &other) const
            {
                return ptr == other.ptr;
            }

            bool operator!=(const Iterator &other) const
            {
                return ptr != other.ptr;
            }

            T *getter()
            {
                return ptr;
            }

            const T *getter() const
            {
                return ptr;
            }

            T &operator*()
            {
                return *(ptr);
            }

            const T &operator*() const
            {
                return *(ptr);
            }

            T *operator->()
            {
                return ptr;
            }

            const T *operator->() const
            {
                return ptr;
            }

            ptrdiff_t operator-(const Iterator &other)
            {
                return this->ptr - other.ptr;
            }

            friend Iterator operator-(const Iterator &l, int r)
            {
                return Iterator(l.ptr - r);
            }

            friend Iterator operator-=(Iterator &l, int r)
            {
                *l = *l - r;
                return *l;
            }

            friend Iterator operator+(const Iterator &l, int r)
            {
                return Iterator(l.ptr + r);
            }

            friend Iterator operator+(int l, const Iterator &r)
            {
                return Iterator(r.ptr + l);
            }

            friend Iterator &operator+=(Iterator &l, int r)
            {
                *l = *l + r;
                return *l;
            }

            friend Iterator &operator+=(int l, Iterator &r)
            {
                *r = *r + l;
                return *r;
            }

            Iterator &operator=(const Iterator &other)
            {
                this->ptr = other.ptr;
                return (*this);
            }

            Iterator &operator=(T *ptr)
            {
                this->ptr = ptr;
                return (*this);
            }

            Iterator &operator++()
            {
                ++ptr;
                return (*this);
            }

            Iterator operator++(int)
            {
                Iterator temp = (*this);
                ++ptr;
                return temp;
            }

            Iterator &operator--()
            {
                --ptr;
                return (*this);
            }

            Iterator &operator--(int)
            {
                Iterator *temp = new Iterator(*this);
                --ptr;
                return *(temp);
            }

            friend bool operator<(const Iterator &l, const Iterator &r)
            {
                return (*l) < (*r);
            }
            // it is for comparing the first and last iterators for erase function
            bool operator<(const Iterator &r)
            {
                return (this->ptr) < (r.ptr);
            }

            friend bool operator<=(const Iterator &l, const Iterator &r)
            {
                return (*l) <= (*r);
            }

            friend bool operator>(const Iterator &r, const Iterator &l)
            {
                return (*r) > (*l);
            }

            bool operator>(const Iterator &r)
            {
                return (this->ptr) > (r.ptr);
            }

            friend bool operator>=(const Iterator &r, const Iterator &l)
            {
                return (*r) >= (*l);
            };
        };
        Pf_Array_Template() : size(0), capacity(50)
        {
            cout << "Default constructor called" << endl;
            data = shared_ptr<T>(new T[capacity]);
        }
        // constructor
        Pf_Array_Template(int cap);
        // copy constructor
        Pf_Array_Template(const Pf_Array_Template &other);
        // copy assignment operator
        Pf_Array_Template &operator=(const Pf_Array_Template &other);
        // move constructor
        Pf_Array_Template(Pf_Array_Template &&other);
        // move assignment operator
        Pf_Array_Template &operator=(Pf_Array_Template &&other);
        // destructor
        ~Pf_Array_Template()
        {
            size = 0;
            capacity = 0;
        }
        shared_ptr<T> &getdata()
        {
            return data;
        }
        const int _size() const
        {
            return size;
        }
        T &operator[](int idx)
        {
            try
            {
                if (idx < 0 || idx > size)
                {
                    throw std::out_of_range("Out of indexes!!!");
                }
            }
            catch (const std::out_of_range &ex)
            {
                cerr << ex.what() << endl <<"Terminating the program !"<<endl;
                exit(0);
            }
            return *Iterator(data.get() + idx);
        }
        const T &operator[](int idx) const
        {
            try
            {
                if (idx < 0 || idx > size)
                {
                    throw std::out_of_range("Out of indexes!!!");
                }
            }
            catch (const std::out_of_range &ex)
            {
                cerr << ex.what() << endl <<"Terminating the program !"<<endl;
                exit(0);
            }
            return *Iterator(data.get() + idx);
        }
        Iterator begin() const
        {
            return Pf_Array_Template::Iterator(data.get());
            // return data.get();
        }
        Iterator end() const
        {
            // return (data.get() + size);
            return Pf_Array_Template::Iterator(data.get() + size);
        }
        const Iterator cbegin() const
        {
            // return data.get();
            return Pf_Array_Template::Iterator(data.get());
        }
        const Iterator cend() const
        {
            // return data.get()+size;
            return Pf_Array_Template::Iterator(data.get() + size);
        }

        bool operator!=(const T &var) const;

        void print() const;

        void push_back(const T &var);

        void clear();

        void erase(const Iterator &first, const Iterator &last);

        void erase(const Iterator &pos);

        const bool empty() const
        {
            if (size == 0)
                return true;
            return false;
        }
    };

}

#endif