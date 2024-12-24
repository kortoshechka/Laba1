#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

// Task 1
int sumLastNums(int x) {
    int last = x % 10;
    int secondLast = (x / 10) % 10;
    return last + secondLast;
}

// Task 2
string isPositive(int x) {
    return x > 0 ? "True" : "False";
}

// Task 3
string isUpperCase(char x) {
    return (x >= 'A' && x <= 'Z') ? "True" : "False";
}

// Task 4
string isDivisor(int a, int b) {
    return (a != 0 && b % a == 0) || (b != 0 && a % b == 0) ? "True" : "False";
}

// Task 5
int lastNumSum(int a, int b) {
    return (a % 10) + (b % 10);
}

// Task 6
double safeDiv(int x, int y) {
    return y == 0 ? 0 : static_cast<double>(x) / y;
}

// Task 7
string makeDecision(int x, int y) {
    if (x > y) return to_string(x) + " > " + to_string(y);
    if (x < y) return to_string(x) + " < " + to_string(y);
    return to_string(x) + " == " + to_string(y);
}

// Task 8
string sum3(int x, int y, int z) {
    return (x + y == z) || (x + z == y) || (y + z == x) ? "True" : "";
}

// Task 9
string age(int x) {
    int lastDigit = x % 10;
    int lastTwoDigits = x % 100;
    if (lastTwoDigits >= 11 && lastTwoDigits <= 14) return to_string(x) + " лет";
    if (lastDigit == 1) return to_string(x) + " год";
    if (lastDigit >= 2 && lastDigit <= 4) return to_string(x) + " года";
    return to_string(x) + " лет";
}

// Task 10
void printDays(string x) {
    vector<string> days = { "понедельник", "вторник", "среда", "четверг", "пятница", "суббота", "воскресенье" };
    auto it = find(days.begin(), days.end(), x);
    if (it == days.end()) {
        cout << "это не день недели" << endl;
    }
    else {
        for (; it != days.end(); ++it) {
            cout << *it << endl;
        }
    }
}

// Task 11
string reverseListNums(int x) {
    string result;
    for (int i = x; i >= 0; --i) {
        result += to_string(i) + " ";
    }
    return result;
}

// Task 12
int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return result;
}

// Task 13
string equalNum(int x) {
    int lastDigit = x % 10;
    while (x > 0) {
        if (x % 10 != lastDigit) return "False";
        x /= 10;
    }
    return "True";
}

// Task 14
void leftTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        cout << string(i, '*') << endl;
    }
}

// Task 15
void guessGame() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    int target = rand() % 10; // Генерация случайного числа от 0 до 9
    int guess, attempts = 0;

    do {
        cout << "Введите число от 0 до 9: ";
        cin >> guess;

        // Проверка на корректность ввода
        if (guess < 0 || guess > 9) {
            cout << "Некорректный ввод. Пожалуйста, введите число от 0 до 9." << endl;
            continue; // Пропускаем итерацию цикла, если ввод неверный
        }

        ++attempts; // Увеличиваем счетчик попыток

        if (guess == target) {
            cout << "Вы угадали!" << endl;
            break; // Выход из цикла, если число угадано
        }
        else {
            cout << "Вы не угадали." << endl;
        }
    } while (true);

    cout << "Вы отгадали число за " << attempts << " попыток." << endl;
}

// Task 16
int findLast(int arr[], int size, int x) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] == x) return i;
    }
    return -1;
}

// Task 17
vector<int> add(vector<int> arr, int x, int pos) {
    arr.insert(arr.begin() + pos, x);
    return arr;
}

// Task 18
void reverse(vector<int>& arr) {
    std::reverse(arr.begin(), arr.end());
}

// Task 19
vector<int> concat(vector<int> arr1, vector<int> arr2) {
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
}

// Task 20
vector<int> deleteNegative(vector<int> arr) {
    arr.erase(remove_if(arr.begin(), arr.end(), [](int x) { return x < 0; }), arr.end());
    return arr;
}

