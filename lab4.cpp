#include <iostream>
#include <random>
#include <chrono>
#include <Header.hpp>


const int Z = 10;
const int R = 3;


int main()
{
	setlocale(LC_ALL, "RUS");
	T_List* head = new T_List;
	head->next = nullptr;
	for (int i = 0; i < Z; i++) {
		int tk = rand() % 10;
		ADD(head, tk);
	}
	PRINT(head);
	int x, k;
	std::cout << "Введите число, которое хотите добавить, и номер, после которого оно должно идти";
	std::cout << std::endl;
	std::cout << "Отсчет идет с 0";
	std::cout << std::endl;
	std::cin >> x >> k;
	vstavka(head, x, k);
	std::cout << std::endl;
	PRINT(head);
	Timer t;
	DELETE(head, R);      //удаление первых R-элементов
	std::cout << "Удаление первых "<< R <<" элементов в списке : " << t.elapsed() << '\n';
	std::cout << std::endl;
	PRINT(head);
	CLEAR(head);
	delete head;


	std::cout << std::endl;
	int* dinamich_array = new int[Z];    
	
	for (int i = 0; i < Z; i++) {
		dinamich_array[i] = rand() % 10;
	}
	std::cout << "Массив:";
	std::cout << std::endl;
	for (int i = 0; i < Z; i++) {
		std::cout << dinamich_array[i] << std::endl;
	}

	int zz = Z;
	Timer rr;
	for (int i = 1; i <= R; i++) {
		for (int y = 1; y <= zz; y++) {
			dinamich_array[y - 1] = dinamich_array[y];
	}
		zz = zz - 1;
	}
	std::cout << std::endl;
	std::cout << "Удаление первых "<< R <<" элементов в массиве : " << rr.elapsed() << '\n';

	std::cout << std::endl;

	for (int i = 0; i < Z-R; i++) {
		std::cout << dinamich_array[i] << std::endl;
	}

	delete[] dinamich_array;
	return 0;
}


