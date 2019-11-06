#include "tempTrender.h"
#include <string>


void project() {
	string pathToFile = "../datasets/data_for_Lund.txt"; //Put the path to your data file here
	tempTrender t(pathToFile); //Instantiate your analysis object
	t.tempOnDay(235);
}
