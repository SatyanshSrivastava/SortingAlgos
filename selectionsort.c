#include <stdio.h>
#include <time.h>
void
reverseArray_241 (int arr[], int start, int end)	//function to reverse the array
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


int
main ()
{
  clock_t beg_241, end_241;
  int array[1000000], n, i, j, swap, position;

  printf ("Enter number of elements\n");
  scanf ("%d", &n);

  for (i = 0; i < n; i++)
    array[i] = rand () % 1000000;	//generating numbers less than 1 million

  //printf("generated elements are: \n");
  //for (i = 0; i < n; i++)
  //printf(" %d \n", array[i]);
//SORTING THE NORMAL ARRAY
for (int b=n;b<=100000;b=b+10000) {
    printf("printing for number of elements = %d \n", b);
  beg_241 = clock ();
  for (i = 0; i < n - 1; i++)
    {
      position = i;
      for (j = i + 1; j < n; j++)
	{
	  if (array[position] > array[j])
	    position = j;
	}
      if (position != i)
	{
	  swap = array[i];
	  array[i] = array[position];
	  array[position] = swap;
	}
    }
  end_241 = clock ();
  printf ("(WORST CASE) Time taken to sort UNSORTED ARRAY using selection sort is %.2f \n",
	  difftime (end_241, beg_241));
//printf("Sorted array\n");
//for (i = 0; i < n; i++)
//    printf(" %d \n", array[i]);
beg_241 = clock ();
  for (i = 0; i < n - 1; i++)
    {
      position = i;
      for (j = i + 1; j < n; j++)
	{
	  if (array[position] > array[j])
	    position = j;
	}
      if (position != i)
	{
	  swap = array[i];
	  array[i] = array[position];
	  array[position] = swap;
	}
    }
  end_241 = clock ();
  printf ("(BEST WORST) Time taken to sort SORTED ARRAY using selection sort is %.2f \n",
	  difftime (end_241, beg_241));

//printf("Reversing the array\n");
  reverseArray_241 (array, 0, n - 1);
//for (i = 0; i < n; i++)
  //  printf(" %d \n", array[i]);


//SORTING THE REVERSED ARRAY
//printf("Sorting the REVERSED ARRAY again using bubble sort\n");
  beg_241 = clock ();
  for (i = 0; i < n - 1; i++)
    {
      position = i;
      for (j = i + 1; j < n; j++)
	{
	  if (array[position] > array[j])
	    position = j;
	}
      if (position != i)
	{
	  swap = array[i];
	  array[i] = array[position];
	  array[position] = swap;
	}
    }
  end_241 = clock ();
  printf("(AVERAGE CASE)Time taken to sort the REVERSED ARRAY using selection sort is %.2f \n", difftime (end_241, beg_241));
//printf("Sorted array\n");
//for (i = 0; i < n; i++)
  //   printf(" %d \n", array[i]);
}

  return 0;
}