#include "function_write_file.h"
#include "list.h"

void function_write_file(list& shoes)
{
	ofstream out("Base_shoes_write.txt");
	BaseShoes* p = shoes.ret_first();
	if (!out.is_open())
	{
		cout << "Файл Base_books_write не открылся\n";
		exit(1);
	}

	while (p)
	{
		out << *p;
		p = p->next;
	}

	out.close();
	cout << "Файл записан!" << endl;
}
