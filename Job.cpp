

#include "Job.h"

Job::Job(string desc, int processors, int ticks, int idNum)
{
	this->jobDesc = desc;
	this->jobProc = processors;
	this->jobticks = ticks;
	this->jobID = idNum;
}
Job::~Job()
{

}
//void Job::initJob(string& desc, int& processors, int& ticks, int& idNum)
//{
//
//	this->jobDesc = desc;
//	this->jobProc = processors;
//	this->jobticks = ticks;
//	this->jobID = idNum;
//}
int Job::getprocessor()const
{
	return this->jobProc;
}

int Job::getticks() const
{
	return this->jobticks;
}

int Job::getjobid() const
{
	return this->jobID;
}

string Job::getjobdes() const
{
	return this->jobDesc;
}

void Job::setticks(int newticks)
{
	this->jobticks = newticks;
	 
}