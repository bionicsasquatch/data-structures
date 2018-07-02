#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;
int getsize(int);
int writedata(int);

int main()
{
	int size = 0;
	size = getsize(size);
	int getsize(int size);
	{
		while (size < 20 || size > 100)
		{
			cout << endl;
			cout << "Enter a number from 20 to 100";
			cin >> size;
			if (cin.fail() || size < 20 || size >100)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Invalid Input.  Please enter a number from 20 to 100";
			}
			cout << endl << endl;
		}
		return(size);
	}
	int writedata(int size);
	{
		ofstream writedata;
		writedata.open("number.txt");
		if (writedata)
		{
			cout << "Could not create/open text file for writing" << endl << endl;
			return(1);
		}
		srand(time(NULL));
		cout << "Generating" << size << "ints." << endl;
		cout << "Start Writing Data File" << endl << endl;
		int number = 0;
		for (int i = 0; i < size; i++);
	}
}