#pragma once
#include "PositionComponent.h"
#include "TextureManager.h"
#include <SDL2/SDL.h>

class PlayerComponent : public Component {
private:
	PositionComponent *position;	
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;
	

public:
	int id;
	bool isOpponentOnline;
	int health = 100;
	int fireballs = 10;
	int fired;
	PlayerComponent(const char* fileName, int x1 = 0, int y1 = 0) {
		texture = TextureManager::loadTexture(fileName);

		id = -1,  isOpponentOnline = false;

		srcRect.x = x1;
		srcRect.y = y1;
		fired = false;
	}

	void init() override {
		position = (entity->getComponent<PositionComponent>());
		
		// srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 32;
	}

	void update() override {
		destRect.x = position->pos.x;
		destRect.y = position->pos.y;


	}

	void render() override {
		TextureManager::render(texture, srcRect, destRect);
	}

};
