#ifndef DATAHANDLER_HPP
#define DATAHANDLER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
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
	int maxBad, minBad, totalBad, totalBadDetected;

public:
	DataHandler();
	DataHandler(string filename);
	void GetParams();
	void PrintParams();
	void GetDataSets();
	void GetBadItems();
	void PrintData();
	void StartMonte();
	void PrintResults();
};

#endif