#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>



class Game
{
public:
	Game(std::string gameTitle, std::string build, std::string release, std::string stage);
	void run();
	void init();

	std::string gameTitle;
	static std::vector<std::string> levelNames;
	static std::string current_level;
	static bool gameRunning;
	static std::string buildName;
	static std::string releaseName;
	static std::string stageName;
	static std::string gameName;



protected:
private:
};

#endif // GAME_H
