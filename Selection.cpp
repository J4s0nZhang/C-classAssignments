

int maxLocation(const int data[], const int numElements)
{
  if(numElements < 0){
    return -1;
  }
  if(numElements == 0){
    return 0;
  }
  int location = 0;
  for(int i = 0; i < numElements; i++){
    if(data[location] < data[i]){
      location = i;
    }

  }

  return location;
}

int selectionSort(int data[], const int numElements)
{
  int maxlocation = 0;
  int count = numElements;
  int temp = 0;

  if(count < 0){
    return -1;
  }

  else if(numElements < 1){
    return 1;
  }
  else{
    maxlocation = maxLocation(data, count);
    temp = data[count-1];
    data[count-1] = data[maxlocation];
    data[maxlocation] = temp;
    count -= 1;
    return selectionSort(data, count);

  }
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
void printArray(const int data[], const int numElements) {
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
  while (i < sz) {
    /* 
     * random() returns long, but we convert to int here. If the
     * number is larger than what can fit in an int, what happens
     * depends on the compiler and machine. In this case, we'll
     * probably just lose the extra data. We don't care because we
     * still get an int's worth of random data. Be very careful about
     * doing this in other code.
     */
    data[i] = (int)random();
    ++i;
  }

  int maxIdx = maxLocation(data, sz); // call maxLocation() to test it
  bool correctMax = true;
  i = 0;
  while (i < sz) {
    if (data[i] > data[maxIdx])
      correctMax = false; // some other index was larger than maxIdx, this shouldn't happen
    ++i;
  }
  if (correctMax)
    cout << "maxLocation() appears to work" << endl;
  else
    cout << "maxLocation() doesn't appear to work" << endl;

  cout << "Array is: ";
  printArray(data, sz);

  int ret = selectionSort(data, sz); // sort the array

  cout << "After sorting, array is: ";
  printArray(data, sz);

  // check the return code
  if (ret < 0)
    cout << "selectionSort() indicated error" << endl;
  else if (ret > 0)
    cout << "selectionSort() indicated warning" << endl;

  return 0;
}


#endif
