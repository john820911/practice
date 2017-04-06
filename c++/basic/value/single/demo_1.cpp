//const value
#include <iostream>

using std::cout;
using std::endl;

class A {

public:
	A(const int x = 0): _x(x) { cout << &x << " " << &_x << endl; }
	~A() {}
	const int f() { return _x; }

private:
	const int _x;

};

int main() {
	A a(10);
	cout << a.f() << endl;
	return 0;	
}
//p.s const value, (const pointer), const argument, const function(can't assign to data members)
