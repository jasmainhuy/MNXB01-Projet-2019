#include <iostream>
#include "tempTrender.h"
#include <fstream>

#define NB_MAX_FILE_VALUES 1024

tempTrender::tempTrender(string filePath) {
        // Store file path parameter into member variable
        _filePath = filePath;
        
        //cout << "The user supplied " << filePath << " as the path to the data file." << endl;
        //cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
}


void tempTrender::tempPerYear(int yearToExtrapolate) {
        
        // open input file
        std::string line;
        ifstream inputfile(_filePath.c_str());
     
        // create array to store values
        std::vector<std::string> entries;
        
        // read values and stor it into array, hist or something else
        if(inputfile.is_open()) {
                while(getline(inputfile, line)) {
                        entries.push_back(line);
                }
        }
        
        //This code is given from project instruction for creating the graph
        //TGraph* graph = new TGraph();
        //for(int bin = 1; bin < hist->GetNbinsX(); ++bin) {
        //        graph->Expand(graph->GetN() + 1, 100);
        //        graph->SetPoint(graph->GetN(), hist->GetBinCenter(bin),
        //                hist->GetBinContent(bin));
        //}
        //graph->Draw("SAME C");
}
