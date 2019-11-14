#include "iostream";
using namespace std;
class Job
{
public:
    Job();
    ~Job();
    int getprocessor()const;
    void initJob(string &desc, int &processors, int &ticks, int &idNum);
private:
    // Job ID number
    int jobID;
    //Job description field
    string jobDesc;
    // Number of processors
    int jobProc;
    int jobticks;
};

Job::Job()
{
    this->jobID = NULL;
    this->jobDesc = "";
    this->jobProc = NULL;
    this->jobticks = NULL;
}
Job::~Job()
{

}
void Job::initJob(string &desc, int &processors, int &ticks, int &idNum)
{

    this->jobDesc = desc;
    this->jobProc = processors;
    this->jobticks = ticks;
    this->jobID = idNum;
}
int Job::getprocessor()const
{
   return this->jobProc;
}
