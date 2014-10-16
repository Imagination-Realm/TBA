#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <vector>

class Level
{
public:
	Level(std::string levelName);
	void setDescription(std::string description);
	void setTitle(std::string title);
	void showLevel();
	void Level::addArgument(std::string argument);
	void Level::createArgList(std::string argumentsList);
	void Level::getArgList();
	std::string Level::getLevelName();

	std::string levelDescription;
	std::string levelTitle;
	std::vector<std::string> argumentsArray;
	bool levelExists = false;
	std::string level_name;




protected:
private:
};

#endif // LEVEL_H
