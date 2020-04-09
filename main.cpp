#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    MyVector A;
    for (int i = 0; i < 5; ++i)
        A.pushBack(i);

    cout << "Вектор А" << endl
         << "Элементы вектора - ";

         A.Show_Vector();

    cout << "Размер - " << A.size() <<endl
         << "Вместимость - " << A.capacity() << endl
         << "Фактор нагрузки - " << A.loadFactor() << endl
         << "Оператор [] - " << A[3] << endl << endl;; //Та ли индексация?

    MyVector B;
    for (int i = 0; i < 6; ++i)
        B.pushBack(i*2);

    cout << "Вектор B" << endl
         << "Элементы вектора - ";

         B.Show_Vector();

    cout << "Размер - " << B.size() <<endl
         << "Вместимость - " << B.capacity() << endl
         << "Фактор нагрузки - " << B.loadFactor() << endl
         << "Оператор [] - " << B[5] << endl << endl;; //Та ли индексация?

    cout << "Вставка 1 элемента на заданную позицию в вектор B" << endl << endl;
        B.insert(3, 150);

        cout << "Вектор B" << endl
         << "Элементы вектора - ";

         B.Show_Vector();

    cout << "Размер - " << B.size() <<endl
         << "Вместимость - " << B.capacity() << endl
         << "Фактор нагрузки - " << B.loadFactor() << endl
         << "Оператор [] - " << B[3] << endl << endl;; //Та ли индексация?

    cout << "Вставка вектора А в вектор B" << endl << endl;
        B.insert(4, A);

        cout << "Вектор B" << endl
         << "Элементы вектора - ";

         B.Show_Vector();

    cout << "Размер - " << B.size() <<endl
         << "Вместимость - " << B.capacity() << endl
         << "Фактор нагрузки - " << B.loadFactor() << endl
         << "Оператор [] - " << B[3] << endl << endl;; //Та ли индексация?

    cout << "Удалим 1 элемент из вектора на заданнной позиции" << endl << endl;

        B.erase(3);

        cout << "Вектор B" << endl
         << "Элементы вектора - ";

         B.Show_Vector();

    cout << "Размер - " << B.size() <<endl
         << "Вместимость - " << B.capacity() << endl
         << "Фактор нагрузки - " << B.loadFactor() << endl
         << "Оператор [] - " << B[3] << endl << endl;; //Та ли индексация?

    cout << "Удалим  len элементов начиная с i в векторе В" << endl << endl;

        B.erase(3, 5);

        cout << "Вектор B" << endl
         << "Элементы вектора - ";

         B.Show_Vector();

    cout << "Размер - " << B.size() <<endl
         << "Вместимость - " << B.capacity() << endl
         << "Фактор нагрузки - " << B.loadFactor() << endl
         << "Оператор [] - " << B[5] << endl << endl;; //Та ли индексация?

    cout << "Удалим  последний элемент в векторе B" << endl << endl;

        B.popBack();

        cout << "Вектор B" << endl
         << "Элементы вектора - ";

         B.Show_Vector();

    cout << "Размер - " << B.size() <<endl
         << "Вместимость - " << B.capacity() << endl
         << "Фактор нагрузки - " << B.loadFactor() << endl
         << "Оператор [] - " << B[4] << endl << endl; //Та ли индексация?

    cout << "Сделаем resize вектора B в большую сторону" << endl << endl;

        B.resize(20);

        cout << "Вектор B" << endl
         << "Элементы вектора - ";

         B.Show_Vector();

    cout << "Размер - " << B.size() <<endl
         << "Вместимость - " << B.capacity() << endl
         << "Фактор нагрузки - " << B.loadFactor() << endl
         << "Оператор [] - " << B[4] << endl << endl; //Та ли индексация?

    cout << "Сделаем resize вектора B в меньшую сторону" << endl << endl;

        B.resize(3);

        cout << "Вектор B" << endl
         << "Элементы вектора - ";

         B.Show_Vector();

    cout << "Размер - " << B.size() <<endl
         << "Вместимость - " << B.capacity() << endl
         << "Фактор нагрузки - " << B.loadFactor() << endl
         << "Оператор [] - " << B[2] << endl << endl; //Та ли индексация?

    cout << "Сделаем clear вектор B" << endl << endl;

        B.clear();

        cout << "Вектор B" << endl
         << "Элементы вектора - ";

         B.Show_Vector();

    cout << endl << "Размер - " << B.size() << endl
         << "Вместимость - " << B.capacity() << endl
         << "Фактор нагрузки - " << B.loadFactor() << endl
         << "Оператор [] - " << B[2] << endl << endl; //Та ли индексация?
}
