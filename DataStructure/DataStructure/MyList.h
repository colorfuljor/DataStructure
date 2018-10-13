#ifndef _MYLIST_H_
#define _MYLIST_H_
#include"pre.h"

//��List��STL��List��ͬ�����������vector
template<typename List_entry>
class List {
public:
	List();
	int size()const;
	bool full()const;
	void clear();
	void traverse(void(*vist)(List_entry));//����List������ÿ����ִ������ĺ���
	Error_code retrieve(int position, List_entry &)const;
	Error_code replace(int position, const List_entry &);
	Error_code remove(int position, List_entry &);
	Error_code insert(int postion, const List_entry &);
	void display();
protected:
	int count;
	List_entry entry[MAXLIST];
};

#endif