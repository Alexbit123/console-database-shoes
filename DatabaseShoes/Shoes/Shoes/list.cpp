#include "list.h"
#include "BaseShoes.h"
#include "print_shapka.h"
#include <iostream>

using namespace std;

list::list() : first(nullptr), last(nullptr)
{
}

bool list::is_empty()
{
	return first == nullptr;
}

void list::push_back(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes)
{
	BaseShoes* p = new BaseShoes(vendor_code_shoes, name_shoes, col_pair_shoes, cost_shoes);
	if (is_empty())                                                          //�������� �� ������� ������
	{
		first = p;
		last = p;
		return;
	}
	last->next = p;
	last = p;
}

void list::push_back_id(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes, int id)
{
	BaseShoes* p = new BaseShoes(vendor_code_shoes, name_shoes, col_pair_shoes, cost_shoes, id);
	if (is_empty())                                                          //�������� �� ������� ������
	{
		first = p;
		last = p;
		return;
	}
	last->next = p;
	last = p;
}

void list::print()
{
	if (is_empty()) return;													//�������� �� ������� ������
	BaseShoes* p = first;
	while (p)                                                               //������ ������ ���� �� ����������
	{
		printf("%-15d%-15s%-35s%-30s%-20d\n", p->key, p->vendor_code_shoes.c_str(), p->name_shoes.c_str(), p->col_pair_shoes.c_str(), p->cost_shoes);
		p = p->next;
	}
	cout << endl;
}

void list::print_most_expensive_shoes()
{
	list r1, r2, r3;
	if (is_empty())
	{
		cout << "���� ����� �����!";
		return;
	}
	print_shapka();
	BaseShoes* p = this->first;
	while (p)                                                 //���� ������ �� ���� ��������� ������ ����� � ������ �����
	{
		if (p->vendor_code_shoes == "�")
		{
			r1.push_back_id(p->vendor_code_shoes, p->name_shoes, p->col_pair_shoes, p->cost_shoes, p->key);
		}
		if (p->vendor_code_shoes == "�")
		{
			r2.push_back_id(p->vendor_code_shoes, p->name_shoes, p->col_pair_shoes, p->cost_shoes, p->key);
		}
		if (p->vendor_code_shoes == "�")
		{
			r3.push_back_id(p->vendor_code_shoes, p->name_shoes, p->col_pair_shoes, p->cost_shoes, p->key);
		}
		p = p->next;
	}
	BaseShoes* start1 = r1.first;
	BaseShoes* start2 = r2.first;
	BaseShoes* start3 = r3.first;
	int max = 0;

	while (start1)                                                                  //������� ������������ ���� ����� �
	{
		if (max < start1->cost_shoes)
		{
			max = start1->cost_shoes;
		}
		start1 = start1->next;
	}
	start1 = r1.first;
	while (start1)																	//�������� ��� ����� �������� � � ������������ ����� (���� ���������)
	{
		if (max == start1->cost_shoes)
		{
			printf("%-15d%-15s%-35s%-30s%-20d\n", start1->key, start1->vendor_code_shoes.c_str(), start1->name_shoes.c_str(), start1->col_pair_shoes.c_str(), start1->cost_shoes);
		}
		start1 = start1->next;
	}

	max = 0;
	while (start2)																//������� ������������ ���� ����� �
	{
		if (max < start2->cost_shoes)
		{
			max = start2->cost_shoes;
		}
		start2 = start2->next;
	}
	start2 = r2.first;
	while (start2)																//�������� ��� ����� �������� � � ������������ ����� (���� ���������)
	{
		if (max == start2->cost_shoes)
		{
			printf("%-15d%-15s%-35s%-30s%-20d\n", start2->key, start2->vendor_code_shoes.c_str(), start2->name_shoes.c_str(), start2->col_pair_shoes.c_str(), start2->cost_shoes);
		}
		start2 = start2->next;
	}

	max = 0;
	while (start3)																//������� ������������ ���� ����� �
	{
		if (max < start3->cost_shoes)
		{
			max = start3->cost_shoes;
		}
		start3 = start3->next;
	}
	start3 = r3.first;
	while (start3)																//�������� ��� ����� �������� � � ������������ ����� (���� ���������)
	{
		if (max == start3->cost_shoes)
		{
			printf("%-15d%-15s%-35s%-30s%-20d\n", start3->key, start3->vendor_code_shoes.c_str(), start3->name_shoes.c_str(), start3->col_pair_shoes.c_str(), start3->cost_shoes);
		}
		start3 = start3->next;
	}
}

void list::remove_first()
{
	if (is_empty()) return;
	BaseShoes* p = first;
	first = p->next;
	delete p;
	cout << "����� �������!" << endl;
}

