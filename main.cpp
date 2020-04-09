#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    MyVector A;
    for (int i = 0; i < 5; ++i)
        A.pushBack(i);

    cout << "������ �" << endl
         << "�������� ������� - ";

         A.Show_Vector();

    cout << "������ - " << A.size() <<endl
         << "����������� - " << A.capacity() << endl
         << "������ �������� - " << A.loadFactor() << endl
         << "�������� [] - " << A[3] << endl << endl;; //�� �� ����������?

    MyVector B;
    for (int i = 0; i < 6; ++i)
        B.pushBack(i*2);

    cout << "������ B" << endl
         << "�������� ������� - ";

         B.Show_Vector();

    cout << "������ - " << B.size() <<endl
         << "����������� - " << B.capacity() << endl
         << "������ �������� - " << B.loadFactor() << endl
         << "�������� [] - " << B[5] << endl << endl;; //�� �� ����������?

    cout << "������� 1 �������� �� �������� ������� � ������ B" << endl << endl;
        B.insert(3, 150);

        cout << "������ B" << endl
         << "�������� ������� - ";

         B.Show_Vector();

    cout << "������ - " << B.size() <<endl
         << "����������� - " << B.capacity() << endl
         << "������ �������� - " << B.loadFactor() << endl
         << "�������� [] - " << B[3] << endl << endl;; //�� �� ����������?

    cout << "������� ������� � � ������ B" << endl << endl;
        B.insert(4, A);

        cout << "������ B" << endl
         << "�������� ������� - ";

         B.Show_Vector();

    cout << "������ - " << B.size() <<endl
         << "����������� - " << B.capacity() << endl
         << "������ �������� - " << B.loadFactor() << endl
         << "�������� [] - " << B[3] << endl << endl;; //�� �� ����������?

    cout << "������ 1 ������� �� ������� �� ��������� �������" << endl << endl;

        B.erase(3);

        cout << "������ B" << endl
         << "�������� ������� - ";

         B.Show_Vector();

    cout << "������ - " << B.size() <<endl
         << "����������� - " << B.capacity() << endl
         << "������ �������� - " << B.loadFactor() << endl
         << "�������� [] - " << B[3] << endl << endl;; //�� �� ����������?

    cout << "������  len ��������� ������� � i � ������� �" << endl << endl;

        B.erase(3, 5);

        cout << "������ B" << endl
         << "�������� ������� - ";

         B.Show_Vector();

    cout << "������ - " << B.size() <<endl
         << "����������� - " << B.capacity() << endl
         << "������ �������� - " << B.loadFactor() << endl
         << "�������� [] - " << B[5] << endl << endl;; //�� �� ����������?

    cout << "������  ��������� ������� � ������� B" << endl << endl;

        B.popBack();

        cout << "������ B" << endl
         << "�������� ������� - ";

         B.Show_Vector();

    cout << "������ - " << B.size() <<endl
         << "����������� - " << B.capacity() << endl
         << "������ �������� - " << B.loadFactor() << endl
         << "�������� [] - " << B[4] << endl << endl; //�� �� ����������?

    cout << "������� resize ������� B � ������� �������" << endl << endl;

        B.resize(20);

        cout << "������ B" << endl
         << "�������� ������� - ";

         B.Show_Vector();

    cout << "������ - " << B.size() <<endl
         << "����������� - " << B.capacity() << endl
         << "������ �������� - " << B.loadFactor() << endl
         << "�������� [] - " << B[4] << endl << endl; //�� �� ����������?

    cout << "������� resize ������� B � ������� �������" << endl << endl;

        B.resize(3);

        cout << "������ B" << endl
         << "�������� ������� - ";

         B.Show_Vector();

    cout << "������ - " << B.size() <<endl
         << "����������� - " << B.capacity() << endl
         << "������ �������� - " << B.loadFactor() << endl
         << "�������� [] - " << B[2] << endl << endl; //�� �� ����������?

    cout << "������� clear ������ B" << endl << endl;

        B.clear();

        cout << "������ B" << endl
         << "�������� ������� - ";

         B.Show_Vector();

    cout << endl << "������ - " << B.size() << endl
         << "����������� - " << B.capacity() << endl
         << "������ �������� - " << B.loadFactor() << endl
         << "�������� [] - " << B[2] << endl << endl; //�� �� ����������?
}
