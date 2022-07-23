// main.cpp 
// Project UID 5366c7e2b77742d5b2142097e51561a5

#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>



using namespace std;

void sort(std::vector<double>& v);
std::vector<double> extract_column(std::string filename, std::string column_name);


int count(vector<double> v) {
    int count_number;
    count_number = v.size();
    return (count_number);
}
double sum(vector<double> v) {
    double sum_number = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        sum_number = sum_number + v.at(i);
    }
    return (sum_number);
}
double mean(vector<double> v) {
    int sum_number = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        sum_number = sum_number + v.at(i);
    }
    int mean_number = sum_number / v.size();
    return (mean_number);
}
double median(vector<double> v) {
    sort(v);
    double median_number;
    if (v.size() % 2 == 0) {
        median_number = v.at((v.size() / 2) + 0.5) - v.at((v.size() / 2) - 0.5);
        return (median_number);
    }
    else {
        median_number = v.at((v.size() / 2) + 0.5);
        return (median_number);
    }
}
double mode(vector<double> v) {
    sort(v);
    int count_max = 1;
    double mode_final = v.at(0);
    for (size_t i = 0; i < v.size(); ++i) {
        int count = 0;
        for (size_t j = 1; j < v.size(); ++j) {
            if (v.at(i) == v.at(j)) {
                ++count;
            }
        }
        if (count > count_max) {
            count_max = count;
            mode_final = v.at(i);
        }
    }
    return(mode_final);
}
double min(vector<double> v) {
    sort(v);
    double min_number = v.at(0);
    return (min_number);
}
double max(vector<double> v) {
    sort(v);
    double max_number = v.at(v.size() - 1);
    return (max_number);
}
double stdev(vector<double> v) {
    double mean_n = mean(v);
    double total = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        double numerator = (v.at(i) - mean_n) * (v.at(i) - mean_n);
        total = total + numerator;
    }
    double stdev_number = sqrt(total / (v.size() - 1));
    return (stdev_number);
}
double percentile(vector<double> v, double p) {
    double percentile_number;
    double percentile_final;
    double intpart;
    double fractpart;
    sort(v);
    percentile_number = p * (v.size() - 1);
    fractpart = modf(percentile_number, &intpart);
    if (intpart == v.size() - 1) {
        percentile_final = v.at(intpart);
        return (percentile_final);
    }
    else {
        percentile_final = v.at(intpart) + fractpart * (v.at(intpart + 1) - v.at(intpart));
        return (percentile_final);
    }
}



vector<vector<double> > summarize(vector<double> v) {
    sort(v);
    vector <vector <double> > summary;
    int summary_count = 1;
    for (size_t i = 1; i < v.size(); ++i) {
        if (v.at(i - 1) == v.at(i)) {
            summary_count++;
        }
        if (v.at(i - 1) != v.at(i)) {
            vector <double> trial;
            trial.push_back(v.at(i - 1));
            trial.push_back(summary_count);
            summary.push_back(trial);
            summary_count = 1;
        }
        if (i == v.size() - 1) {
            vector <double> trial;
            trial.push_back(v.at(i));
            trial.push_back(summary_count);
            summary.push_back(trial);
        }
    }
    return summary;
}



int main() {
    string filename;
    string column;
    cout << "enter a filename" << endl;
    cin >> filename;
    cout << "enter a column name" << endl;
    cin >> column;
    cout << "reading column " << column << " from " << filename << endl;

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