/* Author: 	Kyle Gilmore
 * Date: 	March 18, 2022
 * Project: 	Sorting Visualizer
 * File: 	sorter.cpp
 * Function: 	Holds functions used by the Sorter class.
*/

#include "sorter.h"

// compares the incrementing j to the minimum indesx value, and sets it to i
void Sorter::selectionSort(int anArray[], int arraySize){
	int maxIndex;

	for(int i = 0; i < arraySize - 1; i++){
		maxIndex = i;
		for(int j = i + 1; j < arraySize; j++){
			if(anArray[j] > anArray[maxIndex]){
				maxIndex = j;
			}
		}
		std::swap(anArray[maxIndex],anArray[i]);
		SDL_Delay(20);
		img->getVisual(i,maxIndex,-1,anArray,arraySize,getFinished());
	}
	setFinished(true);
}

// compares the decrementing j to the key, and sets j to key if the key is less than j
void Sorter::insertionSort(int anArray[], int arraySize){
	int i, j, key;
	for(i = 1;i < arraySize; i++){
		key = anArray[i];
		j = i - 1;
		while(j >= 0 && anArray[j] < key){
			anArray[j+1] = anArray[j];
			j = j - 1;
		}
		anArray[j+1] = key;
		SDL_Delay(20);
		img->getVisual(key,anArray[j],-1,anArray,arraySize,getFinished());	
	}
	setFinished(true);
}

// swaps values with an incrementing j's neighbor index if j's is less than its neighbor's value, incrementing i
void Sorter::bubbleSort(int anArray[], int arraySize){
	int i, j;
	bool swapped;
	for(i = 0; i < arraySize-1; i++){
		swapped = false;
		for(j = 0; j < arraySize-i-1; j++){
			if(anArray[j] < anArray[j+1]){
				std::swap(anArray[j],anArray[j+1]);
				swapped = true;
				img->getVisual(j+1,j,-1,anArray,arraySize,getFinished());
			}
		}
		if(swapped == false){
			break;
		}
	}
	setFinished(true);
}

// partitions the portions of the array recursively passed in by Quick Sort
int Sorter::partition(int anArray[], int arraySize, int low, int high){ 
    	int pivot = anArray[low]; 
    	int i = (high + 1); 

    	for (int j = high; j > low; j--){ 
        	if (anArray[j] < pivot){ 
            	i--;
		std::swap(anArray[i], anArray[j]);
	    	SDL_Delay(5);
    	    	img->getVisual(i,j,-1,anArray,arraySize,getFinished());
        	} 
    	} 
	std::swap(anArray[i-1], anArray[low]);
    	SDL_Delay(5);
    	img->getVisual(i+1,high,-1,anArray,arraySize,getFinished());
    	return (i - 1); 
}

// recursively calls itself with divided subarray of the predecessor array
void Sorter::quickSort(int anArray[], int arraySize, int low, int high){ 
    	if (low < high){
       		int pi = partition(anArray,arraySize, low, high); 

        	quickSort(anArray,arraySize, low, pi - 1); 
        	quickSort(anArray,arraySize, pi + 1, high); 
    	} 
} 

// finds the smaller value between the given root and its children, and swaps their values if the smallest node is not the root
void Sorter::heapify(int anArray[], int arraySize, int i, int theArray[], int theSize){
    	int smallest = i;
    	int l = 2 * i + 1;
    	int r = 2 * i + 2;
 
	if (l < arraySize && anArray[l] < anArray[smallest])
        smallest = l;
 
    	if (r < arraySize && anArray[r] < anArray[smallest])
        smallest = r;
 
    	if (smallest != i) {
	std::swap(anArray[i], anArray[smallest]);
	SDL_Delay(5);
	img->getVisual(arraySize,i,smallest,theArray,theSize,getFinished());

        heapify(anArray, arraySize, smallest,theArray,theSize);
    }
}
 
// recursively calls heapify to build the heap based on minimum values placed at the top
void Sorter::heapSort(int anArray[], int arraySize){

    	//builds the heap
    	for (int i = arraySize / 2 - 1; i >= 0; i--){
        	heapify(anArray, arraySize, i,anArray,arraySize); 
    		SDL_Delay(10);
		img->getVisual(i,-1,-1,anArray,arraySize,getFinished());
    	}

    	// extracts a node from the heap
    	for (int i = arraySize - 1; i >= 0; i--) {
		std::swap(anArray[0], anArray[i]);
 
        heapify(anArray, i, 0,anArray,arraySize);
  	}
}

// places sorted elements of a predescessing array into another array, and uses the latter array to rebuild the former in a sorted form
void Sorter::merge(int anArray[],int arraySize, int start, int mid, int end){
	//int lSub = mid - start + 1;
	//int rSub = end - mid;
	int pArray[(end-start)+1];
	int lIndex = start;
	int rIndex = mid+1;
	int mIndex = 0;

	while(lIndex <= mid && rIndex <= end){
		if(anArray[lIndex] >= anArray[rIndex]){
			pArray[mIndex] = anArray[lIndex];
			SDL_Delay(5);
			img->getVisual(lIndex,rIndex,-1,anArray,arraySize,getFinished());
			lIndex++;
		}
		else{
			pArray[mIndex] = anArray[rIndex];
			SDL_Delay(5);
			img->getVisual(lIndex,rIndex,-1,anArray,arraySize,getFinished());
			rIndex++;
		}
		mIndex++;
	}
	while(lIndex <= mid){
		pArray[mIndex] = anArray[lIndex];
		SDL_Delay(5);
		img->getVisual(-1,lIndex,-1,anArray,arraySize,getFinished());
		lIndex++;
		mIndex++;
	}
	while(rIndex <= end){
		pArray[mIndex] = anArray[rIndex];
		SDL_Delay(5);
		img->getVisual(-1,rIndex,-1,anArray,arraySize,getFinished());
		rIndex++;
		mIndex++;
	}
	int x = 0;
	for(int i = start; i <= end; i++){
		anArray[i] = pArray[x];
		img->getVisual(i,-1,-1,anArray,arraySize,getFinished());
		x++;
	}
}

// recursively calls itself, and then merges once subarray portions are as small as possible
void Sorter::mergeSort(int anArray[],int arraySize, int start, int end){
	if( start >= end){
		return;
	}
	int mid = start + (end - start) / 2;
	mergeSort(anArray,arraySize,start,mid);
	mergeSort(anArray,arraySize,mid+1,end);
	merge(anArray,arraySize,start,mid,end);
}



// generates bars with random heights in the array
void Sorter::genRandomBars(int anArray[], int arraySize){
	srand(time(NULL));
	for(int i = 0; i < arraySize; i++){
		int height = rand() % img->getScreenHeight();
		anArray[i] = height;
	}
}
