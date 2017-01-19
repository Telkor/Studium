#include <iostream>
#include "DynArray.h"
#include "Lied.h"
#pragma once

using namespace std;

DynArray::DynArray() { 
	m_capacity = 2;
	m_size = 0;
	m_data = new Lied[m_capacity];

}

DynArray::DynArray(int newcapacity) {
	m_size = 0;
	m_capacity = newcapacity;
        m_data = new Lied[m_capacity];
}

DynArray::~DynArray() {
	delete[] m_data;
        m_data = NULL;
}

DynArray::DynArray(const DynArray& other){
    m_capacity = other.m_capacity;
    m_data = new Lied[m_capacity];
    for (int i = 0; i < m_capacity; i++)
        m_data[i] = other.m_data[i];
} 

int DynArray::size(){
	return m_size;
}

int DynArray::capacity() {
	return m_capacity;
}

void DynArray::resize(int newcapacity) {
	Lied* copy = new Lied[newcapacity];

	for (int i = 0; i < m_size; i++)
		copy[i] = m_data[i];

	delete[] m_data;
	m_data = copy;
	delete[] copy;
}

void DynArray::push_back(Lied elem) {
	if (m_size == m_capacity)
		resize(m_size * 2);

	m_data[m_size] = elem;
	m_size++;
        
        sortierung();
}

void DynArray::pop_back() {
	m_size -= 1;
}

void DynArray::erase(int index) {
        Lied* copy = new Lied[m_size - 1];
	
	for (int i = 0; i < m_size; i++) {
		if (i == index)
			continue;
		else
			copy[i] = m_data[i];
	}

	delete[] m_data;
	m_data = copy;
	delete[] copy;
        //copy = NULL;
        m_size--;
}

Lied& DynArray::at(int index) {
	return m_data[index];
}

void DynArray::print(){
    for (int i = 0; i < m_size; i++){
        cout << i+1 << ". Eintrag" << endl;
        m_data[i].ausgabe();
    }
}

void DynArray::print(int index){
    m_data[index-1].ausgabe();
}

void DynArray::sortierung()
{    
    string titel1, titel2;
 for(int i=m_size-1; i!=0;i--){
     titel2= m_data[i].getTitel();
     titel1= m_data[i-1].getTitel();
     if(titel2.compare(titel1)<=0){
         
     Lied temp = m_data[i-1];
         m_data[i-1] = m_data[i];
         m_data[i] = temp;
         
     }
 }   
}

void DynArray::suchen(string name) {
    cout << "Welchen Titel moechten Sie sehen?" << endl;
    int start = 0;
    int mitte = m_size/2;
    int ende = m_size - 1;
    
    while (ende != start){
        if (m_data[mitte].getTitel() == name){
            m_data[mitte].ausgabe();
            break;}
        else if(name<m_data[mitte].getTitel()){
            ende = mitte;
            mitte = (ende-start)/2 + start;}
        else {
            start = mitte +1;
            mitte = (ende-start)/2 + start;}
        }
    if (ende ==start)
        cout << "Leider existiert dieser Eintrag nicht." << endl;
}
