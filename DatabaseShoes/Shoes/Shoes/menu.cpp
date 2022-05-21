#include "menu.h"
#include "function_write_file.h"

void menu(list& books)
{
	int t;
	bool fl = 1;
	cout << "������������, ��������� ��������� ��������� ������ �� �����!\n";
	while (fl)
	{
		cout << "��� ��������� �������?\n1-�������� ���� �����\n2-�������� ������ � �����\n3-�������� ����� ����������� ��������\n4-�������� ����� ����������� ��������\n5-�������� ����� � ���� ������\n6-������� ����� �� ���� ������\n7-�������� ����� ����������� �������� � ���������� ������� ��������\n8-�������� ����� ������� ����� ������ ���������\n9-����� ����� �� id\n10-�������� ����� ���������� ����\n11-�������� � ����\n0-��������� ���������\n";
		cin >> t;
		cin.ignore(255, '\n');
		switch (t)
		{
		case 0: fl = 0; break;
		case 1:
		{
			print_shapka();
			books.print();
			system("pause");         //�������� �������
			system("cls");			 //������� �������
			break;
		}
		case 2:
		{
			int s1;
			cout << "������� id �����" << endl;
			cin >> s1;
			cin.ignore(255, '\n');
			if (books.find_id(s1) == nullptr)
			{
				cout << "����� �� �������!" << endl;
			}
			else
			{
				string san[3];
				int s2;
				cout << "������� ����� ������� ����� � ��������� �����" << endl;
				getline(cin, san[0]);
				cout << "������� ����� �������� ����� � ��������� �����" << endl;
				getline(cin, san[1]);
				cout << "������� ���������� ��� �����" << endl;
				getline(cin, san[2]);
				cout << "������� ����� ���� �����" << endl;
				cin >> s2;
				books.find_id(s1)->edit(san[0], san[1], san[2], s2);
				function_write_file(books);
				cout << "������ ����� ��������!" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			string s1;
			cout << "������� ������� ����� � ��������� �����" << endl;
			getline(cin, s1);                                  //���������� ���� ������ �������
			books.print_sort(s1);
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			string s1;
			cout << "������� �������� ����� � ��������� �����" << endl;
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
			cout << "������� ������� ����� � ��������� �����" << endl;
			getline(cin, san[0]);
			cout << "������� �������� ����� � ��������� �����" << endl;
			getline(cin, san[1]);
			cout << "������� ���������� ���" << endl;
			getline(cin, san[2]);
			cout << "������� ����" << endl;
			cin >> s1;
			books.push_back(san[0], san[1], san[2], s1);
			function_write_file(books);
			cout << "����� ���������!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			int s1;
			cout << "������� id �����" << endl;
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
			cout << "������� ������� ����� � ��������� �����" << endl;
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
			cout << "������� id �����" << endl;
			cin >> s1;
			if (books.find_id(s1) == nullptr)
			{
				cout << "����� �� �������!" << endl;
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
			cout << "������� ����" << endl;
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
		default: cout << "������������ ����!\n" << endl; system("pause"); system("cls"); break;
		}
	}

}
