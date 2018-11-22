

int mode(const int dataset[], const int size, int modes[])
{
  if(size < 0){
    return -1;
  }
  if(size == 1 or size == 0){
    return 0;
  }
  int data[size];
  int count = 1;
  int maxcount = 1;
  int index = 0;

  for(int i = 0; i < size; i++){ //set data equal to dataset
    data[i] = dataset[i];
  }

  int tmp = 0;
  for(int i = 0; i < size-1; i++){
    for(int j =0; j < size-i-1;j++){
      if(data[j+1] < data[j]){
        tmp = data[j];
        data[j] = data[j+1];
        data[j+1] = tmp;

      }
    }
  }
  
  for(int x = 0; x < size-1; x++){
    if(data[x] == data[x+1]){
      count++;
    }

    if(data[x] != data[x+1] or x+1 == size-1){
      if(count > maxcount){
        maxcount = count;
        index = 0;
        modes[index] = data[x];

      }
      else if(count == maxcount){
        index++;
        modes[index] = data[x];
        
      }
      count = 1;
    }

  }
  
  return ++index;
}


#ifndef MARMOSET_TESTING

/*
 * Marmoset doesn't see anything in here
 *
 * Use this space to test your code
 */

#include <cstdlib>  // atoi
#include <iostream> // cout, endl

using namespace std;

#define MIN_ARGS 2

int main(const int argc, const char* const argv[])
{
  if (argc < MIN_ARGS)              // not enough inputs
    return -1;

  int sz = argc - 1;                // 1 for name
  int input[sz];                    // to hold inputs

  for (int i = 0; i < sz; ++i)      // loop over all inputs, store in array
    input[i] = atoi(argv[i + 1]);   // atoi = string to integer

  int modes[sz];                    // there will be at most as many modes
                                    // as there are numbers

  int ret = mode(input, sz, modes); // call the function

  cout << "Function returned: " << ret << " modes" << endl;

  cout << "Modes were:";
  for (int i = 0; i < ret; ++i)     // loop over and print all modes
    cout << ' ' << modes[i];
  cout << endl;

  return 0;
}

#endif
