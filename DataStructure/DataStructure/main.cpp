#include"MyStack.h"
#include"MyQueue.h"
#include"MyList.h"
#include"MyList.cpp"//写模板类需要.cpp与.h一起被include，或全部在.h里实现，或在.h中包含.cpp
#include<iostream>
#include <math.h>
int count = 0;
void menu();
void stack();
void queue();
void list();
void sequence_stack();
void linked_stack();
void circle_queue();
void linked_queue();
void recursion();
void contuguous_list();
void linke_list();
int factorial(int n);
int factorial_i(int n);
int fibonacci(int n);
int fibonacci_i(int n);
void hanoi(int n, int start, int finish, int temp);

int main()
{
	menu();

	system("pause");
	return 0;
}
void menu() 
{
	while (1) {
		char choice;
		cout << "\n                       ---  Menu  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;//60
		cout << " 1.Stack     2.Queue     3.Recursion     4.List" << endl;
		cout << "*                                                          *" << endl;
		cout << " ?.(...)" << endl;
		cout << "*                                                          *" << endl;
		cout << "                             ..." << endl;
		cout << " ----------------------------*" << endl;//30
		cout << " m.Menu                q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;

		cin >> choice;
		switch (choice) {
		case '1':
			stack();
			break;
		case '2':
			queue();
			break;
		case '3':
			recursion();
			break;
		case '4':
			list();
			break;
		case 'q':
			exit(0);
		case'm':
			break;
		default:
			cout << "No such option" << endl;
			break;
		}
	}
}

void stack()
{
	while (1) {
		char choice;

		cout << "\n                    ---  Stack Menu  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << " 1.Sequence Stack     2.Linked Stack" << endl;
		cout << "                             ..." << endl;
		cout << " ----------------------------*" << endl;
		cout << " m.Menu     b.Back     q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;
		cin >> choice;
		switch (choice) {
		case '1':
			sequence_stack();
			break;
		case'2':
			linked_stack();
			break;
		case'm':
			menu();
			break;
		case 'b':
			return;
		case 'q':
			exit(0);
		default:
			cout << "No such option" << endl;
			break;
		}
	}
}

