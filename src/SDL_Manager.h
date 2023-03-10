/* Author: 	Kyle Gilmore
 * Date: 	March 18, 2022
 * Project: 	Sorting Visualizer
 * File: 	SDL_Manager.h
 * Function: 	Holds the SDL_Manager class.
*/

#ifndef SDL_MANAGER_H
#define SDL_MANAGER_H
#include<SDL2/SDL.h>
#include<iostream>

class SDL_Manager {
	public:
		SDL_Manager();
		~SDL_Manager();

		bool init();
		void getVisual(int, int, int, int[], int, bool);

		void setScreenWidth(int targetScreenWidth){SCREEN_WIDTH = targetScreenWidth;}
		void setScreenHeight(int targetScreenHeight){SCREEN_HEIGHT = targetScreenHeight;}
		void setSDLWindow(SDL_Window* targetWindow){window = targetWindow;}
		void setSDLRenderer(SDL_Renderer* targetRenderer){renderer = targetRenderer;}
		void setBarWidth(int targetBarWidth){barWidth = targetBarWidth;}

		int getScreenWidth(){return SCREEN_WIDTH;}
		int getScreenHeight(){return SCREEN_HEIGHT;}
		SDL_Window* getSDLWindow(){return window;}
		SDL_Renderer* getSDLRenderer(){return renderer;}
		int getBarWidth(){return barWidth;}
	private:
		SDL_Window* window=NULL;
		SDL_Renderer* renderer=NULL;
		int SCREEN_WIDTH=1000;
		int SCREEN_HEIGHT=750;
		int barWidth = 0;
};

#endif

