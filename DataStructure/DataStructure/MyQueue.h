#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#include"pre.h"

class Queue_c {
public:
	Queue_c();
	bool empty()const;
	Error_code append(const Queue_entry &);
	Error_code serve();
	Error_code retrieve(Queue_entry &)const;
	bool full()const;
	void clear();
	int size()const;
	Error_code serve_and_retrieve(Queue_entry &);
	void display();
protected:
	int front,rear;
	Queue_entry entry[MAXQUEUE];
};

class Queue_l {
public:
	Queue_l();
	Queue_l(const Queue_l &);
	~Queue_l();
	void operator = (const Queue_l &);
	Error_code append(const Queue_entry &);
	Error_code serve();
	Error_code retrieve(Queue_entry &)const;
	Error_code serve_and_retrieve(Queue_entry &);
	void clear();
	bool full()const;
	bool empty()const;
	int size()const;
	void display();
protected:
	Node *rear, *front;
};

#endif