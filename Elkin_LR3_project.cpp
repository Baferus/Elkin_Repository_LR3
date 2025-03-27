#include <iostream> 

using namespace std; 
int sumOfDigits(int x) {
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main(){
    int choice,x;
    cout << "Введите натуральное число X: ";
    cin >> x;
    
    if (x <= 0) {
        cout << "Ошибка: X должно быть натуральным числом." << endl;
        return 1;
    } 

    cout << "Выберите операцию:\n"; 
    cin >> choice;
    cout << "1. Определить сумму цифр числа X\n"; 
    switch (choice){
        case 1:{
            int sum = sumOfDigits(x);
            cout << "Сумма цифр числа " << x << " равна: " << sum << endl;
            break;
        }
        default: 
        cout << "Ошибка - неверный выбор операции" << endl; 
        return 1;
    }
    return 0;
}