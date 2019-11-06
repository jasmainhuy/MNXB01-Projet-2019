#include "tempTrender.h"

#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>

#include <TH1.h> // 1d histogram classes

#define NB_MAX_FILE_VALUES 1024
#define MAX_YEAR 2013 // maximum year of input data

tempTrender::tempTrender(string filePath) {
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
std::map<int, double> hotTempPerYear(std::vector<std::string> entries) {
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
                
                hot_value[year] = -100;

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
                if (value > hot_value[year]{
                    hot_values[year]= value;
                }
        // return variable
        std::map<int, double> ret;
        double hot;

        // for each year, compute mean value
        for(size_t i=0; i<MAX_YEAR; i++) {
               hot = hot_value[i];
               std::cerr << "year : " << i << " hottest temp : " << hot << std::endl;
               ret.insert(std::make_pair<int, double>((int)i, (double)hot));
        }
       }

        return ret;
}
        }
        
void tempTrender::hottestTempPerYear(int yearToExtrapol) {

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

        std::map<int, double> hot = hotTempPerYear(entries);

        // create new histogram object
        TH1D* hist = new TH1D("hist", "Hottest Temp Per Year", hot.size(), 1722, 2013);
        
        for( std::map<int, double>::iterator it = mean.begin();
             it != hot.end();
             it++ ) {
                // fill hist with date and value from mean temp per year map
                //std::cerr << "value : " << it->second << std::endl;
                hist->Fill(it->first, it->second);
        }

        void extrapolate(Int_t n)

        hist->Draw();

        //This code is given from project instruction for creating the graph
        //TGraph* graph = new TGraph();
        //for(int bin = 1; bin < hist->GetNbinsX(); ++bin) {
        //        graph->Expand(graph->GetN() + 1, 100);
        //        graph->SetPoint(graph->GetN(), hist->GetBinCenter(bin),
        //                hist->GetBinContent(bin));
        //}
        //graph->Draw("SAME C");
}
