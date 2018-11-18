
int partition(int data[], const int lo, const int hi)
{
  if(lo < 0 or hi < 0 or hi <= lo){
    return -1;
  }
  int pivot = data[hi];
  int dataindex = lo;
  int pindex = lo;
  int temp = 0;

  while (dataindex < hi){
    if( data[dataindex] < pivot){
      temp = data[dataindex];
      data[dataindex] = data[pindex];
      data[pindex] = temp;
      pindex++;
    }
    dataindex++;

  }

  temp = data[pindex];
  data[pindex] = data[hi];
  data[hi] = temp;
  
  return pindex;
}


void quickSortHelper(int data[], const int lo, const int hi)
{
  if( hi - lo < 1){
    return;
  }
  else{
    int pivotindex = partition(data, lo, hi);
    if(pivotindex == -1){
      return;
    }
    quickSortHelper(data, lo , pivotindex -1);
    quickSortHelper(data, pivotindex+1, hi);
  }
}


int quickSort(int data[], const int numElements)
{
  if(numElements < 0){
    return -1;
  }
  else if(numElements < 1){
    return 1;
  }

  quickSortHelper(data, 0, numElements-1);
  return 0;
}


#ifndef MARMOSET_TESTING

/*
 * Marmoset doesn't see anything in here
 *
 * Use this space to test your code
 */

#include <iostream> // cout, endl
#include <stdlib.h> // srandom(), random()

using namespace std;

// print an array in comma separated format
void printArray(const int data[], const int numElements)
{
  int i = 0;
  while (i < numElements-1) {
    cout << data[i] << ", ";
    ++i;
  }
  cout << data[numElements-1] << endl;
}


int main(void)
{
  int sz = 10; // array size

  srandom(0);  // deterministic seed for random()
               // change 0 to a different number to get a different random array 

  int data[sz];
  int i = 0;
  while (i < sz) { // fill array with random values
    data[i] = (int)random();
    ++i;
  }

  cout << "Array is: ";
  printArray(data, sz);

  int ret = quickSort(data, sz); // sort the array

  cout << "After sorting, array is: ";
  printArray(data, sz);

  // check the return code
  if (ret < 0)
    cout << "quickSort() indicated error" << endl;
  else if (ret > 0)
    cout << "quickSort() indicated warning" << endl;

  return 0;
}


#endif
