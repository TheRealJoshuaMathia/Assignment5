#include "app.h"

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

	while (!infile.eof())
	{
		newJob = testing.readline(infile, jobid);
		++jobid;
		testing.insertJob(newJob);
		
		if(newJob.getJobdes() == "")
		{
			continue;
		}
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