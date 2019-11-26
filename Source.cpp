#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;
//Node class is used in linkedList class
class node {
public:
	node()
	{
		this->link = nullptr;
		this->prev = nullptr;
	}
	node(int data)
	{
		this->data = data;
		this->link = nullptr;
		this->prev = nullptr;
	}
	//To be more formal, these should be private and you would make getter and setter functions

	int data; //data of position in list
	node *link; //link to next position in list
	node *prev;
};

class linkedList {
public:

	linkedList()
	{
		first = nullptr;
		last = nullptr;
		Count = 0;
	}

	int Length() {
		return Count;
	}

	bool isEmpty() {
		if (first == nullptr)
		{
			return true;
		}

			return false;
	}

	void Insert(node *temp) {
		if (isEmpty())
		{
			first = temp;
			last = temp;
		}
		else
		{
			if (temp->data < first->data)
			{
				temp->link = first;
				first->prev = temp;
				first = temp;
			}
			else if (temp->data > last->data)
			{
				last->link = temp;
				temp->prev = last;
				last = temp;
			}
			else
			{
				node * current = first;
				node * post = current;
				while (current != nullptr)
				{

					if (temp->data > post->data && temp->data < current->data)
					{
						post->link = temp;
						temp->prev = post;
						temp->link = current;
						current->prev = temp;
						break;
					}
					post = current;
					current = current->link;
				}
			}
		}
		this->Count++;
	}

	void Delete(node *temp) {
		if (isEmpty()) { //If list is empty
			cout << "\nCannot delete data from an empty list.\n";
		}
		else if (first->data == temp->data) //If node to be deleted is first node
		{
			node *current = first;
			first = first->link;
			delete current;
			this->Count--;
		}
		else if (last->data == temp->data) //If node to be deleted is the last node
		{
			//In order to delete we need to have a pointer which is the second to last node.
			node *current = last; //Pointing to current node
			last = last->prev;
			last->link = nullptr;
			delete current;
			this->Count--;
			//After while loop current is pointing to the last node and post is pointing to the second to last node
		}
		else
		{
			node *post = first; //Pointing to node before current
			node *current = first; //Pointing to current node
			while (current != nullptr)
			{
				if (current->data == temp->data)
				{
					post->link = current->link;
					delete current;
					this->Count--;
					break;
				}
				post = current;
				current = current->link;
			}
		}

	}

	void Print(node* N) {
		node *current = N;
		if (current != nullptr)
		{
			cout << current->data << " ";
			if (current->prev != nullptr)
			{
				Print(current->prev);
			}
		}
	}
	node *first;
	node *last;
	int Count;
};

int Fibonacci(int n)
{
	int ab = 1;
	if(n == 1 || n == 2)
	{
		return ab;
	}
	else if(n > 2)
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int Fibo(int n)
{
	int a = 1;
	int b = 1;
	int fibo;
	if (n == 0 || n == 1)
		return 1;
	else {
		int prev1 = a;
		int prev2 = b;
		for (int i = 1; i <= n - 1; i++)
		{
			fibo = prev1 + prev2;
			prev1 = prev2;
			prev2 = fibo;
		}
	}
	
	return fibo;
}

void Hanoi(int N, char A, char C, char B)
{
	if (N > 0) {
		Hanoi(N - 1, A, B, C);
		cout << "move disk from " << A << "to " << C << endl;
		Hanoi(N - 1, B, C, A);
	}
}


int decimalBi(int n)
{
	int temp = decimalBi(n % 2);
	cout << temp;
	return temp;
}


int main()
{
	/*linkedList l;
	int num = 0;
	int temp1;
	node *temp;
	while (num != -999)
	{
		cout << "\nPlease enter -1 to insert, -2 to delete and -999 to quit.\n";
		cin >> num;
		switch (num) {
		case -1:
			cout << "Please enter a number to insert: ";
			cin >> temp1;
			temp = new node();
			temp->data = temp1;
			l.Insert(temp);
			break;
		case -2:
			cout << "Please enter a number to delete: ";
			cin >> temp1;
			temp = new node();
			temp->data = temp1;
			l.Delete(temp);
			break;
		default:
			cout << "Please enter a number that is an option the enxt run around.";
		}
		l.Print(l.last);
	}
	clock_t begin, end;
	double elapsed_secs;
	begin = clock();
	cout << Fibonacci(40);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time: " << elapsed_secs << "secs" << endl;
	cout << endl;
	begin = clock();
	cout << Fibo(40);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time: " << elapsed_secs << "secs" << endl;
	*/

	decimalBi(35);
	return 0;
}