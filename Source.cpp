/////////////////////////////////////////////////////////////////////////////////////////
//	CSC307 Homework 3 - Stacks and Queues
//
//	Marshall "Skittles" Anderson
//
//	07-05-2018
//
/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void readfile(ifstream &, stack<int>*, queue<int>*);
void getuserfile(ifstream &);
void printqueue(queue<int>* myqueue);
void printstack(stack<int>* mystack);
  
int main(int argc, char *argv[])
{
	stack<int> mystack;
	queue<int> myqueue;
	
	if (argc == 2)
	{
		string userfile = (argv[1]);	// Declares that the userfile passed into argv is a file containing strings.
		ifstream datafile;		
		datafile.open(userfile);
		readfile(datafile, &mystack, &myqueue);
	}
	else
	{
		ifstream datafile;
		getuserfile(datafile);
		if (!datafile.is_open())	//	This will check if a user has entered a valid file.
		{
			cout << "File not found." << endl;
			system("Pause");
			return (0);
		}
		readfile(datafile, &mystack, &myqueue);
	}
	printqueue(&myqueue);	// This calls the function to print the queue.
	printstack(&mystack);	// This calls the function to print the queue.
	return(0);
}
// Function to sort the data into a stack or queue based on it's value and skipping data that is not valid.
void readfile(ifstream &datafile, stack<int>* mystack, queue<int>* myqueue)	
{
	int active;	// Declares active as a string.
	//int data;	// Declares data as a int.
	while (datafile >> active)	// Loop used to write data to stack and queue.
		{
		if (datafile.fail() || active < 0 || active >99)
		{
			datafile.clear();
			datafile.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "data fail" << endl;
			system("Pause");
		}
		//data = atoi(active.c_str());	// This converts the string to an int.
		else if (active <= 49 && active >= 0)	//	If loop used to sort int from 0 to 49 into the queue.
		{
			myqueue->push(active);	// Pushes the value to the myqueue.
			cout << "q pushed" << endl;	//Used for testing.  Commented out.
		}
		else if (active >= 50 && active <= 99)	//	If loop used to sort int from 50 to 99 into the stack.
		{
			mystack->push(active);	// Pushes the value to the mystack.
			cout << "s pushed" << endl;	//Used for testing.  Commented out.
		}
	}
	system("Pause");
}
void getuserfile(ifstream &datafile)	// Function to get a file from the user.
{
	string userfile;	// Declares the info in the user file as strings.
	cout << "Enter file name and extension: " << endl;	// Message prompt to user.
	cin >> userfile;	// Declares that the file the user puts in is the userfile.
	datafile.open(userfile);	// Opens the userfile.
	

}
void printstack(stack<int>* mystack)	// Prints the stack and gives the average of the values present.
{
	double st = 0;	// Declares st as a double and sets it to 0.
	double sc = 0;	// Declares sc as a double and sets it to 0.
	ofstream outtext;
	outtext.open("stack.txt");	// Opens and displays values in the stack.txt file.
	while (!mystack->empty())	// While loop that adds and averages ints until the stack is empty.
	{
		outtext << mystack->top() << endl;	// Looks at the int at the top of the stack.
		sc++;								// Running count of values.
		st = mystack->top() + st;			// Running total of values.
		mystack->pop();						// Removes the top value.
		cout << "s popped" << endl;	//Used for testing.  Commented out.
	}
	st = st / sc;							//Averages the values.
	outtext << endl << st;							//Prints the average.
}
void printqueue(queue<int>* myqueue)	// Prints the queue and gives the average of the values present.
{
	double qt = 0;	// Declares qt as a double and sets it to 0.
	double qc = 0;	// Declares qc as a double and sets it to 0.
	ofstream outtext;
	outtext.open("queue.txt");	// Opens and displays values in the queue.txt file.
	while (!myqueue->empty())	// While loop that adds and averages ints until the queue is empty.
	{
		outtext << myqueue->front() << endl;	// Looks at the int at the front of the queue.
		qc++;								// Running count of values.
		qt = myqueue->front()+qt;			// Running total of values.
		myqueue->pop();						// Removes the front value.
		cout << "q popped" << endl;	//Used for testing.  Commented out.
	}
	system("Pause");
	qt = qt / qc;							//Averages the values.
	outtext << endl << qt;							//Prints the average.
}