//Author: Adam Rhodes
//Course: CSCI-3080
//Lab Number: OLA 2
//Purpose: AND OR Truth Table Calculator
//This program will ask the user for either an input of A or and input of O
//Depending on given input the program will display the truth table for
//either And or Or.
//Due Date: September 18, 2020

#include <iostream>
#include <string>
using namespace std;

int main(){
    
    //Array's for P and Q truth values
	bool P[4] = { true, true, false, false };
	bool Q[4] = { true, false, true, false };

	//Prompt for input
	string user_input;
	cout << "Input an A if you want to calculate P AND Q\nInput an O if you want to calculate P OR Q " << endl;
	cin >> user_input;

	//Check for valid input
	while (user_input != "A" && user_input !=  "O") {
		cout << "Input must be either A or O. Try again." << endl;
		cin >> user_input;
	}
	
	//Calculates and prints AND truth table
	if (user_input == "A"){
	    cout << "P AND Q is:\n";
            for (int i=0; i < sizeof(P); i++)
	    {	
	        if  ((P[i] && Q[i]) == true )
		{
	            cout << "True" << endl;
		}
	        else 
		{
		    cout << "False" << endl;
		}
	    }
        }
    //Calculates and prints OR truth table
	else 
	{
	    cout << "P OR Q is:\n";
	    for (int i=0; i < sizeof(P); i++)
	    {
	        if ((P[i] || Q[i]) == true )
		{
		    cout << "True" << endl;
		}
		else
		{
		    cout << "False" << endl;
		}
	    }
	}


return 0;
}
