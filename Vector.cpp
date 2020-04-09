#include <iostream>
#include <cstring>
#include "Vector.h"

using namespace std;

MyVector::~MyVector()
{
    delete[] _data;
}

MyVector::MyVector(const MyVector& copy)
{
    _size = copy._size;
    _capacity = copy._capacity;
    _coef = copy._coef;
    _ResizeStrategy = copy._ResizeStrategy;
    _data = new ValueType[_capacity];

    for (int i = 0; i < copy._size; ++i)
        _data[i] = copy._data[i];
}

MyVector::MyVector(size_t size,ResizeStrategy resizestrategy, float coef)
{
    _size = size;
    _coef = coef;
    _ResizeStrategy = resizestrategy;

    if (_ResizeStrategy == ResizeStrategy::Multiplicative)
    {
        if (_size == 0)
        {
        _capacity = 2;
        }
        else
        {
            _capacity = _size * _coef;
        }
        _data = new ValueType[_capacity];
    }
    else
    {
         _capacity = _size + 5;
    }

    _data = new ValueType[_capacity];

}

size_t MyVector::capacity() const
{
    return _capacity;
}

size_t MyVector::size() const
{
    return _size;
}

//ПОКА НЕ ПОНЯЛ ДЛЯ ЧЕГО ТУТ value(пространство имен..............)
MyVector::MyVector(size_t size, ValueType value, ResizeStrategy resizestrategy, float coef)
{
    _size = size;
    _coef = coef;
    _ResizeStrategy = resizestrategy;

    if (_ResizeStrategy == ResizeStrategy::Multiplicative)
    {
        if (_size == 0)
        {
        _capacity = 2;
        }
        else
        {
            _capacity = _size * _coef;
        }
        _data = new ValueType[_capacity];
    }
    else
    {
         _capacity = _size + 2;
    }

    _data = new ValueType[_capacity];
}

void MyVector::pushBack(const ValueType& value)
{
  reserve(_size+1);
  _data[_size] = value;
  _size++;

}

MyVector::Show_Vector() const
{
    for(int i = 0; i < _size; ++i)
    {
        if(i == _size - 1)
        {
            cout << _data[i] << endl;
        }
        else
        {
            cout << _data[i] <<" ";
        }
    }
}

void MyVector::reserve(const size_t capacity)
{
    if (capacity <= _capacity)
        return;

    if (_ResizeStrategy == ResizeStrategy::Additive)
    {
        _capacity = (_capacity == 0) ? 1 : _capacity;
            while (_capacity < capacity )
                _capacity <<= 1;

            if (_data == nullptr)
                _data = new ValueType[_capacity];
            else
            {
              ValueType *temp = this->_data;
            _data = new ValueType[_capacity];
            memcpy(this->_data, temp, _size * sizeof(ValueType));
            delete[] temp;
            }
    }
    else
    {
        _capacity = _capacity * _coef;

        if (_data == nullptr)
        _data = new ValueType[_capacity];
        else
        {
            ValueType *temp = this->_data;
            _data = new ValueType[_capacity];
            memcpy(this->_data, temp, _size * sizeof(ValueType));
            delete[] temp;
        }
    }
}

//Как обработать ошибку, если i выходит за границу вектора.
ValueType& MyVector::operator[](const size_t i) const
{
    if((i > _size) ||( i < 0))
    {
        cout << "" << endl;
        return _data[0]; //пока оставил так, как ничего не выводить, не знаю
    }

    else
    {
        return _data[i];
    }

}

float  MyVector::loadFactor()
{
    float load_factor = static_cast<float>(_size) / _capacity;
    return load_factor;
}

void  MyVector::insert(const size_t i, const ValueType& value)
{
    if (i >= _size)
        this->pushBack(value);

    reserve(_size+1);

    for(int j = _size; j >= i; --j)
        _data[j] = _data[j-1];

    _data[i] = value;
    _size++;
}

void  MyVector::insert(const size_t i, const MyVector& value)
{

    for(int j = 0; j < value._size; ++j)
    insert(i+j, value._data[j]);

}

void MyVector::popBack()
{
    _size--;
    shrink_fit();
}

void MyVector::erase(const size_t i)
{
    for (int j = i; j < _size; ++j)
        _data[j] = _data[j+1];

    _size--;
    shrink_fit();
}

void MyVector::erase(const size_t i, const size_t len)
{
    for (int j = 0; j < len; j++)
        erase(i);
}

long long int MyVector::find(const ValueType& value, bool isBegin ) const
{
    if (isBegin == true)
    {
        for (int i = 0; i < _size; ++i)
            if (_data[i] == value)
                return i;

    return -1;
    }

    if (isBegin == false)
    {
        for (int i = _size-1; i >= 0; --i)
            if (_data[i] == value)
                return (_size-(_size-i));

    return -1;
    }
}

void MyVector::resize(const size_t size, const ValueType value)
{
    if (size > _size)
    {
        for (int i = _size; i < size; ++i)
            pushBack(value);
    }
    else
    {
        _size = size;

        if(_ResizeStrategy == ResizeStrategy::Multiplicative)
            _capacity = _size * _coef;
        else
        {
            _capacity = _size + 2;
        }

    }
}

void MyVector::clear()
{
   for (int i = 0; i < _size; ++i)
        _data[i] = 0;

   _size = 0;
}

void MyVector::shrink_fit()
{
    float load_factor = this->loadFactor();

    if ( load_factor < 0.5f)
    {
        _capacity = _size;

        ValueType *temp = this->_data;
        _data = new ValueType[_capacity];
        memcpy(this->_data, temp, _size * sizeof(ValueType));
        delete[] temp;
    }
}









MyVector::Show_ResizeStrategy() const
{
    if(_ResizeStrategy == ResizeStrategy::Additive){
        cout << "Additive - " << static_cast <int> (_ResizeStrategy);
    } else {
        cout << "Multiplicative - " << static_cast <int> (_ResizeStrategy);
    }
}
