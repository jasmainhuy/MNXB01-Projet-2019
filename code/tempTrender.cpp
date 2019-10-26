#include "tempTrender.h"

#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>

#define NB_MAX_FILE_VALUES 1024
#define MAX_YEAR 2100 // maximum year of input data

tempTrender::tempTrender(string filePath) {
        // Store file path parameter into member variable
        _filePath = filePath;
        
        //cout << "The user supplied " << filePath << " as the path to the data file." << endl;
        //cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
}

/* Function mean temp per year
 * @param vector of strings with following format "%s %s %s %s" (date, time, value, quality)
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
                
                // get value from 3rd field
                for(size_t i=0; i<2; i++) {
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
        
        //This code is given from project instruction for creating the graph
        //TGraph* graph = new TGraph();
        //for(int bin = 1; bin < hist->GetNbinsX(); ++bin) {
        //        graph->Expand(graph->GetN() + 1, 100);
        //        graph->SetPoint(graph->GetN(), hist->GetBinCenter(bin),
        //                hist->GetBinContent(bin));
        //}
        //graph->Draw("SAME C");
}
