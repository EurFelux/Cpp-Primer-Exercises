#include <iostream>
#include <cstdio>

int main(int argc, char const *argv[])
{
    int v1 = 0, v2 = 0;
    std::cout << "Input v1 and v2:";
    std::cin >> v1 >> v2;
    if (v1 > v2)
        std::swap(v1, v2);
    for (int i = v1; i <= v2; ++i)
        printf(i == v2 ? "%d\n" : "%d ", i);
    return 0;
}
