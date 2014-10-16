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

Level *introductionLevel = new Level("introductionLevel");
Level *levelOne = new Level("levelOne");

void addCommands();

Game::Game(std::string gameTitle, std::string build, std::string release, std::string stage)
{

	//Version
	Input input;
	input.CenterText("===================================");
	input.CenterText("====================" + build + " || " + release + " || " + stage + "====================");
	input.CenterText("===================================");
	std::cout << std::endl;

	//Welcome message
	std::cout << "*****" << "Welcome to " << gameTitle << "*****" << std::endl;
	std::cout << "*****" << "Follow the instructions and , most importantly ... enjoy your stay !" << "*****" << std::endl;
	std::cout << std::endl;



}



void Game::run()
{

	gameRunning = true;
	addCommands(); // Adding game commands to the commands list to be displayed by 'help'

	Input input;
	
	


	introductionLevel->setTitle("Introduction");
	introductionLevel->setDescription("This is the introduction section. We'll go over commands and general story here.For more commands write 'help' ");
	introductionLevel->showLevel();
	current_level = introductionLevel->getLevelName();

	levelOne->setTitle("Level One");
	levelOne->setDescription(" Testing level one description");

	//input.speechMode("Hi there !! What would you like to do next ?? ");

	

	while (gameRunning){ //While the game is running , keep receiving user input
		input.insertCommand();
	}

	//levelOne->showLevel();
	//current_level = levelOne->getLevelName();










}


