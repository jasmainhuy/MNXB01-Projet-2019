#ifndef TEMPTRENDER_H
#define TEMPTRENDER_H

#include <string>

<<<<<<< HEAD
class tempTrender {
	public:
	tempTrender(std::string filePath); //Construct using the specified file
	~tempTrender() {} //Destructor
	
	//void tempOnDay(int monthToCalculate, int dayToCalculate); //Make a histogram of the temperature on this day
	//void tempOnDay(int dateToCalculate); //Make a histogram of the temperature on this date
	//void tempPerDay(); //Make a histogram of the average temperature of each day of the year
	//void hotCold(yearToExtrapol); //Make a histogram of the hottest and coldest day of the year
	//void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year
	void hottestTempPerYear(int yearToExtrapol); //Make a histogram of hottest temperature per year, then fit (maybe if possible extrapolate to the given year)
=======
class tempTrender 
{
public:
    tempTrender(std::string filePath); //Construct using the specified file
    ~tempTrender() {} //Destructor
    
    //void tempOnDay(int monthToCalculate, int dayToCalculate); //Make a histogram of the temperature on this day
    void tempOnDay(int dateToCalculate);//Make a histogram of the temperature on this date
    //void tempPerDay(); //Make a histogram of the average temperature of each day of the year
    //void hotCold(); //Make a histogram of the hottest and coldest day of the year
    void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year
    void hottestTempPerYear(int yearToExtrapol); //Make a histogram of hottest temperature per year, then fit (maybe if possible extrapolate to the given year)
private:
    std::string _filePath;
>>>>>>> 0c2b2351fd45a188871a294592b459e5a26ce633

};

#endif
