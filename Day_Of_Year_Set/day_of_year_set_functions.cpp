#include "dayofyearset.h"
using namespace Dayofyearsetnamespace;

//copy constructor
DayOfYearSet::Day_Of_Year::Day_Of_Year(const Day_Of_Year &obj)
{
	*this = obj;
};

const int DayOfYearSet::Day_Of_Year::getday() const
{
	return day;
};

const int DayOfYearSet::Day_Of_Year::getmonth() const
{
	return month;
};

const string &DayOfYearSet::Day_Of_Year::getstringmonth() const
{
	return months[month - 1];
}

//checking if the day is appr
const bool DayOfYearSet::Day_Of_Year::day_check(int day) const
{
	if (day < 0 || day > 31)
	{
		cout << "Invalid day input!!!" << endl;
		return false;
	}
	else if (month == 2 && day > 29)
	{
		cout << "Invalid day input!!!" << endl;
		return false;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		cout << "Invalid day input!!!" << endl;
		return false;
	}
	return true;
}

void DayOfYearSet::Day_Of_Year::setday(int day)
{
	if (!day_check(day))
		exit(0);
	this->day = day;
};
//checking yhe month
const bool DayOfYearSet::Day_Of_Year::month_check(const string &month) const
{
	int flag = 0;
	for (string test : this->months)
	{ // a için april == April A 65 , a 97
		if (month == test || (month[0] + ('a' - 'A') == test[0]))
			flag = 1;
	}
	if (!flag)
	{
		cout << "Invalid month input!!!" << endl;
		return false;
	}
	return true;
}

void DayOfYearSet::Day_Of_Year::setmonth(const string &month)
{
	if (!month_check(month))
		exit(0);
	int i = 1;
	for (auto test : this->months)
	{
		if (month == test)
		{
			this->month = i;
			break;
		}
		i++;
	}
};

// returns the month vector
const vector<string> &DayOfYearSet::Day_Of_Year::getvector() const
{
	return months;
}

// it prints the months you can choose
void DayOfYearSet::Day_Of_Year::printmonths() const
{
	cout << "Months : " << endl;
	int i = 1;
	for (auto a : getvector())
	{
		cout << " " << i++ << " : " << a << endl;
	}
}

//for input check
const bool DayOfYearSet::Day_Of_Year::input_check(const string &input) const
{
	// if there is a single char excepts numbers it will return false;
	for (char i : input)
	{
		if ((i < '0' || i > '9') && (i != '\n'))
			return false;
	}
	return true;
}

// very very basic atoi for input check
const int DayOfYearSet::Day_Of_Year::make_number(const string &input) const
{
	if (input.size() == 1)
		return input[0] - '0';
	return ((input[0] - '0') * 10 + input[1] - '0');
}

// input part
void DayOfYearSet::Day_Of_Year::input()
{
	decltype(this->day) choice;
	cout << "Choose month = " << endl;
	printmonths();
	string check;
	while (getline(cin, check))
	{
		if (!input_check(check))
			cout << "Wrong input! Enter again = ";
		else
		{
			choice = make_number(check);
			if (choice <= 12 && choice >= 1)
				break;
		}
	}
	this->month = choice;
	cout << "Enter a day = ";
	while (getline(cin, check))
	{
		if (!input_check(check))
			cout << "Wrong input! Enter again = ";
		else
		{
			choice = make_number(check);
			if (day_check(choice))
				break;
		}
	}
	this->day = choice;
	// printwithstring();
}

// classic prints
void DayOfYearSet::Day_Of_Year::print() const
{
	cout << getday() << " " << getmonth() << " " << endl; //<<year<<endl;
}

void DayOfYearSet::Day_Of_Year::printwithstring() const
{
	cout << getday() << " " << getstringmonth() << " " << endl; //<<year<<endl;
}
//overloaded = operator
DayOfYearSet::Day_Of_Year &DayOfYearSet::Day_Of_Year::operator=(const Day_Of_Year &obj)
{
	// this->year = obj.year;
	this->month = obj.month;
	this->day = obj.day;
	return *this;
}
//destructor
DayOfYearSet::Day_Of_Year::~Day_Of_Year()
{
	months.clear();
	day = 0;
	month = 0;
	// year = 0;
}

