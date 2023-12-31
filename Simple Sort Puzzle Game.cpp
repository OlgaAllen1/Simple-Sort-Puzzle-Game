using namespace std;
#include <iostream>
#include <string>

//Class: data member, constructors, methods
class Vial {
private:
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
	//Paremetirized constructors:
	Vial(char c1, char c2, char c3, char c4, int filled) {
		this->contents[0] = c1;
		this->contents[1] = c2;
		this->contents[2] = c3;
		this->contents[3] = c4;
		this->filled = filled;
		this->label = 0;
	}
	bool add(char content) {
		if (filled < 4) {
			contents[filled] = content;
			filled++;
			return true;
		}
		else {
			cout << "The vial is full." << endl;
			return false;
		}
	};
	void display() {
		cout << label << " [";
		for (int i = 0;i < filled; i++) {
			cout << contents[i];
		}
		cout << "]" << endl;
	};
	bool isComplete() {
		char firstItem = contents[0];
		for (int i = 1; i < filled; i++) {
			if (contents[i] != firstItem) {
				return false;
			};
		};
		return filled == 4 || filled == 0;
	};
	int getFilled() {
		return filled;
	}
	
	char* getContents() {
		return contents;
	};
	
	void setLabel(int label) {
		this->label = label;
	};
	bool transfer(Vial& destination) {
		if (this->filled == 0) {
			cout << "The source is empty" << endl;
			return false;
		}
		else if (destination.filled == 4) {
			cout << "The destination is filled" << endl;
			return false;
		}
		else if (destination.filled > 0 && this->contents[filled - 1] != destination.contents[destination.filled - 1]) {
			cout << "Contents do not match" << endl;
			return false;
		}
		else {
			int numberOfTransfers = 0;
			for (int i = filled - 1;i >= 0; i--) {
				if (contents[i] != contents[filled - 1]) {
					break;
				}
				else { numberOfTransfers++; }
			}
			if (numberOfTransfers + destination.filled > 4) {
				numberOfTransfers = 4 - destination.filled;
			}
			for (int i = 0; i < numberOfTransfers; i++) {
				destination.contents[destination.filled] = contents[filled - 1];
				destination.filled++;
			}
			for (int i = filled - 1; i >= filled - numberOfTransfers; i--) {
				contents[i] = ' ';
			}
			filled = filled - numberOfTransfers;
			return true;
		}

	};
};

void displayVials(Vial* vials, int numberOfVials) {
	for (int i = 0; i < numberOfVials; i++) {
		vials[i].display();
	}

}

bool isGameComplete(Vial* vials, int numberOfVials) {
	for (int i = 0; i < numberOfVials;i++) {
		if (!vials[i].isComplete()) {
			return false;
		}
		
	}
	return true;
}

bool isStringDigits(string input) {
	for (char symbol : input) {
		if (!isdigit(symbol)) {
			return false;
		}
	}
	return true;
}

int main()
{
	cout << "Simple Sort Puzzle Game" << endl;
	srand(time(0));
	const int numberOfVials = 6;
	Vial vials[numberOfVials];
	int numberOfTransfers = 0;
	string source, destination;
	char contents[] = {
		'a','b','c','d'
	};
	for (int i = 0; i < 4; i++) {
		for (char item : contents) {
			int vialIndex;
			do {
				vialIndex = rand() % 4;
			} while (vials[vialIndex].getFilled() > i);
			vials[vialIndex].add(item);
		}
	}
	for (int i = 0; i < numberOfVials; i++) {
		vials[i].setLabel(i+1);
	}
	while (!isGameComplete(vials, numberOfVials)) {
		cout << endl;
		displayVials(vials, numberOfVials);
		cout << "Completed Transfers: " << numberOfTransfers << endl;
		cout << "Source (only numbers 1-6): ";
		cin >> source;
		cout << "Destination (only numbers 1-6): ";
		cin >> destination;
		if (!isStringDigits(source)|| !isStringDigits(destination)) {
			cout << "I said numbers only!" << endl;
			continue;
		}
		int s = stoi(source);
		int d = stoi(destination);

		s--;
		d--;
		if (s<0 || s>=numberOfVials || d< 0 || d>=numberOfVials) {
			cout << "Please enter a valid source and destination." << endl; 
			continue;
		}

		bool transferSuccess = vials[s].transfer(vials[d]);
		if (!transferSuccess) {
			cout << "This transfer is not possible." << endl;
		}
		else {
			numberOfTransfers++;
		}
	}
	displayVials(vials, numberOfVials);
	cout << "Congrats! Your vials are sorted!" << endl;
}

