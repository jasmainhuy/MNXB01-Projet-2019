//author: Philip Siemund

#include <iostream>
#include <fstream>

using namespace std;

#include </Users/philipsiemund/root_v6.18.04/include/TH1.h> 
#include </Users/philipsiemund/root_v6.18.04/include/TCanvas.h> 
#include </Users/philipsiemund/root_v6.18.04/include/TLatex.h>

void tempPerDay(){

ifstream file("/Users/philipsiemund/MNXB01-Project-2019/datasets/tempdata_Lund.txt");

if(!file) {
cout << "Error: could not read from file input.txt" << endl; 
}

TH1D* hist = new TH1D("hist", "Temp. per day; Temperature [#circC]; Day", 
			100, 1, 366);

Int_t date;
Int_t time;
Double_t temp;
string quality;

while (file >> date >> time >> temp >> quality){

	if (quality =='Y') {

	continue; 
	}

	else {
	
	hist->Fill(temp);
	} 
}

file.close();

TCanvas* can = new TCanvas("can", "hist canvas", 900, 600);
hist->Draw();


}

