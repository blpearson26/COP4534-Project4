#include "montecarlo.hpp"

MonteCarlo::MonteCarlo(int numBatches, int numSampled)
{
	this->numBatches = numBatches;
	this->numSampled = numSampled;
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
					cout << "Bad APPLE DETECTED!! Batch: " << i+1 << " Item: " << j << endl;
				}
			}
		}
		else
		{
			cout << "ERROR: Could not open file!!!" << endl;
		}
		inFS.close();
	}
}