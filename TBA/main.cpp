#include <iostream>
#include "game.h"
#include <ctime>
#include <sstream>

std::string dateS;
std::string getRevisionDate();

int main()
{
	std::string date = getRevisionDate();

	Game *something = new Game("PLACEHOLDER", "BUILD 0.2.0", date, "ALPHA STAGE");
	something->run();

	return 0;
}

std::string getRevisionDate(){

	char date[10];
	_strdate_s(date);

	std::stringstream ss;
	std::string dd, mm, yyyy;
	std::vector<std::string> list;

	for (int i = 0; i < 8; i = i + 3){
		std::string temp;
		ss << date[i];
		ss >> temp;
		list.push_back(temp);
		ss = std::stringstream();  //Flush the string stream

		std::string temp2;
		ss << date[i + 1];
		ss >> temp2;
		list.push_back(temp2);
		ss = std::stringstream();
	}

	dd = list[2] + list[3];
	mm = list[0] + list[1];
	yyyy = list[4] + list[5];

	dateS = dd + "." + mm + "." + "20" + yyyy;

	return dateS;
}
