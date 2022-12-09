#include "parser.h"

bool parser::validate()
{
	if (this->file.fail())
	{
		std::cout << "�ش� ��ο� ��ġ�ϴ� ������ �����ϴ�." << std::endl;
		return false;
	}
	return true;
}

void parser::update()
{
	while (this->file.good())
	{
		std::vector<std::string> row = csv_read_row(file, ',');
		print(row);
		std::cout << std::endl;
	}
}

void parser::print(std::vector<std::string> row)
{
	for (int i = 0, length = row.size(); i < length; i++)
	{
		std::cout << "[" << row[i] << "]" << "\t";
	}
}

std::vector<std::string> parser::csv_read_row(std::istream& file, char delimeter)
{
	std::stringstream ss;
	std::vector<std::string> row;

	while (file.good())
	{
		char c = file.get();

		if (c == delimeter)
		{
			row.push_back(ss.str());
			ss.str("");
		}
		else if (c == '\n')
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
