/* 
 * File:   Liste.cpp
 * Author: Michael Roth
 * 
 * Created on 10. Dezember 2014, 07:57
 */

#include "Liste.h"
#include <iostream>

Liste::Liste()
{
	m_size = 0;
	m_first = 0;
}

Liste::~Liste()
{
	//TODO:Elemente loeschen
}

Liste::Element* Liste::lastElement()
{

	Element* current = m_first;
	if (current == 0)
		return 0;
	if (current->next == 0)
		return current;

	while (current->next != 0)
	{
		current = current->next;
	}

	return current;
}

Person& Liste::first()
{
	if (m_first != 0)
	{
		return m_first->p;
	}
	//TODO: richtige Fehlerbehandlung!
}

Person& Liste::last()
{
	Element* last = lastElement();
	if (last != 0)
	{
		return last->p;
	}
	//TODO: richtige Fehlerbehandlung
}

int Liste::size()
{
	return m_size;
}

void Liste::push_back(const Person& p)
{
	Element* last = lastElement();
	if (last == 0)
	{
		m_first = new Element;
		m_first->next = 0;
		m_first->p = p;
	}
	else
	{
		last->next = new Element;
		last->next->next = 0;
		last->next->p = p;
	}
	m_size++;
}

void Liste::push_front(const Person& p)
{
	Element* tmp = new Element;
	tmp->p = p;
	tmp->next = m_first;
	m_first = tmp;
	m_size++;
}

void Liste::print()
{
	Element* curr = m_first;
	while (curr != 0)
	{
		::print(curr->p);
		curr = curr->next;
	}
}

Person Liste::pop_front()
{
	if (m_first != 0)
	{
		Element* tmp = m_first->next;
		Person p = m_first->p;
		delete m_first;
		m_first = tmp;
		m_size--;
		return p;
	}
	else
	{
		//TODO: richtige Fehlerbehandlung
		Person p;
		return p;
	}
}

Person Liste::pop_back()
{
	Person p;
	Element* curr = m_first;
	if(curr == 0)
	{
		return p;
	}
	if(curr->next == 0)
	{
		p = curr->p;
		delete curr;
		m_first = 0;
		m_size--;
		return p;
	}
	while(curr->next->next != 0)
	{
		curr = curr->next;
	}
	
	Element* tmp = curr;
	curr = curr->next;
	p = curr->p;
	delete curr;
	tmp->next = 0;
	m_size--;
	return p;
}




void print(const Person& p)
{
	using namespace std;
	cout << p.name << ", " << p.vorname << endl;
}









