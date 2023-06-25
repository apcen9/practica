
#include <iostream>
#include <vector>

using namespace std;

// функция для вычисления многочлена Лагранжа в точке x
double lagrange(double x, vector<double> X, vector<double> Y) {
    int n = X.size();
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        double prod = Y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                prod *= (x - X[j]) / (X[i] - X[j]);
            }
        }
        res += prod;
    }
    return res;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n; // количество точек
    cout << "Введите количество точек= ";
    cin >> n;

    vector<double> X(n); // координаты точек по оси X
    vector<double> Y(n); // координаты точек по оси Y

    cout << "Введите координаты точек х и y " << endl;//введите точки
    for (int i = 0; i < n; i++) {
        cout << "Точка " << i + 1 << ": ";
        cin >> X[i] >> Y[i];
    }

    double x; // точка, в которой нужно вычислить значение функции
    cout << "Введите значение x: ";
    cin >> x;

    double y = lagrange(x, X, Y); // вычисляем значение функции в точке x

    cout << "f(" << x << ") = " << y << endl;

    return 0;
}




