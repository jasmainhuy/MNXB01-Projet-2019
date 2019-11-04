//author: Philip Siemund

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include </Users/philipsiemund/root_v6.18.04/include/TH1.h> 
#include </Users/philipsiemund/root_v6.18.04/include/TH2.h> 
#include </Users/philipsiemund/root_v6.18.04/include/TCanvas.h> 
#include </Users/philipsiemund/root_v6.18.04/include/TLatex.h>

void tempPerDay(Int_t year, Int_t hour){

ifstream file("/Users/philipsiemund/MNXB01-Project-2019/datasets/data_for_Lund.txt");

if(!file) {
cout << "Error: could not read from file data_for_Lund.txt" << endl; 
}

string title = "Temp. per day

TH1D* hist = new TH1D("Stats", "Temp. per day at %d in %d; Day; Temperature [#circC]", 
			366, 0, 366);

Int_t Year;
string month;
string day;
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

/*

for(int bin = 1; bin <= hist->GetNbinsX(); ++bin) {
hist->SetBinContent(bin, 5);
}

*/



TCanvas* can = new TCanvas("can", "hist canvas", 900, 600);
hist->Draw();


}

