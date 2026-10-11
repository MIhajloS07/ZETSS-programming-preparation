#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rows 20
#define cols 20

void ispis(int mat[][cols], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N; cin >> N;
    if (N > 20) return 1;
    int mat[rows][cols];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> mat[i][j];
#pragma region zad_1
    // suma glavne i sporedne dijagonale
    int sumaGlavne = 0, sumaSporedne = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) sumaGlavne += mat[i][j];
            if (i + j == N - 1) sumaSporedne += mat[i][j];
        }
    }
    cout << "Suma glavne: " << sumaGlavne << ", suma sporedne: " << sumaSporedne << endl;
#pragma endregion
#pragma region zad_2
    // rotiranje matrice za 90 stepeni u smeru kazaljke na satu
    int rotirana[rows][cols];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotirana[j][N - 1 - i] = mat[i][j];
        }
    }
    ispis(rotirana, N);
#pragma endregion
#pragma region zad_3 
    // najveci element u svakoj koloni
    vector<int> maxel;
    for (int j = 0; j < N; j++) {
        int max = mat[0][j];
        for (int i = 1; i < N; i++) {
            if (mat[i][j] > max) 
                max = mat[i][j];
        }
        maxel.push_back(max);
    }
    cout << "Maksimumi po kolonama: ";
    for (int el : maxel)
        cout << el << " ";
    cout << endl;
#pragma endregion
#pragma region zad_4
    // spiralni grad
    int broj = 1;
    int top = 0, bottom = N - 1, left = 0, right = N - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) mat[top][j] = broj++;
        top++;
        for (int i = top; i <= bottom; i++) mat[i][right] = broj++;
        right--;
        for (int j = right; j >= left; j--) mat[bottom][j] = broj++;
        bottom--;
        for (int i = bottom; i >= top; i--) mat[i][left] = broj++;
        left++;
    }
    // ispis matrice
    ispis(mat, N);
#pragma endregion
#pragma region zad_5
    // transponovanje matrice
    int transposed[rows][cols];
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            transposed[j][i] = mat[i][j];
    ispis(transposed, N);
#pragma endregion
    return 0;
}
