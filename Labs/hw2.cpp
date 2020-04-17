/*
* Introduction to algorithms - HW2
* Last Modified: 2020/4/15
* Author: 0617052 Ming-Yu Lin
*/
#include <climits>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include "PrecisionTimer.h"	    // high resolution timer.
#define SIZE 100
using namespace std;

/*
* Global Variables 
*/
char sleep;                   // Avoid exe file "Flashback"
int input_array[SIZE];
int backup_array[SIZE];
PrecisionTimer timer;

/*
* Functions
*/
int Brute_Force(int A[], int start, int end);
int Divide_and_conquer(int A[], int start, int end);
int Divide_and_conquer_sub(int A[], int start, int mid, int end);
void random_array_number_generator();          //Copy from HW1

/*
* Main 
*/
int main()
{
	cout << "Introduction to algorithms - HW2" << endl;
	cout << "Last Modified: 2020/4/15" << endl;
	cout << "Author: 0617052 Ming-Yu Lin" << endl;
	cout << "Array SIZE is " << SIZE << " now" << endl;
	cout << "P.S. If TAs want to edit array size, SIZE is at line 11" << endl;
	cout << "--------------------------------------------------------" << endl;
	/*array number test (not necessary)*/
	random_array_number_generator();
	cout << "Test random array number" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << input_array[i] << ',';
	}
	
	/*Brute-force performance O(n^2)*/
	cout << endl << endl << "Brute-Force performance: ";
	double result_BF = 0.0;
	timer.Start();
	Brute_Force(input_array, 0, SIZE);
	result_BF = timer.Stop();
	cout << result_BF << " sec" << endl;

	/*Divide-and-conuer performance O(nlogn)*/
	cout << "Divide-and-conuer performance: ";
	double result_DC = 0.0;
	timer.Start();
	Divide_and_conquer(backup_array, 0, SIZE);
	result_DC = timer.Stop();
	cout << result_DC << " sec" << endl;

	/*Which one is faster ??*/
	if (result_BF < result_DC) {
		cout << "Brute_Force is faster in array size " << SIZE  << endl << endl;
	}
	else {
		cout << "Divide_and_Conquer is faster in array size " << SIZE << endl << endl;
	}
	cout << "Please enter one 'char' if you want to quit" << endl;
	cin >> sleep;
}

/*
* Brute-force
* O(n^2) time algorithm
*/
int Brute_Force(int A[], int start, int end) {
	int maximum = 0;
	int current = 0;

	for (int i = start; i <= end; i++) {
		current = 0;
		for (int j = i; j <= end; j++) {
			current += A[j];
			if (current > maximum) {
				maximum = current;
				}
			}
		}
		return maximum;
	}

/*
* Divide-and-Conquer
* O(nlogn) time algorithm
*/
int Divide_and_conquer(int A[], int start, int end) {
	int mid = 0;
	int leftSum = 0, rightSum = 0, crossSum = 0;
	if (start == end) {
		return A[start];
	}
	else {
		mid = (start + end) / 2;
		leftSum = Divide_and_conquer(A, start, mid);
		rightSum = Divide_and_conquer(A, mid + 1, end);
		crossSum = Divide_and_conquer_sub(A, start, mid, end);
		if (leftSum >= rightSum && leftSum >= crossSum) {
			return (leftSum < 0 ? 0 : leftSum);
		}
		else if (rightSum >= leftSum && rightSum >= crossSum) {
			return (rightSum < 0 ? 0 : rightSum);
		}
		else {
			return (crossSum < 0 ? 0 : crossSum);
			}
		}
	}

/*
* Linear time algorithm, used by the divide & conquer algorithm above.
*/
int Divide_and_conquer_sub(int A[], int start, int mid, int end) {
	int leftSum = INT_MIN;
	int rightSum = INT_MIN;
	int sum = 0;

	for (int i = mid; i >= start; i--)
	{
		sum += A[i];
		if (sum > leftSum) {
			leftSum = sum;
		}
	}
	sum = 0;
	for (int j = mid + 1; j <= end; j++) {
		sum += A[j];
		if (sum > rightSum) {
			rightSum = sum;
		}
	}
		return (leftSum + rightSum);
	}

/*
* Copy From HW1.
*/
void random_array_number_generator() {
		int i, j;
		srand(time(NULL));
		for (i = 0; i < SIZE; i++) {
			j = rand();
			input_array[i] = j;
			backup_array[i] = j;
		}
	}

