#include "menu.h"
#include "function_write_file.h"

void menu(list& books)
{
	int t;
	bool fl = 1;
	cout << "Здравствуйте, программа загрузила начальные данные из файла!\n";
	while (fl)
	{
		cout << "Что требуется сделать?\n1-Показать базу обуви\n2-Изменить данные о обуви\n3-Показать обувь конкретного артикула\n4-Показать обувь конкретного названия\n5-Добавить обувь в базу данных\n6-Удалить обувь из базы данных\n7-Показать обувь конкретного артикула в алфавитном порядке названий\n8-Показать самую дорогую обувь каждой категории\n9-Поиск обуви по id\n10-Показать обувь конкретной цены\n11-записать в файл\n0-Завершить программу\n";
		cin >> t;
		cin.ignore(255, '\n');
		switch (t)
		{
		case 0: fl = 0; break;
		case 1:
		{
			print_shapka();
			books.print();
			system("pause");         //Задержки консоли
			system("cls");			 //Очистка консоли
			break;
		}
		case 2:
		{
			int s1;
			cout << "Введите id обуви" << endl;
			cin >> s1;
			cin.ignore(255, '\n');
			if (books.find_id(s1) == nullptr)
			{
				cout << "Книга не найдена!" << endl;
			}
			else
			{
				string san[3];
				int s2;
				cout << "Введите новый артикул обуви с заглавной буквы" << endl;
				getline(cin, san[0]);
				cout << "Введите новое название обуви с заглавной буквы" << endl;
				getline(cin, san[1]);
				cout << "Введите количество пар обуви" << endl;
				getline(cin, san[2]);
				cout << "Введите новую цену обуви" << endl;
				cin >> s2;
				books.find_id(s1)->edit(san[0], san[1], san[2], s2);
				function_write_file(books);
				cout << "Данные обуви изменены!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			string s1;
			cout << "Введите артикул обуви с заглавной буквы" << endl;
			getline(cin, s1);                                  //Считывание всей строки целиком
			books.print_sort(s1);
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			string s1;
			cout << "Введите название обуви с заглавной буквы" << endl;
			getline(cin, s1);
			books.print_sort(s1);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			string san[3];
			int s1;
			cout << "Введите артикул обуви с заглавной буквы" << endl;
			getline(cin, san[0]);
			cout << "Введите название обуви с заглавной буквы" << endl;
			getline(cin, san[1]);
			cout << "Введите количество пар" << endl;
			getline(cin, san[2]);
			cout << "Введите цену" << endl;
			cin >> s1;
			books.push_back(san[0], san[1], san[2], s1);
			function_write_file(books);
			cout << "Обувь добавлена!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			int s1;
			cout << "Введите id обуви" << endl;
			cin >> s1;
			books.remove(s1);
			function_write_file(books);
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			string s1;
			cout << "Введите артикул обуви с заглавной буквы" << endl;
			getline(cin, s1);
			books.print_sort_alphabet(s1);
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			books.print_most_expensive_shoes();
			system("pause");
			system("cls");
			break;
		}
		case 9:
		{
			int s1;
			cout << "Введите id обуви" << endl;
			cin >> s1;
			if (books.find_id(s1) == nullptr)
			{
				cout << "Обувь не найдена!" << endl;
			}
			else
			{
				print_shapka();
				books.find_id(s1)->print_shoes();

			}
			system("pause");
			system("cls");
			break;
		}
		case 10:
		{
			string s1;
			cout << "Введите цену" << endl;
			getline(cin, s1);
			books.print_sort(s1);
			system("pause");
			system("cls");
			break;
		}
		case 11:
		{
			function_write_file(books);
			system("pause");
			system("cls");
			break;
		}
		default: cout << "Некорректный ввод!\n" << endl; system("pause"); system("cls"); break;
		}
	}

}
