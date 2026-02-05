#include <iostream>
#include "DoubleLinkList.hpp"

int main(void) {

    size_t count = 5;
    DoubleLinkList::List l = {1,2,3,4,5};
    std::cout << l.size() << std::endl;

    DoubleLinkList::List r(5, 42);

    std::cout << r.size() << std::endl;
    r.push_back(3);
    std::cout << r.size() << std::endl;

    return 0;
}
