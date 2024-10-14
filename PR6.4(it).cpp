#include <iostream>
#include <cmath> // Для використання abs

using namespace std;

// Функція для введення елементів масиву
void inputArray(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Функція для підрахунку кількості від’ємних елементів
int countNegativeElements(double* arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}

// Функція для знаходження індексу мінімального за модулем елемента
int findMinIndex(double* arr, int n) {
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (minIndex == -1 || abs(arr[i]) < abs(arr[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Функція для обчислення суми модулів елементів після мінімального за модулем
double sumAbsoluteAfterMin(double* arr, int n, int minIndex) {
    double sum = 0;
    for (int i = minIndex + 1; i < n; i++) {
        sum += abs(arr[i]);
    }
    return sum;
}

// Функція для збереження квадратів від’ємних елементів
void saveNegativeSquares(double* arr, double* negatives, int n) {
    int negIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negatives[negIndex++] = arr[i] * arr[i];
        }
    }
}

// Функція для сортування масиву квадратів (сортування бульбашкою)
void bubbleSort(double* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функція для вставки відсортованих квадратів на місце від’ємних елементів
void insertSortedNegatives(double* arr, double* negatives, int n) {
    int negIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = negatives[negIndex++];
        }
    }
}

// Функція для виведення масиву
void printArray(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of array elements: ";
    cin >> n;

    double* arr = new double[n];

    // Введення елементів масиву
    inputArray(arr, n);

    // Знайдемо кількість від’ємних елементів
    int negativeCount = countNegativeElements(arr, n);
    cout << "Number of negative elements: " << negativeCount << endl;

    // Знайдемо індекс мінімального за модулем елемента
    int minIndex = findMinIndex(arr, n);
    cout << "Index of minimum absolute value element: " << minIndex << endl;

    // Обчислення суми модулів елементів після мінімального за модулем
    double sumAfterMin = sumAbsoluteAfterMin(arr, n, minIndex);
    cout << "Sum of absolute values after the minimum element: " << sumAfterMin << endl;

    double* negatives = new double[negativeCount];

    // Збережемо квадрати від’ємних елементів
    saveNegativeSquares(arr, negatives, n);

    // Сортуємо масив квадратів
    bubbleSort(negatives, negativeCount);

    // Вставка відсортованих квадратів у масив
    insertSortedNegatives(arr, negatives, n);

    cout << "Transformed array with negative elements squared and sorted:\n";
    printArray(arr, n);

    // Звільнення пам'яті
    delete[] arr;
    delete[] negatives;

    return 0;
}
