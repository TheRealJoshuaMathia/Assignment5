#include "scheduler.h"




Scheduler::Scheduler(int processors)
{
	this->num_processors = processors; //user enters number of processors 
}

Scheduler::~Scheduler()
{
	cout << "inside class constructor" << endl;
}


void Scheduler::setprocessors(int numProc)
{
	this->num_processors = numProc; 
}

Job Scheduler::readline(ifstream & infile, int jobid)
{	//correctly reads a line from the file and gathers name, num_ticks, and num_processors
	//int jobid = 1;

	string jobname; 
	string num_ticks;
	string num_proc; 
	getline(infile, jobname, '\t');
	getline(infile, num_proc, '\t');
	getline(infile, num_ticks, '\n');


	int ticks = 0; 
	int procs = 0; 
	ticks = stoi(num_ticks);
	procs = stoi(num_proc);
	//need to make sure this will work for many lines 
	cout << jobname << num_ticks << num_proc << endl;




	//from here pass data into another fucntion to check if insert needed or do it here 
	//new function 
	//handle else where
	if (jobname == "")
	{
		//if jobname is null do not insert job into wait prioity queue end function 

	}
	else
	{//assign new id and insert into wait queue 
		//job id is not null so create a class to return 
		//handle initalizing

		Job newjob(jobname, procs, ticks,jobid);
		return newjob;
//		this->insertjob(jobid, jobname, num_proc, num_ticks);  //insert into wait queue 
	}

	
}

void Scheduler::insertjob(Job toinsert)
{
	//check if job id is null
	//if()
	this->waitqueue.push(toinsert); 


}


//
Job Scheduler::findshortest()
{
	return this->waitqueue.top(); //returns the data at the top of the queue 
}

void Scheduler::deleteshortest()
{
	this->waitqueue.pop(); //remove the minimun value in the heap or as of now the max value 
}

bool Scheduler::checkavailable(int neededprocessors)
{	
	bool success = false;
	if (this->freepool >= neededprocessors)				//if needed processors 
	{
		//if enough processors are available  
		success = true;
	}
	else
	{
		success = false; 
	}
}
