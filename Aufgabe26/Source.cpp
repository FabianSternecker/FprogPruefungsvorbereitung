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
	string substring;
	int pos=0;
	int old_pos=0;
	while (true) {
		pos = values_string.find(" ");
		if (pos != string::npos) {
			substring = values_string.substr(old_pos, pos);
			values_int.push_back(stoi(substring));
		}
		old_pos = pos;
	}
	median = values_int.at(values_int.size() / 2);

	cout << "Median: " << median << endl;
}