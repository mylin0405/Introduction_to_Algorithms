// 演算法_HW1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
// 0617052_林明佑
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#define SIZE 10000                   // input_array size here !!!!;
using namespace std;
/*Global variables*/
int input_array[SIZE];               // input_array -v-;
int backup_array[SIZE];              // store the input_array for comparing;
long double START, END;                   // clock();
/*Random number array generator*/
void random_array_number_generator() 
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        j = rand();
        input_array[i] = j;
        backup_array[i] = j;
    }
}
/*Merge two small arrays*/
void merge(int l, int mid, int h) {

    int* temp = new int[h - l + 1];

    for (int i = 0, j = l; j <= h; i++, j++)
        temp[i] = input_array[j];

    int left = l - l;
    int right = mid + 1 - l;
    int k = l;
    while (k <= h && left <= mid - l && right <= h - l) {
        if (temp[left] < temp[right])
            input_array[k++] = temp[left++];
        else
            input_array[k++] = temp[right++];
    }
    if (left > mid - l)
        while (right <= h - l)
            input_array[k++] = temp[right++];
    else
        while (left <= mid - l)
            input_array[k++] = temp[left++];
    delete[] temp;
}
/*Merge_sort main function*/
void merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

/*Insertion_sort main function*/
void insertion_sort(int array[], int length) {
    int i, j, tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && array[j-1] > array[j]) {
            tmp = array[j];
            array[j] = array[j-1];
            array[j-1] = tmp;
            j--;
        }
    }
}

/*Sort and test sorting-time in different array size*/
int main()
{
    /*Initiation input_array[]*/
    cout << "Array size is " << SIZE << endl;
    cout << "If TAs want to change array size,then please edit #line7's SIZE thx" << endl;
    random_array_number_generator();
    
    /*Test merge_sort time*/
    START = clock();
    merge_sort(0, SIZE-1);
    END = clock();
    /*for (int i = 0; i < SIZE; i++) {
        cout << input_array[i] << endl;
    }*/
    cout << "merge_sort result " << (END - START) / CLOCKS_PER_SEC  << " sec" << endl;

    /*Test insertion_sort time*/
    START = clock();
    insertion_sort(backup_array, SIZE);
    END = clock();
    /*for (int i = 0; i < SIZE; i++) {
        cout << backup_array[i] << endl;
    }*/
    cout << "insertion_sort result " << (END - START) / CLOCKS_PER_SEC << " sec" << endl;
    getch();
   	return 0;
}
