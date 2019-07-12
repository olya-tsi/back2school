#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// A+B assignment
void sum()
{
    int a = 0, b = 0;
    std::cout << "Enter 2 integer numbers:\n";
    std::cin >> a >> b;
    std::cout << "Sum is " << a + b << std::endl;
}

// Min string assignment
void min_string()
{
    std::vector<std::string> ss = {"", "", ""};
    std::cout << "Enter 3 strings:\n";
    std::cin >> ss[0] >> ss[1] >> ss[2];
    std::cout << "Min lexicographical string is " << ss[0] << std::endl;
}

// Quadratic equation assignment
void equation()
{
    int a = 0, b = 0, c = 0;
    double x1 = 0.0, x2 = 0.0;
    std::cout << "Enter 3 coefficients for quadratic equation:\n";
    std::cin >> a >> b >> c;
    if (a == 0 && b != 0 && c != 0)
    {
        x1 = -1.0*c / b;
        std::cout << "Real root: " << x1 << std::endl;
    }
    else
    {
        // calculate discriminant
        int d = b*b - 4*a*c;
        if (d > 0)
        {
            x1 = (-1*b + sqrt(d)) / (2*a);
            x2 = (-1*b - sqrt(d)) / (2*a);
            std::cout << "Real roots: " << x1 << " " << x2 << std::endl;
        }
        else if (d == 0 && a != 0 && b != 0 && c != 0)
        {
            x1 = (-1*b + sqrt(d)) / (2*a);
            std::cout << "Real root: " << x1 << std::endl;
        }
    }
}

int main()
{
    // sum();

    // min_string();

    equation();

    return 0;
}

