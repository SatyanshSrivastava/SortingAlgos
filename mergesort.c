#include <stdio.h>
#include <time.h>
void reverseArray_241 (int arr[], int start, int end)	//function to reverse the array
{
  int temp_241;
  while (start < end)
    {
      temp_241 = arr[start];
      arr[start] = arr[end];
      arr[end] = temp_241;
      start++;
      end--;
    }
}

void mergeSort (int arr[], int l, int r)
{

  if (l < r)
    {
      int mid = (l + r) / 2;
      mergeSort (arr, l, mid);
      mergeSort (arr, mid + 1, r);
      merge (arr, l, mid, r);
    }
}

void merge (int arr[], int l, int mid, int r)
{
  int b[r];
  int i = l;
  int j = mid + 1;
  int k = l;
  while (i <= mid && j <= r)
    {
      if (arr[i] < arr[j])
	{
	  b[k] = arr[i];
	  i++;
	}
      else
	{
	  b[k] = arr[j];
	  j++;
	}
      k++;
      if (i > mid)
	{			//means i is overflowing
	  while (j <= r)
	    {
	      b[k] = arr[j];
	      k++, j++;
	    }
	}
      else if (j > r)
	{
	  while (i <= mid)
	    {
	      b[k] = arr[i];
	      k++, i++;
	    }
	}


    }
  for (k = l; k <= r; k++)
    {
      arr[k] = b[k];
    }

}


int main ()
{
  clock_t beg_241, end_241;
  int array[10000], n, i, j, swap, position;
  for (int b = 0; b <= 9; b = b + 1)	//running the for loop to print the numbers for the given range.
  {
    printf ("Enter number of elements\n");
  scanf ("%d", &n);
  printf ("printing for number of elements = %d \n", n);
  for (i = 0; i < n; i++)
    array[i] = rand () % 1000000;	//generating numbers less than 1 million
//printf("generated elements are: \n");
//for (i = 0; i < n; i++)
//printf(" %d \n", array[i]);
//SORTING THE NORMAL ARRAY
  beg_241 = clock ();
//here i will call the inputed jumbled array
  mergeSort (array, 0, n);
  end_241 = clock ();
  printf ("(WORST CASE) Time taken to sort UNSORTED ARRAY using selection sort is %f \n", difftime (end_241, beg_241));
//printf("Sorted array\n");
//for (i = 0; i < n; i++)
// printf(" %d \n", array[i]);
  beg_241 = clock ();
//here i will call the inputed sorted array
  mergeSort (array, 0, n);
  end_241 = clock ();
  printf("(BEST CASE) Time taken to sort SORTED ARRAY using selection sort is %f \n",difftime (end_241, beg_241));
//printf("Reversing the array\n");
  reverseArray_241 (array, 0, n - 1);
//for (i = 0; i < n; i++)
// printf(" %d \n", array[i]);
//SORTING THE REVERSED ARRAY
//printf("Sorting the REVERSED ARRAY again using bubble sort\n");
  beg_241 = clock ();
  mergeSort (array, 0, n);
  end_241 = clock ();
  printf("(AVERAGE CASE)Time taken to sort the REVERSED ARRAY using selection sort is %f \n", difftime (end_241, beg_241));
//printf("Sorted array\n");
//for (i = 0; i < n; i++)
// printf(" %d \n", array[i]);
}
return 0;
}
