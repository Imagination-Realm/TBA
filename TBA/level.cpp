#include "level.h"
#include "input.h"
#include "game.h"
#include <iostream>
#include <sstream>

//Constructor used to set a level's name
Level::Level(std::string levelName)
{
	level_name = levelName;

	for (unsigned int i = 0; i < Game::levelNames.size(); i++){  //Check if a level already exists in the vector levelNames
		if (Game::levelNames[i] == levelName){
			levelExists = true;
		}
	}

	if (!levelExists){  //If the level doesn't exist , add it to the vector
		Game::levelNames.push_back(levelName);
	}


}

std::string Level::getLevelName(){
	std::cout << "Current_level: " << level_name << std::endl;
	return level_name;
}

void Level::addDescription(std::string description){

	if (levelDescription.size() > 0){
		levelDescription.push_back("\n");
	}
	levelDescription.push_back(description);
	
}


void Level::setTitle(std::string title){

	levelTitle = title;

}

void Level::addArgument(std::string argument){

	argumentsArray.push_back(argument);
}


// !!! Deprecated , to be removed later
void Level::createArgList(std::string argumentsList){


	std::string stringBuffer; // Have a buffer string
	std::stringstream stringStream(argumentsList); // Insert the string into a stream

	std::vector<std::string> tokens; // Create vector to hold our words

	while (stringStream >> stringBuffer){
		tokens.push_back(stringBuffer);
	}


	for (unsigned int i = 0; i < tokens.size(); i++){
		addArgument(tokens[i]);
	}
}


// !!! Deprecated , to be removed later
void Level::getArgList(){
	for (unsigned int i = 0; i<argumentsArray.size(); i++){
		std::cout << argumentsArray[i] << " ";
	}
	std::cout << std::endl;
}


//Prints level name and description
void Level::showLevel(){

	Input levelInput;

	if (levelTitle != "" & levelTitle != " "){  //If the title is not empty or a space character , print it

		std::string titleDelimitation = "";

		for (unsigned int i = 0; i<levelTitle.length(); i++){  //Prints equal signs dynamically based on the level name's size
			titleDelimitation += "=";
		}

		levelInput.CenterText("||" + titleDelimitation + "||");
		levelInput.CenterText("||" + levelTitle + "||");
		levelInput.CenterText("||" + titleDelimitation + "||");
		std::cout << std::endl << std::endl;
	}

	else{
		std::cout << "WARNING ! Title empty " << std::endl;
	}

	if (levelDescription.size() != 0  && (levelDescription[0] != "" || levelDescription[0] != " ")){

		std::string descriptionDelimitation = "+";

		for (int i = 0; i<78; i++){
			descriptionDelimitation += "-";
		}
		descriptionDelimitation += "+";
		std::cout << descriptionDelimitation ;
		for (int i = 0; i < levelDescription.size(); i++){
			std::cout << levelDescription[i];
		}
		std::cout << std::endl;
		std::cout << descriptionDelimitation << std::endl;
	}
	else{
		std::cout << "WARNING ! Description empty " << std::endl;
	}

}



