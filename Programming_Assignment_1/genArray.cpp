#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){

	int size;
	int type;
	
	cout << "Size of Array: ";
	cin >> size;
	cout << "Type of Array (1 for integers, 2 for reals): ";
	cin >> type;

	// just creating these here to avoid errors
	int intArr[size];
	float floatArr[size];
	
	if (type == 1) {
		for (int i = 0; i < size; i++)	// random integer with range [0, 2^16)
			intArr[i] = rand() % 65535 + 1;
	}
	else if (type == 2) {
		for (int i = 0; i < size; i++){	// creates a random float, rounds up and casts to integer with *100 in order to ensure a precision of 2
			float temp = (float)((int)((double)rand()/((double)RAND_MAX+1)*100 + .5)) / 100;
			floatArr[i] = (temp == 1 ? 0.99 : temp);
		}
	}
	else {
		cout << "Failed: incorrect type... Exiting..." << endl;
		return 0;
	}

	// naming the file
	stringstream ss;
	ss << size;
	string filename = ss.str();
	filename += (type == 1) ? "int" : "real";
	filename += "Arr.txt";
	
	// opening and outputing the values to the array.
	ofstream f;
	f.open(filename.c_str());
	f << size << endl;
	for (int i = 0; i < size; i++) {
		if (type == 1)
			f << intArr[i] << " ";
		else
			f << floatArr[i] << " ";
	}
	f.close();

	return 0;
}
