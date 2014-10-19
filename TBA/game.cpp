#ifdef __linux
#include <unistd.h>
#elif _WIN32

#endif

#include "game.h"
#include "input.h"
#include "level.h"
#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <sstream>


std::vector<std::string> Game::levelNames;
std::string Game::current_level;
bool Game::gameRunning;
std::string Game::buildName;
std::string Game::releaseName;
std::string Game::stageName;
std::string Game::gameName;

Level *introductionLevel = new Level("introductionLevel");
Level *levelOne = new Level("levelOne");
Input input;

void addCommands();

Game::Game(std::string gameTitle, std::string build, std::string release, std::string stage)
{
	buildName = build;
	releaseName = release;
	stageName = stage;
	gameName = gameTitle;

	//Version
	Input input;
	input.CenterText("===================================");
	input.centerBuildMessage("====================" + build + " || " + release + " || " + stage + "====================");
	input.CenterText("===================================");
	std::cout << std::endl;

	//Welcome message
	std::cout << "*****" << "Welcome to " << gameTitle << "*****" << std::endl;
	std::cout << "*****" << "Follow the instructions and , most importantly ... enjoy your stay !" << "*****" << std::endl;
	std::cout << std::endl;


}



void Game::run()
{
	std::cout << "Press any key to continue... " << std::endl;
	std::cin.get();
	system("cls");

	init();
	gameRunning = true;
	addCommands(); // Adding game commands to the commands list to be displayed by 'help'

	//input.speechMode("Hi there !! What would you like to do next ?? ");


	while (gameRunning){ //While the game is running , keep receiving user input
		input.insertCommand();
	}

	//levelOne->showLevel();
	//current_level = levelOne->getLevelName();

}

void Game::init(){
	introductionLevel->setTitle("Introduction");
	introductionLevel->addDescription(" This is the introduction section. Let's take a look at the basic commands..  ");
	introductionLevel->addDescription("  go \"location\"   -  moves the player to another location ");
	introductionLevel->showLevel();
	current_level = introductionLevel->getLevelName();

	levelOne->setTitle("Level One");
	levelOne->addDescription(" Testing level one description");
}
