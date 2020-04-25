#include <iostream>

using namespace std;
# pragma once

template <class T>
class TreasureMap {
	T *steps;
	int current_step;
	int total_steps;
	int max_steps;

	public:
	TreasureMap() {
		total_steps = 0;
		current_step = 0;
		max_steps = 10;
		steps = new T[10];
	}
	TreasureMap(int max_steps) {
		this -> max_steps = max_steps;
		this -> steps = new T[max_steps];
	}

	T * getSteps() {
		return this -> steps;
	}

	int getCurrentStep() {
		return this -> current_step;
	}

	int getTotalSteps() {
		return this -> total_steps;
	}

	void addStep(T step) {

		if (this -> total_steps == this -> max_steps) {
			cout << "Cannot add more steps, TreasureMap is full" << endl;
		} else {
			this -> steps[total_steps] = step;
			this -> total_steps++;
		}
	}

	void removeStep(int index) {
		this -> steps[index] = NULL;
		this -> total_steps--;
		// for (int i = 0; i < this -> total_steps; i++) {
		// 	if (i == index) {
		// 		for (int j = i; j < this -> total_steps - i; j++) {
		// 			if (j + 1 < this -> total_steps) {
		// 				steps[j] = steps[j+1];
		// 			}
		// 		}
		// 		steps[this -> total_steps - 1] = NULL
		// 	}
		// }
	}

	void nextStep() {
		if (this -> current_step == this -> max_steps) {
			cout << "Cannot goto next step, treasure has already been found!" << endl;
		} else {
			cout << "Going from " << this -> steps[this -> current_step] << " to " << this -> steps[this -> current_step + 1] << endl;
			this -> current_step++;
		}
		if (this -> current_step + 1 == this -> total_steps) {
			cout << "Congratulations, you have found treasure!" << endl;
		}
	}

	void backtrack() {
		if (this -> current_step == 0) {
			cout << "Cannot backtrack, you're at the very first step!" << endl;
		} else {
			cout << "Backtracking from " << this -> steps[this -> current_step] << "to" << this -> steps[this -> current_step - 1] << endl;
			this -> current_step--;
		}
	}

	TreasureMap operator + (TreasureMap tm) {
		TreasureMap temp;
		if (this -> total_steps == tm.total_steps) {
			for (int i = 0; i < this -> total_steps; i++) {
				temp.steps[i] = this -> steps[i] + tm.steps[i];
			}
		}
		return temp;
	}

	bool operator == (TreasureMap tm) {
		bool equal = false;
		if (this -> total_steps == tm.total_steps) {
			for (int i = 0; i < this -> total_steps; i++) {
				equal = equal && (this -> steps[i] == tm.steps[i]);
			}
		}
		return equal;
	}
};