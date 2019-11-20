#include "App.h"

// Function: App()
// Constructor. Creates an instance of the App class
App::App()
{
    cout << "Running app ..." << endl;
}

// Function: App()
// Destructor. Terminates the instance of the App class.
App::~App()
{
    cout << "Closing app ..." << endl;
}

// Function: runApp()
// This function encloses all the logic requried to run the app
void App::runApp()
{
    Scheduler testing(5);
    App startApp;
    string fileName;
    ifstream infile;

    fileName = startApp.filePrompt();
    infile.open(fileName);

    int nump = 0;
    nump = startApp.processorPrompt();
    testing.setProcessors(nump);
    testing.setFreepool(nump);

    int jobID = 1;
    Job newJob("", 0, 0, 0);
    int ticks = 1;
    bool availProc = false;
    Job leastJob("", 0, 0, 0);
    
    while (!infile.eof()) {
        
        //testing.printRun();
        cout << "Tick Number " << ticks << ":" << endl;
        
        testing.DecrementTimer();
        testing.freeProcessors();
        
        newJob = testing.readline(infile, jobID);
        ++jobID;
        testing.insertJob(newJob);
        

        if (newJob.getJobdes() == "")
        { //Job ID is incremented by default if the job is null decrease the value to display right Job ID
            
        }
        else
        {
            while (testing.waitqueueEmpty() != true)
            {
                leastJob = testing.findShortest();
                availProc = testing.checkAvailable(leastJob.getProcessorConst());
                
                if (availProc == true)
                {
                    testing.deleteShortest();
                    testing.runJob(leastJob);
                    break;
                }
                else
                {
                    break;
                }
            }
            
            ticks++;
        }
    }
    
    //Update ticks count after EOF
    
    while ((testing.waitqueueEmpty() != true) || ((testing.runningqueueEmpty()) != true)) {
        cout << "Tick Number " << ++ticks << ":" << endl;
            
        testing.DecrementTimer();
        testing.freeProcessors();
        
        
    do {
        leastJob = testing.findShortest();
//        cout <<"--------------------------" << endl;
//        testing.printRun();
//        cout <<"--------------------------" << endl;
        availProc = testing.checkAvailable(leastJob.getProcessorConst());
        if (availProc == true)
        {
            if(testing.waitqueueEmpty() == true)
            {
                //cout << "Print is Empty" << endl;
                break;
            }
            testing.deleteShortest();
            testing.runJob(leastJob);
        }
        else
        {
            continue;
        }
        
        } while (availProc != false);
    }
}

// Function: processorPrompt()
// This function gets the number of proccessors from the user
// Number of processors is returned
int App::processorPrompt()
{
    int processors;
    cout << "Enter the number of processors." << endl;
    cin >> processors;

    return processors;
}

// Function: filePrompt()
// This function gets the file name from the user
// The file name is returned
string App::filePrompt()
{
    string fileName;
    cout << "Enter the test file to begin." << endl;
    cin >> fileName;
    return fileName;
}