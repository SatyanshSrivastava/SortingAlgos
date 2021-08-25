#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10000

int arr[size - 1];
int rev_arr[size - 1];
int sort_arr[size - 1];

void reverse241()
{
    int j = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        rev_arr[j] = arr[i];
        j++;
    }
}

void quicksort241(int number[], int first, int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort241(number,first,j-1);
      quicksort241(number,j+1,last);

   }
}

void sorted()
{
    for (int i = 0; i < size - 1; i++)
    {
        sort_arr[i] = arr[i];
    }
}

int main()
{
    clock_t start, end;
    double time1, time2, time3;

    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = rand() % 100;
    }

    //Time calculation for random array
    start = clock();
    quicksort241(arr, 1, size - 1);
    end = clock();
    time1 = end - start / 1000;

    //Time calculation for sorted array
    sorted();
    start = clock();
    quicksort241(sort_arr, 1, size - 1);
    end = clock();
    time2 = end - start / 1000;

    //Time calculation for reverse array
    reverse241();
    start = clock();
    quicksort241(rev_arr, 1, size - 1);
    end = clock();
    time3 = end - start / 1000;

    printf("\nRandom array time= %fms\n\nSorted array time= %fms \n\nReverse array time= %fms \n\n", time1, time2, time3);
}