
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
	Scheduler testing(20);
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
	testing.setfreepool(nump);
	//testing 
	//1 tick 


	Job newJob("", 0, 0, 0);
	Job toprint("", 0, 0, 0);
	bool avaiproc = false;
	int ticks = 0; 
	
	for (int i = 0; i < 50; i++)
	{
		newJob = testing.readline(infile, jobid);
		//Job newJob2("", 0, 0, 0);
		++jobid;
		//newJob2 = testing.readline(infile, jobid);		

		testing.insertjob(newJob);
		//testing.insertjob(newJob2);

		if (newJob.getjobdes() == "")
		{
			//start new tick 
		}
		else
		{
			while ((testing.getprocs() != 0) && (testing.waitqueueempty() != true))			//want to add as many jobs as possible into running queue 
			{	
				//if()
				//or if wait queue is empty 
			//	if (waitqueue.isempty() == true)
				//{

			//			}
				toprint = testing.findshortest();
				avaiproc = testing.checkavailable(toprint.getprocessor());
				if (avaiproc == false)
				{
					//if not enough processors 
					break;
					//start new tick 
					//move to next value in prority queue; 
					//break; //return back up to next tick 
				}
				else
				{

					testing.deleteshortest();			//remove the job from the wait queue 
					testing.Runjob(toprint);			//pass toprint (the job just popped from the stack ) into running queue with run job


				}
				//testing.freeprocessors();
			}
		}

		testing.DecrementTimer();
		testing.freeprocessors();
		cout << "Number of ticks: " << ticks << endl;
		ticks++;
	}
	//

	//vector<Job>::iterator run;//if doing this way i need to have a getvectorbegin in scheduler 
	





	//cout << "11:00 testing: \t" << toprint.getprocessor() << endl; 

	//11:07 findshortest / insertjob / readline/ all work 

	//inserting into priorty queue now works


	//10:49 works so far next handling of 
	//cout << "Testing" << newJob.getprocessor() << endl;
	//after each call update job id
	//testing.readline(infile);


	return 0;

}
