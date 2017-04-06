//const pointer to array
#include <iostream>

using std::cout;
using std::endl;

class A {

public:
	typedef const int (*int_ptr_to_arr)[3];
	A(const int (*x)[3]): _x(x) {}
	~A() {}
	int_ptr_to_arr f() const { return _x; }
	const void g1(const int (*x)) const { for(int i = 0; i < 3; ++i) { cout << x[i] << " "; } }
	const void g2(const int (*x)[3]) const { for(int i = 0; i < 2; ++i) { g1(x[i]); cout << endl; } }

private:
	const int (*_x)[3];

};

int main() {
	const int x[2][3] = {{1, 2, 3}, {4, 5, 6}};
	A a(x);
	a.g2(a.f());
	return 0;
}
