#ifndef _PRE_H_
#define _PRE_H_
#include<iostream>
using namespace std;

typedef int Node_entry;
struct Node {
	Node_entry entry;
	Node *next;
	Node() { next = NULL; };
	Node(Node_entry item, Node *add_on = NULL) { entry = item; next = add_on; };
};
enum Error_code { success, overflow, underflow, range_error };

#define MAXSTACK 10
#define MAXQUEUE 10
#define MAXLIST 10

typedef int Stack_entry;
typedef int Queue_entry;


//queue_c
#define COUNT (MAXQUEUE+rear-front+1)%MAXQUEUE
#define ISEMPTY (COUNT == 0)
#define ISFULL (COUNT == MAXQUEUE-1)
#define next(i) (i + 1) % MAXQUEUE

#endif
