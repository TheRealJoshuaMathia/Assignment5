#pragma once


#include "iostream";
using namespace std;
class Job
{
public:
	Job(string desc, int processors, int ticks, int idNum);
	~Job();
	int getprocessor()const;
	int getticks() const; 

	//void initJob(string& desc, int& processors, int& ticks, int& idNum);
private:
	// Job ID number
	int jobID;
	//Job description field
	string jobDesc;
	// Number of processors
	int jobProc;
	int jobticks;
};



class Compareclass
{

public:			//pass this class into priority queue to allow for heap to be constructed based on number of ticks 

	int operator() (const Job& j1, const Job& j2)
	{
		return j1.getticks() > j2.getticks();
	}

};
