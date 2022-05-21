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

	void edit(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes);     //Функция добавления или изменения книги
	void print_shoes();                                                                                //Функция печати книги

	friend ostream& operator <<(ostream& ost, BaseShoes& san);                                         //Функция перегруженного оператора << для записи в файл
};