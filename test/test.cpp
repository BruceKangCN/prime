#include <cstdio>
#include <list>

int main()
{
    std::list<int> l = {};
    std::printf("%d\n", *(l.end()));

    return 0;
}