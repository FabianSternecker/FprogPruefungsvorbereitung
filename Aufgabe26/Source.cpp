#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define SWAP = 
int main() {
	string values_string;
	vector<int> values_int;
	int size;
	int median;
	getline(std::cin, values_string);

	values_int.push_back(stoi(values_string.substr(0, values_string.find(" "))));

	for (auto in : values_string) {	
		values_int.push_back(in - '0');
	}
	values_string.
	size = values_int.size();
	median = values_int.at(size / 2);

	cout << "Median: " << median << endl;
}