#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>

class parser
{
public:
	parser(std::string destination) : file(destination)
	{
		validate();
	}

	~parser()
	{
		file.close();
	}


	void update();

	std::vector<std::string> csv_read_row(std::istream& file, char delimeter);

private:
	void print(std::vector<std::string> row);
	bool validate();

private:
	std::string destination;

	std::ifstream file;
};