void queue()
{
	while (1) {
		char choice;

		cout << "\n                    ---  Queue Menu  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << " 1.Circle Queue     2.Linked Queue" << endl;
		cout << "                             ..." << endl;
		cout << " ----------------------------*" << endl;
		cout << " m.Menu     b.Back     q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;

		cin >> choice;
		switch (choice) {
		case '1':
			circle_queue();
			break;
		case'2':
			linked_queue();
			break;
		case'm':
			menu();
			break;
		case 'b':
			return;
		case 'q':
			exit(0);
		default:
			cout << "No such option" << endl;
			break;
		}
	}
}
void sequence_stack()
{
	Stack_s test;
	while (1) {
		char choice;
		cout << "\n                  ---  Sequence Stack  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << " 1.Push     2.Pop     3.Top" << endl;
		cout << "*                                                          *" << endl;
		cout << " 4.Empty     5.Display" << endl;
		cout << " ----------------------------*" << endl;
		cout << " m.Menu     b.Back     q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;

		cin >> choice;
		switch (choice) {
		case '1':
			cout << "\nPlese input the numbers you want to push:" << endl;
			int temp;
			while (cin >> temp) {
				if (test.push(temp) == overflow) {
					cout << "\nOverflow" << endl;
					break;
				}
				if (cin.get() == '\n')break;
			}
			test.display();
			break;
		case '2':
			if (test.pop() == underflow)
				cout << "\nUnderflow" << endl;
			else
			    test.display();
			break;
		case '4':
			if (test.empty())
				cout << "\nEmpty!" << endl;
			else {
				cout << "\nNot Empty." << endl;
				test.display();
			}
			break;
		case '3':
			int top;
			if (test.top(top) == underflow) 
				cout << "\nUnderflow" << endl;
			else
				cout << "\nTop -> [" << top << "]" << endl;
			break;
		case '5':
			test.display();
			break;
		case 'b':
			return;
		case 'm':
			menu();
			break;
		case 'q':
			exit(0);
		default:
			cout << "\nNo such option" << endl;
			break;
		}
	}
}
void linked_stack()
{
	Stack_l test;
	while (1) {
		char choice;
		cout << "\n                   ---  Linked Stack  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << " 1.Push     2.Pop     3.Top" << endl;
		cout << "*                                                          *" << endl;
		cout << " 4.Empty     5.Display" << endl;
		cout << " ----------------------------*" << endl;
		cout << " m.Menu     b.Back     q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;

		cin >> choice;
		switch (choice) {
		case '1':
			cout << "\nPlese input the numbers you want to push:" << endl;
			int temp;
			while (cin >> temp) {
				if (test.push(temp) == overflow) {
					cout << "\nOverflow" << endl;
					break;
				}
				if (cin.get() == '\n')break;
			}
			test.display();
			break;
		case '2':
			if (test.pop() == underflow)
				cout << "\nUnderflow" << endl;
			else
				test.display();
			break;
		case '4':
			if (test.empty())
				cout << "\nEmpty!" << endl;
			else {
				cout << "\nNot Empty." << endl;
				test.display();
			}
			break;
		case '3':
			int top;
			if (test.top(top) == underflow)
				cout << "\nUnderflow" << endl;
			else
				cout << "\nTop -> [" << top << "]" << endl;
			break;
		case '5':
			test.display();
			break;
		case 'b':
			return;
		case 'm':
			menu();
			break;
		case 'q':
			exit(0);
		default:
			cout << "\nNo such option" << endl;
			break;
		}
	}
}
void circle_queue()
{
	Queue_c test;
	while (1) {
		char choice;
		cout << "\n                   ---  Circle Queue  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << " 1.Append     2.Serve     3.Retrieve     \n\n 4.Serve and Retrieve     5.Clear" << endl;
		cout << "*                                                          *" << endl;
		cout << " 6.Size     7.Empty     8.Full     9.Display" << endl;
		cout << " ----------------------------*" << endl;
		cout << " m.Menu     b.Back     q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;

		cin >> choice;
		switch (choice) {
		case '1':
			cout << "\nPlese input the numbers you want to push:" << endl;
			int temp;
			while (cin >> temp) {
				if (test.append(temp) == overflow) {
					cout << "\nOverflow" << endl;
					break;
				}
				if (cin.get() == '\n')break;
			}
			test.display();
			break;
		case '2':
			if (test.serve() == underflow)
				cout << "\nUnderflow" << endl;
			else
				test.display();
			break;
		case '3':
			int front;
			if (test.retrieve(front) == underflow) 
				cout << "\nUnderflow" << endl;
			else {
				cout << "\n[front]" << front << endl;
			}
			break;
		case '4':
			if (test.serve_and_retrieve(front) == underflow)
				cout << "\nUnderflow" << endl;
			else {
				cout << "\n[Ex-front]" << front << endl;
				test.display();
			}
			break;
		case '5':
			test.clear();
			test.display();
			break;
		case'6':
			cout << "There are " << test.size() << " elements." << endl;
			break;
		case '7':
			if (test.empty())
				cout << "\nEmpty!" << endl;
			else {
				cout << "\nNot Empty." << endl;
				test.display();
			}
			break;
		case '8':
			if (test.full())
				cout << "\nFull!" << endl;
			else {
				cout << "\nNot Full." << endl;
				cout << "There are " << MAXQUEUE - test.size() - 1 << " empty seats left." << endl;
			}
			break;
		case '9':
			test.display();
			break;
		case 'b':
			return;
		case 'm':
			menu();
			break;
		case 'q':
			exit(0);
		default:
			cout << "\nNo such option" << endl;
			break;
		}
	}
}
void linked_queue()
{
	Queue_l test;
	while (1) {
		char choice;
		cout << "\n                   ---  Linked Queue  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << " 1.Append     2.Serve     3.Retrieve     \n\n 4.Serve and Retrieve     5.Clear" << endl;
		cout << "*                                                          *" << endl;
		cout << " 6.Size     7.Empty     8.Full     9.Display" << endl;
		cout << " ----------------------------*" << endl;
		cout << " m.Menu     b.Back     q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;

		cin >> choice;
		switch (choice) {
		case '1':
			cout << "\nPlese input the numbers you want to push:" << endl;
			int temp;
			while (cin >> temp) {
				if (test.append(temp) == overflow) {
					cout << "\nOverflow" << endl;
					break;
				}
				if (cin.get() == '\n')break;
			}
			test.display();
			break;
		case '2':
			if (test.serve() == underflow)
				cout << "\nUnderflow" << endl;
			else
				test.display();
			break;
		case '3':
			int front;
			if (test.retrieve(front) == underflow)
				cout << "\nUnderflow" << endl;
			else {
				cout << "\nFront ->[" << front << "]" << endl;
			}
			break;
		case '4':
			if (test.serve_and_retrieve(front) == underflow)
				cout << "\nUnderflow" << endl;
			else {
				cout << "\nEx-front ->[" << front << "]" << endl;
				test.display();
			}
			break;
		case '5':
			test.clear();
			test.display();
			break;
		case'6':
			cout << "There are " << test.size() << " elements." << endl;
			break;
		case '7':
			if (test.empty())
				cout << "\nEmpty!" << endl;
			else {
				cout << "\nNot Empty." << endl;
				test.display();
			}
			break;
	    case '8':
			if (test.full())
				cout << "\nFull!" << endl;
			else {
				cout << "\nThere's still plenty of room." << endl;
			}
			break;
		case '9':
			test.display();
			break;
		case 'b':
			return;
		case 'm':
			menu();
			break;
		case 'q':
			exit(0);
		default:
			cout << "\nNo such option" << endl;
			break;
		}
	}
}

