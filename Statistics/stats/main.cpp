// main.cpp 
// Project UID 5366c7e2b77742d5b2142097e51561a5

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <limits>
#include <fstream>
#include <map>
#include <regex>
#include <exception>
#include <sstream>

#include "stats.h"
#include "p1_library.h"

using namespace std;



int main(int argc, char *argv[]) 
{
    string filename = string(argv[1]);
    string column = string(argv[2]);
    
    vector <double> column_data = extract_column(filename, column);

    //summary
    vector <vector <double> > summary = summarize(column_data);
    cout << "Summary (value: frequency)" << endl;
    for (size_t i = 0; i < summary.size(); ++i) {
        cout << summary[i][0] << ": " << summary[i][1] << endl;
    }
    cout << endl;
    //count
    cout << "count = " << count(column_data) << endl;
    //sum
    cout << "sum = " << sum(column_data) << endl;
    //mean
    cout << "mean = " << mean(column_data) << endl;
    //stdev
    cout << "stdev = " << stdev(column_data) << endl;
    //median
    cout << "median = " << median(column_data) << endl;
    //mode
    cout << "mode = " << mode(column_data) << endl;
    //min
    cout << "min = " << min(column_data) << endl;
    //max
    cout << "max = " << max(column_data) << endl;
    //percentile
    cout << "  0th percentile = " << percentile(column_data, 0) << endl;
    cout << " 25th percentile = " << percentile(column_data, 0.25) << endl;
    cout << " 50th percentile = " << percentile(column_data, 0.5) << endl;
    cout << " 75th percentile = " << percentile(column_data, 0.75) << endl;
    cout << "100th percentile = " << percentile(column_data, 1) << endl;

}