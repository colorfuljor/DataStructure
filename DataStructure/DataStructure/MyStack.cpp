#include"MyStack.h"

//Ë³ÐòÕ»
Stack_s::Stack_s()
{
	count = 0;
}

Error_code Stack_s::push(const Stack_entry &item)
{
	if (count >= MAXSTACK)
		return overflow;

	entry[count++] = item;
	return success;
}

Error_code Stack_s::pop()
{
	if (count == 0)
		return underflow;

	count--;
	return success;
}

bool Stack_s::empty()const
{
	return (count == 0);
}

Error_code Stack_s::top(Stack_entry &item)const
{
	if (count == 0)
		return underflow;

	item = entry[count - 1];
	return success;
}

void Stack_s::display()
{
	for (int i = count - 1; i >= 0; i--) {
		if (i == count - 1)
			cout << "\nTop -> [" << entry[i] << "]" << endl;
		else
			cout << "       [" << entry[i] << "]" << endl;
	}
	if (count == 0)
		cout << "\nEmpty!" << endl;
	if (count == MAXSTACK)
		cout << "\nFull!" << endl;
}

bool Stack_s::full()const
{
	return (count == MAXSTACK);
}

//Á´Ê½Õ»
Stack_l::Stack_l()
{
	top_node = NULL;
}

Error_code Stack_l::push(const Stack_entry &item)
{
	Node* new_node = new Node(item,top_node);
	if (new_node == NULL)return overflow;

	top_node = new_node;
	return success;
}

Error_code Stack_l::pop()
{
	if (top_node == NULL)return underflow;

	Node* old_top = top_node;
	top_node = old_top->next;
	delete old_top;
	return success;
}

Error_code Stack_l::top(Stack_entry &item)const
{
	if (top_node == NULL)return underflow;

	item = top_node->entry;
	return success;
}

bool Stack_l::empty()const
{
	return (top_node == NULL);
}

Stack_l::~Stack_l()
{
	while (!empty())
		pop();
}

void Stack_l::operator =(const Stack_l &other)
{
	Node *new_top,*copy_node,*other_node = other.top_node;
	if (other_node == NULL)
		new_top = NULL;
	else {
		new_top = copy_node = new Node(other_node->entry);
		while (other_node->next != NULL) {
			other_node = other_node->next;
			copy_node->next = new Node(other_node->entry);
			copy_node = copy_node->next;
		}
	}
	while (!empty())
		pop();
	top_node = new_top;
}

Stack_l::Stack_l(const Stack_l &other)
{
	Node  *copy_node, *other_node = other.top_node;
	if (other_node == NULL)
		top_node = NULL;
	else {
		top_node = copy_node = new Node(other_node->entry);
		while (other_node->next != NULL) {
			other_node = other_node->next;
			copy_node->next = new Node(other_node->entry);
			copy_node = copy_node->next;
		}
	}
}

void Stack_l::display()
{
	if (top_node == NULL)
		cout << "\nEmpty!" << endl;
	Node *index = top_node;
	cout << "\nTop -> ";
	while (index != NULL)
	{
		cout << "[" << index->entry << "]->";
		index = index->next;
	}
	cout << " NULL" << endl;
}