#include "game.h"
#include <iostream>
#include <vector>
#include "level.h"
#include <stdlib.h>
#include "input.h"

std::vector<std::string> commands_list;
extern Level *levelOne;

//Sets gameRunning to false and interrupts the while loop, thus exiting the program
void exit(){
	Game::gameRunning = false;
}

//Command 'go'
void go(std::vector<std::string> words){
	
	if (words.size() > 1 && words[1] == "levelone"){  //If vector 'words' is not empty and its second or third element is 'town' , then execute command  
		system("cls"); //Clears the console ... it's bad to use this one , but it should do the work for now
		levelOne->showLevel();
		Game::current_level = levelOne->getLevelName();
	}
	else { std::cout << "ERROR ! Incorrect or missing argument" << std::endl; }
}

//Prints a list of available commands
void help(std::vector<std::string> words){

	if (words.size() == 1){
		std::cout << "Available commands: ";
		for (unsigned int i = 0; i < commands_list.size(); i++){	//Parses the commands_list vector and prints available commands
			std::cout << commands_list[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Check a command's description using: help \"command\"" << std::endl;
	}
	else if (words.size() > 1 && words[1] == "exit"){
		std::cout << "'exit' quits the game" << std::endl;
	}
	else { 
		std::cout << "Command not found . Write 'help' for a list of available commands" << std::endl;
	}
	
}

void pick(std::vector<std::string> words){
	if (words.size()>1 && words[1]=="leaf"){
		std::cout << "Picking leaf" << std::endl;
	}
	else {
		std::cout << "ERROR ! Incorrect or missing argument" << std::endl;
	}
}


void main_menu(){
	std::string build = Game::buildName;
	std::string release = Game::releaseName;
	std::string stage = Game::stageName;
	std::string gameTitle = Game::gameName;

	system("cls");

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

//Checks whether a valid command has been inputted by the user 
void check_command_validity(std::vector<std::string> words){

	if (words[0] == "exit"){
		exit();
	}
	else if (words[0] == "go"){
		go(words);
	}
	else if (words[0] == "help"){
		help(words);
	}
	else if (words[0] == "pick"){
		pick(words);
	}
	else if (words[0] == "menu"){
		main_menu();
	}
	else if (words[0] != "") { std::cout << "Error ! Command invalid . Please type 'help' to check for available commands " << std::endl; }

}

//Add a command name to the list of commands to be printed by 'help'
void addCommand(std::string command){
	commands_list.push_back(command);
}

//Calls addCommand for each command ... used to minimize code repetition and to ensure maintainability 
void addCommands(){

	addCommand("menu");
	addCommand("pick");
	addCommand("go");
	addCommand("exit");
}




