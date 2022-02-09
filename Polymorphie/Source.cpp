#include <iostream>
#include <string>
using namespace std;
class Person {
	string name;
protected:
	string ahnenbaum[];
public:
	Person(string name) {
		ahnenbaum 
		this->name = name;
	}
	virtual void alltag() {
		cout << "Chilli, Chilli om nom" << endl;
	};
	virtual void nacht() {
		cout << "Schlaf, Schlaf" << endl;
	}
};
class Arbeiter : public Person {
	
	string arbeit;
public:
	Arbeiter(string name, string arbeit): Person(name) {
		this->arbeit = arbeit;
	}
	virtual void alltag() {
		cout << "Arbeite, Arbeite" << endl;
	}
	void nacht() {
		cout << "Schwitz, Schwitz" << endl;
	}
};

void doStuff(Person& p) {
	cout<<typeid(p).name() << endl;
	cout << (typeid(p) == typeid(Person)) << endl;
	p.alltag();
	p.nacht();
}
void doStuff(Person* p) {
	cout << typeid(*p).name() << endl;
	cout << (typeid(*p) == typeid(Person)) << endl;
	(*p).alltag();
	(*p).nacht();
}
int main() {
	Person p("Horst Seehofer");
	Arbeiter a("Karl Mags", "Schuhtester");
	doStuff(p);
	doStuff(a);
}
