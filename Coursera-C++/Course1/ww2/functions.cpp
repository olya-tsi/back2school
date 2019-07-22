#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

/* Factorial assignment
Напишите функцию, которая

* называется Factorial
* возвращает int
* принимает int и возвращает факториал своего аргумента. Гарантируется, что аргумент функции по модулю не превышает 10. Для отрицательных аргументов функция должна возвращать 1.

| Аргумент функции | Результат |
| ---------------- | --------- |
| 1                | 1         |
| -2               | 1         |
| 4                | 24        |
*/

int factorial(int x)
{
    if (x <= 1)
        return 1;

    int f = 1;
    for (auto i = 1; i <= x; i++)
    {
        f *= i;
    }

    return f;
}

/* Palindrome assignment
Напишите функцию, которая

* называется IsPalindrom
* возвращает bool
* принимает параметр типа string и возвращает, является ли переданная строка палиндромом
Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево. Пустая строка является палиндромом.

| Аргумент функции | Результат |
| ---------------- | --------- |
| madam            | true      |
| gentleman        | false     |
| X                | true      |
*/

bool IsPalindrom(std::string word)
{
    std::string rev_word = word;
    std::reverse(rev_word.begin(), rev_word.end());
    if (word == rev_word)
        return true;

    return false;
}

/* Palindrome selection assignment
Напишите функцию, которая

* называется PalindromFilter
* возвращает vector<string>
* принимает vector<string> words и int minLength и возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.

Примеры
| words           | minLength | результат    |
| -----           | --------- | ---------    |
| abacaba, aba    | 5         | abacaba      |
| abacaba, aba    | 2         | abacaba, aba |
| weew, bro, code | 4         | weew         |

*/
std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength)
{
    std::vector<std::string> res_words;

    for (auto w : words)
    {
        if (IsPalindrom(w) and w.size() >= minLength)
            res_words.push_back(w);
    }

    return res_words;
}

/* Maximizer assignment
Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента: first и second. Если first оказался больше second,
Ваша функция должна записывать в second значение параметра first. При этом изменение параметра second должно быть видно на вызывающей стороне.

Пример
int a = 4;
int b = 2;
UpdateIfGreater(a, b);
// b должно стать равно 4
*/
void UpdateIfGreater(const int first, int& second)
{
    if (first > second)
        second = first;
}

/* Moving strings assignment
Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination, и дописывает все строки из первого вектора в конец второго.
После выполнения функции вектор source должен оказаться пустым.

Чтобы очистить содержимое вектора, надо вызвать у него метод clear:
vector<string> words = {"hey", "hi"};
words.clear();
// Теперь вектор words пуст

Пример
vector<string> source = {"a", "b", "c"};
vector<string> destination = {"z"};
MoveStrings(source, destination);
// source должен оказаться пустым
// destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
*/
void MoveStrings(std::vector<std::string>& src, std::vector<std::string>& dst)
{
    for (auto i : src)
    {
        dst.push_back(i);
    }
    src.clear();
}

/* Reversing a sequence
Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.
Пример
vector<int> numbers = {1, 5, 3, 4, 2};
Reverse(numbers);
// numbers должен оказаться равен {2, 4, 3, 5, 1}
*/

void Reverse(std::vector<int>& v)
{
    auto size = v.size();
    for (auto i = 0; i < size / 2; i++)
    {
        std::swap(v[i], v[size - i - 1]);
    }
}

/* Reversing a sequence #2
Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую копию вектора v, в которой числа переставлены в обратном порядке.

Пример

| Вектор v      | Результат функции |
| --------      | ----------------- |
| 1, 5, 3, 4, 2 | 2, 4, 3, 5, 1     |
*/
std::vector<int> Reversed(const std::vector<int>& v)
{
    auto reversed_v = v;
    Reverse(reversed_v);
    return reversed_v;
}

int main()
{
    /*
    int x = 0;
    std::cout << "Enter a number:\n";
    std::cin >> x;
    std::cout << "Factorial of " << x << " is " << factorial(x) << std::endl;
    */

    /*
    std::string str = "";
    std::cout << "Enter a word:\n";
    std::cin >> str;
    std::cout << "The word " << str << " is palindrome? " << IsPalindrom(str) << std::endl;
    */

    /*
    std::vector<std::string> words = {"weew", "bro", "code"};
    int min_l = 4;
    std::vector<std::string> pals = PalindromFilter(words, min_l);
    for (auto p : pals)
    {
        std::cout << p << " ";
    }
    */

    /*
    int a = 4, b = 2;
    UpdateIfGreater(a, b);
    std::cout << "b == " << b << std::endl;
    */

    /*
    std::vector<std::string> src = {"a", "b", "c"};
    std::vector<std::string> dest = {"z"};
    MoveStrings(src, dest);
    std::cout << "Source vector has size " << src.size() << std::endl;
    std::cout << "Destingation vector is ";
    for (auto e : dest)
    {
        std::cout << e << " ";
    }
    */

    std::vector<int> numbers = {1, 5, 3, 7, 4, 2};
    std::cout << "Original sequence: ";
    for (auto i : numbers)
    {
        std::cout << i << " ";
    }
    //Reverse(numbers);
    std::vector<int> rev_nums = Reversed(numbers);
    std::cout << "\nReversed sequence: ";
    for (auto i : rev_nums)
    {
        std::cout << i << " ";
    }


    return 0;
}