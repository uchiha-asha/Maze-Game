#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
		




#define GAME_NAME "Witches of Agnesi" 
#define SCREEN_WIDTH 640 // height of the game window  (change in Map.h)
#define SCREEN_HEIGHT 512  // width of the game window

class App 
{
public:
	App();
	~App();

	void init(); //init sdl and window
	void handleEvents();
	void update();
	void render();
	void initMapTiles();
	bool AABB(const SDL_Rect& recA, const SDL_Rect& recB); // Axis-Aligned-Bounding-Box, to check collisions
	void CollisionCheck();
	void TargetCheck();
	

	static SDL_Event event;
    inline bool getQuit() const { return quit; }
    void setQuit( bool q ) { quit = q; }

private:
	
	bool quit;
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	
	
	


};