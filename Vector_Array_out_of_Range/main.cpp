#include <iostream>
#include <vector>
#include <array>
#include <numeric> // for std::iota

int main()
{
    constexpr size_t container_size {1000};

#if 1
    std::vector<int> v (container_size);

    // Fill the vector with rising numbers
    std::iota(std::begin(v), std::end(v), 0);

    // Chances are, that the following line will not lead to a crash...
    std::cout << "Out of range element value: " << v[container_size + 10] << "\n";

    try 
    {
        // This out of bounds access DOES lead to an exception...
        std::cout << "Out of range element value: "
                  << v.at(container_size + 10) << "\n";

    } 
    catch (const std::out_of_range &e) 
    {
        // ...which we catch here.
        std::cout << "Out of range access detected: "
                  << e.what() << "\n";
    }
#endif


    // The same access methods and rules apply to std::array:
    std::array<int, container_size> ary;

    // Fill the vector with rising numbers
    std::iota(std::begin(ary), std::end(ary), 0);

    // Chances are, that the following line will not lead to a crash...
    std::cout << "Out of range element value: "
              << ary[container_size + 10] << "\n";

#if 1
    try 
    {
#endif
        // This out of bounds access DOES lead to an exception...
        std::cout << "Out of range element value: "
                  << ary.at(container_size + 10) << "\n";

#if 1
    } 
    catch (const std::out_of_range &e) 
    {
        // ...which we catch here.
        std::cout << "Out of range access detected: "
                  << e.what() << "\n";
    }
#endif
}