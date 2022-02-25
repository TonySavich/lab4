#include <iostream>
#include <random>
#include <Header.hpp>

void ADD(T_List* head, int age)
{
	T_List* p = new T_List;
	p->age = age;
	p->next = head->next;
	head->next = p;
}
void PRINT(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->age << std::endl;
		p = p->next;
	}
}
void DELETE(T_List* head, int k)
{
	T_List* tmp;
	T_List* p = head;
	int i = 0;
	while (i <= k - 1) {
		if (p == nullptr) {
			break;
		}
		if (i <= k) {
			tmp = p->next;
			p->next = p->next->next;
			delete tmp;
		}
		i++;
	}
}
void CLEAR(T_List* head)
{
	T_List* tmp;
	T_List* p = head->next;
	while (p != nullptr)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
}
void vstavka(T_List* head, int x, int k)
{
	T_List* p = head->next;
	int i = 0;
	while (i <= k) {
		if (p == nullptr) {
			break;
		}
		if (i == k) {
			T_List* q = new T_List;
			q->next = p->next;
			p->next = q;
			q->age = x;
		}
		p = p->next;
		i++;
	}
}

