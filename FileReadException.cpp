#include "FileReadException.h"

FileReadException :: FileReadException(string err) {
	err_message = err;
}
string FileReadException :: getMessage () {
	return this -> err_message;
}