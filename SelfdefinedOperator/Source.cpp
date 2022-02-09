#include <iostream>
#include <string>
using namespace std;

template<int n = 3>
class OperatorInClass {
public:
	int* array;
	OperatorInClass() {
		array = new int[n];
		array[0] = 0;
		array[1] = 1;
		for (int i = 2; i < n; i++) {
			array[i] = array[i - 1] + array[i - 2];
		}
	}
	OperatorInClass(int a) {
		array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = a;
		}
	}
	OperatorInClass(OperatorInClass& other) {
		array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = other.array[i];
		}
	}
	OperatorInClass(OperatorInClass&& other){
		array = other.array;
		other.array = nullptr;
	}
	OperatorInClass<n> operator +(OperatorInClass<n>& other) { // funkioniert nur wenn other nicht kleiner als n ist
		for (int i = 0; i < n; i++) {
			array[i] += other.array[i];
		}
		return *this;
	}
	OperatorInClass operator ++(){
		for (int i = 0; i < n; i++) {
			array[i] += 1;
		}
		return *this;
	}
	OperatorInClass operator ++(int) {
		auto tmp = *this;
		for (int i = 0; i < n; i++) {
			array[i] += 1;
		}
		return tmp;
	}
	OperatorInClass operator --() {
		for (int i = 0; i < n; i++) {
			array[i] -= 1;
		}
		return *this;
	}
	ostream& operator >>(ostream& out) {
		string s;
		for (int i = 0; i < n; i++) {
			out << " " << to_string(array[i]);
		}
		return out << endl;
	}
	~OperatorInClass() {
		delete[] array;
	}

};

class OperatorOutOfClass {
	int n;
	friend OperatorOutOfClass operator +(OperatorOutOfClass& self, OperatorOutOfClass& other);
	friend ostream& operator <<(ostream& out, const OperatorOutOfClass& self){
		string s;
		for (int i = 0; i < self.n; i++) {
			out << " " << to_string(self.array[i]);
		}
		return out << endl;
	}

	friend OperatorOutOfClass operator ++(OperatorOutOfClass& self);
	friend OperatorOutOfClass operator ++(OperatorOutOfClass& self, int);
public:
	int* array;
	OperatorOutOfClass(int m):n(m) {
		array = new int[n];
		array[0] = 0;
		array[1] = 1;
		for (int i = 2; i < n; i++) {
			array[i] = array[i - 1] + array[i - 2];
		}
	}
	OperatorOutOfClass(OperatorOutOfClass& other):n(other.n) {
		array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = other.array[i];
		}
	}

	OperatorOutOfClass(OperatorOutOfClass&& other) :n(other.n) {
		array = other.array;
		other.array = nullptr;
		other.n = 0;
	}
	~OperatorOutOfClass() {
		delete[] array;
	}
	/*OperatorOutOfClass(int a) {
		array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = a;
		}
	}*/
	OperatorOutOfClass& operator=(OperatorOutOfClass& other) {
		delete[] array;

		n = other.n;
		array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = other.array[i];
		}
		return *this;
	}
	OperatorOutOfClass& operator=(OperatorOutOfClass&& other) {
		delete[] array;
		array = other.array;
		other.array = nullptr;
		other.n = 0;
		return *this;
	}

	template<int m>
	operator OperatorInClass<m>() {
		return OperatorInClass<n>();
	}
	operator string() {
		return "test";
	}

};
OperatorOutOfClass operator +(OperatorOutOfClass& self, OperatorOutOfClass& other) {
	for (int i = 0; i < self.n; i++) {
		self.array[i] = other.array[i] + 1;
	}
	return self;
}
OperatorOutOfClass operator ++(OperatorOutOfClass& self) {
	for (int i = 0; i < self.n; i++) {
		self.array[i] += 1;
	}
	return self;
}
OperatorOutOfClass operator ++(OperatorOutOfClass& self,int) {
	auto tmp = self;
	for (int i = 0; i < self.n; i++) {
		self.array[i] += 1;
	}
	return tmp;
}

template<typename T>
class OperatorOutOfClassTemplate {
	friend OperatorOutOfClassTemplate operator +(OperatorOutOfClassTemplate& self, OperatorOutOfClassTemplate& other);
};

template<typename T>
OperatorOutOfClassTemplate<T> operator +(OperatorOutOfClassTemplate<T>& self, OperatorOutOfClassTemplate<T>& other) {
	for (int i = 0; i < self.n; i++) {
		self.array[i] = other.array[i] + 1;
	}
	return self;
}
int main() {
	OperatorInClass<6> a;
	a >> cout;
	/*a++ >> cout;
	++a >> cout;
	*/

	OperatorInClass<6> c = 3;
	//c = a + c;
	c >> cout;
	OperatorOutOfClass b(6);
	std::cout << b;
	b = 5;
	b = b + b;
	//b = b + (OperatorOutOfClass)5;
	std::cout << b++;
	std::cout << ++b;
	b = OperatorOutOfClass(6);
}