#pragma once

#include "iostream"
using namespace std;
class Job
{
public:
    Job(string desc, int processors, int ticks, int idNum);
    ~Job();
    int getProcessor()const;
    int getTicks() const;
    int getJobid() const;
    string getJobdes() const;
    void setTicks(int newticks);
    int getProcessorConst()const;
    int getTicksConst()const;
private:
    // Job ID number
    int jobID;
    //Job description field
    string jobDesc;
    // Number of processors
    int jobProc;
    // Number of ticks
    int jobTicks;
    
    int constTicks;
    int constProc;
};

class Compareclass
{

public:

    int operator () (const Job& j1, const Job& j2)
    {
        return j1.getTicks() > j2.getTicks();
    }

};
