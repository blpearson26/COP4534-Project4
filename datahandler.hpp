#ifndef DATAHANDLER_HPP
#define DATAHANDLER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <time.h>
#include <algorithm>
#include "montecarlo.hpp"
using namespace std;

class DataHandler {

private:
	ofstream outFS;
	ifstream inFS;
	string filename;
	int numBatches, numItems, pctBadBatch, pctBadItem, numSampled;
	int totalBadSets, maxBadItems, minBadItems, avgBadItems;
	int maxBad, minBad, totalBad;

public:
	DataHandler(string filename);
	void GetParams();
	void PrintParams();
	void GetDataSets();
	void GetBadItems();
	void PrintData();
	void StartMonte();
	//int GetNumBatches();
	//int GetNumSampled();

};

#endif