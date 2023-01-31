#include "tetris_h_H.H"
int Tetromino::result_lengt;
int Tetromino::previousresult;
int Tetris::column_result_length;
int Tetris::column_previousresult_length;
int Tetris::row_result_length;
int Tetris::row_previousresult_length;

int main()
{
	 // fixing the shapes

	/* first i will test my Tetromino class's functions*/
	// i will do it like this way , im going to play the first homework , then second
//	vector<Tetromino> testobjects;
	Tetromino* testobjects;
	testobjects = new Tetromino[7];
	testobjects[0]=(tetro::O); // MY constructor understands from tetros which shape will be added to my private vectors
	testobjects[0].fix();
	testobjects[1]=(tetro::I); // also my setter calls in my constructor , and it sets the shapes and sets result length you can see it 
	testobjects[2]=(tetro::L);
	testobjects[3]=(tetro::Z);
	testobjects[4]=(tetro::S);
	testobjects[5]=(tetro::J);
	testobjects[6]=(tetro::T);
	for (int i = 0; i < 7; i++)
		testobjects[i].print(); // showing my print function
	cout << "test phase 1 completed" << endl;
	testobjects[3].whichshapeprint(); // prints whichshape
	// nicefit(4,vector<char>(40,' ')); thats why there are spaces and if your terminal is small you won't be able too see all the phases
	testobjects[4].nicefitprint(); // prints nicefit
	cout << "now we will try rotate function" << endl;
	for(int j = 0; j<7; j++)
	{
		int a = 0;
		while (a < 4)
		{
			cout<<"rotating left..."<<endl;
			testobjects[j].rotatewhichone('L',testobjects[j]); // it will rotate 4 times left
			testobjects[j].print();
			a++;
		}
		while (a < 8)
		{
			cout<<"rotating right..."<<endl;
			testobjects[j].rotatewhichone('R',testobjects[j]); // now for times right and all will be printed
			testobjects[j].print();
			a++;
		}
	}
	cout<<"hadi ya!"<<endl;
	Tetromino *testobjects2;
	testobjects2 = new Tetromino[7];
	testobjects2[0]=(tetro::O); // MY constructor understands from tetros which shape will be added to my private vectors
	testobjects2[1]=(tetro::I); // also my setter calls in my constructor , and it sets the shapes and sets result length you can see it 
	testobjects2[2]=(tetro::L);
	testobjects2[3]=(tetro::Z);
	testobjects2[4]=(tetro::S);
	testobjects2[5]=(tetro::J);
	testobjects2[6]=(tetro::T);
	for (int l = 1; l < 7; l++)
	{
		cout<<"icerdeyim"<<endl;
		int i = 0;
		while (i < 8)
		{
			if (i < 4 )
			{
				if(testobjects2[0].canfit(testobjects2[l],'L'))
				{
					cout<<"If I am in canfit returns true"<<endl;
					testobjects2[0].addtonicefit(testobjects2[l]);
					break;
				}
				else
					i++;
			}
			else
			{
				if(testobjects2[0].canfit(testobjects2[l],'R'))
				{
					cout<<"If I am in canfit returns true"<<endl;
					testobjects2[0].addtonicefit(testobjects2[l]);
					break;
				}
				else
				{
					i++;
					if (i == 8)
					{
					//	objects[0].canfit(objects[l],'R');
						cout<<"If I am in i == 8 section , canfit returns false"<<endl;
						testobjects2[0].addtonicefit(testobjects2[l]);
					}
				}
			}
		}
	}
	cout<<" My fit "<<endl; // your terminal must be big enough to see actual result , otherwise you will see spaces between letters in same tetro
	// i couldnt delete the spaces between two tetros but if you see spaces in one tetro like
	/*I
	  
	  I  it happens because of the small terminals 
	  
	  I
	  
	  I*/
	cout<<"it shows the final length, it is setted in first setter , result length = "<<testobjects[0].getlengt()<<endl;
	testobjects2[0].nicefitprint();
	// testobjects2[0].otherprint(testobjects2[0].getnicefit());s
	/* you can see from above addnicetofit works , i can print it also*/
	/*canfit works wrong but it works i couldn't fix it im going to write another one*/
	// I have functions i dont use , i couldn't delete them due to deadline , you can look if you want
	// If spacecontrol returns 1 , canfit returns true 
	/* I made some changes on functions for testing, i added cout s for seeing things better , seeing how they work*/
	delete[] testobjects;
	testobjects = nullptr;
 	cout<<"Test phase 2 completed"<<endl;
	cout<<"Now testing the tetris functions"<<endl;
	Tetris testobject(10,16); // making the board
	testobject.draw(); // draw is okey it is working
	getchar(); // it is for not deleting the old test results
	Tetromino willbeadd = tetro::I;
	testobject.add(willbeadd); // add works too
	testobject.draw();
	cout<<endl;
	getchar(); // it is for not deleting the old test results
	testobject.addnicely(willbeadd,7); // it adds where i want to, i send an integer
	testobject.draw();
	testobject.deletefirstadded();
	testobject.draw(); // it is deleted
	getchar(); // it is for not deleting the old test results
	// testobject.draw();
	// cout<<endl<<endl<<endl;
	// getchar(); // it is for not deleting the old test results
	// /* in play function i call animate function who calls fit function and fit function calls add functions */
	// /* PLAY function wants you to choose which one will be add*/
	// // you will see that int the other part driver2
	// /* i copied some functions from Tetromino to Tetris(rotatewhichone,otherprint) , i showed their work 
	// i'm not going to do it again it is above*/
	int i = 0;
	while(i<7)
	{	
		testobject.play(testobjects2); // random shapes , but 3 rotate , it is for showing
		cout<<endl;
		// it is for not deleting the old test results
		i++;
		/* i called only animate because it is test driver you won't play the game*/
	}
	// // you can test "play" function in driver2
	// cout<<"Test phases ended"<<endl;
	return 0;
}