#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    std::vector<int> v {1, 2, 3, 2, 5, 2, 6, 2, 4, 8};

    {
        const auto new_end (remove(begin(v), end(v), 2));
        v.erase(new_end, end(v));
    }
    std::cout<<"Size of vector: "<<v.size();
    std::cout<<"\nInput Vectors\n";
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << "\nErase the odd numbers\n";
    {
        const auto odd ([](int i) { return i % 2 != 0; });
        const auto new_end (remove_if(begin(v), end(v), odd));
        v.erase(new_end, end(v));
    }

    v.shrink_to_fit();

    std::cout<<"New Size: "<<v.size()<<std::endl;

    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}