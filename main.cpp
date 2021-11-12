#include "datahandler.hpp"

using namespace std;

/****  MAIN FUNCTION ****/
int main()
{
	static const int ARR_SIZE = 4;
	string filenames[ARR_SIZE] = {"t1.txt", "t2.txt", "t3.txt", "t4.txt"};
	srand(time(NULL));
	cout << "Size of Filenames: " << sizeof(filenames) << endl;

	//for(int i = 0; i < ARR_SIZE; ++i)
	//{
		DataHandler d(filenames[0]);
		cout << "\nSimulation " << 1 << ":" << endl;
		cout << "-----------------------------------------------------" << endl;

		d.GetParams();
		d.PrintParams();

		cout << "\nGenerating data sets:\n" << endl;

		d.GetDataSets();
		d.PrintData();

		cout << "\nAnalyzing Data Sets:\n" << endl;

		d.StartMonte();

		//MonteCarlo m(d.GetNumBatches(), d.GetNumSampled());

	//}
	

	return 0;
}

