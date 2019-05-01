#include <iostream>

// A+B assignment
int sum(int a, int b)
{
    return a + b;
}

int main() 
{
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << sum(a, b);

    return 0;
}

