#include "sorting.h"
#include<bits/stdc++.h>

void mergeSort(int *arr, int size, int &compCount, int &moveCount)//it put it in another merge sort where it has first and last
{
    mergeSort(arr, 0, size-1, compCount, moveCount);
}

void mergeSort(int* arr, int first, int last, int& compCount, int& moveCount )
{

    if (first < last)
    {

        int mid = (first + last)/2; 	// index of midpoint
        mergeSort(arr, first, mid, compCount, moveCount);

        mergeSort(arr, mid + 1, last, compCount, moveCount);

        // merge the two halves
        merge(arr,first,mid, last, compCount, moveCount);
    }
}

void merge( int* arr, int first, int mid, int last, int &compCount, int &moveCount) //merges and compares each half of the array
{

    int first1 = first;
    int first2 = mid+1;
    int *temp = new int[last - first + 1];
    int count = 0;
    while (first1 <= (mid) && first2 <= last)
    {
        if (arr[first2] < arr[first1])
        {
            temp[count++] = arr[first2];
            first2 += 1;
        }
        else
        {
            temp[count++] = arr[first1];
            first1 += 1;
        }
        compCount++;
        moveCount++;
    }
    while (first1 <= (mid))
    {
        temp[count++] = arr[first1];
        first1 += 1;
        moveCount++;
    }

    while (first2 <= last)
    {
        temp[count++] = arr[first2];
        first2 += 1;

        moveCount++;
    }

    for (int i = 0; i < (count); i++)
    {
        arr[i + first] = temp[i];
        moveCount++;
    }
    delete [] temp;


}

void quickSort(int *arr, int size, int &compCount, int &moveCount)//it put it in another quick sort where it has first and last
{
    quickSort( arr, 0, size-1, compCount, moveCount);
}

void quickSort(int *arr, int first, int last, int &compCount, int &moveCount)
{

    int pivotIdx;

    if (first < last)
    {

        partition(arr, first, last, pivotIdx, compCount, moveCount);
        quickSort(arr, first, pivotIdx - 1, compCount, moveCount);
        quickSort(arr, pivotIdx + 1, last, compCount, moveCount);
    }
    
}

void partition(int *arr, int first, int last, int &pivotIdx, int &compCount, int &moveCount)
{

    int pivot = arr[first];

    moveCount++;

    int endS1 = first;
    int firstUnknown = first + 1;


    while (firstUnknown <=  last)
    {
        if (arr[firstUnknown] < pivot)
        {
            endS1++;
            swap(arr[firstUnknown], arr[endS1]);

            moveCount = moveCount + 3;
        }
        compCount++;
        firstUnknown++;
    }
    swap(arr[first], arr[endS1]); //swap is three moves
    moveCount = moveCount + 3;
    pivotIdx = endS1;
}

void swap(int &a, int &b)//swap functions requires three moves  
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *arr, const int size, int &compCount, int &moveCount) {
  for (int last = size-1; last >= 1; --last) {
    int largest = indexOfLargest(arr, last+1, compCount, moveCount);
    swap(arr[largest], arr[last]);
    moveCount = moveCount + 3;
  }
}

int indexOfLargest(int arr[], int size, int &compCount, int &moveCount) {
  int indexSoFar = 0; 
  for (int currentIndex=1; currentIndex<size;++currentIndex)
  {
    if (arr[currentIndex] > arr[indexSoFar]){
         indexSoFar = currentIndex;
         compCount++;
    }     
  }
  return indexSoFar;
}

void radixSort(int *arr, int size){
 
    int maximum = arr[0];
 
    for(int i=1;i<size;i++){
        maximum = max(maximum, arr[i]);
    }
 
    int digits = 0;
 
    while(maximum > 0){
        digits++;
        maximum /= 10;
    }
 

    for(int i=0;i<digits;i++){
 
        int power = pow(10, i);
        int new_array[size];
        int count[10];

        memset(count, 0, sizeof(count));
 
   
        for(int j=0;j<size;j++){
 
     
            int num = (arr[j]/power) % 10;
 
            count[num]++;
        }
 
        
        for(int j=1;j<10;j++){
            count[j] += count[j-1];
        }
 

        for(int j=size-1;j>=0;j--){
            int num = (arr[j]/power) % 10;
 
            new_array[count[num]-1] = arr[j];
            count[num]--;
        }
        for(int j=0;j<size;j++)
            arr[j] = new_array[j];
     
    }
 
           
}

