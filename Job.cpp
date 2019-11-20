#include "Job.h"

// Function: Job()
// Constructor. Creates an instance a Job.
// Initalizes the properties of a Job.
Job::Job(string desc, int processors, int ticks, int idNum)
{
    this->jobDesc = desc;
    this->jobProc = processors;
    this->jobTicks = ticks;
    this->jobID = idNum;
    this->constTicks = ticks;
    this->constProc = processors;
}

// Function: ~Job()
// Destructor. This destroys the Job object
Job::~Job()
{

}

// Function: getProcessor()
// This function returns processors from the job.
int Job::getProcessor()const
{
    return this->jobProc;
}

// Function: getTicks()
// This function returns the number of ticks from the job.
int Job::getTicks() const
{
    return this->jobTicks;
}


// Function: getProcessor()
// This function returns processors from the job.
int Job::getProcessorConst()const
{
    return this->constProc;
}

// Function: getTicks()
// This function returns the number of ticks from the job.
int Job::getTicksConst() const
{
    return this->constTicks;
}

// Function: getJobid()
// This function returns the job id.
int Job::getJobid() const
{
    return this->jobID;
}

// Function: getJobdes()
// This function returns the job description.
string Job::getJobdes() const
{
    return this->jobDesc;
}

// Function: setTicks()
// This function sets the ticks for the job.
void Job::setTicks(int newticks)
{
    this->jobTicks = newticks;
}
