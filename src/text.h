#pragma once
#include<string>
#include "TextureManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

class Text : public Component {
private:
	SDL_Rect srcRect, destRect;
	TTF_Font *Sans = TTF_OpenFont("../res/font.ttf", 10);
	SDL_Color White = {255, 255, 255};
	SDL_Texture* Message;
	string message;

public:
	PlayerComponent* player1;
	PlayerComponent* player2;
	Text() {
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 100;
		srcRect.h = 32;
		destRect.x = 0;
		destRect.y = 480;
		destRect.w = 640;
		destRect.h = 32;
	}

	void init() override {
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 100;
		srcRect.h = 32;
		destRect.x = 0;
		destRect.y = 480;
		destRect.w = 640;
		destRect.h = 32;
	}

	void update() override {
		if (player1->health == 0) {
			message = "Pishach won";
		}
		else if (player2->health == 0) {
			message = "Vetaal won";
		}
		else message = "Vetaal:: Health = " + to_string(player1->health) + "; Fires Left = " + to_string(player1->fireballs) + "AND "
					+ "Pishach:: Health = " + to_string(player2->health) + "; Fires Left = " + to_string(player2->fireballs);

		
	}

	void render() override {

		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), White);
		Message = SDL_CreateTextureFromSurface(TextureManager::renderer, surfaceMessage);
		SDL_FreeSurface(surfaceMessage);
		SDL_RenderCopy(TextureManager::renderer, Message, NULL, &destRect);
		SDL_DestroyTexture(Message);
	}

};
