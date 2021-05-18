#include "PositionComponent.h"
#include "TextureManager.h"
#include <SDL2/SDL.h>

class PlayerComponent : public Component {
private:
	PositionComponent *position;	
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;


public:
	PlayerComponent(const char* fileName) {
		texture = TextureManager::loadTexture(fileName);
	}

	void init() override {
		position = (entity->getComponent<PositionComponent>());
		
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;
	}

	void update() override {
		destRect.x = position->x();
		destRect.y = position->y();

	}

	void render() override {
		TextureManager::render(texture, srcRect, destRect);
	}

};