void list::remove_last()
{
	if (is_empty()) return;
	if (first == last)
	{
		remove_first();
		return;
	}
	BaseShoes* p = first;
	while (p->next != last) p = p->next;
	p->next = nullptr;
	delete last;
	last = p;
	cout << "����� �������!" << endl;
}

void list::remove(int id)
{
	if (is_empty()) return;                                                //�������� �� ������� ������
	if (first->key == id)		                                           //���� ������ ����� ������ � ������, ������� 
	{
		remove_first();
		return;
	}
	else if (last->key == id)											   //���� ������ ����� ��������� � ������, �������
	{
		remove_last();
		return;
	}
	BaseShoes* slow = first;
	BaseShoes* fast = first->next;
	while (fast && fast->key != id )									    //���� �����
	{
		fast = fast->next;
		slow = slow->next;
	}
	if (!fast)                                                             //���� �� �����
	{
		cout << "����� ����� ���!" << endl;
		return;
	}
	slow->next = fast->next;
	delete fast;
	cout << "����� �������!" << endl;
}

void list::print_sort(string buf)
{
	if (is_empty())
	{
		cout << "���� ����� �����!";
		return;
	}
	print_shapka();
	BaseShoes* p = first;
	while (p)                                              //���� ������ �� ���� ���������� ������ ������ � ������� ������ �����
	{
		if (p->vendor_code_shoes == buf)
		{
			printf("%-15d%-15s%-35s%-30s%-20d\n", p->key, p->vendor_code_shoes.c_str(), p->name_shoes.c_str(), p->col_pair_shoes.c_str(), p->cost_shoes);
		}
		if (p->name_shoes == buf)
		{
			printf("%-15d%-15s%-35s%-30s%-20d\n", p->key, p->vendor_code_shoes.c_str(), p->name_shoes.c_str(), p->col_pair_shoes.c_str(), p->cost_shoes);

		}
		if (to_string(p->cost_shoes) == buf)
		{
			printf("%-15d%-15s%-35s%-30s%-20d\n", p->key, p->vendor_code_shoes.c_str(), p->name_shoes.c_str(), p->col_pair_shoes.c_str(), p->cost_shoes);

		}
		p = p->next;
	}
	cout << endl;
}

BaseShoes* list::find(string vendor_code_shoes, string name_shoes)              //���� ����� �� ������� � ��������
{
	BaseShoes* p = first;
	while (p && (p->vendor_code_shoes != vendor_code_shoes || p->name_shoes != name_shoes))
	{
		p = p->next;
	}
	return (p && p->vendor_code_shoes == vendor_code_shoes && p->name_shoes == name_shoes) ? p : nullptr;
}

BaseShoes* list::find_id(int id)
{
	BaseShoes* p = first;
	while (p && p->key != id)
	{
		p = p->next;
	}
	return (p && p->key == id) ? p : nullptr;
}

BaseShoes* list::ret_first()                                  //���������� ��������� �� ������ ������� ������
{
	if (is_empty()) return nullptr;
	return first;
}

void list::print_sort_alphabet(string buf)
{
	list r;
	if (is_empty())
	{
		cout << "���� ����� �����!";
		return;
	}
	print_shapka();
	BaseShoes* p = this->first;
	while (p)                                                 //���� ������ �� ���� ��������� ������ ����� � ������ �����
	{
		if (p->vendor_code_shoes == buf)
		{
			r.push_back_id(p->vendor_code_shoes, p->name_shoes, p->col_pair_shoes, p->cost_shoes, p->key);
		}
		p = p->next;
	}
	//��������� ��� ������ ��� ������ ����� �� �������� ��������
	BaseShoes* start, * tek;
	start = r.first;        //����� �������
	while (start->next)  //���� �� ��������������� �����
	{
		tek = start->next; //��������� �� ��������������� ������ �������
		BaseShoes* k = r.first, * predk = k;
		while (k != tek && (k->name_shoes < tek->name_shoes || k->name_shoes == tek->name_shoes))//���� ����� (������ // ���� �� ��������)
		{
			predk = k; // ���������� ����� ������� ����� predk
			k = k->next;            // ����� k
		}
		if (k != tek)       //������� ����� (���� �� ����� �� ��������)
		{
			start->next = tek->next;//������ �������
			tek->next = k;//�������� ����� k-���
			if (k == r.first)
			{
				r.first = tek;  //��������� � ������ �������
			}

			else
			{
				predk->next = tek;   //��������� ����� predk ����� k
			}
		}
		start = tek;
	}

	p = r.first;
	while (p)
	{
		printf("%-15d%-15s%-35s%-30s%-20d\n", p->key, p->vendor_code_shoes.c_str(), p->name_shoes.c_str(), p->col_pair_shoes.c_str(), p->cost_shoes);
		p = p->next;
	}

	cout << endl;
}
