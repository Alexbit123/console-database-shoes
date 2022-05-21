#include <iostream>
#include <fstream>
#include <windows.h>
#include "BaseShoes.h"
#include "list.h"
#include "function_read_file.h"
#include "function_write_file.h"
#include "menu.h";

using namespace std;

int id = 1;

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);                          //устанавливает кодировку вывода на консоль
	SetConsoleCP(1251);                                //устанавливает кодировку ввода в консоль

	list k;

	function_read_file(k);                             //Функция загрузки данных из файла

	menu(k);                                           //Функция реализации меню

}