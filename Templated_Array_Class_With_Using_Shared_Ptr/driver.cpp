#include "PfArray_Template.hpp"
#include "Pf_Array_Template_Functions.cpp"
#include<cstdlib>
#include<ctime>

int main()
{
    srand(time(NULL));
    Pf_Array_Template<int> test; // capacity 50
    for(int i = 0; i<10; i++)
        test.push_back(rand()%25); //push_back work
    test.print(); // it uses for_each
    cout<<"test[5] = "<<test[5]<<endl; // index operator works too
    cout<<"Testing and using the sort and find functions..."<<endl;
    Pf_Array_Template<int>::Iterator it,it2;
    it = test.cbegin(); // begin and end is tested
    it2 = test.cend();
    sort(it,it2);
    test.print();
    // it = find(it,it2,7); // 
    test.push_back(7); // i pushed 7 then i will sort and find 7 in it
    it2 = test.end(); // end has changed
    sort(it,it2);
    test.print();
    cout<<"Testing the find"<<endl;
    it2 = find(it,it2,7);
    cout<<"7 is found at position "<<it2-it<<endl; 
    cout<<"Testing the *operator : "<<*it2<<endl;
    it2 = test.cend(); // it2 changed again
    // testing the range based loop
    cout<<"Testing the range based loop"<<endl;
    for(int i : test)
        cout<<i<<" ";
    cout<<endl<<"Size of test array = "<<test._size()<<endl;
    if(!test.empty())
        cout<<"Test is not empty"<<endl;
    cout<<"Now testing erase function..."<<endl;
    cout<<"Before erase()"<<endl;
    test.print();
    test.erase(it,it+3);
    cout<<"Size after erasee() = "<<test._size()<<endl;
    cout<<"First three elementns will be erased"<<endl;
    cout<<"After erase()"<<endl;
    test.print();
    cout<<"Before erasing test[5] = "<<test[5]<<endl;
    test.print();
    test.erase(test.cbegin()+5); // erasing test[5]
    cout<<"After erasing new test[5] = "<<test[5]<<" (i push random integers so maybe they are same you can look the positions)"<<endl;
    test.print();
    
    
    Pf_Array_Template<char> deneme(3); // capacity 3
    cout<<"Now i will push 5 elements to a char array of whose capacity is 3"<<endl;
    deneme.push_back('d');
    deneme.push_back('^');
    deneme.push_back('G');
    deneme.push_back('%');
    deneme.push_back('4');
    cout<<"Printing it"<<endl;
    deneme.print();
    sort(deneme.begin(),deneme.end());
    cout<<"It is sorted"<<endl;
    deneme.print();

    cout<<"Now i will test constructors and assignment operators"<<endl;
    Pf_Array_Template<int> empty(test);
    cout<<"Printing test"<<endl;
    test.print();
    cout<<"Printing empty"<<endl;
    empty.print();
    cout<<"Copy constructor is tested and you can see it works"<<endl;
    cout<<"Empty is same with test"<<endl;
    Pf_Array_Template<int> empty2 = empty;
    cout<<"Printing empty2"<<endl;
    empty2.print();
    cout<<"Copy assignment operator is tested and you can see it works"<<endl;
    cout<<"Now empty,empty2 and test arrays are same"<<endl;
    Pf_Array_Template<char>empty_char;
    cout<<"Now i will try move assignment operator"<<endl;
    cout<<"Deneme before using move assignment operator"<<endl;
    deneme.print();
    empty_char = move(deneme);
    cout<<"Empty_char after using move assignment operator"<<endl;
    empty_char.print();
    cout<<"Deneme after using move assignment operator"<<endl;
    deneme.print();
    cout<<"Trying the move constructor, now i m printing empty_char before stealing its data"<<endl;
    empty_char.print();
    Pf_Array_Template<char>empty_char2(move(empty_char));
    cout<<"After deleting its data empty_char : "<<endl;
    empty_char.print();
    cout<<"Now empty_char2 has all of its members, empty_char2 : "<<endl;
    empty_char2.print();

    cout<<"I have test exceptions but I can not try all of them because they end the program so you can read them"<<endl;
    cout<<"I will only show one of them"<<endl;
    empty_char2[-2];
    return 0;
}