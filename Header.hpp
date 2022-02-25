#pragma once
#include <iostream>
#include <random>
#include <chrono>

struct T_List
{
	T_List* next;
	int age;
};
void ADD(T_List* head, int age); 
void PRINT(T_List* head); 
void DELETE(T_List* head, int k);
void CLEAR(T_List* head);
void vstavka(T_List* head, int x, int k);
class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now())
    {
    }
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};
