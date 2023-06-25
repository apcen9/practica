
#include <iostream>
#include <vector>

using namespace std;

// ������� ��� ���������� ���������� �������� � ����� x
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
    int n; // ���������� �����
    cout << "������� ���������� �����= ";
    cin >> n;

    vector<double> X(n); // ���������� ����� �� ��� X
    vector<double> Y(n); // ���������� ����� �� ��� Y

    cout << "������� ���������� ����� � � y " << endl;//������� �����
    for (int i = 0; i < n; i++) {
        cout << "����� " << i + 1 << ": ";
        cin >> X[i] >> Y[i];
    }

    double x; // �����, � ������� ����� ��������� �������� �������
    cout << "������� �������� x: ";
    cin >> x;

    double y = lagrange(x, X, Y); // ��������� �������� ������� � ����� x

    cout << "f(" << x << ") = " << y << endl;

    return 0;
}




