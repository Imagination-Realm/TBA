#ifdef _WIN32
#include <windows.h>

#elif __linux
#include <sys/ioctl.h>
#include <unistd.h>
#endif

#include "input.h"
#include "level.h"
#include "game.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string> 


void check_command_validity(std::vector<std::string> words);


//Prints a string and moves to a newline
void Input::e_print(std::string aString)
{
	std::cout << aString << std::endl;
}

//Prints a string without moving to a newline
void Input::print(std::string aString)
{
	std::cout << aString;
}


//Puts a string in the middle of the console
void Input::CenterText(std::string text)
{
	int lineLen = consoleWidth();  //Read the console width
	int space = (lineLen + text.length()) / 2; // Compute number of spaces needed

	std::cout << std::setw(space) << text << std::endl; // Align text left using the number of spaces and print text 

}

void Input::centerBuildMessage(std::string text){
	int lineLen = consoleWidth();  //Read the console width
	int space = (lineLen + text.length()) / 2; // Compute number of spaces needed

	std::cout << std::setw(space) << text ; // Align text left using the number of spaces and print text 
}

int Input::consoleWidth()
{

#if defined(__linux__)

	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w); //input/output control is a system call for device-specific input/output operations ;  TIOCGWINSZ = IOCtl to Get the Window Size
	return w.ws_col; // ws_col - nr of columns
#elif _WIN32
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int ret;
	ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	if (ret)
	{
		return csbi.dwSize.X;
	}
#endif

}


//Simulates old-style game speech for characters
void Input::speechMode(char text[])
{
	char *hello = text;  //char text[] is a pointer , hence it can only be copied in a pointer of equal type
	int length = strlen(text); //Get the string length of 'text'
	for (int i = 0; i<length; i++)
	{
		std::cout << hello[i] << std::flush; //std::flush makes sure the file stream is updated with data . std::endl also calls flush after going to \n

#if defined(__linux__)
		usleep(45000);
#elif _WIN32
		Sleep(45);
#endif

	}
	std::cout << std::endl;

}


//Reads user input from the console and shows output based on inserted commands
void Input::insertCommand(){

	std::cout << ">> ";
	std::string line;
	std::getline(std::cin, line);   //Used instead of std::cin because it only reads input from one line , instead of multiple lines. Allows for a better command management .
	std::cout << std::endl;
	std::vector<std::string > words;  //Used to store user input

	std::transform(line.begin(), line.end(), line.begin(), ::tolower);  //Transforms user input to lower case

	std::stringstream ss(line);  //std::stringstream reads every word as a single object

	while (!ss.eof()){  //Inserts every word in a vector for further analysis 
		std::string argument;
		ss >> argument; //Extract words from stringstream and dump them in the temporary string 
		words.push_back(argument); //Push words into the vector 
	}


	//Reads words and takes decisions based on available commands
	check_command_validity(words);


	//for (unsigned int i = 0; i < words.size();i++){
	//std::cout << words[i] << std::endl;
	//}

}