int main() {
    // Настройка локали для работы с русскими символами
    std::locale::global(std::locale(""));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

    int choice;
    cout << "Выберите задание (0-20) где 0-выполнение всех задач: ";
    cin >> choice;
    if (choice == 0) {
        cout << "Task 1: " << sumLastNums(4568) << endl;
        cout << "Task 2: " << isPositive(3) << endl;
        cout << "Task 3: " << isUpperCase('D') << endl;
        cout << "Task 4: " << isDivisor(3, 6) << endl;

        int sum = lastNumSum(5, 11);
        sum = lastNumSum(sum, 123);
        sum = lastNumSum(sum, 14);
        sum = lastNumSum(sum, 1);
        cout << "Task 5: " << sum << endl;

        cout << "Task 6: " << safeDiv(5, 0) << endl;
        cout << "Task 7: " << makeDecision(5, 7) << endl;
        cout << "Task 8: " << sum3(5, 7, 2) << endl;
        cout << "Task 9: " << age(31) << endl;
        printDays("четверг");
        cout << "Task 11: " << reverseListNums(5) << endl;
        cout << "Task 12: " << pow(2, 5) << endl;
        cout << "Task 13: " << equalNum(1111) << endl;
        leftTriangle(4);

        guessGame();

        int arr[] = { 1, 2, 3, 4, 2, 2, 5 };
        cout << "Task 16: " << findLast(arr, 7, 2) << endl;

        vector<int> arr17 = { 1, 2, 3, 4, 5 };
        vector<int> result17 = add(arr17, 9, 3);
        cout << "Task 17: ";
        for (int num : result17) cout << num << " ";
        cout << endl;

        vector<int> arr18 = { 1, 2, 3, 4, 5 };
        reverse(arr18);
        cout << "Task 18: ";
        for (int num : arr18) cout << num << " ";
        cout << endl;

        vector<int> arr1 = { 1, 2, 3 };
        vector<int> arr2 = { 7, 8, 9 };
        vector<int> result19 = concat(arr1, arr2);
        cout << "Task 19: ";
        for (int num : result19) cout << num << " ";
        cout << endl;

        vector<int> arr20 = { 1, 2, -3, 4, -2, 2, -5 };
        vector<int> result20 = deleteNegative(arr20);
        cout << "Task 20: ";
        for (int num : result20) cout << num << " ";
        cout << endl;
    }
    else {
        switch (choice) {
  

        case 1:
            cout << "Task 1: " << sumLastNums(4568) << endl;
            break;
        case 2:
            cout << "Task 2: " << isPositive(3) << endl;
            break;
        case 3:
            cout << "Task 3: " << isUpperCase('D') << endl;
            break;
        case 4:
            cout << "Task 4: " << isDivisor(3, 6) << endl;
            break;
        case 5:
            int sum;
            sum = lastNumSum(5, 11);
            sum = lastNumSum(sum, 123);
            sum = lastNumSum(sum, 14);
            sum = lastNumSum(sum, 1);
            cout << "Task 5: " << sum << endl;
            break;
        case 6:
            cout << "Task 6: " << safeDiv(5, 0) << endl;
            break;
        case 7:
            cout << "Task 7: " << makeDecision(5, 7) << endl;
            break;
        case 8:
            cout << "Task 8: " << sum3(5, 7, 2) << endl;
            break;
        case 9:
            cout << "Task 9: " << age(31) << endl;
            break;
        case 10:
            printDays("четверг");
            break;
        case 11:
            cout << "Task 11: " << reverseListNums(5) << endl;
            break;
        case 12:
            cout << "Task 12: " << pow(2, 5) << endl;
            break;
        case 13:
            cout << "Task 13: " << equalNum(1111) << endl;
            break;
        case 14:
            leftTriangle(4);
            break;
        case 15:
            guessGame();
            break;
        case 16: {
            int arr[] = { 1, 2, 3, 4, 2, 2, 5 };
            cout << "Task 16: " << findLast(arr, 7, 2) << endl;
            break;
        }
        case 17: {
            vector<int> arr17 = { 1, 2, 3, 4, 5 };
            vector<int> result17 = add(arr17, 9, 3);
            cout << "Task 17: ";
            for (int num : result17) cout << num << " ";
            cout << endl;
            break;
        }
        case 18: {
            vector<int> arr18 = { 1, 2, 3, 4, 5 };
            reverse(arr18);
            cout << "Task 18: ";
            for (int num : arr18) cout << num << " ";
            cout << endl;
            break;
        }
        case 19: {
            vector<int> arr1 = { 1, 2, 3 };
            vector<int> arr2 = { 7, 8, 9 };
            vector<int> result19 = concat(arr1, arr2);
            cout << "Task 19: ";
            for (int num : result19) cout << num << " ";
            cout << endl;
            break;
        }
        case 20: {
            vector<int> arr20 = { 1, 2, -3, 4, -2, 2, -5 };
            vector<int> result20 = deleteNegative(arr20);
            cout << "Task 20: ";
            for (int num : result20) cout << num << " ";
            cout << endl;
            break;
        }
        default:
            cout << "Некорректный выбор, попробуйте снова." << endl;
            break;
        }
    }

    return 0;
}
