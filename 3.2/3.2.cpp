
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));
    int nomer = 0;
    int min = 1000;
    int proizvedenie = 1;
    int N = 0;
    const int n = 5;
    int a[n][n] = { {1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15},
                    {16,17,18,19,20},
                    {21,22,23,24,25},
    };
    int ch = 0; cin >> ch;
    cout << "N = "; cin >> N;
    switch (ch)
    {
    case 1: {

        break;
    }
    case 2: {
        for (int t = 0; t < n; t++)
            for (int k = 0; k < n; k++)
                a[t][k] = rand() % N + 1;
        break;
    }
    case 3: {
        for (int t = 0; t < n; t++)
            for (int k = 0; k < n; k++)
                cin >> a[t][k];
    }
    }
    for (int t = 0; t < n; t++) {
        for (int k = 0; k < n; k++)
            cout << setw(3) << a[t][k];
        cout << endl;
    }

    for (int t = 0; t < n; t++) {
        proizvedenie *= a[t][0]; nomer = 0;
    }

    for (int k = 1; k < n; k++) {
        for (int t = 0; t < n; t++) {
            proizvedenie *= a[t][k];
        }
        if (proizvedenie < min) { min = proizvedenie; nomer = k; }
        proizvedenie = 1;
    }
    cout << "nomer min stolba = " << nomer + 1 << endl;

    int max = a[0][0];
    int pmax = 0; int lmax = 0;

    for (int t = 0; t < n; t++) {
        for (int k = 0; k < n; k++) {
            if (max < a[t][k]) { pmax = t; lmax = k; max = a[t][k]; }
        }
    }
    cout << "max = a[" << pmax + 1 << "][" << lmax + 1 << "] = " << a[pmax][lmax] << endl;

    int sumelementov = 0;

    for (int t = 0; t < n; t++)
    {
        for (int k = 0; k < n; k++) {
            if (a[t][k] == a[pmax][lmax]) {
                for (int j = 0; j < n; j++) {
                    sumelementov += a[t][j];
                } break;
            }
        }
    }

    cout << "summa elementov s maks. elementov v stroke = " << sumelementov << endl;

    return 0;
}