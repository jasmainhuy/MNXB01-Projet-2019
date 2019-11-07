#include "tempTrender.h"
#include <string>


void project() {
<<<<<<< HEAD
	string pathToFile = "../datasets/tempdata_uppsala.txt"; //Put the path to your data file here
	tempTrender t(pathToFile); //Instantiate your analysis object
	
	//t.tempOnDay(8, 23); //Call some functions that you've implemented
	//t.tempOnDay(235);
	//t.tempPerDay();
	//t.hotCold(2050);
	t.hottestTempPerYear(2050);
	//t.tempPerYear(2050);
=======
    string pathToFile = "../datasets/tempdata_uppsala.txt"; //Put the path to your data file here
    tempTrender t(pathToFile); //Instantiate your analysis object
    
    //t.tempOnDay(8, 23); //Call some functions that you've implemented:
    //t.tempOnDay(235);
    //t.tempPerDay();
    //t.hotCold();
    //t.hottestTempPerYear(2050);
    t.tempPerYear(2050);
>>>>>>> 0c2b2351fd45a188871a294592b459e5a26ce633
}
