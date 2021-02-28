#include "sorting.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>




int main()
{
    int array1[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int array2[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int array3[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int array4[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int mov1 = 0;
    int comp1 = 0;
    int mov2 = 0;
    int comp2 = 0;
    int mov3 = 0;
    int comp3 = 0;
    cout <<"------ SELECTION SORT ------"<<endl;
    selectionSort(array1, 16, comp1, mov1);
    displayArray(array1, 16);
    cout << "Number of comparisons: "<<comp1<<endl;
    cout << "Number of moves: "<<mov1<<endl;
    cout<<"------ MERGE SORT ------"<<endl;
    mergeSort(array2, 16, comp2, mov2);
    displayArray(array2, 16);
    cout << "Number of comparisons: "<<comp2<<endl;
    cout << "Number of moves: "<<mov2<<endl;
    cout <<"------ QUICK SORT ------"<<endl;
    quickSort(array3, 16, comp3, mov3);
    displayArray(array3, 16);
    cout << "Number of comparisons: "<<comp3<<endl;
    cout << "Number of moves: "<<mov3<<endl;
    cout <<"------ RADIX SORT ------"<<endl;
    radixSort(array4, 16);
    displayArray(array4, 16);
    
    cout <<"------ PERFORMANCE ANALYSIS ------"<<endl;
    
    performanceAnalysis();
    

    return 0;
 
}