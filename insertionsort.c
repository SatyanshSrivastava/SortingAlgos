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

void insertion241 (int arr[], int n)
{
  int i, key241, j;
  for (i = 1; i < n; i++)
    {
      key241 = arr[i];
      j = i - 1;

      while (j >= 0 && arr[j] > key241)
	{
	  arr[j + 1] = arr[j];
	  j = j - 1;
	}
      arr[j + 1] = key241;
    }
}

int main ()
{
  clock_t beg_241, end_241;
  int array[10000], n, i, j, swap, position;
for (int b = 0; b < 10; b = b +1)//running the for loop to print the numbers for the given range.
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
      insertion241 (array, n);

      end_241 = clock ();
      printf("(AVERAGE CASE) Time taken to sort UNSORTED ARRAY using selection sort is %.2f \n",
	 difftime (end_241, beg_241));
//printf("Sorted array\n");
//for (i = 0; i < n; i++)
//    printf(" %d \n", array[i]);
      beg_241 = clock ();
//here i will call the inputed sorted array
      insertion241 (array, n);
      end_241 = clock ();
      printf("(BEST CASE) Time taken to sort SORTED ARRAY using selection sort is %.2f \n",
	 difftime (end_241, beg_241));

//printf("Reversing the array\n");
      reverseArray_241 (array, 0, n - 1);
//for (i = 0; i < n; i++)
      //  printf(" %d \n", array[i]);


//SORTING THE REVERSED ARRAY
//printf("Sorting the REVERSED ARRAY again using bubble sort\n");
      beg_241 = clock ();
      insertion241 (array, n);
      end_241 = clock ();
      printf("(WOSRT CASE)Time taken to sort the REVERSED ARRAY using selection sort is %.2f \n",
	 difftime (end_241, beg_241));
//printf("Sorted array\n");
//for (i = 0; i < n; i++)
      //   printf(" %d \n", array[i]);
    }

  return 0;
}

