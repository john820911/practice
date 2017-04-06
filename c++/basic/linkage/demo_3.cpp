#include <iostream>

using std::cout;
using std::endl;

const int b = 1000;
extern int c;
static int d = 1000;
extern const int e;
static const int f = 1000;

void fb3() { cout << b << endl; }
void fc3() { c = 1000; cout << c << endl; }
void fd3() { d = 1000; cout << d << endl; }
void fe3() { cout << e << endl; }
void ff3() { cout << f << endl; }
