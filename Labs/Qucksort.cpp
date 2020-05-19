/* HW3 Randomized Quicksort
* Author: Unfish0705
* last Modifed: 2020/5/15 */
#include<iostream>
#include<ctime>						// srand(), time;
#include "PrecisionTimer.h"			// Copy from HW2;
using namespace std;

/*Global Variable*/
int A[1005] = {}; // Array contains 1000 elements(I arrange 5 more size than we should use)
int Backup_A[1005] = {};
int times = 0;  // times for the line 4;
int store_times[30] = {}; // store times value for 30 runs randomize Quicksort;
int average_times;
char quit;
PrecisionTimer Timer;

/*Fucntions*/
void Quicksort_R(int A[], int p, int r);	// Main function of Quicksort, Recursive call itself;
void Quicksort_N(int A[], int p, int r);    // Normal Version;
void insertion_sort(int A[], int length);	// Copy From HW1;
void random_array_number_generator();		// Copy From HW1;
void Array_to_Random_Array(int A[], int r); // Convert an array to a Random array;
int Partition_random(int A[], int p, int r); // Perform a randomized partition for Quicksort;
int Partition_normal(int A[], int p, int r); // Perform partition for an randomized array for Quicksort;

int main()
{
	cout << "HW3 Randomized Quicksort" << endl;
	cout << "Student ID: 0617052" << endl << endl;
	cout << "Problem (0) Test Quicksort is correct or not(Take first 5 elements to check)" << endl;
	random_array_number_generator();
	cout << "Before Quicksort(A[1] to A[5])" << endl;
	for (int i = 1; i <= 5; i++)
	{
		cout << A[i] << ",";
	}
	cout << endl << endl;
	Quicksort_R(A, 1, 1000);
	cout << "After Quicksort(A[1] to A[5])" << endl;
	for (int i = 1; i <= 5; i++)
	{
		cout << A[i] << ",";
	}
	cout << endl << endl;
	int B[11];
	cout << "Array_to_Randomized_Array Function:" << endl;
	cout << "Before Randomized" << endl;
	for (int i = 1; i <= 10; i++)
	{
		B[i] = i;
		cout << B[i] << ",";
	}
	cout << endl << endl;
	Array_to_Random_Array(B, 10);
	cout << "After Randomized" << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << B[i] << ",";
	}
	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Problem (a) Partition Line 4 Execution Times(30 runs)" << endl;
	for (int i = 0; i < 30; i++)
	{
		random_array_number_generator();
		Quicksort_R(A, 1, 1000);
		store_times[i] = times;
		times = 0;
	}
	for (int i = 0; i < 30; i++)
	{
		average_times += store_times[0];
	}
	average_times /= 30;
	cout << "The average times of Partition line 4(30 runs): " << average_times << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Problem (b) Randomized Quicksort v.s Aleardy randomized array then do Quicksort" << endl;
	Timer.Start();
	Array_to_Random_Array(A, 1000);
	Quicksort_N(A, 1, 1000);
	cout << "Aleardy randomized array then do Quicksort result " << Timer.Stop() << endl;
	Timer.Start();
	Quicksort_R(Backup_A, 1, 1000);
	cout << "Randomized Quicksort result: " << Timer.Stop() << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Problem (c) Insertion sort v.s Quicksort running time" << endl;
	random_array_number_generator();
	Timer.Start();
	Quicksort_N(A, 1, 1000);
	cout << "Quicksort running time " << Timer.Stop() << endl; // O(nlogn)
	Timer.Start();
	insertion_sort(Backup_A, 1000);
	cout << "Insertion sort running time " << Timer.Stop() << endl; // O(n^2)
	cin.get(quit);
	cout << "Enter one char to quit";
}

void Quicksort_N(int A[],int p,int r)
{
	if (p < r)
	{
		int q;
		q = Partition_normal(A, p, r);
		Quicksort_N(A, p, q - 1);
		Quicksort_N(A, q + 1, r);
	}
}

void Quicksort_R(int A[], int p, int r)
{
	if (p < r)
	{
		int q;
		q = Partition_random(A, p, r);
		Quicksort_R(A, p, q - 1);
		Quicksort_R(A, q + 1, r);
	}
}

int Partition_random(int A[], int p, int r)
{
	int x;
	int random = 0;
	int temp;
	int i = p - 1;
	/* Random choose a number to swap with A[r]*/
	/*-----------------------------------------*/
	while (random < p)
	{
		random = rand() % r + 1;
	}	
	temp = A[random];
	A[random] = A[r];
	A[r] = temp;
	/*-----------------------------------------*/
	x = A[r];	
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x) 
		{
			times++;
			i = i + 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}	
	}
	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	return i + 1;
}

int Partition_normal(int A[], int p, int r)
{
	int x;
	int temp;
	int i = p - 1;
	x = A[r];
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	return i + 1;
}

void Array_to_Random_Array(int A[], int r)
{
	int random;
	int temp;
	for (int i = r; i > 0; i--)
	{
		random = rand() % i + 1;
		temp = A[random];
		A[random] = A[i];
		A[i] = temp;
	}
}

void insertion_sort(int A[], int length) {
	int i, j, tmp;
	for (i = 1; i < length; i++) {
		j = i;
		while (j > 0 && A[j - 1] > A[j]) {
			tmp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = tmp;
			j--;
		}
	}
}

void random_array_number_generator()
{
	int i, j;
	srand(time(NULL));
	for (i = 1; i <= 1000; i++) {
		j = rand();
		A[i] = j;
		Backup_A[i] = j;
	}
}