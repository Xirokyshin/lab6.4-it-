#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.4(it).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // �������, �� ���������
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
            // �������� ������� 1
            double arr1[] = { -1.5, 2.3, -4.0, 0.0, 5.0 }; // 2 �䒺���� ��������
            int count1 = countNegativeElements(arr1, 5);
            Assert::AreEqual(2, count1);

            // �������� ������� 2
            double arr2[] = { 1.0, 2.0, 3.0 }; // 0 �䒺���� ��������
            int count2 = countNegativeElements(arr2, 3);
            Assert::AreEqual(0, count2);

            // �������� ������� 3
            double arr3[] = { -1.0, -2.0, -3.0 }; // 3 �䒺���� ��������
            int count3 = countNegativeElements(arr3, 3);
            Assert::AreEqual(3, count3);

            // �������� ������� 4
            double arr4[] = { 0.0, 0.0, 0.0 }; // 0 �䒺���� ��������
            int count4 = countNegativeElements(arr4, 3);
            Assert::AreEqual(0, count4);
        }
    };
}
