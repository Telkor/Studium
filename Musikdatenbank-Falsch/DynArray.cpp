#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "DynArray.h"
#include "Lied.h"

using namespace std;


DynArray::DynArray(){
    
    m_size = 0;
    m_capacity = 20;
    m_data = new Lied[m_capacity];
}

DynArray::DynArray(int newCapacity){
    m_size = 0;
    m_capacity = newCapacity;
    m_data = new Lied[newCapacity];
}
 
DynArray::~DynArray(){
    delete[] m_data;
    m_size = 0;
}

Lied& DynArray::at(int index) {
    return m_data[index];
}

int DynArray::size(){
    return m_size; 
}

int DynArray::capacity(){
    return m_capacity;
}

void DynArray::print(){                                 //Alle gespeicherten Elemente anzeigen
    for (int i = 0; i < m_size; i++){
        
        cout << endl << i+1 << ".Eintrag" << endl;
        cout << "Titel: " << m_data[i].titel << endl;
        cout << "Interpret: " << m_data[i].interpret << endl;
        cout << "Erscheinungsjahr: " << m_data[i].erscheinungsjahr << endl;
        cout << "Laenge: " << m_data[i].laenge << endl;
        
        if (m_data[i].g == 0)
            cout << "Genre: Pop" << endl;
        
        if (m_data[i].g == 1)
            cout << "Genre: Rock" << endl;
        
        if (m_data[i].g == 2)
            cout << "Genre: Klassik" << endl;
        
        if (m_data[i].g == 3)
            cout << "Genre: Hard Rock" << endl;
        
        
    }
}


void DynArray::resize(int newCapacity){                             //"vergrößert" das Array
    Lied* copy = new Lied[newCapacity];
    
    for (int i = 0; i < m_size; i++){
        copy[i] = m_data[i];
    }
    
    delete[] m_data;
    m_data = copy;
    m_capacity = newCapacity;
    
}

 void DynArray::push_back(Lied elem){                              //Neuer Eintrag
    if (m_size == m_capacity){  
        resize(m_size + m_capacity);  
    }
    
    cout << "Geben Sie einen Titel an: ";
    cin >> elem.titel;
     
    cout << "Geben Sie einen Interpreten an: ";
    cin >> elem.interpret;
    
    cout << "Geben Sie ein Erscheinungsjahr an: ";
    cin >> elem.erscheinungsjahr;
    
    cout << "Geben Sie eine laenge an: ";
    cin >> elem.laenge;
   
    cout << "Geben sie ein Genre an:";
    string k;
    cin >> k;
    
    if (k == "pop") {
        elem.g = pop;
    }
        
    if (k == "rock") {
        elem.g = rock;
    }
        
    if (k == "klassik") {
        elem.g = klassik;
    }   
    if (k == "hard_rock") {
        elem.g = hard_rock;    
    }

    m_data[m_size] = elem;
    m_size = m_size + 1; 
}

 void DynArray::erase(int index){                                   //Eintrag löschen
    index = index -1;
     
     
    Lied* copy = new Lied[m_size - 1];
    
    for (int i = 0; i < m_size; i++){
        if (i < index)
            copy[i] = m_data[i];
        
        if (i == index){
            continue;
        }
        if (i > index){
            copy[i-1] = m_data[i];
        }
    }
    
    delete[] m_data;
    m_data = copy;
    m_size = m_size - 1;  
}
 
 
 void DynArray::pop_back(){
     Lied* copy = new Lied[m_size - 1];
     
     for (int i = 0; i < m_size - 1; i++)
         copy[i] = m_data[i];
                 
     delete[] m_data;
     m_data = copy;
     m_size = m_size -1;
     
 }
 
 void DynArray::edit(int index, Lied elem){
     string l;
     string y;
     int x;
     
    
        
        cout << "Welchhe Information wollen Sie bearbeiten?" << endl;
        
        cin >> l;
        
        if (l == "titel" | l == "Titel") {
            cout << "Geben Sie einen Titel an." << endl;
            cin >> l;
            m_data[index-1].titel = l;
        }
        
        if (l == "interpret" | l == "Interpret") {
            cout << "Geben Sie einen Interpreten an." << endl;
            cin >> l;
            m_data[index-1].interpret = l;
        }
        
        if (l == "erscheinungsjahr" | l == "Erscheinungsjahr") {
            cout << "Geben Sie ein Erscheinungsjahr an." << endl;
            cin >> x;
            m_data[index-1].erscheinungsjahr = x;
        }
        
        if (y =="genre" | y == "Genre") {
            cout << "Bitte geben Sie das Genre an: ";
            
            cin >> l;
            
            if (l == "pop"){
                m_data[index-1].g = pop;
            }
            if (l == "rock"){
                m_data[index-1].g = rock;
            }
            if (l == "klassik"){
                m_data[index-1].g = klassik;
            }
            if (l == "hard rock"){
                m_data[index-1].g = hard_rock;
            }  
        }    
}
 
 void DynArray::detail(int index){
     cout << index <<  ". Eintrag" << endl;
     index = index - 1;
     cout << "Titel: " << m_data[index].titel << endl;
     cout << "Interpret: " << m_data[index].interpret << endl;
     cout << "Erscheinungsjahr: " << m_data[index].erscheinungsjahr << endl;
     cout << "Laenge: " << m_data[index].laenge << endl;
     if (m_data[index].g == 0) {
        cout << "Genre: Pop" << endl;
    }
        
    if (m_data[index].g == 1) {
        cout << "Genre: Rock" << endl;
    }
        
    if (m_data[index].g == 2) {
        cout << "Genre: Klassik" << endl;
    }   
    if (m_data[index].g == 3) {
        cout << "Genre: Hard Rock" << endl;    
    }  
 }