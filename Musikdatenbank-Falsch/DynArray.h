#ifndef DYNARRAY_H
#define	DYNARRAY_H
#pragma once
#include "Lied.h"
class Lied;
class DynArray
{
public:
        
        DynArray(); //Standardkonstruktor
	DynArray(int newCapacity); //Weiterer Konstruktor
	~DynArray(); //Destruktor, muss implementiert werden

	Lied& at(int index);

	void push_back(Lied elem);
	void pop_back();
	void erase(int index);

	int size();
	int capacity();

	void print();
        void detail(int index);
        void edit(int index, Lied elem);
        
private:
	void resize(int newCapacity);
	DynArray(const DynArray& other); //Kopierkonstruktor soll explizit *nicht* aufgerufen werden
	Lied* m_data;
	int m_size;
	int m_capacity;
};

#endif	/* DYNARRAY_H */