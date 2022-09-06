#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <set>
#include <algorithm>
#include <iterator> // for ostream_iterator
#include <cassert>


template <typename C>
void print_vector(const C &v)
{
    std::cout << "Words: {";
    copy(begin(v), end(v), std::ostream_iterator<typename C::value_type>(std::cout, " "));
    std::cout << "}\n";
}


template <typename C, typename T>
void insert_sorted(C &v, const T &word)
{
    const auto it (lower_bound(begin(v), end(v), word));
    v.insert(it, word);
}


int main()
{   
    const uint8_t size = 50;
    std::vector<std::string> v {}; 
   
    for(int i = 0; i<size; i++)
    { 
        v.push_back(std::to_string(rand() % 9+1));
    }

    assert(false == is_sorted(begin(v), end(v)));

    print_vector(v);

    sort(v.begin(), v.end());

    assert(true == is_sorted(begin(v), end(v)));

    print_vector(v);

    for(int i = 0; i<10; i++)
    { 
        insert_sorted(v,std::to_string(rand() % 9+1));
        print_vector(v);
    }
    print_vector(v);
}