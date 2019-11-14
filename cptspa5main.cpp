
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
	int jobid = 1; 
	Scheduler testing(5);
	string filename;
	ifstream infile;
	//cout << "Enter a file to open: " << endl;
	//cin >> filename;
	//infile.open(filename);
	infile.open("test13.txt");

	int nump = 0; 
	cout << "Enter number of processors: " << endl;
	cin >> nump;
	testing.setprocessors(nump);				//defining the number of processorzs

	//testing 
	Job newJob("", 0, 0, 0);
	newJob = testing.readline(infile, jobid);
	Job newJob2("", 0, 0, 0);
	++jobid;
	newJob2 = testing.readline(infile, jobid);		

	testing.insertjob(newJob);
	testing.insertjob(newJob2);
	
	Job toprint("", 0, 0, 0);
	toprint = testing.findshortest();		 

	cout << "11:00 testing: \t" << toprint.getprocessor() << endl; 

	//11:07 findshortest / insertjob / readline/ all work 

	//inserting into priorty queue now works


	//10:49 works so far next handling of 
	//cout << "Testing" << newJob.getprocessor() << endl;
	//after each call update job id
	//testing.readline(infile);


	return 0;

}
