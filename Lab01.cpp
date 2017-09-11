// Lab01.cpp
// Miles Golding
// COSC 2030
// 11 September 2017


#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void countNumbers(std::istream & infile)
{

	long numberCount = 0;
	double secondLast(0), last(0), first(0), second(0);
	while (true)
	{
		double number;
		infile >> number;

		if (numberCount == 0)
		{
			first = number;
		}
		if (numberCount == 1)
		{
			second = number;
		}

		// check for end of file after every read
		if (infile.fail())
		{
			break;
		}
		else
		{
			secondLast = last;
			last = number;
		}
		numberCount++;

	}
	cout << numberCount << " numbers in file." << endl;
	cout << first << endl << second << endl
		<< secondLast << endl << last << endl;

}



int
main()
{
	// get the filename and open the file
	string filename;
	cout << "Print the first and last two numbers of the list:" << endl;
	cout << endl << "Enter file name (or quit)  :   ";
	cin >> filename;

	while (filename != "quit")
	{

		ifstream infile(filename);
		if (infile)
		{
			cout << filename << " opened for reading." << endl;
			countNumbers(infile);

		}
		else
		{
			cout << filename << " failed to open" << endl;
		}
		cout << endl << "Enter file name: ";
		cin >> filename;


	}

	return 0;
}