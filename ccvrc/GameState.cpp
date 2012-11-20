#include "GameState.h"
#include "StateHandler.h"

GameState::GameState(const char * _path, StateHandler* _stateHandler){
	stateHandler = _stateHandler;
	luaInterface = new LuaInterface(_path, this);
}

GameState::~GameState(void){
	//getGuiList()->clear();
}

void GameState::update(double delta){

}

void GameState::callState(void){

}

void GameState::addSprite(int index, sf::Drawable* spr){
	printf("adding sprite index: %d list size: %d\n", index, sprites.size());
	while(sprites.size() <= index){
		std::vector<sf::Drawable*> vec;
		sprites.push_back(vec);
		printf("added new index\n");
	}
	printf("new size: %d\n", sprites.size());

	sprites.at(index).push_back(spr);
}

void GameState::addSprite(int index, int xpos, int ypos, std::string src, int scaleX, int scaleY){
	sf::Sprite * spr = new sf::Sprite();
	
}

void GameState::addPolySprite(int index, int x, int y, int w, int h, int color){

	//printf("\npoly added info: %d %d %d %d %d %d \n", index, x, y, w, h, color);
	sf::ConvexShape * poly = new sf::ConvexShape();

	poly->setPointCount(4);
	poly->setPoint(0, sf::Vector2f(x, y));
	poly->setPoint(1, sf::Vector2f(x + w, y));
	poly->setPoint(2, sf::Vector2f(x + w, y + h));
	poly->setPoint(3, sf::Vector2f(x, y + h));
	int r = ((color / 256) / 256) % 256;
	int g = (color / 256) % 256;
	int b = color % 256;
	poly->setFillColor(sf::Color(r, g, b));

	addSprite(index, poly);
}

void GameState::addStringSprite(int index, int x, int y, int size, std::string text, int color){
	printf("adding string sprite: index: %d x: %d y: %d size: %d string: %s color: %d\n", index, x, y, size, text.c_str(), color);

	sf::Text * spr = new sf::Text(text, *stateHandler->getFont(), size);

	int r = ((color / 256) / 256) % 256;
	int g = (color / 256) % 256;
	int b = color % 256;
	spr->setColor(sf::Color(r, g, b));
	spr->setPosition(x, y);

	addSprite(index, spr);
}