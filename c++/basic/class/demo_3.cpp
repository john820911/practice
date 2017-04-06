#include <iostream>

using std::cout;
using std::endl;

class GrandFather {

public:
	GrandFather() { cout << "construct GrandFather" << endl; }
	virtual ~GrandFather() = 0;
	/*call fucntion by method 1, function in GrandFather*/
	void f() { cout << "function in GrandFather" << endl; }
	/*call function by method 2, function in Father
	virtual void f() { cout << "function in GrandFather" << endl; }
	*/

protected:

private:

};

GrandFather::~GrandFather() { cout << "destruct GrandFather" << endl; }

class Father: public GrandFather {

public:
	Father() { cout << "construct Father" << endl; }
	~Father() { cout << "destruct Father" << endl; }
	void f() { cout << "function in Father" << endl; }

protected:

private:

};

int main() {
	GrandFather* father = new Father;
	father -> f();
	delete father;
	return 0;
}
