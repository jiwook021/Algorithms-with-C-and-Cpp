#include <iostream>
#include <queue>
#include <tuple>
#include <string>

int main()
{
    using item_type = std::pair<int, std::string>;
    
    std::initializer_list<item_type> il {
        {1, "dishes"},
        {0, "Listen to Podcast"},
        {4, "company work"},
        {3, "Coding"},
        {2, "read books"},
    };

    std::priority_queue<item_type> q;

    for (const auto &p : il) {
        q.push(p);
    }

    
    while(!q.empty()) {
        std::cout << q.top().first << ": " << q.top().second << '\n';
        q.pop();
    }
    
    return 0; 
}