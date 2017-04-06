#include <iostream>

using std::cout;
using std::endl;

int a = 10;
const int b = 10; //header
extern int c; //header
int c = 10; 
static int d = 10; //header
extern const int e; //header
extern const int e = 10;
static const int f = 10; //header

//below function declaration can write in another header also
void fb2();
void fc2();
void fd2();
void fe2();
void ff2();
void fb3();
void fc3();
void fd3();
void fe3();
void ff3();

int main() {
	fb2();
	fc2();
	fd2();
	fe2();
	ff2();
	fb3();
	fc3();
	fd3();
	fe3();
	ff3();
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
	return 0;
}