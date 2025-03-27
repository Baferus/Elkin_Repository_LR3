#include <iostream> 
#include <cmath>
using namespace std;
int countDigits(int x) {
    if (x == 0) return 1;
    int count = 0;
    while (x != 0) {
        x /= 10;
        count++;
    }
    return count;
}
int productOfFirstNDigits(int x, int n) {
    int numDigits = countDigits(x);
    if (n <= 0 || n > numDigits) return 0;
    
    int product = 1;
    for (int i = 0; i < n; i++) {
        int digit = x / (int)pow(10, numDigits - 1 - i) % 10;
        product *= digit;
    }
    return product;
}
int sumOfDigits(int x) {
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main(){
    int choice,x,n;
    cout << "Введите натуральное число X: ";
    cin >> x;
    
    if (x <= 0) {
        cout << "Ошибка: X должно быть натуральным числом." << endl;
        return 1;
    }
    while (true) {
        cout << "Выберите операцию:\n"; 
        cout << "1. Определить сумму цифр числа X\n";
        cout << "2. Определить произведение первых N цифр числа X\n";
        cout << "3. Выход\n";  // Добавляем вариант выхода
        cout << "Ваш выбор: ";
        cin >> choice;
    
        switch (choice) {
            case 1: {
                int sum = sumOfDigits(x);
                cout << "Сумма цифр числа " << x << " равна: " << sum << endl;
                break;
            }
            case 2: {
                cout << "Введите цифру N (меньше количества разрядов числа X): ";
                cin >> n;
                int numDigits = countDigits(x);
                if (n <= 0 || n > numDigits) {
                    cout << "Ошибка: N должно быть больше 0 и меньше количества разрядов числа X." << endl;
                    break;  // Не return, чтобы не закрывать программу
                }
                int product = productOfFirstNDigits(x, n);
                cout << "Произведение первых " << n << " цифр числа " << x << " равно: " << product << endl;
                break;
            }
            case 3: 
                return 0;  // Выход из программы
            default: 
                cout << "Ошибка - неверный выбор операции" << endl; 
        }
    }
    return 0;
}