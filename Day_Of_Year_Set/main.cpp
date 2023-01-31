#include"dayofyearset.h"
#include<fstream>
using namespace Dayofyearsetnamespace;

int main()
{
	cout<<"Testing the Day_Of_Year constructor , and in that constructor i have setmonth()\n"<<
	"and setday() , int these functions i call day_check and month_check so they are all being tested"<<
	"rigth now."<<endl;
	
	fstream file;
	file.open("test.txt",ios::out);
	
	file << "Testing the Day_Of_Year constructor , and in that constructor i have setmonth()\n"<<
	"and setday() , int these functions i call day_check and month_check so they are all being tested"<<
	"rigth now."<<endl;

	DayOfYearSet::Day_Of_Year day(5,"January");
	decltype(day) day1(28,"February");
	decltype(day) day2(13,"March");
	decltype(day) day3(23,"May");
	decltype(day) day4(18,"June");
	decltype(day) day5(30,"August");
	
	cout<<"Testing the print function (inside the printwithstring function , i used getters\n"<<
	"so every Day_Of_Year function is tested. ): \n";
	
	file<<"Testing the print function (inside the printwithstring function , i used getters\n"<<
	"so every Day_Of_Year function is tested. ): \n";
	
	cout<<day3;
	file<<day3;
	
	decltype(day) day11(29,"February");
	decltype(day) day21(13,"March");
	decltype(day) day31(2,"April");
	decltype(day) day41(19,"July");
	decltype(day) day51(31,"December");
	decltype(day) day61(23,"May");
	DayOfYearSet set {day,day1,day2,day3,day4};//,day5}; // i used initializer list
	
	// testing the stream

	cout<<"Testing the stream for the sets :"<<endl;
	file<<"Testing the stream for the sets :"<<endl;
	
	cout<<set<<endl;
	file<<set<<endl;

	decltype(set) set1 {day11,day21,day31,day41,day51,day61};

	cout<<"Now Set1 : \n";
	file<<"Now Set1 : \n";
	cout<<set1<<endl;
	file<<set1<<endl;

	cout<<"set ' s size = "<<set.size()<<endl;
	file<<"set ' s size = "<<set.size()<<endl;

	cout<<"Testing the index operator : set[0] = "<<set[0]<<endl;
	file<<"Testing the index operator : set[0] = "<<set[0]<<endl;
	
	cout<<"Testing the == and != operators"<<endl;
	file<<"Testing the == and != operators"<<endl;

	if(set == set1)
	{
		cout<<"Set's are equal!"<<endl;
		file<<"Set's are equal!"<<endl;
	}
	else // obviously there are not equal
	{
		cout<<"Set's are not equal!"<<endl;
		file<<"Set's are not equal!"<<endl;
	}

	cout<<"Testing the remove function : "<<endl;
	file<<"Testing the remove function : "<<endl;
	
	cout<<"First state of set1 :"<<endl<<set1;
	file<<"First state of set1 :"<<endl<<set1;
	
	set1.remove(day11); // testing the remove function
	
	cout<<"After remove :"<<endl;
	file<<"After remove :"<<endl;
	cout<<set1<<endl;
	file<<set1<<endl;
	
	cout<<"testing the add operator which adds an object to our set : "<<endl;
	file<<"testing the add operator which adds an object to our set : "<<endl;
	set1 + day11; // testing the add operator which adds an object to our set
	
	cout<<"After addition :"<<endl;
	file<<"After addition :"<<endl;
	cout<<set1<<endl;
	file<<set1<<endl;

	cout<<"Testing the - operator which removes an Day_Of_Year object from a set : "<<endl;
	file<<"Testing the - operator which removes an Day_Of_Year object from a set : "<<endl;

	cout<<"First state of set :"<<endl<<set;
	file<<"First state of set :"<<endl<<set;
	
	set - day;
	
	cout<<"After remove :"<<endl<<set<<endl;
	file<<"After remove :"<<endl<<set<<endl;
	
	set + day;
	
	cout<<"Now testing the - operator which returns the difference set : "<<endl;
	file<<"Now testing the - operator which returns the difference set : "<<endl;

	cout<<"Our sets :\n Set = \n"<<set<<endl<<" Set1 = \n"<<set1<<endl;
	file<<"Our sets :\n Set = \n"<<set<<endl<<" Set1 = \n"<<set1<<endl;
	

	DayOfYearSet set2 = set - set1;

	cout<<"Testing also the overloaded assign operator and the difference set is :\n"<<set2<<endl;
	file<<"Testing also the overloaded assign operator and the difference set is :\n"<<set2<<endl;

	cout<<"Again testing the - operator which returns the difference set but now set1 - set: "<<endl;
	file<<"Again testing the - operator which returns the difference set but now set1 - set: "<<endl;

	cout<<"Our sets :\n Set1 = \n"<<set1<<endl<<" Set = \n"<<set<<endl;
	file<<"Our sets :\n Set1 = \n"<<set1<<endl<<" Set1 = \n"<<set<<endl;

	set2 = set1 - set;

	cout<<"Testing also the overloaded assign operator and the difference set is :\n"<<set2<<endl;
	file<<"Testing also the overloaded assign operator and the difference set is :\n"<<set2<<endl;

	cout<<"Now testing the ^ operator which returns the intersection set : "<<endl;
	file<<"Now testing the ^ operator which returns the intersection set : "<<endl;
	
	cout<<"Our sets :\n Set = \n"<<set<<endl<<" Set1 = \n"<<set1<<endl;
	file<<"Our sets :\n Set = \n"<<set<<endl<<" Set1 = \n"<<set1<<endl;

	DayOfYearSet set3 = set^set1;

	cout<<"The intersection set is :\n"<<set3<<endl;
	file<<"The intersection set is :\n"<<set3<<endl;

	cout<<"Our sets :\n Set = \n"<<set<<endl<<" Set1 = \n"<<set1<<endl;
	file<<"Our sets :\n Set = \n"<<set<<endl<<" Set1 = \n"<<set1<<endl;

	cout<<"Now testing the + operator which returns union of sets :\nThe union set is : \n"<<
	set+set1<<endl;
	
	cout<<"First set is :\n "<<set<<endl;
	file<<"First set is :\n "<<set<<endl;

	cout<<"The hardest part is testing the complement it will be very long : \n"<<
	"Complement of first set : \n "<<!set<<endl;
	file<<"The hardest part is testing the complement it will be very long : \n"<<
	"Complement of first set : \n "<<!set<<endl;

	cout<<"Testing the !(set+set1) == (!set^!set1) , if it works i will print It is worked \n";
	file<<"Testing the !(set+set1) == (!set^!set1) , if it works i will print It is worked \n";
	if(!(set+set1) == (!set^!set1))
	{	
		cout<<"It is worked"<<endl;
		file<<"It is worked"<<endl;
	}

	cout<<"Now testing the empty set kind of things ..."<<endl;
	file<<"Now testing the empty set kind of things ..."<<endl;

	cout<<"First state of set :"<<endl<<set;
	file<<"First state of set :"<<endl<<set;
	
	DayOfYearSet temp = {};
	
	cout<<"Empty set -> temp : "<<temp<<endl;
	file<<"Empty set -> temp : "<<temp<<endl;
	
	set2 = set-temp;

	file<<"Now the differennce set : "<<endl<<set2<<endl;
	cout<<"Now the differennce set : "<<endl<<set2<<endl;

	set2 = temp-set;
	
	file<<"The differennce set but temp - set: "<<endl<<set2<<endl;
	cout<<"The differennce set but temp - set: "<<endl<<set2<<endl;

	cout<<"First state of set :"<<endl<<set;
	file<<"First state of set :"<<endl<<set;
	
	cout<<"Empty set -> temp : "<<temp<<endl;
	file<<"Empty set -> temp : "<<temp<<endl;

	set2 = set^temp;
	
	cout<<"Now testing the ^ operator which returns the intersection set : "<<endl;
	file<<"Now testing the ^ operator which returns the intersection set : "<<endl;

	file<<"The intersection set : "<<endl<<set2<<endl;
	cout<<"The intersection set : "<<endl<<set2<<endl;

	cout<<"Our sets :\n Set = \n"<<set<<endl<<" Empty set = \n"<<temp<<endl;
	file<<"Our sets :\n Set = \n"<<set<<endl<<" Empty set = \n"<<temp<<endl;

	cout<<"Now testing the + operator which returns union of sets :\nThe union set is : \n"<<
	set+temp<<endl;
	file<<"Now testing the + operator which returns union of sets :\nThe union set is : \n"<<
	set+temp<<endl;

	cout<<"Empty set is :\n "<<temp<<endl;
	file<<"Empty set is :\n "<<temp<<endl;

	cout<<"The hardest part is testing the complement it will be very long : \n"<<
	"Complement of empty set : \n "<<!temp<<endl;
	file<<"The hardest part is testing the complement it will be very long : \n"<<
	"Complement of empty set : \n "<<!temp<<endl;
	
	cout<<"Now testing can we add a day which is already in the list..."<<endl;
	file<<"Now testing can we add a day which is already in the list..."<<endl;
	cout<<"Our set is :"<<endl<<set;
	file<<"Our set is :"<<endl<<set;	
	cout<<"Our day is :"<<endl<<day;
	file<<"Our day is :"<<endl<<day;

	cout<<"Now testing..."<<endl;
	set+day;
	cout<<"Is it happened ?"<<set<<endl;
	file<<"Is it happened ?"<<set<<endl;
	
	cout<<"Now testing can we remove a day which is not in the list..."<<endl;
	file<<"Now testing can we remove a day which is not in the list..."<<endl;
	cout<<"Our set is :"<<endl<<set;
	file<<"Our set is :"<<endl<<set;	
	cout<<"Our day is :"<<endl<<day11;
	file<<"Our day is :"<<endl<<day11;
	cout<<"Now testing..."<<endl;
	set-day11;
	cout<<"Our set is :"<<set<<endl;
	file<<"In terminal , you can see the error messages but in text , you can not because\n"<<
	"I did not open a file for every function."<<endl;

	cout<<"Now if you want to continue , if you want to try it yourself , the input part is coming. "<<endl;
	file<<"Now if you want to continue , if you want to try it yourself , the input part is coming. "<<endl;
	
	char quit; 
	DayOfYearSet neww;
	DayOfYearSet neww2;
	DayOfYearSet::Day_Of_Year input_day;
	do
	{
		cout<<"Adding elements for first set ..."<<endl;
		input_day.input();
		neww + input_day;
		cout<<"Your set is :"<<endl<<neww<<endl;
		cout<<"If you want to end , enter 'q' : (Otherwise enter anything) : ";
		cin>>quit;
	} while (quit != 'q');

	do
	{
		cout<<"Adding elements to second set ..."<<endl;
		input_day.input();
		neww2 + input_day;
		cout<<"Your set is :"<<endl<<neww2<<endl;
		cout<<"If you want to end , enter 'q' : (Otherwise enter anything) : ";
		cin>>quit;
	} while (quit != 'q');

	neww.program(neww2);
	file.close();
	
}
// 	// deneme.sort();
// 	// printt(deneme);
	// DayOfYearSet merhaba(deneme);
	// DayOfYearSet complement = !merhaba;
	// cout<<complement<<endl;
	// complement = complement + merhaba;
	// cout<<complement;