/*it implements whole year*/
DayOfYearSet::DayOfYearSet(int specialcase) : sizeofptr(specialcase)
{
			if(specialcase != 366)
			{
				throw "ERROR !!!";
			}
			ptr = new Day_Of_Year[specialcase];
			decltype(this->sizeofptr) day = 1;
			for(int i = 0, l = 0; l<12,i<specialcase; i++) // i <365
			{	
				if(l == 1 && day <= 29)
				{	
					this->ptr[i].setmonth(this->ptr[i].getvector()[l]);
					this->ptr[i].setday(day++);
					if(day == 30)
						day = 1,l++;
				}
				else if ((l == 3 || l == 5 
				|| l == 8 || l == 10) && day <= 30)
				{
					this->ptr[i].setmonth(this->ptr[i].getvector()[l]);
					this->ptr[i].setday(day++);
					if(day == 31)
						day = 1,l++;
				}
				else if(day <= 31)
				{
					this->ptr[i].setmonth(this->ptr[i].getvector()[l]);
					this->ptr[i].setday(day++);
					if(day == 32)
						day = 1,l++;
				}
			}
}

//returns the pointer which is holding Day_Of_Year objects
DayOfYearSet::Day_Of_Year *DayOfYearSet::getptr()
{
	return ptr;
}

namespace Dayofyearsetnamespace
{
//overloaded stream insertion operator
	ostream &operator<<(ostream &out, const DayOfYearSet &obj)
	{
		for (int i = 0; i < obj.size(); i++)
		{
			out << obj.ptr[i].getday() << " " << obj.ptr[i].getstringmonth();
			out << endl;
		}
		return out;
	}

	ostream &operator<<(ostream &out, const DayOfYearSet::Day_Of_Year &obj)
	{
		out << obj.getday() << " " << obj.getstringmonth() << " " << endl; //<<year<<endl;
		return out;
	}
}

//return sizeofptr which is the size of pointer holding the Day_Of_Year objects
const int DayOfYearSet::size() const
{
	return sizeofptr;
}

//removes the specific element which is sent to function
void DayOfYearSet::remove(const Day_Of_Year &obj)
{
	// // will remove the element and sizeofptr-=1
	// // i will copy the elements
	if(*this != obj)
	{
		cout<<"This element is not in the set so it cannot be removed ..."<<endl;
		return;
	}
	decltype(this->ptr) newptr = new Day_Of_Year[sizeofptr - 1];
	int k = 0;
	int i = 0;
	for (i = 0, k = 0; i < sizeofptr; i++, k++)
	{
		if (ptr[i].getmonth() == obj.getmonth() && ptr[i].getday() == obj.getday())
			k--;
		else
			newptr[k] = ptr[i];
	}
	delete[] ptr;
	ptr = nullptr;
	ptr = newptr;
	this->sizeofptr -= 1;
}

// it searches the Dayofyear pointer and looks if there any same Day_Of_Year object
const bool DayOfYearSet::operator==(const Day_Of_Year &obj) const
{
	for (int i = 0; i < this->sizeofptr; i++)
	{
		if (ptr[i].getday() == obj.getday() && ptr[i].getmonth() == obj.getmonth())
			return true;
	}
	return false;
}

// does the opposite of == operator
const bool DayOfYearSet::operator!=(const Day_Of_Year &obj) const
{
	if (*this == obj)
		return false;
	return true;
}

// it compares two sets
const bool DayOfYearSet::operator==(const DayOfYearSet &obj) const
{
	// it searches the Dayofyear pointer and looks if there any same object
	if(this->sizeofptr != obj.size())
		return false;
	for (int i = 0; i < this->sizeofptr; i++)
	{
		if (*this != obj.ptr[i])
			return false;
	}
	return true;
}

// does the opposite of == operator
const bool DayOfYearSet::operator!=(const DayOfYearSet &obj) const
{
	// it searches the Dayofyear pointer and looks if there any same object
	if(*this == obj)
		return false;
	return true;
}

// overloaded = operator , performs deep copy
DayOfYearSet &DayOfYearSet::operator=(DayOfYearSet &obj)
{
	if(this == &obj)
		return *this;
	if (obj.size() == 0)
	{
		if(this->sizeofptr != 0)
		{
			delete[] ptr;
			ptr = nullptr;
			this->sizeofptr = 0;
		}
		return *this;
	}
	if(this->sizeofptr!= 0)
	{	
		delete[] ptr;
		ptr = nullptr;
	}
	this->sizeofptr = obj.size();
	this->ptr = new Day_Of_Year[obj.size()];
	for (int i = 0; i < obj.size(); i++)
	{
		// obj.ptr[i].printwithstring();
		this->ptr[i] = obj.ptr[i];
	}
	return *this;
}

