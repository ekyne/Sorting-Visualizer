/* Author: 	Kyle Gilmore
 * Date: 	March 18, 2022
 * Project: 	Sorting Visualizer
 * File: 	sorter.h
 * Function: 	Holds the Sorter class.
*/

#ifndef SORTER_H
#define SORTER_H
#include<SDL2/SDL.h>
#include "SDL_Manager.h"

class Sorter {
	public:
		void selectionSort(int[], int);
		void insertionSort(int[], int);
		void bubbleSort(int[], int);
		void heapSort(int[], int);
		void quickSort(int[], int, int, int);
		void merge(int[], int, int, int, int);
		void mergeSort(int[], int, int, int);
		void genRandomBars(int[], int);
		int partition(int[], int, int, int);
		void heapify(int[], int, int, int[], int);

		void setFinished(bool targetFinished){finished = targetFinished;}
		void setSDLManager(SDL_Manager* targetImg){img = targetImg;}
		bool getFinished(){return finished;}
		SDL_Manager* getSDLManager(){return img;}
	private:
		SDL_Manager* img;
		bool finished = false;
};

#endif
