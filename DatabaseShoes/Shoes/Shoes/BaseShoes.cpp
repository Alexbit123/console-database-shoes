#include "BaseShoes.h"
#include <iostream>

BaseShoes::BaseShoes(): next(nullptr)
{
}

BaseShoes::BaseShoes(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes) : vendor_code_shoes(vendor_code_shoes), name_shoes(name_shoes), col_pair_shoes(col_pair_shoes), cost_shoes(cost_shoes), next(nullptr), key(id)
{
	id++;
}

BaseShoes::BaseShoes(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes, int id) : vendor_code_shoes(vendor_code_shoes), name_shoes(name_shoes), col_pair_shoes(col_pair_shoes), cost_shoes(cost_shoes), next(nullptr), key(id)
{
}

void BaseShoes::edit(string vendor_code_shoes, string name_shoes, string col_pair_shoes, int cost_shoes)
{
	this->vendor_code_shoes = vendor_code_shoes;
	this->name_shoes = name_shoes;
	this->col_pair_shoes = col_pair_shoes;
	this->cost_shoes = cost_shoes;
}

void BaseShoes::print_shoes()
{
	printf("%-15d%-15s%-35s%-30s%-20d\n", key, vendor_code_shoes.c_str(), name_shoes.c_str(), col_pair_shoes.c_str(), cost_shoes);
}


ostream& operator<<(ostream& ost, BaseShoes& san)
{
	return ost << san.vendor_code_shoes << endl << san.name_shoes << endl << san.col_pair_shoes << endl << san.cost_shoes << endl;
}
