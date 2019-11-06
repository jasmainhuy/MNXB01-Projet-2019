#include "tempTrender.h"

#include <fstream>
#include <iostream>

#include <TF1.h> 
#include <TH1.h>
#include <TStyle.h> 
#include <TMath.h> 
#include <TCanvas.h>
#include <vector>
#include <string>

using namespace std;

tempTrender::tempTrender(string filePath) {
	//cout << "The user supplied " << filePath << " as the path to the data file." << endl;
	//cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;	
	_filePath = filePath;
}



void tempTrender::tempOnDay(int Day) {
	
    ifstream file(_filePath.c_str());
    
    //Defining all vaiables we need
    vector<string> entries;
    vector<float> temp;
    
    string line, t;
    int i, j=0, day, s;
    
    //Check if the file is opened
    if(file.is_open()) 
    {
		//Fill up the vector with the entries
		while(getline(file, line)) 
		{
			entries.push_back(line);
		}
	}
	
	s = entries.size();
	//goes through all the entries
	for(i=0; i<s; i++)
	{
		line = entries[i];
		
		//get the day from 22th character
		day = stoi(line.substr(22,4));
		if (day == Day)
		{
			//get the corresponding temperature at the 16th character
			temp[j]= stof(line.substr(16,3));
			j=j+1;
		}
	}
	
	
	//creating histogram
	TH1D* Hist = new TH1D("Hist", "Temperature on a given day", 100, -20, 40);
	
	
	//filling up histogram with the values from vector temp
	for (i=0; i<j; i++)
	{
		t=temp[j];
		Hist->Fill(t);
	}
	
	//drawing histogram
	Hist->Draw();

	return 0;
}

