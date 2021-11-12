#include "datahandler.hpp"

DataHandler::DataHandler()
{
	this->maxBad = 0;
	this->minBad = 999;
	this->totalBad = 0;
}
DataHandler::DataHandler(string filename)
{
	this->filename = filename;
	this->maxBad = 0;
	this->minBad = 999;
	this->totalBad = 0;
}
void DataHandler::StartMonte()
{
	MonteCarlo m(numBatches, numSampled);
	m.DetectBad();
	totalBadDetected = m.GetTotalBadDetected();
}
void DataHandler::GetDataSets()
{
	float toDecimal = pctBadBatch / 100.0;
	vector<int> badBatchIndex;
	totalBadSets = numBatches * toDecimal;

	string prefix = "datasets/ds";
	string suffix = ".txt";
	
//Randomly assigns Bad Batches
	for(int i = 0; i < totalBadSets; ++i)
	{
		int randIndex = rand() % (numBatches - 1);
	//Assign bad batch to different Batch # if already Bad
		while(find(badBatchIndex.begin(), badBatchIndex.end(), randIndex) != badBatchIndex.end())
		{
			randIndex = rand() % (numBatches - 1);
		}
		badBatchIndex.push_back(randIndex);
	}
//If Batch is Bad, Get Bad Items in said batch, otherwise assign all items to 'g'
	for(int i = 0; i < numBatches; ++i)
	{
		string filename = prefix + to_string(i+1) + suffix;
		outFS.open(filename);

		if(find(badBatchIndex.begin(), badBatchIndex.end(), i) != badBatchIndex.end())
			GetBadItems();
		else
		{
			for(int j = 0; j < numItems; ++j)
			{
				outFS << 'g' << endl;
			}
		}
		outFS.close();
	}
}
void DataHandler::GetBadItems()
{
	int numBad = 0;

	for(int i = 0; i < numItems; ++i)
	{
		int randNum = rand() % 99;
		if(randNum < pctBadItem)
		{
			numBad += 1;
			outFS << 'b' << endl;
		}
		else
			outFS << 'g' << endl;
	}

	maxBad = max(maxBad, numBad);
	minBad = min(minBad, numBad);
	totalBad += numBad;

}
void DataHandler::GetParams()
{
	string line;
	inFS.open(filename);
	if(inFS.is_open())
	{	
		getline(inFS, line);
		numBatches = stoi(line);
		getline(inFS, line);
		numItems = stoi(line);
		getline(inFS, line);
		pctBadBatch = stoi(line);
		getline(inFS, line);
		pctBadItem = stoi(line);
		getline(inFS, line);
		numSampled = stoi(line);

	}
	else
	{
		cout << "ERROR: Could not open file!!!" << endl;
		exit(1);
	}
}
void DataHandler::PrintParams()
{
	cout << "  Number of batches of items: 			" << numBatches << endl;
	cout << "  Number of items in each batch:		" << numItems << endl;
	cout << "  Percentage of batches containing bad items:	" << pctBadBatch << endl;
	cout << "  Percentage of items that are bad in a set: 	" << pctBadItem << endl;
	cout << "  Items sampled from each set:			" << numSampled << endl; 
}
void DataHandler::PrintData()
{
	float avgBad = (float)totalBad / (float)totalBadSets;
	cout << "  Total bad sets = " << totalBadSets << endl; 
	cout << "  Max number of bad items in a bad set = " << maxBad << endl;
	cout << "  Min number of bad items in a bad set = " << minBad << endl;
	cout << "  Average number of bad items in a bad set = " << avgBad << endl;
}
void DataHandler::PrintResults()
{
	float pctDetected = ((float)totalBadDetected / (float)totalBadSets) * 100;
	float base = 1 - (pctBadItem / 100.0);
	cout << "  Total bad sets found = " << totalBadDetected << endl;
	cout << "  Percentage of bad batches actually detected = " << pctDetected << "%" << endl;
	cout << "  Base = " << base << "  Exponent = " << numSampled << endl;
	cout << "  Predicted P(failure to detect bad batch) = " << pow(base, numSampled) << endl;
}

