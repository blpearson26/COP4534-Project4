#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP
#include <fstream>
#include <iostream>
using namespace std;

class MonteCarlo{

private:
	ifstream inFS;
	int numBatches, numSampled, totalBadDetected;
	string prefix, suffix;


public:
	MonteCarol();
	MonteCarlo(int numBatches, int numSampled);
	void DetectBad();
	int GetTotalBadDetected();
};

#endif