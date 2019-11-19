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
	cout << jobname << ticks << procs << endl;




	//from here pass data into another fucntion to check if insert needed or do it here 
	//new function 
	//handle else where
	if (jobname == "")
	{
		//if jobname is null do not insert job into wait prioity queue end function 
		Job nojob("", 0, 0, 0);
		return nojob; 
	}
	else
	{//assign new id and insert into wait queue 
		//job id is not null so create a class to return 
		//handle initalizing

		Job newjob(jobname, procs, ticks, jobid);
		return newjob;
//		this->insertjob(jobid, jobname, num_proc, num_ticks);  //insert into wait queue 
	}

	
}

void Scheduler::insertjob(Job toinsert)
{
	//check if job id is null
	//if()
	if (toinsert.getjobdes() == "")				//might want to handle somewhere else 
	{
		cout << "No job to be inserted." << endl;
	}
	else
	{
		this->waitqueue.push(toinsert);	//inserting job into wait queue  
		cout << "Job Id " << toinsert.getjobid() << " successfully submitted" << endl;
		//says when job is inserted into wait queue
	}
}


//
Job Scheduler::findshortest()
{
	//O(c) finds root 
	//waitqueue.top().getprocessor();

	return this->waitqueue.top(); //returns the data at the top of the queue 

	//might put delete and check availablity here as well 

}

void Scheduler::deleteshortest()
{
	//O(c) deletes root 
	this->waitqueue.pop(); //remove the minimun value in the heap 
}

bool Scheduler::checkavailable(int neededprocessors)
{	//O(c)
	bool success = false;
	if (this->freepool >= neededprocessors)				//if needed processors 
	{
		//if enough processors are available  
		success = true;
		this->freepool = this->freepool - neededprocessors;
	}
	else
	{
		success = false;		//not enough processors avaiable function ceasses 
		//find next shortest job and retry 
	}
	return success;
}

//adding 12:26

void Scheduler::DecrementTimer()
{
	//O(n)
	//loop through running queue and decrement the number of ticks for each job 
	vector<Job>::iterator check = this->runningqueue.begin();

	while (check != this->runningqueue.end())
	{
		//->setticks() = it->getticks() - 1;		//decrease amount of ticks by 1 for each item in the structure 
	/*	if (check->getticks() == 0)
		{
			this->runningqueue.erase(check); 
		}*/
		check->setticks(check->getticks() - 1);		//loops through vector and decreases ticks for every value by 1 
		
		check++;
	}

}

int Scheduler::getprocs() const
{
	return this->freepool;
}

void Scheduler::setfreepool(int np)
{
	this->freepool = np;
}

void Scheduler::checklast()
{
	vector<Job>::iterator it = this->runningqueue.begin();
	if (this->runningqueue.size() == 1)
	{
		if (it->getticks() == 0)
		{
			this->runningqueue.clear();
		}
	}
}

void Scheduler::printrun()
{
	vector<Job>::iterator it = this->runningqueue.begin();
	for(it;it != this->runningqueue.end(); it++)
	{
		cout << "Vector: Job description: " << it->getjobdes() << ", Proc: " << it->getprocessor() << ", ticks: " << it->getticks() << endl;
	}
}

void Scheduler::freeprocessors()
{	
	vector<Job>::iterator nextit; 
	vector<Job>::iterator it = this->runningqueue.begin();

	while (it != this->runningqueue.end())
	//for (vector<Job>::iterator i = this->runningqueue.begin(); i != this->runningqueue.end(); advance(i, 1))
	{
		//nextit = it++;
		if (it->getticks() == 0)
		{	

			this->freepool = this->freepool + (it->getprocessor());			//free the processors 
			cout << "Job completed: " << "Job description: " << it->getjobdes() << ", Proc: " << it->getprocessor() << ", ticks: " << it->getticks() << endl;
			it = this->runningqueue.erase(it);
		}
		else
		{
			it++;
		}

	/*	if (it->getticks() == 0)
		{
			this->freepool = this->freepool + (it->getprocessor());			//free the processors 
			cout << "Job completed: " << "Job description: " << it->getjobdes() << ", Proc: " << it->getprocessor() << ", ticks: " << it->getticks() << endl;
			it = this->runningqueue.erase(it);
		}
		else
		{
			++it;
		}
	*/
	}
	/*
	//O(n)
	for (vector<Job>::iterator i = this->runningqueue.begin(); i != this->runningqueue.end(); advance(i,1))
	{
		//nextit = i; 
		if (i->getticks() == 0)
		{
			//this->freeprocessors((it->getprocessor());
			this->freepool = this->freepool + (i->getprocessor());			//free the processors 
			cout << "Job completed: " << "Job description: " << i->getjobdes() << ", Proc: " << i->getprocessor() << ", ticks: " << i->getticks() << endl;
		
			if (i++ == this->runningqueue.end()  )
			{
				//nextit = i;
				//i = 
				//runningqueue.erase(i);
				//i = this->runningqueue.begin();
			//	i = this->runningqueue.pop_back(i);
				//this->runningqueue.erase(this->runningqueue.end());
				this->runningqueue.erase(i);
				break;
			}
			if (i == this->runningqueue.end())
			{
				this->runningqueue.clear();

			}
			else
			{
				i = runningqueue.erase(i); 
			}
			//nextit = runningqueue.erase(i);
		//	if(nextit != )
			//i = nextit;
			//}
			//return nextit;
		}
		*/
	}
	/*

	while (loop through running queue)
	{
		if (queuejob.getticks() == 0)
		{
			this->freepool = this->freepool + completed.getprocessor();
			cout << "Job completed: " << "Job description: " << completed.getjobdes() << ", Proc: " << completed.getprocessor() << ", ticks: " << completed.getticks() << endl;
			this->freeprocessors(currentjob); 
			//move to next location
		}
		else
		{
			//move to next location 
		}
	}
	*/


/*
void Scheduler::freeprocessors(int completed)
{
	//will search through running queue 
	//if(completed.getticks() == 0)
	//{
	//	this->freepool = this->freepool + completed.getprocessor(); 
	//	cout << "Job completed: " << "Job description: " << completed.getjobdes() << ", Proc: " << completed.getprocessor() << ", ticks: " << completed.getticks() << endl;

	//
	//}
	//serach through wait queue look for number of ticks being zero, remove 


	this->freepool = this->freepool + completed.getprocessor(); //restore processors 
	//cout << "Job completed: " << "Job description: " << completed.getjobdes() << ", Proc: " << completed.getprocessor() << ", ticks: " << completed.getticks() << endl;
}
*/

void Scheduler::Runjob(Job torun)
{		
	//runs job just poped off of prority queue 
	//O(c)
	//testing with vector implementation 
	//pass job into run queue 
	this->runningqueue.push_back(torun);

	//print job started
	cout << "Job Started: " << "Job description: " << torun.getjobdes() << ", Proc: " << torun.getprocessor() << ", ticks: " << torun.getticks() << endl; 


}

bool Scheduler::waitqueueempty()
{
	bool success = false;
	if (this->waitqueue.empty() == true)
	{
		success = true;
	}
	else
	{
		success = false;
	}
	return success; 
}
