#include "tempTrender.h"

#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <TF1.h>
#include <TStyle.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TH1.h> // 1d histogram classes

#define NB_MAX_FILE_VALUES 200000
#define MAX_YEAR 2100 // maximum year of input data

tempTrender::tempTrender(std::string filePath) {
        // Store file path parameter into member variable
        _filePath = filePath;

        //cout << "The user supplied " << filePath << " as the path to the data file." << endl;
        //cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
}

/* Function mean temp per year
 * @param vector of strings
 *               with following format "%s %s %s %s %s" 
 *               (year, month, day, temp, temp with urban correction, city)
 * @return map of mean temp per year
 */
std::map<int, double> meanTempPerYear(std::vector<std::string> entries) {
        // we assume that values are uniformatically spread on the year

        // temp values
        std::string year_str, value_str;
        size_t pos;
        int year;
        double value;

        // storage
        int nb_values[MAX_YEAR]={0};
        double sum_values[MAX_YEAR]={0};

        // for each entry, extract year and value
        for(size_t y=0; y<entries.size(); y++) {

                std::string s = entries[y];

                // get year from 4 first characters
                year_str = s.substr(0, 4);
                year = atoi(year_str.c_str());

                // get value from 5th field
                for(size_t i=0; i<4; i++) {
                        pos = s.find(' '); // find first delimiter
                        s.substr(0, pos);
                        s.erase(0, pos + 1);
                }
                pos = s.find(' ');
                value_str = s.substr(0, pos);
                value = atof(value_str.c_str());

                // add value to arrays
                nb_values[year]++;
                sum_values[year]+=value;
        }

        // return variable
        std::map<int, double> ret;
        double mean;

        // for each year, compute mean value
        for(size_t i=0; i<MAX_YEAR; i++) {
                if(nb_values[i]>0) {
                        mean = sum_values[i]/nb_values[i];
                        //std::cerr << "year : " << i << " mean : " << mean << std::endl;
                        ret.insert(std::make_pair<int, double>((int)i, (double)mean));
                }
        }

        return ret;
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

        std::map<int, double> mean = meanTempPerYear(entries);

        // create canvas for graph
        TCanvas *c1 = new TCanvas("Estelle", "Project : Mean Temp Per Year");

        // create new histogram object
        TH1F* hist = new TH1F("graph", "Mean Temp Per Year", mean.size(), 1722, 2100);


        for( std::map<int, double>::iterator it = mean.begin();
             it != mean.end();
             it++ ) {
                // fill hist with date and value from mean temp per year map
                //std::cerr << "value : " << it->second << std::endl;
                hist->Fill(it->first, it->second);
        }

        //This code is given from project instruction for creating the graph
        TGraph* graph = new TGraph();
        
        graph->SetHistogram(hist);
        
        //for(int bin = 1; bin < hist->GetNbinsX(); ++bin) {
        //    graph->Expand(graph->GetN() + 1, 100);
        //    graph->SetPoint(graph->GetN(), hist->GetBinCenter(bin),
        //    hist->GetBinContent(bin));
       // }
        graph->Draw("SAME C");

        //void extrapolate(Int_t n)

        //hist->Draw();


}
