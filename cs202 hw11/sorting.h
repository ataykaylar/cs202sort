#include <iostream>
using namespace std;
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

/*
* Title: Algorithm Efficiency and Sorting
* Author: Kaylar Atay
* ID: 21703284
* Assignment: 1
* Description: Header File
*/


void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);


int indexOfLargest(int arr[], int size,int &compCount, int &moveCount);
void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort( int* arr, const int size, int& compCount, int& moveCount );
void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
void partition(int *arr, int first, int last, int &pivotIdx, int &compCount, int &moveCount);
void quickSort( int* arr, const int size, int& compCount, int& moveCount );
void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
void performanceAnalysis();

void radixSort(int *arr, const int size);

void swap(int &a, int &b);