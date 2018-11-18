
int binarySearchHelper(const int data[], const int start, const int end, const int numberToFind){
	
	if(end >= start){
		int midindex = start+ (end-start)/2; 


		if(data[midindex] == numberToFind){
			return midindex;
		}
		if(data[midindex] > numberToFind){
			return binarySearchHelper(data, start, midindex-1, numberToFind);
		}
		
		return binarySearchHelper(data, midindex+1, end, numberToFind);
		
	}


	return -1;
 
}

int binarySearch(const int data[],const int numElements,const int numberToFind){

	if(numElements < 0){
		return -1;
	}
	if(numElements == 0){
		return 1;
	}

	return binarySearchHelper(data, 0, numElements-1, numberToFind);
}