void displayArray(const int *arr, const int size)
{
    for(int i = 0; i<size-1; i++)
    {
        if(i !=size -2)
            cout<< arr[i]<< ", ";
        else
            cout<< arr[i];
    }
    cout<<endl;

}


void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    
    for(int i = 0; i < size -1; i++)
    {
        arr1[i] = rand()%1000;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];

    }

}


void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    
    for(int i = 0; i < size -1; i++)
    {
         arr1[i] = rand()%1000;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];

    }
    int a = 0;
    int b = 0;
    quickSort(arr1, size, a, b );
    quickSort(arr2, size, a, b );
    quickSort(arr3, size, a, b );
    quickSort(arr4, size, a, b );

 

}


void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    
    for(int i = 0; i < size -1; i++)
    {
        arr1[i] = rand()%1000;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];

    }
    int a = 0;
    int b = 0;
    quickSort(arr1, size, a, b );
    quickSort(arr2, size, a, b );
    quickSort(arr3, size, a, b );
    quickSort(arr4, size, a, b );

     for (int low = 0, high = size - 1; low < high; low++, high--) {
        swap(arr1[low], arr1[high]);
        swap(arr2[low], arr1[high]);
        swap(arr3[low], arr1[high]);
        swap(arr4[low], arr1[high]);
    }

    
}


