#include "tempTrender.h"

#include <fstream>
#include <map>
#include <stdlib.h>

#include <TH1.h> // 1d histogram classes

#define NB_MAX_FILE_VALUES 200000
<<<<<<< HEAD
#define MAX_YEAR 2013 // maximum year of input data

tempTrender::tempTrender(string filePath) {
=======
#define MAX_YEAR 2100 // maximum year of input data
#define MIN_TEMP_VALUE -100 // minimum value of temperature

/*
 * Constructor
 */
tempTrender::tempTrender(std::string filePath) {
>>>>>>> 0c2b2351fd45a188871a294592b459e5a26ce633
        // Store file path parameter into member variable
        _filePath = filePath;

        //cout << "The user supplied " << filePath << " as the path to the data file." << endl;
        //cout << "You should probably store this information in a member variable of the class. Good luck with the project! :)" << endl;
}

//////////////////////////////////
// JASMAIN CODE PART:
//////////////////////////////////

/* Function hottest temp per year
 * @param vector of strings
 *               with following format "%s %s %s %s %s" 
 *               (year, month, day, temp, temp with urban correction, city)
 * @return map of mean temp per year
 */
std::map<int, double> hotTempPerYear(std::vector<std::string> entries) {
        // temporary values
        std::string year_str, value_str;
        size_t pos;
        int year;
        double value;

        // storage
        int nb_values[MAX_YEAR]={0};
        double hot_values[MAX_YEAR]={0};
        
        // initialise hot_values to have a minimum value
        for(size_t i=0; i<MAX_YEAR; i++) {
            hot_values[i] = MIN_TEMP_VALUE;
        }

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
                // Note : correct algorithm for max value, good job Jasmin
                if (value > hot_values[year] ) {
                    hot_values[year] = value;
                }
        }
        
        // return variable
        std::map<int, double> ret;
        double hot;

        // for each year, compute mean value
        for(size_t i=0; i<MAX_YEAR; i++) {
               hot = hot_values[i];
               //std::cerr << "year : " << i << " hottest temp : " << hot << std::endl;
               ret.insert(std::make_pair<int, double>((int)i, (double)hot));
        }
        return ret;
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
        
        for( std::map<int, double>::iterator it = hot.begin();
             it != hot.end();
             it++ ) {
                // fill hist with date and value from mean temp per year map
                //std::cerr << "value : " << it->second << std::endl;
                hist->Fill(it->first, it->second);
        }
        
        hist->Draw();
}


//////////////////////////////////
// JOHAN CODE PART
//////////////////////////////////

// NOTE : you should give more explicit names to your variables
// Single letter variables are quite hard to maintain, prefer longer names

// Be careful at which file is used
void tempTrender::tempOnDay(int dateToCalculate) {

    ifstream file(_filePath.c_str());
    
    //Defining all vaiables we need
    vector<string> entries;
    vector<float> temp;
    
    string line;
    int i, j=0, day, s;
    float t;
    
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
        day = atoi(line.substr(22,4).c_str());
        if (day == dateToCalculate)
        {
            //get the corresponding temperature at the 16th character
            temp[j]= atof(line.substr(16,3).c_str());
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
}

//////////////////////////////////
// ESTELLE CODE PART
//////////////////////////////////

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
<<<<<<< HEAD
               hot = hot_value[i];
               std::cerr << "year : " << i << " hottest temp : " << hot << std::endl;
               ret.insert(std::make_pair<int, double>((int)i, (double)hot));
=======
                if(nb_values[i]>0) {
                        mean = sum_values[i]/nb_values[i];
                        std::cerr << "year : " << i << " mean : " << mean << std::endl;
                        ret.insert(std::make_pair<int, double>((int)i, (double)mean));
                }
>>>>>>> 0c2b2351fd45a188871a294592b459e5a26ce633
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
        
        //compute hottest temp per year
        std::map<int, double> hot = hotTempPerYear(entries);
        
        //compute hot temp for all time
        double hottestAllTime = 0;
        for( std::map<int, double>::iterator it = hot.begin();
             it != hot.end();
             it++ ) {
                 hottestAllTime += it->second;
                 
        }
        hottestAllTime /= hot.size();
        
        
        //create canvas for graph
        TCanvas *c1 = new TCanvas("Jasmain", "Project : Hottest Temp Per Year ");

        // create new histogram object
        TH1D* hist = new TH1D("hist", "Hottest Temp Per Year", hot.size(), 1722, 2013);
        
        
        //fill hist with hotteest temp per year values from input file
        for( std::map<int, double>::iterator it = hot.begin();
             it != hot.end();
             it++ ) {
                // fill hist with date and value from hottest temp per year map
                //std::cerr << "value : " << it->second << std::endl;
                hist->Fill(it->first, it->second);
        }
        
        
<<<<<<< HEAD

        TLine *hotline = new TLine(1722, hottestAllTime,2013,hottestAllTime);
        hist->Draw();

        //This code is given from project instruction for creating the graph
        //TGraph* graph = new TGraph();
        //for(int bin = 1; bin < hist->GetNbinsX(); ++bin) {
        //        graph->Expand(graph->GetN() + 1, 100);
        //        graph->SetPoint(graph->GetN(), hist->GetBinCenter(bin),
        //                hist->GetBinContent(bin));
        //}
        //graph->Draw("SAME C");
=======
        //for(int bin = 1; bin < hist->GetNbinsX(); ++bin) {
        //    graph->Expand(graph->GetN() + 1, 100);
        //    graph->SetPoint(graph->GetN(), hist->GetBinCenter(bin),
        //    hist->GetBinContent(bin));
        //}
        //graph->Draw("SAME C");

        // create function for extrapolation
        //TF1 *f = (TF1*)hist->GetFunction("pol7");
        //f->Eval(yearToExtrapolate);

        //Axis title
        hist->SetTitle("Mean temperature per year (Uppsala, 1722-2013)");
        hist->GetXaxis()->SetTitle("Year");
        hist->GetXaxis()->CenterTitle();
        hist->GetYaxis()->SetTitle("Mean temperature (Celcius Deg)");
        hist->GetYaxis()->CenterTitle();

        // draw hist
        hist->Draw("SAME");

        // draw mean line
        meanline->Draw();

>>>>>>> 0c2b2351fd45a188871a294592b459e5a26ce633
}

