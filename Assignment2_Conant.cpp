/****************************
 * Name: Riley Conant	
 * Date Completed: 9/16/19
 * Function: Sorts the arr of user entered information. Will do a bubble sort and an insertion sort.
 * Input: 10 numbers for the array that vary depending on what the user inputs
 * Output: The array in its unsorted manner and the array sorted either by a bubble sort or insertion sort both of which will sort the array into least to greatest
 * Additional Comments: The program is able to do both the insertion sort and bubble sort. The sort that the user does not want to use must have the call to its f
 * function commented out so that the intended sort will be used.
 * *************************/
#include <cstdlib>
#include <iostream>

using namespace std;
//Prototypes of the sort functions, the reading of the array, the printing and the binary search 
void bubbleSort(int[] ,int);
void insertionSort(int[],int);
int search(int[],int,int);
void readData(int[] , int);
void printData(int[] , int);
int bSearch(int[],int,int);
int main (int argc, char **argv){
	//Initializing the array with 10 empty spots 
	int arr[10]= {};
	int element, element2;
	//Determines the size of the array so that it can be used in the sorts	
	int size = sizeof(arr)/sizeof(arr[0]);
	//Call to function that will populate the array
	readData(arr,size);
	//Prints the array unsorted
	cout << "Array before sorting: ";
	printData(arr,size);
	//A regular search of the array while unsorted
	cout << "Enter a value from the array that you would like to search for: " << endl;
	cin >> element;
	//Print out the index of the element
	cout << "The index of your value is " << search(arr,size, element) << ". (if it is -1 the value is not in the array)" << endl;
	//Sorts the array based on which one isnt commented out 
	//bubbleSort(arr, size);
	insertionSort(arr,size);
	//Prints the sorted array
	cout << "Array after sorting: ";
	printData(arr,size);
	//A binary search of the array after it has been sorted 
	cout << "Enter a value from the array that you would like to do a binary search for: " << endl;
	cin >> element2;
	//Print out the index of the element
	cout << "The index of your value is " << bSearch(arr,size, element2) << ". (if it is -1 the value is not in the array)" << endl;
	
}
//Function to print the data, iterates through the whole array while printing each element 
void printData(int arr[], int size)
{
	for(int j = 0; j < 10; j++)
		{
		cout << arr[j] << " ";
		} 
	cout << endl;
}
//Function that prompts the user to enter the numbers they want for the array elements
void readData(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "Enter element arr[" << i << "]:" << endl;
		cin >> arr[i];
	}
}
//Bubble Sort
void bubbleSort(int arr[], int size)
	{
		for(int i = 0; i <= size-2;i++)
		{
			//For the indicated index i the element will go through the rest of the array using j as the indexes in the array then will go back to the next i after
			//the j reaches the end of the array.
			for(int j = 0; j <= size-2;j++)
			{
				//Switches the elements if the element to the right is smaller than the one to the left so that it can go from least to greatest
				if(arr[j] > arr[j+1])
				{
					int temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}	
			}
		}
	} 
//Insertion Sort
void insertionSort(int arr[], int size)
{
	for(int i = 0; i <= size-1; i++)
	{
		//Copys the index so that the while loop can keep the switching of elements within bounds
		int j = i;
		while((j>0) && (arr[j] < arr[j-1]))
		{
			//Switches the elements until element reaches the left most part of the array or the element to its left is not smaller than it 
			int temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j = j-1;
		}
	}
}
//Search Function
int search(int arr[], int size, int element)
{
	//Iterates through the array and if the value is equal to the element
	for(int i = 0; i <= size-1; i++)
	{
		if(arr[i] == element)
		{
			return i;
		}
	} 
	return -1;
}
//Binary Search
int bSearch(int arr[], int size, int element)
{

	int low = 0;
	int high = size -1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid]>element)
		{
			high = mid-1;
		}
		else if(arr[mid]<element)
		{
			low = mid-1;
		}
		else 
		{
			return mid;
		}	
	}
	return -1;
}
