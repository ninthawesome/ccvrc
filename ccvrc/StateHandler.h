#pragma once

#include "GuiObject.h"
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include "GameState.h"

//game states
#include "GuiTitleScreen.h"
#include "MatchSetup.h"

class LogicHandler;

class StateHandler{
public:
	StateHandler(int* width_of_window, int* height_of_window, LogicHandler* handler);
	~StateHandler(void);
	void setupGui(void);
	void loading(sf::RenderWindow *window, std::string text = "Loading...");
	void loaded();
	void setState(int index_of_state);
	void setState(std::string statename);
	GameState* getCurrentState(void);
	std::vector<GuiObject*>* getGuiList(void);

	void update(double delta);

	//get functions used by game states
	sf::Texture* getTexture(int index);

	int* getWindowWidth(void){
		return width;
	}
	int* getWindowHeight(void){
		return height;
	}
private:
	std::vector<GameState*> states;
	GameState* currentState;
	
	LogicHandler* logicHandler;

	bool gameLoaded;
	int *width, *height;
};

