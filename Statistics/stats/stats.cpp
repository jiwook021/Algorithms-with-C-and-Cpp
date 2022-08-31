#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

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
    std::sort(v.begin(), v.end());
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
    std::sort(v.begin(), v.end());
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
    std::sort(v.begin(), v.end());
    double min_number = v.at(0);
    return (min_number);
}
double max(vector<double> v) {
    std::sort(v.begin(), v.end());
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
    std::sort(v.begin(), v.end());
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
    std::sort(v.begin(), v.end());
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

