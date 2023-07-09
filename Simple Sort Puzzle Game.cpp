using namespace std;
#include <iostream>
//Class: data member, constructors, methods
class Vial {
	char contents[4];
	int filled;
	int label;

// The constructor has to be public. 
public:
	// default constructor:
	Vial() { 
		for (int i = 0; i < 4; i++) {
			contents[i] = ' ';
		}
		filled = 0;
		label = 0;

	}
	Vial(char contents[], int size, int filled) {
		for (int i = 0; i < size; i++) {
			this->contents[i] = contents[i];
		}
		this->filled = filled;
		this->label = 0;
	}
	Vial(char c1, char c2, char c3, char c4, int filled) {
		this->contents[0] = c1;
		this->contents[1] = c2;
		this->contents[2] = c3;
		this->contents[3] = c4;
		this->filled = filled;
		this->label = label;
	}

};

int main()
{
   
}