void performanceAnalysis()
{

    //Declaring pointers
    int *arrS_random1 , *arrM_random1 , *arrQ_random1, *arrR_random1, *arrS_random2, *arrM_random2, *arrQ_random2, *arrR_random2, *arrS_random3
    , *arrM_random3, *arrQ_random3, *arrR_random3, *arrS_random4, *arrM_random4, *arrQ_random4, *arrR_random4, *arrS_random5, *arrM_random5
    , *arrQ_random5, *arrR_random5, *arrS_random6, *arrM_random6, *arrQ_random6, *arrR_random6, *arrS_random7 , *arrM_random7, *arrQ_random7, 
    *arrR_random7;

    int *arrS_ascending1 , *arrM_ascending1 , *arrQ_ascending1, *arrR_ascending1, *arrS_ascending2, *arrM_ascending2, *arrQ_ascending2, *arrR_ascending2, *arrS_ascending3
    , *arrM_ascending3, *arrQ_ascending3, *arrR_ascending3, *arrS_ascending4, *arrM_ascending4, *arrQ_ascending4, *arrR_ascending4, *arrS_ascending5, *arrM_ascending5
    , *arrQ_ascending5, *arrR_ascending5, *arrS_ascending6, *arrM_ascending6, *arrQ_ascending6, *arrR_ascending6, *arrS_ascending7 , *arrM_ascending7, *arrQ_ascending7, 
    *arrR_ascending7;

    int *arrS_descending1 , *arrM_descending1 , *arrQ_descending1, *arrR_descending1, *arrS_descending2, *arrM_descending2, *arrQ_descending2, *arrR_descending2, *arrS_descending3
    , *arrM_descending3, *arrQ_descending3, *arrR_descending3, *arrS_descending4, *arrM_descending4, *arrQ_descending4, *arrR_descending4, *arrS_descending5, *arrM_descending5
    , *arrQ_descending5, *arrR_descending5, *arrS_descending6, *arrM_descending6, *arrQ_descending6 , *arrR_descending6, *arrS_descending7 , *arrM_descending7, *arrQ_descending7, 
    *arrR_descending7;


    int compCount=0;
    int moveCount=0;
    clock_t startTime;
    double duration;

    createRandomArrays(arrS_random1, arrM_random1, arrQ_random1, arrR_random1, 6000);
    createRandomArrays(arrS_random2, arrM_random2, arrQ_random2, arrR_random2, 10000);
    createRandomArrays(arrS_random3, arrM_random3, arrQ_random3, arrR_random3, 14000);
    createRandomArrays(arrS_random4, arrM_random4, arrQ_random4, arrR_random4, 18000);
    createRandomArrays(arrS_random5, arrM_random5, arrQ_random5, arrR_random5, 22000);
    createRandomArrays(arrS_random6, arrM_random6, arrQ_random6, arrR_random6, 26000);
    createRandomArrays(arrS_random7, arrM_random7, arrQ_random7, arrR_random7, 30000);

    createAscendingArrays(arrS_ascending1, arrM_ascending1, arrQ_ascending1, arrR_ascending1, 6000);
    createAscendingArrays(arrS_ascending2, arrM_ascending2, arrQ_ascending2, arrR_ascending2, 10000);
    createAscendingArrays(arrS_ascending3, arrM_ascending3, arrQ_ascending3, arrR_ascending3, 14000);
    createAscendingArrays(arrS_ascending4, arrM_ascending4, arrQ_ascending4, arrR_ascending4, 18000);
    createAscendingArrays(arrS_ascending5, arrM_ascending5, arrQ_ascending5, arrR_ascending5, 22000);
    createAscendingArrays(arrS_ascending6, arrM_ascending6, arrQ_ascending6, arrR_ascending6, 26000);
    createAscendingArrays(arrS_ascending7, arrM_ascending7, arrQ_ascending7, arrR_ascending7, 30000);
     
    createDescendingArrays(arrS_descending1, arrM_descending1, arrQ_descending1, arrR_descending1, 6000);
    createDescendingArrays(arrS_descending2, arrM_descending2, arrQ_descending2, arrR_descending2, 10000);
    createDescendingArrays(arrS_descending3, arrM_descending3, arrQ_descending3, arrR_descending3, 14000);
    createDescendingArrays(arrS_descending4, arrM_descending4, arrQ_descending4, arrR_descending4, 18000);
    createDescendingArrays(arrS_descending5, arrM_descending5, arrQ_descending5, arrR_descending5, 22000);
    createDescendingArrays(arrS_descending6, arrM_descending6, arrQ_descending6, arrR_descending6, 26000);
    createDescendingArrays(arrS_descending7, arrM_descending7, arrQ_descending7, arrR_descending7, 30000);

    
    

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Selection Sort(Random)"<<endl;
    cout << "Array Size\t\tElapsed Time\t\tcompCount\t\tmoveCount"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_random1, 6000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount= 0, moveCount = 0;


    cout << "8000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_random2, 8000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "10000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_random3, 10000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;




    cout << "14000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_random4, 14000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "18000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_random5, 18000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "22000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_random6, 22000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "30000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_random7, 30000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Selection Sort(Ascending)"<<endl;
    cout << "Array Size\t\tElapsed Time\t\tcompCount\t\tmoveCount"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_ascending1, 6000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "8000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_ascending2, 8000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "10000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_ascending3, 10000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "14000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_ascending4, 14000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "18000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_ascending5, 18000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "22000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_ascending6, 22000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t        "<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "30000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_ascending7, 30000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Selection Sort(Descending)"<<endl;
    cout << "Array Size\t\tElapsed Time\t\tcompCount\t\tmoveCount"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_descending1, 6000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "8000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_descending2, 8000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "10000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_descending3, 10000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "14000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_descending4, 14000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "18000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_descending5, 18000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "22000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_descending6, 22000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "30000"<<"\t\t";
    startTime = clock();
    selectionSort(arrS_descending7, 30000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Merge Sort(Random)"<<endl;
    cout << "Array Size\t\tElapsed Time\t\tcompCount\t\tmoveCount"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_random1, 6000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "8000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_random2, 8000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "10000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_random3, 10000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "14000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_random4, 14000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "18000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_random5, 18000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "22000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_random6, 22000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;


   


    cout << "30000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_random7, 30000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Merge Sort(Ascending)"<<endl;
    cout << "Array Size\t\tElapsed Time\t\tcompCount\t\tmoveCount"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_ascending1, 6000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "8000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_ascending2, 8000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "10000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_ascending3, 10000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "14000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_ascending4, 14000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "18000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_ascending5, 18000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "22000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_ascending6, 22000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "30000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_ascending7, 30000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Merge Sort(Descending)"<<endl;
    cout << "Array Size\t\tElapsed Time\t\tcompCount\t\tmoveCount"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_descending1, 6000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "8000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_descending2, 8000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "10000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_descending3, 10000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "14000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_descending4, 14000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "18000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_descending5, 18000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    

    compCount = 0, moveCount = 0;

    cout << "22000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_descending6, 22000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "30000"<<"\t\t";
    startTime = clock();
    mergeSort(arrM_descending7, 30000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Quick Sort(Random)"<<endl;
    cout << "Array Size\t\tElapsed Time\t\tcompCount\t\tmoveCount"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    

    quickSort(arrQ_random1, 6000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "8000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_random2, 8000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "10000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_random3, 10000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "14000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_random4, 14000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "18000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_random5, 18000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "22000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_random6, 22000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "30000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_random7, 30000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Quick Sort(Ascending)"<<endl;
    cout << "Array Size\t\tElapsed Time\t\tcompCount\t\tmoveCount"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_ascending1, 6000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "8000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_ascending2, 8000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "10000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_ascending3, 10000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "14000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_ascending4, 14000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "18000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_ascending5, 18000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "22000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_ascending6, 22000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "30000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_ascending7, 30000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Quick Sort(Descending)"<<endl;
    cout << "Array Size\t\tElapsed Time\t\tcompCount\t\tmoveCount"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_descending1, 6000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "8000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_descending2, 8000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;
    
    compCount = 0, moveCount = 0;

    cout << "10000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_descending3, 10000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "14000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_descending4, 14000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "18000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_descending5, 18000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "22000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_descending6, 22000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "30000"<<"\t\t";
    startTime = clock();
    quickSort(arrQ_descending7, 30000, compCount, moveCount);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<compCount<<"\t\t"<<moveCount<<endl;

    compCount = 0, moveCount = 0;

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Radix Sort(Random)"<<endl;
    cout << "Array Size\t\tElapsed Time"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_random1, 6000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;
    
    

    cout << "8000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_random2, 8000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;
    
    

    cout << "10000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_random3, 10000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "14000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_random4, 14000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "18000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_random5, 18000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "22000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_random6, 22000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "30000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_random7, 30000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Radix Sort(Ascending)"<<endl;
    cout << "Array Size\t\tElapsed Time"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_ascending1, 6000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;
    
    

    cout << "8000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_ascending2, 8000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;
    
    

    cout << "10000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_ascending3, 10000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "14000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_ascending4, 14000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "18000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_ascending5, 18000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "22000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_ascending6, 22000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "30000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_ascending7, 30000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "-----------------------------------------------------"<<endl;
    cout << "Analysis of Radix Sort(Descending)"<<endl;
    cout << "Array Size\t\tElapsed Time"<<endl;
    cout << "6000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_descending1, 6000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;
    
    

    cout << "8000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_descending2, 8000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;
    
    

    cout << "10000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_descending3, 10000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "14000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_descending4, 14000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "18000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_descending5, 18000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "22000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_descending6, 22000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;

    

    cout << "30000"<<"\t\t";
    startTime = clock();
    radixSort(arrR_descending7, 30000);
    duration = (1000 * double( clock() - startTime ) / CLOCKS_PER_SEC );
    cout<<"\t"<<duration <<" ms\t\t\t"<<endl;




    delete arrS_random1 , arrM_random1 , arrQ_random1, arrR_random1, arrS_random2, arrM_random2, arrQ_random2, arrR_random2, arrS_random3
    , arrM_random3, arrQ_random3, arrR_random3, arrS_random4, arrM_random4, arrQ_random4, arrR_random4, arrS_random5, arrM_random5
    , arrQ_random5, arrR_random5, arrS_random6, arrM_random6, arrQ_random6, arrR_random6, arrS_random7 , arrM_random7, arrQ_random7, 
    arrR_random7;

    delete arrS_ascending1 , arrM_ascending1 , arrQ_ascending1, arrR_ascending1, arrS_ascending2, arrM_ascending2, arrQ_ascending2, arrR_ascending2, arrS_ascending3
    , arrM_ascending3, arrQ_ascending3, arrR_ascending3, arrS_ascending4, arrM_ascending4, arrQ_ascending4, arrR_ascending4, arrS_ascending5, arrM_ascending5
    , arrQ_ascending5, arrR_ascending5, arrS_ascending6, arrM_ascending6, arrQ_ascending6, arrR_ascending6, arrS_ascending7 , arrM_ascending7, arrQ_ascending7, 
    arrR_ascending7;

    delete arrS_descending1 , arrM_descending1 , arrQ_descending1, arrR_descending1, arrS_descending2, arrM_descending2, arrQ_descending2, arrR_descending2, arrS_descending3
    , arrM_descending3, arrQ_descending3, arrR_descending3, arrS_descending4, arrM_descending4, arrQ_descending4, arrR_descending4, arrS_descending5, arrM_descending5
    , arrQ_descending5, arrR_descending5, arrS_descending6, arrM_descending6, arrQ_descending6 , arrR_descending6, arrS_descending7 , arrM_descending7, arrQ_descending7, 
    arrR_descending7;


    

    
}