#pragma once
#include <string>
#include "BaseShoes.h"

using namespace std;

struct list {
    BaseShoes* first;
    BaseShoes* last;

    list();

    bool is_empty();                                                                          //������� �������� ������� ����� � ������

    void push_back(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes);  //������� ���������� ����� � ����� ������

    void push_back_id(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes, int id);   //������� ���������� ����� � ����� ������ � ��� ��������� ������

    void print();                                                                             //������� ������ ���� �����

    void print_most_expensive_shoes();                                                        //������� ������ ����� ������� ����� ������ ���������

    void remove_first();                                                                      //������� �������� ������� ����

    void remove_last();                                                                       //������� �������� ���������� ����

    void remove(int id);                                                                      //������� �������� ����� �� ������

    void print_sort(string buf);                                                              //������� ������ ���� ����� ����������� �������� ��� ����������� �������� ��� ���������� ���� 

    BaseShoes* find(string vendor_code_shoes, string name_shoes);                             //������� ������ ����� �� �������� � �������� 

    BaseShoes* find_id(int id);                                                               //������� ������ ����� �� ����� (id)

    BaseShoes* ret_first();                                                                   //������� �������� ��������� �� ������ �����

    void print_sort_alphabet(string buf);                                                     //������� ������ ���� ����� ����������� �������� � ���������� ������� ��������
};
