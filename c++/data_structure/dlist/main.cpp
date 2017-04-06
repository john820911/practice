#include <iostream>
#include "dlist.h"

using std::cout;
using std::endl;
using std::DList;

int main() {
	DList<int> d_l; DList<int>::iterator it;
	d_l.insert(-1); d_l.insert(0); d_l.insert(1); d_l.insert(2); d_l.insert(3);
	d_l.erase(-1); d_l.erase(0); d_l.erase(1); d_l.erase(2); d_l.erase(3);
	d_l.insert(-1); d_l.insert(0); d_l.insert(1); d_l.insert(2); d_l.insert(3);
	for(int i = 0; i < d_l.size(); ++i) {
		cout << d_l[i] << " ";
	}
	cout << endl;
	d_l.clear();
	for(int i = 0; i < d_l.size(); ++i) {
		cout << d_l[i] << " ";
	}
	cout << endl;
	return 0;
}