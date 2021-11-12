/**
 * Author: Brandon Pearson
 * Course: COP4534
 * 
 * This is the program for Project 4 - Monte Carlo Short
 *
 * This Program uses Monte Carlo Algorithm to solve the
 * bad microchip problem.
 * 
 * Results will be displayed on the terminal. The files
 * for individual batches will be saved in a subdirectory
 * called datasets within the working directory of the project.
 * 
 */
#include <time.h>
#include "datahandler.hpp"

using namespace std;

/****  MAIN FUNCTION ****/
int main()
{
	static const int ARR_SIZE = 4;
	string filenames[ARR_SIZE] = {"t1.txt", "t2.txt", "t3.txt", "t4.txt"};
	srand(time(NULL));

	for(int i = 0; i < ARR_SIZE; ++i)
	{
		DataHandler d(filenames[i]);
		cout << "\nSimulation " << i+1 << ":" << endl;
		cout << "-----------------------------------------------------" << endl;

		d.GetParams();
		d.PrintParams();

		cout << "\nGenerating data sets:\n" << endl;

		d.GetDataSets();
		d.PrintData();

		cout << "\nAnalyzing Data Sets:\n" << endl;

		d.StartMonte();
		d.PrintResults();
		cout << endl;
	}
	
	return 0;
}

