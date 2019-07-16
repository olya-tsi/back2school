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

/* Division assignment
Дано два натуральных числа A и B, не превышающих 1 000 000. Напишите программу, которая вычисляет целую часть частного от деления A на B.

Если B = 0, выведите "Impossible".

Пример

| stdin | stdout     |
| ----- | ------     |
| 10 2	| 5          |
| 3 5   | 0          |
| 11 0  | Impossible |
*/
void divison()
{
    int a = 0, b = 0;

    std::cout << "Enter 2 positive integer numbers:\n";
    std::cin >> a >> b;
    if (b > 0 && a >= 0)
    {
        std::cout << "The result is " << a / b << std::endl;
    }
    else if (b == 0)
    {
        std::cout << "Impossible\n";
    }
}

/* Cost calculation assignment
Написать программу вычисления стоимости покупки с учётом скидки. Скидка в X процентов предоставляется, если сумма покупки больше A рублей, в Y процентов -
если сумма больше B рублей.

В стандартном вводе содержится пять вещественных чисел, разделённых пробелом: N, A, B, X, Y (A < B) - где N - исходная стоимость товара. Выведите стоимость
покупки с учётом скидки.

Пример

| stdin              | stdout |
| -----              | ------ |
| 100 110 120 5 10   | 100    |
| 115 110 120 5 10   | 109.25 |
| 150 110 120 5 12.5 | 131.25 |
*/
void cost()
{
    double n = 0, a = 0, b = 0, x = 0, y = 0;

    std::cout << "Enter 5 numbers in the following order: current total cost, cost for discount #1, cost for discount #2, discount #1's value, discount #2's value\n";
    std::cin >> n >> a >> b >> x >> y;

    double cost = n;
    if (n > b && y > 0)
    {
        cost = n * ((100 - y) / 100);
    }
    else if (n > a && x > 0)
    {
        cost = n * ((100 - x) / 100);
    }

    std::cout << "Final cost is " << cost << std::endl;
}

/* Even numbers assignment
Дано два целых числа A и B (A <= B, A >= 1, B <= 30000). Выведите через пробел все чётные числа от A до B (включительно).

Для проверки целого числа x на чётность используется операция взятия остатка от деления на 2, которая в C++ оформляется с помощью символа "%". Например,


int x; <br>
cin >> x; <br>
if (x % 2 == 0) { <br>
  // x - чётное число <br>
} else { <br>
  // x - нечётное число <br>
} <br>

Пример

| stdin | stdout     |
| ----- | ------     |
| 1 10  | 2 4 6 8 10 |
| 2 3   | 2          |
| 9 11  | 10         |
*/
void even_numbers() {
    int a = 0, b = 0;

    std::cout << "Enter 2 integer numbers between 1 and 30000:\n";
    std::cin >> a >> b;

    if (a % 2 == 1)
    {
        a++;
    }

    while (a <= b)
    {
        std::cout << a << " ";
        a += 2;
    }
}

/* Second entry of 'f' assignment
Дана строка. Найдите в этой строке второе вхождение буквы f и выведите индекс этого вхождения. Если буква f в данной строке встречается только один раз,
выведите число -1, а если не встречается ни разу, выведите число -2. Индексы нумеруются с нуля.

Пример
| stdin   | stdout |
| -----   | ------ |
| comfort | -1     |
| coffee  | 3      |
| car     | -2     |

*/
void second_entry()
{
    std::string s = "";
    std::cout << "Enter the string:\n";
    std::cin >> s;
    int i = -2; // no 'f' character in string
    for (auto k = 0; k < s.size(); k++)
    {
        if (s[k] == 'f' && i == -2)
        {
            i = -1;
        }
        else if (s[k] == 'f' && i == -1)
        {
            i = k;
            break;
        }
    }
    std::cout << "Second entry of 'f' character in string " << s << " is " << i << std::endl;
}

/* Greatest common divisor assignment
В stdin даны два натуральных числа. Выведите в stdout их наибольший общий делитель.

Пример

| stdin | stdout |
| ----- | ------ |
| 25 27 | 1      |
| 12 16 | 4      |
| 13 13	| 13     |

*/
void gcd()
{
    int a = 0, b = 0;
    std::cout << "Enter 2 positive numbers:\n";
    std::cin >> a >> b;

    int gcd = 0;
    if (a == b || b == 0)
    {
        gcd = a;
    }
    else if (a == 0)
    {
        gcd = b;
    }
    else
    {
        // int start = a;
        // if (a > b)
        // {
        //     start = b;
        // }
        // for (auto i = start; i >= 1; i--)
        // {
        //     if (a % i == 0 and b % i == 0)
        //     {
        //         gcd = i;
        //         break;
        //     }
        // }
        gcd = std::min(a, b);
        int q = a, r = b;
        if (q < r)
        {
            std::swap(q, r);
        }
        while (q % r != 0)
        {
            gcd = q % r;
            q = r;
            r = gcd;
        }

    }

    std::cout << "GCD(" << a << "," << b << ") is " << gcd << std::endl;
}

/* Binary numbers
На вход дано целое положительное число N. Выведите его в двоичной системе счисления без ведущих нулей.

Пример

| stdin | stdout |
| ----- | ------ |
| 5     | 101    |
| 32    | 100000 |
| 1     | 1      |
Подсказка
* число N можно считывать в переменную типа int
* в этой задаче вам может пригодиться контейнер vector; напоминаем, что добавление значения x в конец вектора v делается так: v.push_back(x);
*/
void to_binary()
{
    int n = 0;
    std::cout << "Enter positive number:\n";
    std::cin >> n;
    std::vector<int> bins;
    while (n / 2 != 0)
    {
        bins.push_back(n % 2);
        n /= 2;
    }
    bins.push_back(1);
    std::reverse(bins.begin(), bins.end());
    std::cout << "Binary representation: ";
    for (auto i : bins)
    {
        std::cout << i;
    }
}

int main(int argc, char *argv[])
{
    if (1 == argc)
    {
        std::cout << "-s  - A+B assignment\n";
        std::cout << "-ms - min string assignment\n";
        std::cout << "-e  - quadratic equation assignment\n";
        std::cout << "-d  - division assignment\n";
        std::cout << "-c  - cost calculation assignment\n";
        std::cout << "-en - even numbers assignment\n";
        std::cout << "-se - second entry assignment\n";
        std::cout << "-gd - greatest common divisor assignment\n";
        std::cout << "-b  - number to binary representation\n";
        return 0;
    }

    std::string option(argv[1]);
    if (option == "-s")
    {
        sum();
    }
    else if (option == "-ms")
    {
        min_string();
    }
    else if (option == "-e")
    {
        equation();
    }
    else if (option == "-d")
    {
        divison();
    }
    else if (option == "-c")
    {
        cost();
    }
    else if (option == "-en")
    {
        even_numbers();
    }
    else if (option == "-se")
    {
        second_entry();
    }
    else if (option == "-gd")
    {
        gcd();
    }
    else if (option == "-b")
    {
        to_binary();
    }
    else
    {
        std::cout << "Unknown option\n";
    }


    return 0;
}

