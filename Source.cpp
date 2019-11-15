#include<iostream>
#include<string>
#include <ctime> 
using namespace std;

int fib1(int a, int b, int n) //This is the recursive function
{ 
	if (n == 0) //If the number of times to go through is zero, it returns zero
		return a; 
	else if(n == 1) //If the number of times to go through is one, it returns
		return b; 
	else
		return fib1(a, b, n - 1) + fib1(a, b, n - 2); //Runs the program again with a smaller number and adds it onto the current number
}

int fib2(int a, int b, int n) 
{ 
	int fact; 
	if (n == 0) //If the number of times to go through is zero, it returns zero
	{ 
		return a; 
	}
	else if(n == 1) //If the number of times to go through is one, it returns
	{ 
		return b; 
	} 
	else 
	{ 
		int prev1 = a;
		int prev2 = b; 
		for (int i = 1; i <= n - 1; i++) //Loops through the numbers starting from the top adding the last two numbers to the total
		{ 
			fact = prev1 + prev2; 
			prev1 = prev2; 
			prev2 = fact; 
		} 
	}
	return fact;  //Returns number
}

void power(int F[2][2], int n); //Initializes the power function (you raise the matrix to the nth power

int fib3(int n)
{
	int F[2][2] = { {1,1},{1,0} }; //Makes a matrix
	if (n == 0)
		return 0;
	power(F, n - 1); //Calls the power function on the matrix

	return F[0][0]; //Returns the matrix
}

void multiply(int F[2][2], int M[2][2]) //This is the function that multiplies the matrixes
{
	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0]; //Multiplication statements
	int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(int F[2][2], int n)
{
	int i;
	int M[2][2] = { {1,1},{1,0} }; //Another matrix to multiply by

	// n - 1 times multiply the matrix to {{1,0},{0,1}} 
	for (i = 2; i <= n; i++)
		multiply(F, M); //Calls multiply function
}

int main()
{
	clock_t begin, end;
	double elapsed_secs;

	int n; //Number of times going through fibonacci sequence
	
	cout << "Enter a number to get the fibonacci number of: ";
	cin >> n; //Ask for user input


	begin = clock();//Starts timer
	cout << "N = " << n << " Approach A: " << fib1(0, 1, n);
	end = clock();//Ends timer
	elapsed_secs = (end - begin)/CLOCKS_PER_SEC;
	cout << "\nElapsed Time: " << elapsed_secs;
	begin = clock();//Starts second timer
	cout << "\n" << "N = " << n << " Approach B: " << fib2(0, 1, n);
	end = clock();//Ends second timer
	elapsed_secs = (end - begin) / CLOCKS_PER_SEC;
	cout << "\nElapsed Time: " << elapsed_secs;
	begin = clock();//STarts third timer
	cout << "\n" << "N = " << n << " Approach C: " << fib3(n);
	end = clock();//Ends second timer
	elapsed_secs = (end - begin) / CLOCKS_PER_SEC;
	cout << "\nElapsed Time: " << elapsed_secs;
	//cout the results of every approach
	return 0;
}