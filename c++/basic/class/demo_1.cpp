#include <iostream>

using std::cout;
using std::endl;

/*constructed by method 1*/
class GrandFather {

public:
	GrandFather() { cout << "construct GrandFather using 1st method" << endl; }
	GrandFather(int age) { _age = age; cout << "construct GrandFather using 2nd method" << endl; }
	GrandFather(int age, int height) { _age = age; _height = height; cout << "construct GrandFather using 3rd method" << endl; }
	GrandFather(int age, int height, int weight) { _age = age; _height = height; _weight = weight; cout << "construct GrandFather using 4th method" << endl; }
	~GrandFather() { cout << "destruct GrandFather" << endl; }

protected:

private:
	int _age;
	int _height;
	int _weight;
};

int main() {
	GrandFather grandfather_obj_1;
	GrandFather grandfather_obj_2(100);
	GrandFather grandfather_obj_3(100, 160);
	GrandFather grandfather_obj_4(100, 160, 40);
	return 0;
}

/*constructed by method 2
class GrandFather {

public:
	GrandFather(int age = 100, int height = 160, int weight = 40) { _age = age; _height = height; _weight = weight; cout << "construct GrandFather" << endl; }
	~GrandFather() { cout << "destruct GrandFather" << endl; }

protected:

private:
	int _age;
	int _height;
	int _weight;

};

int main() {
	GrandFather grandfather_obj_1;
	GrandFather grandfather_obj_2(100);
	GrandFather grandfather_obj_3(100, 160);
	GrandFather grandfather_obj_4(100, 160, 40);
	return 0;
}
*/

/*constructed by method 3
class GrandFather {

public:
	GrandFather(int age, int height, int weight): _age(age), _height(height), _weight(weight) { cout << "construct GrandFather" << endl; }
	~GrandFather() { cout << "destruct GrandFather" << endl; }

protected:

private:
	int _age;
	int _height;
	int _weight;

};

int main() {
	GrandFather grandfather_obj_4(100, 160, 40);
	return 0;
}
*/
