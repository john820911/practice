#include <iostream>

using std::cout;
using std::endl;

const int b = 100;
extern int c;
static int d = 100;
extern const int e;
static const int f = 100;

void fb2() { cout << b << endl; }
void fc2() { c = 100; cout << c << endl; }
void fd2() { d = 100; cout << d << endl; }
void fe2() { cout << e << endl; }
void ff2() { cout << f << endl; }
