#include <iostream>
#include <list>
#include <iterator>



int main()
{
    std::list<int> l {1, 2, 3, 4, 5};

    copy(l.rbegin(), l.rend(), std::ostream_iterator<int>{std::cout, ", "});
    std::cout << '\n';

    copy(make_reverse_iterator(end(l)),
         make_reverse_iterator(begin(l)),
         std::ostream_iterator<int>{std::cout, ", "});
    std::cout << '\n';
}