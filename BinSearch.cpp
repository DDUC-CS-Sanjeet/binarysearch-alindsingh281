#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
  if(startIndex>lastIndex)
      return false;
  else
  {
      int mid=(startIndex+lastIndex)/2;
      if(array[mid]==element)
          return true;
      else if(array[mid]>element)
          binarySearchReacursive(array, startIndex, mid-1, element);
      else
          binarySearchReacursive(array, mid+1, lastIndex, element);
  }
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
  while(startIndex<=lastIndex)
  {
    int mid = (startIndex+lastIndex)/2;
    if(array[mid] == element)
        return true;
    else if(array[mid] < element)
        startIndex = mid+1;
    else if(array[mid] > element)
        lastIndex = mid-1;
   }
   if(startIndex>lastIndex)
        return false;
}

int main()
{
 int size = 0, num = 0;
 bool result1 = false,result2 = false;
 cout<<"Enter the size of Array: \n";
 cin>>size;
 int *arr = new int[size];
 cout<<"Enter array elements. \n";
 for(int i=0; i<size; i++)
     cin>>arr[i];
 sort(arr, arr+size);
 cout<<"Enter the element to be searched: ";
 cin>>num;
 result1 = binarySearchIterative(arr, 0, size-1, num);
 result2 = binarySearchReacursive(arr, 0, size-1, num);
 if(result1 == true)
     cout<<num<<"Element found.\n";
 else
     cout<<"Element not found!\n";
 if(result2 == true)
     cout<<num<<"Element found.\n";
 else
     cout<<"Element not found!\n";
 delete[] arr;
 return 0;
}
