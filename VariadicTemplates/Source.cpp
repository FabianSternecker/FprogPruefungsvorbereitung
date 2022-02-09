#include <string>
#include <iostream>
using namespace std;
template <typename T, typename... Rest>
void anzeigen(const T& obj, const Rest &... rest) {
	std::cout << obj << ' ';
	std::cout << " [" << sizeof...(Rest) << " Typ-Parameter] ";
	std::cout << " [" << sizeof...(rest) <<
		" Funktions-Parameter] ";
	anzeigen(rest...);
}

void f() { cout << endl; };
template<typename T,typename ...Ts> void f(T a,Ts ...args) {
	std::cout << to_string(a) << endl;
	f(args...);
};

int main() {
/*	string s1 = "hallo";
	string s2 = "tschuessli";
	string s3 = "muesli";
	anzeigen<string,string>(s1,s2);
*/
	f(1.0, 1.5, 1.4);

}