// adds an element to the set
void DayOfYearSet::operator+(const Day_Of_Year &obj)
{
	// it will add the end
	if(*this == obj)
	{
		cout<<"Same element is in the set , the parameter cannot be add ..."<<endl;
		return;
	}
	if(this->sizeofptr != 0)
	{
		decltype(this->ptr) newptr = new Day_Of_Year[sizeofptr += 1];
		int i = 0;
		for (; i < this->size() - 1; i++)
			newptr[i] = ptr[i];
		newptr[i] = obj;
		delete[] ptr;
		ptr = nullptr;
		ptr = newptr;
	}
	else
	{	
		this->ptr = new Day_Of_Year[sizeofptr+=1];
		this->ptr[0] = obj;
	}
}

// removes an element from the set , parameter is the element of that set
void DayOfYearSet::operator-(const Day_Of_Year &obj)
{
	remove(obj);
}

// returns the difference of two set 
DayOfYearSet &DayOfYearSet::operator-(const DayOfYearSet &obj)
{
	if (obj.size() == 0)
	{
		cout << "The second set is empty set !" << endl;
		return *this;
	}
	else if (this->sizeofptr == 0)
	{
		cout << "First set is empty set so difference is an empty set !" << endl;
		return *this;
	}
	decltype(this->sizeofptr) differencecount = 0;
	vector<int> positions;
	/*ilk setin elemanlarını ikincide arayacağız aynısı yoksa ekleyeceği<*/
	//123 12345
	//12345 123
	for (int k = 0; k < this->size(); k++)
	{
		if (obj != this->ptr[k]) // looking through whole set and searches objects elements in it
		{
			differencecount++;
			positions.push_back(k);
		}
	}
	if ((differencecount == 0 && this->size() <= obj.size()))
	{
		decltype(this) temp = new DayOfYearSet;
		temp->sizeofptr = 0;
		cout << "The second set contains all elements of first set so difference is empty set ..." << endl;
		return *temp;
	}
	if ((differencecount == 0 && this->size() > obj.size()))
	{
		decltype(this) temp = new DayOfYearSet;
		temp->sizeofptr = 0;
		cout << "The second set contains all elements of first set so difference is empty set ..." << endl;
		return *temp;
	}
	decltype(this) willreturn = new DayOfYearSet;
	willreturn->sizeofptr = differencecount;
	willreturn->ptr = new Day_Of_Year[differencecount];
	for (int i = 0; i < willreturn->size(); i++)
	{
		// vectorde indisler var o indislerdeki elemanları bu sete atıcaz
		willreturn->ptr[i] = this->ptr[positions[i]];
	}
	positions.clear();
	return *willreturn;
}

// returns the intersection of two sets
DayOfYearSet& DayOfYearSet::operator^(const DayOfYearSet& obj)
{
	decltype(this) temp = new DayOfYearSet;
	if(this->sizeofptr == 0 || obj.size() == 0)
	{
		return *temp;
	}
	vector<int> positions; // holds the intersections 
	
	for(int i = 0; i<obj.size(); i++)
		if(*this == obj.ptr[i])
			positions.push_back(i);

	if(positions.size() == 0) // if vector is empty it means there is no intersection
		return *temp;
	temp->ptr = new Day_Of_Year[positions.size()];
	temp->sizeofptr = positions.size();
	for(int i = 0; i<temp->size(); i++)
	{
		temp->ptr[i] = obj.ptr[positions[i]];
	}
	return *temp;
}

//returns the complemet of a set , difference set of whole year and a set is complement of that set
DayOfYearSet& DayOfYearSet::operator!()
{
	decltype(this) complement = new DayOfYearSet;
	DayOfYearSet trying(366); // whole year
	*complement = trying; 
	return *complement-*this; // it returns the complement
}

// returns the union of two sets
DayOfYearSet& DayOfYearSet::operator+(const DayOfYearSet& obj)
{
	if(*this == obj) // if they are the same objects dont do anything
		return *this;
	decltype(this) union_set = new DayOfYearSet;
	*union_set = *this;
	for(int i = 0; i<obj.size(); i++)
	{
		if(*union_set != obj.ptr[i]) // controlling if there are any same object
			*union_set + obj.ptr[i];
	}
	return *union_set;
}

