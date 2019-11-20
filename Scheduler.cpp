#include "Scheduler.h"

// Function: Scheduler(int processors)
// Constructor
// Initalizes the Scheduler with the number of processors.
// The number of processors is user defined.
Scheduler::Scheduler(int processors)
{
    this->num_processors = processors;
}

// Function: Scheduler(int processors)
// Constructor
// Initalizes the Scheduler with the number of processors.
// The number of processors is user defined.
Scheduler::~Scheduler()
{
    cout << "inside class constructor" << endl;
}

// Function: setProcessors(int numProc)
// This function sets the number of processors
// The number of processors is user defined.
void Scheduler::setProcessors(int numProc)
{
    this->num_processors = numProc;
}

// Function: readline(ifstream & infile, int jobid)
// This function reads a line from the text file and parses the data and sets
// the parsed data into a job object
Job Scheduler::readline(ifstream & infile, int jobid)
{
    string jobname;

    string num_ticks;
    string num_proc;
    
    int ticks;
    int procs;
    
    string delim = "\n";
    infile >> jobname;
    infile >> num_proc;
    infile >> num_ticks;
    
    try {
         ticks = stoi(num_ticks);
         procs = stoi(num_proc);
    }
    catch (std::invalid_argument& e) {
        e.what();
        cout << " No job to be extracted here. Empty Job" << endl;
    }
    
 ;
                
    // Prints out the data read
    //cout << "Job Name: " << jobname << " Number of ticks: " << ticks << " Number of Processors: " << procs << endl;

    if (jobname == "")
    {
        //if jobname is null do not insert job into wait prioity queue end function
        Job nojob("", 0, 0, 0);
        return nojob;
    }
    
    else
    {
        //assign new id and insert into wait queue
        Job newjob(jobname, procs, ticks, jobid);
        return newjob;
    }
}

// Function: insertJob(Job toinsert)
// This function inserts the job into the wait queue if the job description is not null
// The function prints a confrimation if the job was successfully submitted
void Scheduler::insertJob(Job toinsert)
{
    //If job description is null don't push into wait queue.
    if (toinsert.getJobdes() == "")
    {
        cout << "No job to be inserted." << endl;
    }
    else
    {
        this->waitqueue.push(toinsert);    //inserting job into wait queue
        cout << "Job Id " << toinsert.getJobid() << " successfully submitted" << endl;
        //says when job is inserted into wait queue
    }
}
// Function: checkLast()
// This function prints the contents in the vector.
// Returns Nothing
// Efficency: O(n)
void Scheduler::checkLast()
{
    vector<Job>::iterator it = this->runningqueue.begin();
    if (this->runningqueue.size() == 1)
    {
        if (it->getTicks() == 0)
        {
            this->runningqueue.clear();
        }
    }
}

// Function:printRun()
// This function prints the contents in the vector.
// Returns Nothing
// Efficency: O(n)
void Scheduler::printRun()
{
    vector<Job>::iterator it = this->runningqueue.begin();
    for(;it != this->runningqueue.end(); it++)
    {
        cout << "Vector: Job description: " << it->getJobdes()<< ", Proc: " << it->getProcessor() << ", ticks: " << it->getTicks() << endl;
    }
}

// Function: findShortest()
// This function finds the shortest Job.
// Returns the shortest from the wait queue
Job Scheduler::findShortest()
{
    return this->waitqueue.top(); //returns the data at the top of the queue (min value)
}

// Function: deleteShortest()
// This function removes the minimum value from the wait queue
// This function does not return anything.
void Scheduler::deleteShortest()
{
    this->waitqueue.pop(); //remove the minimun value in the heap
}

// Function: checkAvailable(int neededprocessors)
// This function checks if there are enough processors available to use.
// If the processors available is greater then the processors needed
// The function returns true and the amount of available processors is subtracted
// By the processors needed.
// If there are not enough processors the function returns false;
// Returns true if enough processors. Returns false if not enough processors.
bool Scheduler::checkAvailable(int neededprocessors)
{
    bool success = false;

    if (this->freepool >= neededprocessors)
    {
        //if enough processors are available function is evaluated true
        success = true;
        this->freepool = this->freepool - neededprocessors;
    }
    return success;
}

// Function: DecrementTimer()
// This function iterates through the running queue decreasing
// The number of ticks for each job in the queue.
void Scheduler::DecrementTimer()
{
    //loop through running queue and decrement the number of ticks for each job
    vector<Job>::iterator check = this->runningqueue.begin();

    while (check != this->runningqueue.end())
    {
        check->setTicks(check->getTicks() - 1);        //loops through vector and decreases ticks for every value by 1
        check++;
    }
}

// Function: getProcs()const
// This function returns the available processors.
int Scheduler::getProcs()const
{
    return this->freepool;
}

// Function: setFreepool(int np)
// This function sets the number of available processors.
// Returns nothing
void Scheduler::setFreepool(int np)
{
    this->freepool = np;
}

// Function: freeProcessors()
// This function iterates througgh the running queue. Searches through the vector
// If the job that the iterator is pointing has 0 amount of ticks.
// The freepool (amount of available processors) adds the processors of the finished
// Job back into the freepool.
// The completed job information is printed.
// The number of processors is user defined.
void Scheduler::freeProcessors()
{
    auto it = runningqueue.begin();

    while (it != runningqueue.end())
    {
        if (it->getTicks() == 0)
        {
            this->freepool = this->freepool + it->getProcessorConst(); //adds the processors back into the avaialble space
            cout << "Job completed: " << "Job description: " << it->getJobdes() << ", Proc: " << it->getProcessorConst() << ", ticks: " << it->getTicksConst() << endl;
            it = runningqueue.erase(it);
        }
        else // Move the iterator if the following condition is not true
        {
            ++it;
        }
    }
}

// Function: Scheduler(int processors)
// Constructor
// Initalizes the Scheduler with the number of processors.
// The number of processors is user defined.
void Scheduler::runJob(Job torun)
{
    //runs job just poped off of prority queue
    //O(c)
    //testing with vector implementation
    //pass job into run queue
    this->runningqueue.push_back(torun);

    //print job started
    cout << "Job Started: " << "Job description: " << torun.getJobdes() << ", Proc: " << torun.getProcessor() << ", ticks: " << torun.getTicks() << endl;

}

// Function: Scheduler(int processors)
// Constructor
// Initalizes the Scheduler with the number of processors.
// The number of processors is user defined.
bool Scheduler::waitqueueEmpty()
{
    bool success = false;
    if (this->waitqueue.empty() == true)
    {
        success = true;
    }
    return success;
}

bool Scheduler::runningqueueEmpty()
{
    bool success = false;
    if (this->runningqueue.empty() == true)
    {
        success = true;
    }
    return success;
}
