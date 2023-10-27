#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>

using namespace std;

// функция для вычисления весовых коэффициентов
vector<double> calculateWeights(vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<double> weights(n);

// вычисление суммы для каждого столбца
    vector<double> cSums(n);
    for (int j = 0; j < n; ++j) {
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += matrix[i][j];
        }
        cSums[j] = sum;
    }

// вычисление весовых коэффициентов
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < n; ++j) {
            sum += matrix[i][j] / cSums[j];
        }
        weights[i] = sum / n;
    }

    return weights;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введите количество критериев: ";
    cin >> n;
    //проверяем введенные данные на правильность
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1, '\n');

        cout << "Ошибка!" << endl << endl;
        return 0;
    }

    vector<vector<double>> m(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                m[i][j] = 1.0;
            }
            else {
                cout << "Введите пару сравнения для критериев " << i + 1 << " и " << j + 1 << ": ";
                cin >> m[i][j];
                //проверяем введенные данные на правильность
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1, '\n');

                    cout << "Ошибка!" << endl << endl;
                    return 0;
                }
                m[j][i] = 1.0 / m[i][j];
            }
        }
    }

    vector<double> weights = calculateWeights(m);

    cout << "Весовые коэффициенты: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(2) << weights[i] << " ";
    }
}