#include "tempTrender.h"
#include <string>

void project() {
	string pathToFile = "../datasets/tempdata_uppsala.txt"; //Put the path to your data file here
	tempTrender t(pathToFile); //Instantiate your analysis object
	
	//t.tempOnDay(8, 23); //Call some functions that you've implemented
	//t.tempOnDay(235);
	//t.tempPerDay();
	//t.hotCold();
	//t.hottestTempPerYear(2050);
	t.tempPerYear(2050);
}
