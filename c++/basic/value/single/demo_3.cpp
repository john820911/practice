//common
#include <iostream>

using std::cout;
using std::endl;

class A {

public:
	A(const int& x): _x(x) { cout << &x << " " << &_x << endl; }
	~A() {}
	int f() const { return _x; }

private:
	int _x;

};

int main() {
	A a(10);
	cout << a.f() << endl;
	return 0;
}
