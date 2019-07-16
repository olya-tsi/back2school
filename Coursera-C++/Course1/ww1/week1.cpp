#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

/* A+B assignment
На вход программе через стандартный ввод передаются два целых числа, по модулю не превышающие 100000. Выведите в стандартный вывод их сумму.

| stdin | stdout |
| ----- | ------ |
| 2 3   | 5      |
| -4 -9 | -13    |
| -1 2  | 1      |

Подсказки
  * Ваша программа должна выводить в cout только одно число — сумму введённых чисел (т.е. не надо выводить в cout входные числа или строки типа "A = ")
  * Вам не надо проверять, что входные числа не превышают по модулю 100000. Мы гарантируем, что в тестирующей системе вашей программе будут подаваться только числа,
    удовлетворяющие указанным ограничениям
*/
void sum()
{
    int a = 0, b = 0;
    std::cout << "Enter 2 integer numbers:\n";
    std::cin >> a >> b;
    std::cout << "Sum is " << a + b << std::endl;
}

/* Min string assignment
В стандартном потоке даны три строки, разделённые пробелом. Каждая строка состоит из строчных латинских букв и имеет длину не более 30 символов.
Выведите в стандартный вывод лексикографически минимальную из них.

Примеры
| stdin                | stdout |
| -----                | ------ |
| milk milkshake month | milk   |
| c a b                | a      |
| fire fog wood	       | fire   |
*/
void min_string()
{
    std::vector<std::string> ss = {"", "", ""};
    std::cout << "Enter 3 strings:\n";
    std::cin >> ss[0] >> ss[1] >> ss[2];
    std::cout << "Min lexicographical string is " << ss[0] << std::endl;
}

/* Quadratic equation assignment
На вход вашей программе в стандартном вводе даны действительные коэффициенты A, B и C уравнения Ax² + Bx + C = 0. Выведите все его различные действительные корни
в любом порядке. Гарантируется, что хотя бы один из коэффициентов не равен нулю.

Пример
| stdin  | stdout  |
| -----  | ------  |
| 2 5 2	 | -0.5 -2 |
| 2 4 2	 | -1      |
| 2 1 2  |         |
| 0 4 10 | -2.5    |

Подсказка

Для вычисления квадратного корня используйте функцию __sqrt__ из библиотеки cmath. Чтобы подключить библиотеку, в начале программы напишите
#include <cmath>
*/
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

