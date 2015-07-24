#include<iostream>
#include<string>
#include<list>

using namespace std;

void showList(list<int> &l)
{
	cout << "There are " << l.size() << " elements in list." << endl;
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}

int main()
{
	list <int> g_list1;

	g_list1.push_back(1);
	g_list1.push_back(2);
	g_list1.push_front(3);

	showList(g_list1);

	return 0;
}