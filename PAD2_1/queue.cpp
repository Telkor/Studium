#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size)
{
	m_data = new double[size]; //Erzeugen des Arrays
	m_front = 0; //Schreib- und Leseposition auf 0
	m_back = 0;
	m_size = size; //Uebernehmen des size-Wertes
	for(int i = 0; i < m_size; i++)
	{ //Fuellen mit -1, kann man auch weglassen
		m_data[i] = -1;
	}
}

Queue::~Queue()
{
	delete[] m_data;
}

void Queue::enqueue(double elem)
{
	if(full())
	{
		cout << "Fehler: Queue voll!" << endl;
		return;
	}
	m_data[m_front] = elem;
	m_front = (m_front + 1) % m_size;
}

double Queue::dequeue()
{
	if(empty())
	{
		cout << "Fehler: Queue leer!" << endl;
		return -1;
	}
	double tmp = m_data[m_back];
	m_back = (m_back + 1) % m_size;
	return tmp;
}

int Queue::size()
{
	return (m_size + m_front - m_back) % m_size;
}

void Queue::clear()
{
	m_front = 0;
	m_back = 0;
}

bool Queue::empty()
{
	if ( m_back == m_front)
		return true;
	return false;
}

bool Queue::full()
{
	if(m_back == m_front + 1) //Normalfall: Leseposition ist direkt hinter Schreibposition
		return true;
	else if(m_back == 0 && m_front == m_size -1) //Spezialfall: Ueber das Arrayende hinaus
		return true;
	return false;
}

void Queue::print()
{
	cout << m_front << ", " << m_back << " (" << size() << ") " << ": ";
	for(int i = 0; i < m_size; i++)
		cout << m_data[i] << " ";
	cout << endl;
}

