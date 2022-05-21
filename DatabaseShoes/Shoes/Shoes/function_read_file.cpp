#include "function_read_file.h"
#include "list.h"

void function_read_file(list& k)
{
	string line[4];
	int s1;
	ifstream in("Base_shoes_read.txt"); // ��������� ���� ��� ������
	if (!in.is_open())
	{
		cout << "���� Base_shoes_read �� ��������\n";
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
		s1 = stoi(line[3].c_str());                               //����������� �� string � int
		k.push_back(line[0], line[1], line[2], s1);
	}
	in.close();
}
