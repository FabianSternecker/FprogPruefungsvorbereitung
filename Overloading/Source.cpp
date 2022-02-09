#include <iostream>
#include <string>
class SubOverloading;
class Overloading {
private:
	static std::string b;
	static const std::string d;
	std::string c = "hallo";
public:
	virtual void foo(int a, int b, std::string c) { std::cout << "iid" << std::endl; }
	virtual void foo(int a, std::string c, int b) { std::cout << "idi" << std::endl; }
	virtual void test(int a) { std::cout << "i" << std::endl; }
	friend void hallo(Overloading& b, SubOverloading& f);
	friend void halloInClass() {
		std::cout << "hallo in class" << std::endl;
	};
	static void tschüss(){ std::cout << "tschüss" << std::endl; }
	/*Overloading operator =(Overloading& a) {
		std::cout << "test";
		return Overloading();

	}
	*/

};
std::string Overloading::b = "Hallo";
const std::string Overloading::d = "hallo";
class SubOverloading;

class SubOverloading : public Overloading {
	int foobar = 30;

public:
	int bar = 30;
	void foo(std::string c, int a, int b){ std::cout << "dii" << std::endl; }
	//Overloading& operator =(Overloading& a) = delete;
	friend void hallo(Overloading& b, SubOverloading& f);
	operator bool() {
		return bar == 30;
	}
};

void hallo(Overloading& b, SubOverloading& f) {
	b.c += "hallo2";
	f.foobar = 0;
	std::cout << b.c << std::endl;
}
int main() {
	//a.foo(1, 1, "3.0");
	//a.foo(1, "3.0", 1);
	/*
	a.foo("3.0", 1, 1);
	
	std::cout << a.bar;
	a = b;
	//a = d;
	std::cout << a.bar;
	*/
	SubOverloading a;
	SubOverloading* ap;
	SubOverloading b;
	Overloading c;
	hallo(c,a);
	c.tschüss();
	//c.halloInClass();
	Overloading* cp;
	a = b;
	a.bar += 3;
	std::cout << a.bar << std::endl;

	cp = &c;

	ap = (SubOverloading*)&c;
	ap->test(1);

	ap = dynamic_cast<SubOverloading*>(cp);
	//ap->test(1);

;
	std::cout << (*ap).bar;
	
}
