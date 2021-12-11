/**
1) Initialize the first as 0(i.e, index of arr[0] element
2) Start traversing the array from array[1],
   a) If the current element in array say arr[i] is greater
      than first. Then update first and second as,
      second = first
      first = arr[i]
   b) If the current element is in between first and second,
      then update second to store the value of current variable as
      second = arr[i]
3) Return the value stored in second.
*/

// C program to find second largest
// element in an array

#include <limits.h>
#include <stdio.h>

/* Function to print the second largest elements */
void print2largest(int arr[], int arr_size)
{
	int i, first, second;

	/* There should be atleast two elements */
	if (arr_size < 2) {
		printf(" Invalid Input ");
		return;
	}

	first = second = INT_MIN;
	for (i = 0; i < arr_size; i++) {
		/* If current element is greater than first
		then update both first and second */
		if (arr[i] > first) {
			second = first;
			first = arr[i];
		}

		/* If arr[i] is in between first and
		second then update second */
		else if (arr[i] > second && arr[i] != first)
			second = arr[i];
	}
	if (second == INT_MIN)
		printf("There is no second largest element\n");
	else
		printf("The second largest element is %dn", second);
}

/* Driver program to test above function */
int main()
{
	int arr[] = { 12, 35, 1, 10, 34, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	print2largest(arr, n);
	return 0;
}
