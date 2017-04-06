#include <iostream>

using std::cout;
using std::endl;

class GrandFather {

public:
	GrandFather(int age = 100, int height = 160, int weight = 40): _age(age), _height(height), _weight(weight) { cout << "construct GrandFather" << endl; }
	/*destructed by method 1, construct GrandFather, construct Father, destruct GrandFather*/
	~GrandFather() { cout << "destruct GrandFather" << endl; }
	/*destructed by method 2, construct GrandFather, construct Father, destruct Father, destruct GrandFather
	virtual ~GrandFather() { cout << "destruct GrandFather" << endl; }
	*/
	/*destructed by method 3(pure destructor, declaration), construct GrandFather, construct Father, destruct Father, destruct GrandFather
	virtual ~GrandFather() = 0;
	*/

protected:

private:
	int _age;
	int _height;
	int _weight;

};

/*destructed by method 3(pure destructor, definition)
GrandFather::~GrandFather() { cout << "destruct GrandFather" << endl; }
*/

class Father: public GrandFather {

public:
	Father() { cout << "construct Father" << endl; }
	~Father() { cout << "destruct Father" << endl; }

protected:

private:

};

int main() {
	GrandFather* father = new Father;
	delete father;
	return 0;
}
