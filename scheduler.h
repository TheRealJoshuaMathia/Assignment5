#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <cstddef>
#include <cstdlib>
#include <set>
#include <queue>

//Inlude Jobs
#include "job.hpp"

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


class Scheduler
{
public:
	Scheduler(int processors); //consturctor initalize with number of processors 
	~Scheduler();			   //destructor 
	//void readfilejob();
	void readline(ifstream & infile);				
	void tick();							//tick is a function itself probably call all other fucntions within tick 
	//void insertjobintowaitqueue();
	//wait queue 
	//findshortest 
	//checkava processor pool function 
	//delete shortest
	//runjob assign processors 



	//decrease timer after each tick 
	//also relases processors during this time 
	//

private:
	//priorty queue(wait queue ) 
	//processor pool data sturcture 
	//running queue //holds current number of jobs running 
	int num_processors;			//basic definied on consturction 

	//priority queue info 
	priority_queue<Jobs, vector<Jobs> , Compareclass> waitqueue;				//wait queue made of jobs need to have queue based on number of ticks 
	//need to find_shortest which just returns top of the queue 
	//delete shortest which deletes the top of the queue								//how do we arrage data in terms of ticks so queue is minium # of times - solved by using comparator class
	//				if queue is not empty 
	//					find_shortest job (top()) next check avaiablity 
	//			if(processors are aviavle ){delete shortest remove n procs from free pool }				//free pool is just a variable  
	//				{then assign processors with run job}
	//check if more processors are avaiable to run or find next shortest job

	int freepool; //holds current number of processors avaiable to use 
	//
	queue<job> runqueue; //for running queue 
	//how do we access the number of ticks and the number of processors for each job in the running queue 


};

//NEEDED CLASSES:
//job class to access ticks and n_processors 
//compareclass is to specify which values are compared in stl priority queue 

//needed to specify which values are compared in min heap 
class Compareclass
{

public:

	int operator(const Job& j1, const Job& j2)
	{
		return j1.getticks() > j2.getticks();
	}




};