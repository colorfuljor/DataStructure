#include"MyQueue.h"

Queue_c::Queue_c()
{
	front = 0;
	rear = MAXQUEUE - 1;
}

bool Queue_c::empty()const
{
	return ISEMPTY;
}

Error_code Queue_c::append(const Queue_entry &item)
{
	if (ISFULL)return overflow;
	
	rear = next(rear);
	entry[rear] = item;
	return success;
}

Error_code Queue_c::serve()
{
	if (ISEMPTY)return underflow;

	front = next(front);
	return success;
}

Error_code Queue_c::retrieve(Queue_entry &item)const
{
	if (ISEMPTY)return underflow;

	item = entry[front];
	return success;
}

//Extended queue
bool Queue_c::full()const
{
	return ISFULL;
}

void Queue_c::clear()
{
	front = 0;
	rear = MAXQUEUE - 1;
}

int Queue_c::size()const
{
	return COUNT;
}

Error_code Queue_c::serve_and_retrieve(Queue_entry &item)
{
	if (ISEMPTY)return underflow;

	item = entry[front];
	front = next(front);
	return success;
}
void Queue_c::display()
{
	if(ISEMPTY)
		cout << "\nEmpty!" << endl;
	if (ISFULL)
		cout << "\nFull!" << endl;
	for (int i = front; i <= rear; i = next(i)) {
		if(i == front)
			cout << "\n[front]" << entry[front] << "   ";
		else if(i == rear)
			cout << "[rear]" << entry[rear] << endl;
		else
		cout << "[" << i << "]" << entry[i] << "   ";
	}
}

//а╢й╫╤сап
Queue_l::Queue_l()
{
	rear = front = NULL;
}
Queue_l::Queue_l(const Queue_l &other)
{
	Node *other_node = other.front;
	if (other.front == NULL)
		rear = front = NULL;
	else {
		rear = front = new Node(other.front->entry);
		while (other_node->next != NULL) {
			other_node = other_node->next;
			rear->next = new Node(other_node->entry);
			rear = rear->next;
		}
	}
}
Queue_l::~Queue_l()
{
	while (!empty())
		serve();
}
void Queue_l::operator = (const Queue_l &other)
{
	Node *new_front,*new_rear,*other_node = other.front;
	if (other.front == NULL)
		new_rear = new_front = NULL;
	else {
		new_rear = new_front = new Node(other.front->entry);
		while (other_node->next != NULL) {
			other_node = other_node->next;
			new_rear->next = new Node(other_node->entry);
			new_rear = new_rear->next;
		}
	}
	while (!empty())
		serve();
	rear = new_rear;
	front = new_front;
}
bool Queue_l::empty()const
{
	return (front == NULL);
}
bool Queue_l::full()const
{
	Node *new_node = new Node();
	if (new_node == NULL) {
		delete new_node;
		return true;
	}
	else {
		delete new_node;
		return false;
	}
}
Error_code Queue_l::append(const Queue_entry &item)
{
	Node *new_rear = new Node(item);
	if (new_rear == NULL)return overflow;

	if (rear == NULL)rear = front = new_rear;
	else {
		rear->next = new_rear;
		rear = new_rear;
	}
	return success;
}
Error_code Queue_l::serve()
{
	if (front == NULL)return underflow;

	Node *old_front = front;
	front = old_front->next;
	if (front == NULL)
		rear = NULL;
	delete old_front;
	return success;
}
Error_code Queue_l::retrieve(Queue_entry &item)const
{
	if (front == NULL)return underflow;

	item = front->entry;
	return success;
}
void Queue_l::display()
{
	if (empty())
		cout << "\nEmpty!" << endl;
	else {
		cout << "\nFront ->";
		Node *window = front;
		while (window != rear) {
			cout << "[" << window->entry << "]->";
			window = window->next;
		}
		cout << "[" << window->entry << "]<- Rear" << endl;
	}
}
Error_code Queue_l::serve_and_retrieve(Queue_entry &item)
{
	if (front == NULL)return underflow;

	item = front->entry;
	Node *old_front = front;
	front = old_front->next;
	if (front == NULL)
		rear = NULL;
	delete old_front;
	return success;
}
void Queue_l::clear()
{
	while (!empty())
		serve();
}
int Queue_l::size()const
{
	Node *window = front;
	int count = 0;
	while (window != NULL) {
		window = window->next;
		count++;
	}
	return count;
}