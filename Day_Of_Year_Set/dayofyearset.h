#ifndef dayofyearset_h
#define dayfoyearset_h
// #include "dayofyear.h"
#include <iostream>
#include <vector>
#include <initializer_list>
#include <list>
#include <iterator>
using namespace std;
// using namespace Dayofyearnamespace;

namespace Dayofyearsetnamespace
{
	// template<class T>
	class DayOfYearSet
	{
	public:
		class Day_Of_Year
		{
		private:
			int day;
			int month;
			// int year;
			vector<string> months = {
				"January", "February", "March", "April", "May", "June",
				"July", "August", "September", "October", "November", "December"};
			const bool day_check(int day) const;
			const bool month_check(const string &month) const;

		public:
			// Day_Of_Year() : day(1), month(1)
			// {
			// }
			//
			Day_Of_Year() : day(1) , month(1)
			{

			} 
			Day_Of_Year(int day, const string &month) //,int year)
			{
				// setyear(year);
				setmonth(month);
				setday(day);
			}
			Day_Of_Year(const Day_Of_Year &obj);
			const int getday() const;
			const int getmonth() const;
			friend ostream &operator<<(ostream &out, const Day_Of_Year &obj);
			const vector<string> &getvector() const;
			const string &getstringmonth() const;
			void setday(int day);
			void setmonth(const string &month);
			void setmonth(int month);
			void print() const;
			void printwithstring() const;
			void printmonths() const;
			Day_Of_Year &operator=(const Day_Of_Year &obj);
			void input();
			const bool input_check(const string &input) const;
			const int make_number(const string &input) const;
			~Day_Of_Year();
		};
		DayOfYearSet() : sizeofptr(0)
		{
			cout << "No allocation for ptr!" << endl;
		}
		DayOfYearSet(int specialcase);

		DayOfYearSet(const initializer_list<Day_Of_Year> &obj) : sizeofptr(obj.size())
		{
			ptr = new Day_Of_Year[sizeofptr]; 
			int i = 0;
			for (auto &it : obj) // i used it with auto
				this->ptr[i++] = const_cast<Day_Of_Year&>(it);
		}
		
		Day_Of_Year &operator[](int idx)
		{
			return this->ptr[idx];
		}
		
		const Day_Of_Year &operator[](int idx) const
		{
			return this->ptr[idx];
		}
		
		~DayOfYearSet()
		{
			if (sizeofptr == 0)
				return;
			delete[] ptr;
			sizeofptr = 0;
			ptr = nullptr;
		}
	
		DayOfYearSet &operator=(DayOfYearSet &obj);
		friend ostream &operator<<(ostream &out, const DayOfYearSet &obj);
		void sort();
		const int size() const;
		Day_Of_Year *getptr();
		void remove(const Day_Of_Year &obj);
		const bool operator==(const Day_Of_Year &obj) const;
		const bool operator!=(const Day_Of_Year &obj) const;
		const bool operator==(const DayOfYearSet &obj) const;
		const bool operator!=(const DayOfYearSet &obj) const;
		void operator+(const Day_Of_Year &obj);
		DayOfYearSet &operator+(const DayOfYearSet &obj);
		void operator-(const Day_Of_Year &obj);
		DayOfYearSet &operator-(const DayOfYearSet &obj);
		DayOfYearSet &operator!();
		DayOfYearSet &operator^(const DayOfYearSet &obj);
		void program(DayOfYearSet& obj);
	private:
		Day_Of_Year *ptr;
		int sizeofptr;
	};
}

#endif