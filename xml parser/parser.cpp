#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>

std::vector<std::string> csv_read_row(std::istream& file, char delimeter);

int main(void)
{
	std::ifstream file("C:\\Users\\Desktop\\test.csv");

	if (file.fail())
	{
		std::cout << "해당 경로에 위치하는 파일이 없습니다." << std::endl;
		return 0;
	}

	while (file.good())
	{
		std::vector<std::string> row = csv_read_row(file, ',');

		if (!row[0].find("#"))
		{
			continue;
		}
		else
		{
			for (int i = 0, int length = row.size() - 2; i < length; i++)
			{
				std::cout << "[" << row[i] << "]" << "\t";
			}
		}

		std::cout << std::endl;
	}

	file.close();

	return 0;
}

std::vector<std::string> csv_read_row(std::istream& file, char delimeter)
{
	std::stringstream ss;
	bool inquotes = false;
	std::vector<std::string> row;

	while (file.good())
	{
		char c = file.get();
		
		if (!inquotes && c == ' ')
		{
			inquotes = true;
		}
		else if (inquotes && c == ' ')
		{
			if (file.peek() == ' ')
			{
				ss << (char)file.get();
			}
			else
			{
				inquotes = false;
			}
		}
		else if (!inquotes && c == delimeter)
		{
			row.push_back(ss.str());
			ss.str("");
		}
		else if (!inquotes && (c == '\r' || c == '\n'))
		{
			if (file.peek() == '\n')
			{
				file.get();
			}
			row.push_back(ss.str());
			return row;
		}
		else
		{
			ss << c;
		}
	}


	return std::vector<std::string>();
}
