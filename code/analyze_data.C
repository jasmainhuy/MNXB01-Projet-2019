//author: Philip Siemund
//Draws a 1D histogram showing temp. per day at a specified time during a year. The raw data 
//is extracted from the datasets using a bash script tempdata.sh. The bash script is executed once whenever
//the argument const char* town is specified for the first time for a given town. Check your paths!

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include </Users/philipsiemund/root_v6.18.04/include/TH1.h> 
#include </Users/philipsiemund/root_v6.18.04/include/TH2.h> 
#include </Users/philipsiemund/root_v6.18.04/include/TCanvas.h> 
#include </Users/philipsiemund/root_v6.18.04/include/TLatex.h>
#include </Users/philipsiemund/root_v6.18.04/include/TSystem.h>

void tempPerDay(Int_t year, Int_t hour, const char* town){

string fileName = Form("/Users/philipsiemund/MNXB01-Project-2019/datasets/data_for_%s.txt", town);

ifstream tempo(fileName);

if(!tempo) {
cout << "Error: could not read from file ..." << endl; 
cout << "Running tempdata.sh ..." << endl; 
gSystem->Exec(Form("./tempdata.sh %s", town));

}

tempo.close();
ifstream file(fileName);

TH1D* hist = new TH1D("Stats", Form("Temp. per day in %s at %d:00 UTC in %d; Day; Temperature [#circC]",town,hour,year), 
			366, 0, 366);

Int_t Year;
Int_t month;
Int_t day;
Int_t time;
Double_t temp;
string quality;
Int_t dayno;

while (file >> Year >> month >> day >> time >> temp >> quality >> dayno){

	if (Year == year && time == hour) {
	
	hist->SetBinContent(dayno,temp); 
	}

	else {
	
	continue;
	} 
} 

file.close();

TCanvas* can = new TCanvas("can", "hist canvas", 900, 600);
hist->SetLineColor(1);
hist->Draw();

can->SaveAs("hist.png");

}