void recursion()
{
	while (1) {
		char choice;
		cout << "\n                  ---  Recurison  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << " 1.Hanoi\n" << endl;
		cout << " 2.Factorial     3.Iteration Factorial\n" << endl;
		cout << " 4.Fibonacci     5.Iteration Fibonacci\nl" << endl;
		cout << " ----------------------------*" << endl;
		cout << " m.Menu     b.Back     q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;

		cin >> choice;
		switch (choice) {
		case '2':
			int n;
			cout << "Please input the number:";
			cin >> n;
			cout << "Result:" << factorial(n) << endl;
			break;
		case '1':
			::count = 0;
			cout << "Please input the number:";
			cin >> n;
			hanoi(n, 1, 3, 2);
			if (int(pow(2, n) - 1) % 3)
				cout << endl;
			break;
		case '3':
			cout << "Please input the number:";
			cin >> n;
			cout << "Result:" << factorial_i(n) << endl;
			break;
		case '4':
			cout << "Please input the number:";
			cin >> n;
			cout << "Result:" << fibonacci(n) << endl;
			break;
		case '5':
			cout << "Please input the number:";
			cin >> n;
			cout << "Result:" << fibonacci_i(n) << endl;
			break;
		case 'b':
			return;
		case 'm':
			menu();
			break;
		case 'q':
			exit(0);
		default:
			cout << "\nNo such option" << endl;
			break;
		}
	}
}
int factorial(int n)
{
	if (n == 1)return 1;

	return factorial(n - 1) * n;
}
void hanoi(int n, int start, int finish, int temp)
{

	if (n == 1) {
		cout << ++::count << ":" << start << " => " << finish;
		if (::count % 3 == 0)
			cout << endl;
		else
			cout << "   ";
	}
	else {
		hanoi(n - 1, start, temp, finish);
		cout << ++::count << ":" << start << " => " << finish;
		if (::count % 3 == 0)
			cout << endl;
		else
			cout << "   ";
		hanoi(n - 1, temp, finish, start);
	}
}
int factorial_i(int n)
{
	if (n == 1)return 1;
	int result = 1;
	for (int i = 2; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
int fibonacci(int n)
{
	if (n <= 0)return 0;
	else if (n == 1)return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}
int fibonacci_i(int n)
{
	if (n <= 0)return 0;
	else if (n == 1)return 1;
	
	int current, first = 0, second = 1;
	for (int i = 1; i < n; i++) {
		current = first + second;
		first = second;
		second = current;
	}
	return current;
}

void list()
{
	while (1) {
		char choice;

		cout << "\n                    ---  List Menu  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << " 1.Contuguous List     2.Linke List" << endl;
		cout << "                             ..." << endl;
		cout << " ----------------------------*" << endl;
		cout << " m.Menu     b.Back     q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;
		cin >> choice;
		switch (choice) {
		case '1':
			contuguous_list();
			break;
		case'2':
			linke_list();
			break;
		case'm':
			menu();
			break;
		case 'b':
			return;
		case 'q':
			exit(0);
		default:
			cout << "No such option" << endl;
			break;
		}
	}
}

void contuguous_list()
{
	List<int> test;
	int pos, num;
	Error_code msg;
	while (1) {
		char choice;
		cout << "\n                   ---  Contuguous List  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << " 1.Insert     2.Remove     3.Retrieve     \n\n 4.Traverse    5.Replace    6.Clear" << endl;
		cout << "*                                                          *" << endl;
		cout << " 6.Size     7.Full     8.Display" << endl;
		cout << " ----------------------------*" << endl;
		cout << " m.Menu     b.Back     q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;

		cin >> choice;
		switch (choice) {
		case '1':
			cout << "\nPlese input the position:" << endl;
			cin >> pos;
			cout << "\nPlese input the number:" << endl;
			cin >> num;
			msg = test.insert(pos, num);
			if(msg == overflow) cout << "\nOverflow" << endl;
			if(msg == ::range_error) cout << "\nRange error" << endl;
			test.display();
			break;
		case '2':
			cout << "\nPlese input the position:" << endl;
			cin >> pos;
			msg = test.remove(pos, num);
			if (msg == underflow) cout << "\nUnderflow" << endl;
			if (msg == ::range_error) cout << "\nRange error" << endl;
			if (msg == success) cout << "\nRemove " << num << " from [" << pos << "]."<< endl;
			test.display();
			break;
		case '3':
			cout << "\nPlese input the position:" << endl;
			cin >> pos;
			msg = test.retrieve(pos, num);
			if (msg == underflow) cout << "\nUnderflow" << endl;
			if (msg == ::range_error) cout << "\nRange error" << endl;
			if (msg == success) cout << "\nThis position is " << num << "." << endl;
			break;
		case '4':
			cout << "\nUnopened." << endl;
			break;
		case '5':
			cout << "\nPlese input the position:" << endl;
			cin >> pos;
			cout << "\nPlese input the number:" << endl;
			cin >> num;
			msg = test.replace(pos, num);
			if (msg == ::range_error) cout << "\nRange error" << endl;
			if (msg == success) cout << "\nReplace the position [" << pos << "] with " << num << "." << endl;
			test.display();
			break;
		case'6':
			cout << "\nNow has " << test.size() << " elements." << endl;
			test.display();
			break;
		case '7':
			test.display();
			break;
		case '8':
			test.display();
			break;
		case 'b':
			return;
		case 'm':
			menu();
			break;
		case 'q':
			exit(0);
		default:
			cout << "\nNo such option" << endl;
			break;
		}
	}
}

void linke_list()
{
	List<int> test;
	int pos, num;
	Error_code msg;
	while (1) {
		char choice;
		cout << "\n                    ---  Linked List  ---" << endl;
		cout << "*                                                          *" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << " 1.Insert     2.Remove     3.Retrieve     \n\n 4.Traverse    5.Replace    6.Clear" << endl;
		cout << "*                                                          *" << endl;
		cout << " 6.Size     7.Full     8.Display" << endl;
		cout << " ----------------------------*" << endl;
		cout << " m.Menu     b.Back     q.Quit" << endl;
		//cout << "*----------------------------------------------------------*" << endl;
		cout << endl;

		cin >> choice;
		switch (choice) {
		case '1':
			cout << "\nPlese input the position:" << endl;
			cin >> pos;
			cout << "\nPlese input the number:" << endl;
			cin >> num;
			msg = test.insert(pos, num);
			if (msg == overflow) cout << "\nOverflow" << endl;
			if (msg == ::range_error) cout << "\nRange error" << endl;
			test.display();
			break;
		case '2':
			cout << "\nPlese input the position:" << endl;
			cin >> pos;
			msg = test.remove(pos, num);
			if (msg == underflow) cout << "\nUnderflow" << endl;
			if (msg == ::range_error) cout << "\nRange error" << endl;
			if (msg == success) cout << "\nRemove " << num << " from [" << pos << "]." << endl;
			test.display();
			break;
		case '3':
			cout << "\nPlese input the position:" << endl;
			cin >> pos;
			msg = test.retrieve(pos, num);
			if (msg == underflow) cout << "\nUnderflow" << endl;
			if (msg == ::range_error) cout << "\nRange error" << endl;
			if (msg == success) cout << "\nThis position is " << num << "." << endl;
			break;
		case '4':
			cout << "\nUnopened." << endl;
			break;
		case '5':
			cout << "\nPlese input the position:" << endl;
			cin >> pos;
			cout << "\nPlese input the number:" << endl;
			cin >> num;
			msg = test.replace(pos, num);
			if (msg == ::range_error) cout << "\nRange error" << endl;
			if (msg == success) cout << "\nReplace the position [" << pos << "] with " << num << "." << endl;
			test.display();
			break;
		case'6':
			cout << "\nNow has " << test.size() << " elements." << endl;
			test.display();
			break;
		case '7':
			test.display();
			break;
		case '8':
			test.display();
			break;
		case 'b':
			return;
		case 'm':
			menu();
			break;
		case 'q':
			exit(0);
		default:
			cout << "\nNo such option" << endl;
			break;
		}
	}
}