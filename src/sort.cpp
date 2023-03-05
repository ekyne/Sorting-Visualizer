/* Author: 	Kylie Gilmore
 * Date: 	March 18, 2022
 * Project: 	Sorting Visualizer
 * File: 	sort.cpp
 * Function: 	Main Driver of the Sorting Visualizer Project.
*/

#include<SDL2/SDL.h>
#include<iostream>
#include<time.h>
#include "sorter.h"
#include "SDL_Manager.h"

// main function of the program, prompts for user input for algorithm selection
int main(){
	Sorter sort;
	SDL_Manager* sortImg = new SDL_Manager();
	SDL_Event event;
	sort.setSDLManager(sortImg);
	int arraySize;
	int bWidth;

	std::cout << "Welcome to the Sorting Visualization program using SDL2!" << std::endl;
	std::cout << "\n"

	// bar width is entered here
	<< "Enter the bar width (6 is recommended): ";
	std::cin >> bWidth;
	sort.getSDLManager()->setBarWidth(bWidth);
	arraySize = sort.getSDLManager()->getScreenWidth() / sort.getSDLManager()->getBarWidth();
	int anArray[arraySize];
	sort.getSDLManager()->init();

	// beginning of algorithhm selections and executions
	std::cout << "\n" 
	<< "Press 1 for the Insertion Sort algorithm.\n"
	<< "Press 2 for the Selection Sort algorithm.\n"
	<< "Press 3 for the Bubble Sort algorithm.\n"
	<< "Press 4 for the Quick Sort algorithm.\n"
	<< "Press 5 for the Heap Sort algorithm.\n"
	<< "Press 6 for the Merge Sort algorithm.\n"
	<< "Press Q to quit.\n"
	<< "\n";

	// loops through the selection until the user exits
	while(SDL_WaitEvent(&event)){
		if(event.type == SDL_KEYDOWN){
			const Uint8* state = SDL_GetKeyboardState(NULL);
			
			// user keystroke is prompted, if key is 0 the user exits the program
			if(state[SDL_SCANCODE_Q]){
				sortImg = nullptr;
			       	exit(0);
			}
			if(state[SDL_SCANCODE_1]){
				sort.genRandomBars(anArray,arraySize);
				sort.insertionSort(anArray,arraySize);
				sort.getSDLManager()->getVisual(0,0,0,anArray,arraySize,sort.getFinished());
				sort.setFinished(false);
			}
			if (state[SDL_SCANCODE_2]){
				sort.genRandomBars(anArray,arraySize);
				sort.selectionSort(anArray,arraySize);
				sort.getSDLManager()->getVisual(0,0,0,anArray,arraySize,sort.getFinished());
				sort.setFinished(false);
			} 
			if(state[SDL_SCANCODE_3]){
				sort.genRandomBars(anArray,arraySize);
				sort.bubbleSort(anArray,arraySize);
				sort.setFinished(true);
				sort.getSDLManager()->getVisual(0,0,0,anArray,arraySize,sort.getFinished());
				sort.setFinished(false);
			}
			if(state[SDL_SCANCODE_4]){
				sort.genRandomBars(anArray,arraySize);
				sort.quickSort(anArray,arraySize,0,arraySize-1);
				sort.setFinished(true);
				sort.getSDLManager()->getVisual(0,0,0,anArray,arraySize,sort.getFinished());
				sort.setFinished(false);

			}
			if(state[SDL_SCANCODE_5]){
				sort.genRandomBars(anArray,arraySize);
				sort.heapSort(anArray,arraySize);
				sort.setFinished(true);
				sort.getSDLManager()->getVisual(0,0,0,anArray,arraySize,sort.getFinished());
				sort.setFinished(false);
			}
			if(state[SDL_SCANCODE_6]){
				sort.genRandomBars(anArray,arraySize);
				sort.mergeSort(anArray,arraySize,0,arraySize-1);
				sort.setFinished(true);
				sort.getSDLManager()->getVisual(0,0,0,anArray,arraySize,sort.getFinished());
				sort.setFinished(false);
			}
		}
	}
	sortImg = nullptr;
	return 0;
}
