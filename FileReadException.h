#include <iostream>
#include <string>
using namespace std;
# pragma once

class FileReadException {
	string err_message;
	public:
	FileReadException(string);
	string getMessage ();
};