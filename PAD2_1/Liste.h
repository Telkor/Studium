/* 
 * File:   Liste.h
 * Author: Michael Roth
 *
 * Created on 10. Dezember 2014, 07:57
 */

#ifndef LISTE_H
#define	LISTE_H

#include <string>

struct Person
{
	std::string name;
	std::string vorname;
	std::string telefon;
	std::string adresse;
};

void print(const Person& p);

class Liste
{
public:
	Liste();
	virtual ~Liste();

	void push_back(const Person& p);
	Person pop_back();
	Person& last();

	void push_front(const Person& p);
	Person pop_front();
	Person& first();

	int size();
	
	void print();

private:

	struct Element
	{
		Person p;
		Element* next;
	};

	Element* lastElement();

	Element* m_first;
	int m_size;

};

#endif	/* LISTE_H */

