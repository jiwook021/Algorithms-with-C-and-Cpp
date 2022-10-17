/**
 * @file main.cpp
 * @author Jiwook Kim (Jiwook021@gmail.com)
 * @brief Find the number of Random generated Value
 * @version 0.1
 * @date 2022-08-27
 * @copyright Copyright (c) 2022
 */

//Include Files
#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cstdint>

//Global Variable
const uint8_t RESULT_ARRAY_SIZE = 10;


//Function Prototype
void RandomGenerator(const uint8_t, const uint8_t , std::vector<int>&, const uint16_t);
void PrintVector(std::vector<int>);
void CountOccurrenceOfNum(const std::vector<int>, std::array<uint16_t,10> &);
void PrintResultArray(const std::array<uint16_t,10>);


void RandomGenerator(const uint8_t Lower_bound, const uint8_t Upper_bound, std::vector<int> &random_numbers, const uint16_t VectorLength) 
{
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(Lower_bound, Upper_bound);
    
    for (uint16_t i = 0; i < VectorLength; i++)
    {
        random_numbers.push_back(dis(gen));
    }
}

void PrintVector(std::vector<int> vectors) 
{
    std::cout<< "Stored Value " << std::endl;     
    std::vector<int>::iterator iter = vectors.begin();
    for( ; iter != vectors.end(); iter++)
    {
        std::cout << *iter << " ";
    }
}

void CountOccurrenceOfNum(const std::vector<int> Vectors, std::array<uint16_t,RESULT_ARRAY_SIZE> &Result)
{
    for (uint16_t i=0; i < Vectors.size();i++) 
    {  
        Result[Vectors[i]]++;  
    }
}

void PrintResultArray(const std::array<uint16_t, RESULT_ARRAY_SIZE> Result)
{
    std::cout << "\n\nOccurrence" << std::endl;
    uint16_t idx = 0; 
    for (auto i: Result)
    {
        std::cout << "Result[" << idx << "] :" << i << std::endl;
        idx++;
    }
}
 

int main() 
{
    const uint16_t VectorLength = 100; 
    std::vector<int> Vector_random_numbers;  //Initialization
    Vector_random_numbers.reserve((const uint16_t) VectorLength);  //Requests that the vector capacity be at least enough to contain elements 

    RandomGenerator((const uint8_t) 0, (const uint8_t) 9, (std::vector<int>&)Vector_random_numbers, (const uint16_t) VectorLength);  //Random Generator, Assign 0 to 9 to vector Vector_random_numbers with VectorLength 
    PrintVector((std::vector<int>&) Vector_random_numbers);  //Print All the Numbers inside the vectors

    std::array<uint16_t, RESULT_ARRAY_SIZE> Result = { 0 };      
    CountOccurrenceOfNum((const std::vector<int>&) Vector_random_numbers, (std::array<uint16_t,RESULT_ARRAY_SIZE> &) Result);  //Count Occurence of Number in Given Vector, and store in Result Array
    PrintResultArray((const std::array<uint16_t,RESULT_ARRAY_SIZE> &) Result);  //Print the Array of Result 
    
     
    Vector_random_numbers.clear();// Remove all Vector elements
    Vector_random_numbers.shrink_to_fit(); //Free Up vector Memory

    return 0; 
}
