#pragma once

#include <string>

using namespace std;

extern int id;

struct BaseShoes
{
	string vendor_code_shoes;
	string name_shoes;
	string col_pair_shoes;
	int cost_shoes;
	BaseShoes* next;
	int key;

	BaseShoes();
	BaseShoes(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes);
	BaseShoes(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes, int id);

	void edit(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes);     //������� ���������� ��� ��������� �����
	void print_shoes();                                                                                //������� ������ �����

	friend ostream& operator <<(ostream& ost, BaseShoes& san);                                         //������� �������������� ��������� << ��� ������ � ����
};