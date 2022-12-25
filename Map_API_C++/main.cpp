#include <iostream>
#include <utility>
#include <string>
#include <map>
 
auto print_node = [](const auto &node) 
{
    std::cout << "[" << node.first << "] = " << node.second << '\n';
};
 
auto print_result = [](auto const &pair) 
{
    std::cout << (pair.second ? "inserted: " : "ignored:  ");
    print_node(*pair.first);
};
 
int main()
{
    using namespace std::literals;
    std::map<std::string, std::string> m;

    
    print_result( m.try_emplace("a", "a"s) );
    print_result( m.try_emplace("b", "abcd") );
    print_result( m.try_emplace("c", 10, 'c') );
    print_result( m.try_emplace("c", "Won't be inserted") );
    m.insert(std::make_pair("d", "4"));
    m.insert(std::make_pair("e", "5"));
    m["f"] = "6";
    m["g"] = "7";
    m.erase("d");

    std::cout << "Find b: " << m.find("b")->second << '\n';
    std::cout << "Find f: " << m.find("f")->second << '\n';

    std::cout << "a count: " << m.count("a") << '\n';
    


    if(!m.empty()) 
    {
        std::cout << "m size: " << m.size() << '\n';
    }

    for (const auto &p : m) 
    { 
        print_node(p); 
    }

    m.clear();
    for (const auto &p : m) 
    { 
        print_node(p); 
    }
    return 0;
}