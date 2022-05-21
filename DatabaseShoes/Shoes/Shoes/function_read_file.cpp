#include "function_read_file.h"
#include "list.h"

void function_read_file(list& k)
{
	string line[4];
	int s1;
	ifstream in("Base_shoes_read.txt"); // открываем файл для чтения
	if (!in.is_open())
	{
		cout << "Файл Base_shoes_read не открылся\n";
		exit(1);
	}
	while (!in.eof())
	{
		getline(in, line[0]);
		if (line[0] == "")
		{
			break;
		}
		getline(in, line[1]);
		getline(in, line[2]);
		getline(in, line[3]);
		s1 = stoi(line[3].c_str());                               //конвертация из string в int
		k.push_back(line[0], line[1], line[2], s1);
	}
	in.close();
}
