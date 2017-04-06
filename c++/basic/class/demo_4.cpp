#include <iostream>

using std::cout;
using std::endl;

class GrandFather {

public:
	GrandFather() { cout << "construct GrandFather" << endl; }
	virtual ~GrandFather() = 0;
	void f() { cout << "function in GrandFather" << endl; }
	int _pub;

protected:
	int _pro;

private:
	int _pri;

};

GrandFather::~GrandFather() { cout << "destruct GrandFather" << endl; }

/*public inheritance*/
class Father: public GrandFather {

public:
	Father() { cout << "construct Father" << endl; }
	~Father() { cout << "destruct Father" << endl; }
	void f() { cout << "_pub: " << ++_pub << endl; cout << "_pro: " << ++_pro << endl; cout << "function in Father" << endl; }

protected:

private:

};


/*protected inheritance
class Father: protected GrandFather {

public:
	Father() { cout << "construct Father" << endl; }
	~Father() { cout << "destruct Father" << endl; }
	void f() { cout << "_pub: " << ++_pub << endl; cout << "_pro: " << ++_pro << endl; cout << "function in Father" << endl; }

protected:

private:

};
*/

/*private inheritance
class Father: private GrandFather {

public:
	Father() { cout << "construct Father" << endl; }
	~Father() { cout << "destruct Father" << endl; }
	void f() { cout << "_pub: " << ++_pub << endl; cout << "_pro: " << ++_pro << endl; cout << "function in Father" << endl; }

protected:

private:

};
*/

int main() {
	Father father;
	father.f();
	cout << father._pub << endl;
	return 0;
}