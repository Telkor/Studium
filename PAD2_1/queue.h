#ifndef GUARD_QUEUE_H
#define GUARD_QUEUE_H

class Queue
{
public:
	Queue(int size = 10); //bestimmt die Groesse des zugrunde liegenden Arrays
	~Queue();
	
	void enqueue(double elem);
	double dequeue();
	int size();
	void clear();
	bool empty();
	bool full();
	void print(); //Dient nur zur Kontrolle, kann man auch weglassen
	
private:
	double* m_data;
	int m_front;
	int m_back;
	int m_size;
};

#endif