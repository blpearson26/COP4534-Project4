#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP
#include <fstream>
#include <iostream>
using namespace std;

class MonteCarlo{

private:
	ifstream inFS;
	int numBatches, numSampled;
	string prefix, suffix;


public:
	MonteCarlo(int numBatches, int numSampled);
	void DetectBad();


};
#endif