/* Author: 	Kylie Gilmore
 * Date: 	March 18, 2022
 * Project: 	Sorting Visualizer
 * File: 	SDL_Manager.cpp
 * Function: 	Holds functions of the SDL_Manager class.
*/

#include "SDL_Manager.h"

SDL_Manager::SDL_Manager(){

}

SDL_Manager::~SDL_Manager(){

}

// SDL initialization process is set up here, if warnings or errors are found, they are caught by the program
bool SDL_Manager::init()
{
    bool success=true;
    if(SDL_Init(SDL_INIT_VIDEO)<0){
	    std::cout<<"SDL Error: " << SDL_GetError() << std::endl;
        success=false;
    }
    else{
        if(!(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))){
		std::cout<<"Linear Texture Filtering isn't enabled." << std::endl;
        }
        window=SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window==NULL){
		std::cout<<"SDL Error: "<< SDL_GetError() << std::endl;
            success=false;
        }
        else{
            renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer==NULL){
		    std::cout<<"SDL Error: "<< SDL_GetError() << std::endl;
                success=false;
            }
        }
    }
    return success;
}

// visualizes the occurences of each algorithm, placing the parent index in green and the child index in red,
// and another index in yellow for heap sort, displaying the contents to the screen
void SDL_Manager::getVisual(int parent, int child, int etc, int anArray[], int arraySize,bool finished){

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	for(int i = 0; i < arraySize; i++){
		SDL_Rect rect = {i*getBarWidth(), anArray[i], getBarWidth(), getScreenHeight()};
		if(finished){
			SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
			SDL_RenderDrawRect(renderer, &rect);
			continue;
		}	
		if(i == parent){	
			SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
			SDL_RenderFillRect(renderer, &rect);
		}
		else if(i == child){
			SDL_SetRenderDrawColor(renderer, 180, 100, 100, 0);
			SDL_RenderFillRect(renderer, &rect);
		}
		else if(i == etc){
			SDL_SetRenderDrawColor(renderer, 180, 180, 100, 0);
			SDL_RenderFillRect(renderer, &rect);
		}
		else{
			SDL_SetRenderDrawColor(renderer, 100, 100, 100, 0);
			SDL_RenderDrawRect(renderer, &rect);
		}
	}
	SDL_RenderPresent(renderer);
}
