#ifndef INPUT_H
#define INPUT_H
#include <string>


class Input
{
public:

	void CenterText(std::string text);
	void centerBuildMessage(std::string text);
	int consoleWidth();
	void Input::insertCommand();
	void e_print(std::string aString);
	void print(std::string aString);
	void speechMode(char text[]);



};

#endif // INPUT_H
