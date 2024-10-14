#include <iostream>
#include <cmath> // ��� ������������ abs

using namespace std;

// ������� ��� �������� �������� ������
void inputArray(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// ������� ��� ��������� ������� �䒺���� ��������
int countNegativeElements(double* arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}

// ������� ��� ����������� ������� ���������� �� ������� ��������
int findMinIndex(double* arr, int n) {
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (minIndex == -1 || abs(arr[i]) < abs(arr[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}

// ������� ��� ���������� ���� ������ �������� ���� ���������� �� �������
double sumAbsoluteAfterMin(double* arr, int n, int minIndex) {
    double sum = 0;
    for (int i = minIndex + 1; i < n; i++) {
        sum += abs(arr[i]);
    }
    return sum;
}

// ������� ��� ���������� �������� �䒺���� ��������
void saveNegativeSquares(double* arr, double* negatives, int n) {
    int negIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negatives[negIndex++] = arr[i] * arr[i];
        }
    }
}

// ������� ��� ���������� ������ �������� (���������� ����������)
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

// ������� ��� ������� ������������ �������� �� ���� �䒺���� ��������
void insertSortedNegatives(double* arr, double* negatives, int n) {
    int negIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = negatives[negIndex++];
        }
    }
}

// ������� ��� ��������� ������
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

    // �������� �������� ������
    inputArray(arr, n);

    // �������� ������� �䒺���� ��������
    int negativeCount = countNegativeElements(arr, n);
    cout << "Number of negative elements: " << negativeCount << endl;

    // �������� ������ ���������� �� ������� ��������
    int minIndex = findMinIndex(arr, n);
    cout << "Index of minimum absolute value element: " << minIndex << endl;

    // ���������� ���� ������ �������� ���� ���������� �� �������
    double sumAfterMin = sumAbsoluteAfterMin(arr, n, minIndex);
    cout << "Sum of absolute values after the minimum element: " << sumAfterMin << endl;

    double* negatives = new double[negativeCount];

    // ��������� �������� �䒺���� ��������
    saveNegativeSquares(arr, negatives, n);

    // ������� ����� ��������
    bubbleSort(negatives, negativeCount);

    // ������� ������������ �������� � �����
    insertSortedNegatives(arr, negatives, n);

    cout << "Transformed array with negative elements squared and sorted:\n";
    printArray(arr, n);

    // ��������� ���'��
    delete[] arr;
    delete[] negatives;

    return 0;
}
