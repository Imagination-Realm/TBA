#include "game.h"
#include <iostream>
#include <vector>

std::vector<std::string> commands_list;

//Sets gameRunning to false and interrupts the while loop, thus exiting the program
void exit(){
	Game::gameRunning = false;
}

//Command 'go'
void go(std::vector<std::string> words){
	if (words.size() > 1 && words[1] == "town"){  //If vector 'words' is not empty and its second element is 'town' , then execute command  
		std::cout << "WORKS" << std::endl;
	}
	else { std::cout << "ERROR ! Missing or incorrect argument" << std::endl; }
}

//Prints a list of available commands
void help(){

	for (unsigned int i = 0; i < commands_list.size(); i++){	//Parses the commands_list vector and prints available commands
		std::cout << commands_list[i] << " ";
	}
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
		help();
	}
	else if (words[0] != "") { std::cout << "Error ! Command invalid . Please type 'help' to check for available commands " << std::endl; }

}

//Add a command name to the list of commands to be printed by 'help'
void addCommand(std::string command){
	commands_list.push_back(command);
}

//Calls addCommand for each command ... used to minimize code repetition and to ensure maintainability 
void addCommands(){
	addCommand("exit");
	addCommand("go");
	addCommand("help");
}