void DayOfYearSet::program(DayOfYearSet &obj)
{
	char choice;
	char end = '0';
	vector<string> operations = {" k- Intersection"," d- Difference"," u- Union",
	" c- Complement"," r- Removing an object"," a- Adding and object"," s- Size of ?"};
	cout<<"Choose the operation : ";
	DayOfYearSet foroperations;
	DayOfYearSet::Day_Of_Year day;
	do{
		
		do{
			for(auto a : operations)
				cout<<a<<endl;
			cout<<"Choose between k and s : ";
			cin>>choice;
		}
		while(choice != 'k' && choice != 'd' && choice != 'u' 
		&& choice != 'c' && choice != 'r' && choice != 'a' && choice != 's' );
		char whichset;
		switch(choice)
		{
			case 'k':
				cout<<"You have chosen Intersection."<<endl;
				
				cout<<"First set is :"<<endl<<*this<<endl;
				cout<<"Second set is :"<<endl<<obj<<endl;
				
				foroperations = *this^obj;
				cout<<"The intersection is :"<<endl<<foroperations;
				break;
			case 'd':
				cout<<"You have chosen Difference."<<endl;
				
				cout<<"First set is :"<<endl<<*this<<endl;
				cout<<"Second set is :"<<endl<<obj<<endl;
				
				foroperations = *this-obj;
				cout<<"The difference 1 is :"<<endl<<foroperations;
				
				cout<<"First set is :"<<endl<<obj<<endl;
				cout<<"Second set is :"<<endl<<*this<<endl;
				
				foroperations = obj-(*this);
				cout<<"The difference 2 is :"<<endl<<foroperations;
				break;
			case 'u':
				cout<<"You have chosen Union."<<endl;
				
				cout<<"First set is :"<<endl<<*this<<endl;
				cout<<"Second set is :"<<endl<<obj<<endl;

				foroperations = *this + obj;
				cout<<"The union is :"<<endl<<foroperations;
				break;
			case 'c':
				cout<<"You have chosen Complement."<<endl;
				cout<<"Warning : if you choose complement you object will be replaced by his complement"<<endl;
				char ending;
				cout<<"If you want to get out of it : enter 'q' !!! "<<endl;
				cin>>ending;
				if(ending == 'q')
					break;
				cout<<"First set is :"<<endl<<*this<<endl;
				cout<<"Second set is :"<<endl<<obj<<endl;
				
				cout<<"Complement of first set is :"<<endl<<!(*this)<<endl;
				cout<<"Complement of second set is :"<<endl<<!obj<<endl;
				break;
			case 'r':
				cout<<"You want to remove an DayOfYearSet::Day_Of_Year. "<<endl;
				cout<<"Choose your set : l or r (l is 1 , r is 2) : ";
				cout<<"Warning : if you do this operation your objects will be change!!"<<endl;
				cin>>whichset;
				if(whichset == 'l')
				{
					cout<<"First set is :"<<endl<<*this<<endl;
					day.input();
					cout<<"The day is : "<<day<<endl;
					*this - day;
					cout<<"After the remove , new set is : "<<*this<<endl;
				}
				else if (whichset == 'r')
				{		
					cout<<"Second set is :"<<endl<<obj<<endl;
					day.input();
					cout<<"The day is : "<<day<<endl;
					obj - day;
					cout<<"After the remove , new set is : "<<obj<<endl;
				}
				break;
			case 'a':
				cout<<"You want to add an DayOfYearSet::Day_Of_Year object. "<<endl;
				cout<<"Choose your set : l or r (l is 1 , r is 2) : ";
				cout<<"Warning : if you do this operation your objects will be change!!"<<endl;
				cin>>whichset;
				if(whichset == 'l')
				{
					cout<<"First set is :"<<endl<<*this<<endl;
					day.input();
					cout<<"The day is : "<<day<<endl;
					*this + day;
					cout<<"After the addition , new set is : "<<*this<<endl;
				}
				else if (whichset == 'r')
				{		
					cout<<"Second set is :"<<endl<<obj<<endl;
					day.input();
					cout<<"The day is : "<<day<<endl;
					obj + day;
					cout<<"After the addition , new set is : "<<obj<<endl;
				}
				break;
			case 's':
				cout<<"You wonder the size of objects. "<<endl;
				cout<<"First set's size is : "<<(*this).size()<<endl;
				cout<<"Second set is : "<<obj.size()<<endl;
				break;
		}
		whichset = 't';
		cout<<"If you want to terminate the program , type 'q' :";
		cin>>end;
	}
	while(end != 'q');
	cout<<"Program is terminated!!!"<<endl;
}