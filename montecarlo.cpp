#include "montecarlo.hpp"

MonteCarlo::MonteCarlo()
{
	this->numBatches = 0;
	this->numSampled = 0;
	this->totalBadDetected = 0;
	this->prefix = "datasets/ds";
	this->suffix = ".txt";
}
MonteCarlo::MonteCarlo(int numBatches, int numSampled)
{
	this->numBatches = numBatches;
	this->numSampled = numSampled;
	this->totalBadDetected = 0;
	this->prefix = "datasets/ds";
	this->suffix = ".txt";
}
void MonteCarlo::DetectBad()
{
	string line;

	for(int i = 0; i < numBatches; ++i)
	{
		string filename = prefix + to_string(i+1) + suffix;
		inFS.open(filename);
		if(inFS.is_open())
		{
			for(int j = 0; j < numSampled; ++j)
			{
				getline(inFS, line);
				if(line.compare("b") == 0)
				{
					totalBadDetected += 1;
					break;
				}
			}
		}
		else
		{
			cout << "ERROR: Could not open file!!!" << endl;
			break;
		}
		inFS.close();
	}
}
int MonteCarlo::GetTotalBadDetected()
{
	return this->totalBadDetected;
}