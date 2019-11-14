
/*
Authors: Parker Guillen 
Date: 11/13/19
Class: Cpts 223 
Project: PA#5 scheduler 
Description:

*/


#include "scheduler.h"


int main(void)
{

	Scheduler testing(5);
	string filename;
	ifstream infile;
	cout << "Enter a file to open: " << endl;
	cin >> filename;
	infile.open(filename);


	testing.readline(infile); 


	return 0;

}