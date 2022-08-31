#ifndef STATS_H
#define STATS_H

#include <vector>


std::vector<std::vector<double> > summarize(std::vector<double> v);

//EFFECTS: returns the count of the numbers in v
int count(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the sum of the numbers in v
double sum(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the arithmetic mean of the numbers in v
double mean(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the sample median of the numbers in v
double median(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the mode of the numbers in v
double mode(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the min number in v
double min(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the max number in v
double max(std::vector<double> v);

//REQUIRES: v contains at least 2 elements
//EFFECTS: returns the corrected sample standard deviation of the numbers in v
double stdev(std::vector<double> v);

//REQUIRES: v is not empty
//          p is between 0 and 1, inclusive
//EFFECTS: returns the percentile p of the numbers in v like Microsoft Excel.
double percentile(std::vector<double> v, double p);

#endif
#pragma once
