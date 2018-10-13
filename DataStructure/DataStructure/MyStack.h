#ifndef _MYSTACK_H_
#define _MYSTACK_H_
#include"pre.h"

//À≥–Ú’ª
class Stack_s {
public:
	Stack_s();
	Error_code push(const Stack_entry&);
	Error_code pop();
	bool empty()const;
	bool full()const;
	Error_code top(Stack_entry &item)const;
	void display();
private:
	int count;
	Stack_entry entry[MAXSTACK];
};
//¡¥ Ω’ª
class Stack_l {
public:
	Stack_l();
	Stack_l(const Stack_l &other);
	~Stack_l();
	bool empty()const;
	Error_code push(const Stack_entry&);
	Error_code pop();
	Error_code top(Stack_entry &item)const;
	void operator =(const Stack_l &other);
	void display();
private:
	Node *top_node;
};

#endif
