#pragma once
#include <string>
#include "BaseShoes.h"

using namespace std;

struct list {
    BaseShoes* first;
    BaseShoes* last;

    list();

    bool is_empty();                                                                          //Функция проверки наличия обуви в списке

    void push_back(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes);  //Функция добавления обуви в конец списка

    void push_back_id(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes, int id);   //Функция добавления обуви в конец списка с уже имеющимся ключем

    void print();                                                                             //Функция вывода всей обуви

    void print_most_expensive_shoes();                                                        //Функция вывода самой дорогой обуви каждой категории

    void remove_first();                                                                      //Функция удаления первого узла

    void remove_last();                                                                       //Функция удаления последнего узла

    void remove(int id);                                                                      //Функция удаления обуви из списка

    void print_sort(string buf);                                                              //Функция вывода всей обуви конкретного артикула или конкретного названия или конкретной цены 

    BaseShoes* find(string vendor_code_shoes, string name_shoes);                             //Функция поиска обуви по артикулу и названию 

    BaseShoes* find_id(int id);                                                               //Функция поиска обуви по ключу (id)

    BaseShoes* ret_first();                                                                   //Функция возврата указателя на первую обувь

    void print_sort_alphabet(string buf);                                                     //Функция вывода всей обуви конкретного артикула в алфавитном порядке названий
};
