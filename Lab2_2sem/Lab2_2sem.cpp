#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>      
#include <limits>     
using namespace std;

//ввод списка чисел
vector<double> inputList() {
    vector<double> list;
    int n;
    cout << "введите количество элементов в списке: ";
    cin >> n;

    cout << "введите " << n << " чисел:" << endl;
    for (int i = 0; i < n; i++) {
        double num;
        cin >> num;
        list.push_back(num);
    }
    return list;
}

//cреднее арифметическое
double avg(const vector<double>& list) {
    if (list.empty()) return 0;
    double sum = 0;
    for (double x : list) {
        sum += x;
    }
    return sum / list.size();
}

// минимальный элемент
double min(const vector<double>& list) {
    if (list.empty()) return 0;
    double minVal = list[0];
    for (double x : list) {
        if (x < minVal) minVal = x;
    }
    return minVal;
}

//максимальный элемент
double max(const vector<double>& list) {
    if (list.empty()) return 0;
    double maxVal = list[0];
    for (double x : list) {
        if (x > maxVal) maxVal = x;
    }
    return maxVal;
}

//создать список в виде стека
stack<double> Stack(const vector<double>& list) {
    stack<double> st;
    for (double x : list) {
        st.push(x);
    }
    return st;
}

//cоздать список в виде очереди
queue<double> createQueue(const vector<double>& list) {
    queue<double> q;
    for (double x : list) {
        q.push(x);
    }
    return q;
}

//cумма чётных элементов
double sumEven(const vector<double>& list) {
    double sum = 0;
    for (double x : list) {
        int intPart = (int)x;
        if (intPart % 2 == 0) {
            sum += x;
        }
    }
    return sum;
}

//cумма нечётных элементов
double sumOdd(const vector<double>& list) {
    double sum = 0;
    for (double x : list) {
        int intPart = (int)x;
        if (intPart % 2 != 0) {
            sum += x;
        }
    }
    return sum;
}

//новый список по формуле x^2 - 1
vector<double> computeFormula(const vector<double>& list) {
    vector<double> newList;
    for (double x : list) {
        newList.push_back(x * x - 1);  // x^2 - 1
    }
    return newList;
}

//сумма положительных элементов
double sumPositive(const vector<double>& list) {
    double sum = 0;
    for (double x : list) {
        if (x > 0) {
            sum += x;
        }
    }
    return sum;
}

//сумма отрицательных элементов
double sumNegative(const vector<double>& list) {
    double sum = 0;
    for (double x : list) {
        if (x < 0) {
            sum += x;
        }
    }
    return sum;
}

//функция для вывода стека
void printStack(stack<double> st) {
    cout << "Стек: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

//функция для вывода очереди
void printQueue(queue<double> q) {
    cout << "Очередь: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

//функция для вывода вектора
void printVector(const vector<double>& vec, const string& name) {
    cout << name << ": ";
    for (double x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод списка
    vector<double> numbers = inputList();

    if (numbers.empty()) {
        cout << "список пуст!" << endl;
        return 1;
    }

    cout << "1.Среднее арифметическое: " << avg(numbers) << endl;
    cout << "2. Минимальный элемент: " << min(numbers) << endl;
    cout << "3. Максимальный элемент: " << max(numbers) << endl;
    stack<double> myStack = Stack(numbers);
    printStack(myStack);
    queue<double> myQueue = createQueue(numbers);
    printQueue(myQueue);
    cout << "6. Сумма чётных элементов: " << sumEven(numbers) << endl;
    cout << "7. Сумма нечётных элементов: " << sumOdd(numbers) << endl;
    vector<double> newList = computeFormula(numbers);
    printVector(newList, "8. Новый список (x^2 - 1)");
    cout << "9. Сумма положительных элементов: " << sumPositive(numbers) << endl;
    cout << "10. Сумма отрицательных элементов: " << sumNegative(numbers) << endl;

    return 0;
}

