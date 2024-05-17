#include <iostream>
#include "Sales_item.h"

int main(int argc, char const *argv[])
{
    Sales_item item1, item2;
    std::cout << "Input:";
    std::cin >> item1 >> item2;
    if (compareIsbn(item1, item2))
        std::cout << "Sum:" << item1 + item2;
    else
        std::cout << "Not equal ISBN";
    return 0;
}
