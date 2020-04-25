#include <iostream>
#include <string>
#include <fstream>

#include "TreasureMap.h"
#include "FileReadException.h"
#include "Location.h"

using namespace std;

//overload operator << of Location class, no changes needed
ostream& operator<<(ostream& os, Location& pt) {
	return os << pt.getName();
}

//overload operator >> of Location class, no changes needed
istream& operator >> (istream& os, Location& pt) {
	string name;
	float x,y;
	os >> name >> x >> y;
	pt.setName(name);
	pt.setX(x);
	pt.setY(y);

	return os;
}

template <class T>
TreasureMap <T> readMap (string file_name, int max_steps) {
	ifstream infile;
	infile.open(file_name);
	if (!infile) {
		FileReadException err("Error reading map: " + file_name + " does not exists!");
		throw(err);
	}
	TreasureMap <T> tm;
	T item;
	int cntItem = 0;
	while (infile >> item) {
		tm.addStep(item);
		cntItem++;
	}
	if (cntItem > max_steps) {
		FileReadException err("Error reading map: " + file_name + " contains more than " + to_string(max_steps) + " steps!");
		throw (err);
	}
	return tm;
}

int main() {
	string file_name, file_type;
	int max_steps;
	cin >> file_name >> file_type >> max_steps;

	try{
		if (file_type == "string"){
			TreasureMap<string> Tmap = readMap<string>(file_name, max_steps);
			for (int i = 0; i < Tmap.getTotalSteps()-1; i ++){
				Tmap.nextStep();
			}
		} else if (file_type == "int"){
			TreasureMap<int> Tmap = readMap<int>(file_name, max_steps);
			for (int i = 0; i < Tmap.getTotalSteps() - 1; i++) {
				Tmap.nextStep();
			}
		} else if (file_type == "char"){
			TreasureMap<char> Tmap = readMap<char>(file_name, max_steps);
			for (int i = 0; i < Tmap.getTotalSteps() - 1; i++) {
				Tmap.nextStep();
			}
		} else if (file_type == "location"){
			TreasureMap<Location> Tmap = readMap<Location>(file_name, max_steps);
			for (int i = 0; i < Tmap.getTotalSteps() - 1; i++) {
				Tmap.nextStep();
			}
		} else {
			FileReadException err("Error file type: Invalid file type");
			throw (err);
		}
	} catch(FileReadException err){
		cout << err.getMessage() << endl;
	}

	return 0;
}
