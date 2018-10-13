#include"MyList.h"

template<typename List_entry>
List<List_entry>::List() 
{
	count = 0;
}

template<typename List_entry>
int List<List_entry>::size()const 
{
	return count;
}

template<typename List_entry>
bool List<List_entry>::full()const
{
	return (count == MAXLIST);
}

template<typename List_entry>
void List<List_entry>::clear()
{
	count = 0;
}

template<typename List_entry>
void List<List_entry>::traverse(void(*vist)(List_entry))
{
	for (int i = 0; i < count; i++) {
		(*visit)(entry[i]);
	}
}

template<typename List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &item)const
{
	if (count == 0) return underflow;
	if (position < 0 || position > count) return ::range_error;

	item = entry[position];
	return success;
}

template<typename List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &item)
{
	if (position < 0 || position > count - 1) return ::range_error;

	entry[position] = item;
	return success;
}

template<typename List_entry>
Error_code List<List_entry>::remove(int position, List_entry &item)
{
	if (count == 0) return underflow;
	if (position < 0 || position > count) return ::range_error;

	item = entry[position];
	count--;
	for (int i = position; i < count; i++) {
		entry[i] = entry[i + 1];
	}
	return success;
}

template<typename List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &item)
{
	if (count == MAXLIST) return overflow;
	if (position < 0 || position > count) return ::range_error;

	for (int i = count; i > position; i--)
		entry[i] = entry[i - 1];
	entry[position] = item;
	count++;
	return success;
}

template<typename List_entry>
void List<List_entry>::display()
{
	if (full())
		cout << "\nFull!" << endl;
	if (count == 0)
		cout << "\nEmpty!" << endl;
	for (int i = 0; i < count; i++) {
		if (i == 0) cout << "\n";
		cout << "[" << i << "]" << entry[i];
		if (i == count - 1)
			cout << endl;
		else
			cout << "   ";
	}
}