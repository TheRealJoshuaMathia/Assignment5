#pragma once


#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <cstddef>
#include <cstdlib>
#include <set>
#include <queue>


using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
using namespace std;

#include "job.h" 

class Scheduler
{
public:
	Scheduler(int processors); //consturctor initalize with number of processors 
	~Scheduler();			   //destructor 
	//void readfilejob();
	
	int getProcs() const;

	Job readline(ifstream & infile, int jobid);		//returns job to be inserted
	void insertJob(Job toinsert);
	//void tick();							//tick is a function itself probably call all other fucntions within tick 
	//void insertjobintowaitqueue();
	Job findShortest();						//returns the shortest job 
	void setProcessors(int numProc); 
	void setFreepool(int np);
	void deleteShortest();
	bool checkAvailable(int neededprocessors);
	bool waitqueueEmpty(); 
	//void findfinished();

	void freeProcessors();

	void DecrementTimer(); //decrement time for each running job //go through running job queue and decrement each time value 
//	void freeprocessors(int completed);	//
	void Runjob(Job torun);
	//decrease timer after each tick 
	//also relases processors during this time 
	//

private:
	//running queue //holds current number of jobs running 
	int num_processors;			//basic definied on consturction 
	//Data structures 
	
	priority_queue<Job, vector<Job> , Compareclass> waitqueue;				//wait queue made of jobs need to have queue based on number of ticks is min heap  

	//Running queue could use vector, set or map 
	vector<Job> runningqueue; 

	int freepool; //holds current number of processors avaiable to use 	
};