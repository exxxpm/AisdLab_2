#include<LinkedList.cpp>
#include<iostream>

using namespace Linkedlist;
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    Linkedlist::LinkedList<int> list1;

    for (int i = 0; i < 5; ++i) {
        list1.push_tail(rand() % 100);
    }

    std::cout << "list1: ";
    list1.printTower();

    Linkedlist::LinkedList<int> list3(list1);

    std::cout << "list3 (копия list1): ";
    list3.printTower();

    int i1 = 42;
    int i2 = 99;
    list1.push_head(i1);
    list1.push_head(i2);

    std::cout << "list1 после push_head: ";
    list1.printTower();

    list1.pop_head();

    std::cout << "list1 после pop_head: ";
    list1.printTower();

    std::cout << "Длинна list1: " << list1.length() << std::endl;

    int elementAtIndex = list1[2];
    std::cout << "Элемент по индексу 2: " << elementAtIndex << std::endl;

    list1.reverse();

    std::cout << "Реверс list1: ";
    list1.printTower();

    cout << endl;
    cout << "Решение задачи" << endl;

    Linkedlist::LinkedList<int> num1, num2;
    num1.push_tail(1);
    num1.push_tail(2);

    num2.push_tail(2);
    num2.push_tail(0);

    cout << num1 << endl;
    cout << num2 << endl;


    Linkedlist::LinkedList<int> sum = addNumbers(num1, num2);
    Linkedlist::LinkedList<int> product = multiplyNumbers(num1, num2);

    std::cout << "Сумма: " << sum << std::endl;
    std::cout << "Произведение: " << product << std::endl;

    return 0;
}