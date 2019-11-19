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

	int jobid = 1;
	Job newJob("",0,0,0);
	int ticks = 1;
	bool availProc = false;
	Job toDelete("",0,0,0);

	while (!infile.eof())
	{	
		cout << "Tick Number " << ticks << ":" << endl;
		newJob = testing.readline(infile, jobid);

	    if(newJob.getJobdes() == "")
		{	//Job ID is incremented by default if the job is null decrease the value to display right Job ID
			continue;
		}
		else 
		{	
			++ticks;
			++jobid;
			testing.insertJob(newJob);
			toDelete = testing.findShortest();
			availProc = testing.checkAvailable(toDelete.getProcessor());

			if(availProc == false)
			{
				continue;
			}

			else 
			{
				testing.deleteShortest();
				testing.runJob(toDelete);			
			}
		}
			testing.DecrementTimer();
			testing.freeProcessors();
		
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