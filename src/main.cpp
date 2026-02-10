#include <iostream>
#include "DoubleLinkList.hpp"

int main(void) {

    int x = 9;
    DoubleLinkList::List l = {1,2,3,4,5};
    DoubleLinkList::List r(5, 42);

    l.insert(3, 42);
    l.insert(4, x); // x = 9

    std::cout << l << std::endl;

    l.insert(3, 2, 6);
    std::cout << l << std::endl;

    l.insert(3, {7, 7, 7, 7});
    std::cout << l << std::endl;

    l.pop_back();
    std::cout << l << std::endl;

    l.push_front(345);
    std::cout << l << std::endl;

    l.pop_front();
    std::cout << l << std::endl;

    l.erace(2);
    std::cout << l << "\nsize: " << l.size() << std::endl;

    l.resize(11);
    std::cout << l << "\nsize: " << l.size() << std::endl;

    l.sort();
    std::cout << l << std::endl;

    l.merge(r);
    std::cout << l << std::endl;


    return 0;
}
