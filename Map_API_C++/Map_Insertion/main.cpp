#include <iostream>
#include <map>
#include <string>



using map_type = std::map<std::string, int>;

int main()
{
    map_type m {{"b", 2}, {"c", 3}, {"d", 4}};

    auto insert_it (std::end(m));
    uint8_t counter =0;
    for (const auto &s : {"v", "w", "x", "y", "z"}) {
        insert_it = m.insert(insert_it, {s, 1+counter});
        counter++;
    }

    // In this example line, the hint is wrong.
    // It points past the last element, but the "0" string will be inserted
    // at the front. Therefore it does not have a better runtime performance
    // than insert without a hint parameter!
    m.insert(end(m), {"a", 1});

    m.insert(end(m), {"e", 5});

    for (const auto & [key, value] : m) {
        std::cout << "\"" << key << "\": " << value << ", ";
    }
    std::cout << '\n';
}