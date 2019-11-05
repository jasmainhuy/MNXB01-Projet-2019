#include "tempTrender.h"
#include <string>


void project() {
	string pathToFile = "/home/courseuser/Documents/Project/MNXB01-project/datasets/smhi-openda_Karlstad.csn"; //Put the path to your data file here
	tempTrender t(pathToFile); //Instantiate your analysis object
	t.tempOnDay(235);
	return 0;
}
