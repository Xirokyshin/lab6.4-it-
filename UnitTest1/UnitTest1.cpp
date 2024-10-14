#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.4(it).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // Функція, що тестується
        int countNegativeElements(double* arr, int n) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] < 0) {
                    count++;
                }
            }
            return count;
        }

        TEST_METHOD(TestCountNegativeElements)
        {
            // Тестовий випадок 1
            double arr1[] = { -1.5, 2.3, -4.0, 0.0, 5.0 }; // 2 від’ємних елемента
            int count1 = countNegativeElements(arr1, 5);
            Assert::AreEqual(2, count1);

            // Тестовий випадок 2
            double arr2[] = { 1.0, 2.0, 3.0 }; // 0 від’ємних елементів
            int count2 = countNegativeElements(arr2, 3);
            Assert::AreEqual(0, count2);

            // Тестовий випадок 3
            double arr3[] = { -1.0, -2.0, -3.0 }; // 3 від’ємних елемента
            int count3 = countNegativeElements(arr3, 3);
            Assert::AreEqual(3, count3);

            // Тестовий випадок 4
            double arr4[] = { 0.0, 0.0, 0.0 }; // 0 від’ємних елементів
            int count4 = countNegativeElements(arr4, 3);
            Assert::AreEqual(0, count4);
        }
    };
}
