#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

// ��������� ��������� capacity
enum class ResizeStrategy {
	Additive,
	Multiplicative
};

// ��� �������� � �������
// ����� ����� ������� �� ������
using ValueType = double;

class MyVector
{
public:
	MyVector(size_t size = 0, ResizeStrategy resizestrategy = ResizeStrategy::Multiplicative, float coef = 1.5f);
	MyVector(size_t size, ValueType value, ResizeStrategy resizestrategy = ResizeStrategy::Multiplicative, float coef = 1.5f);

	MyVector(const MyVector& copy);
	MyVector& operator=(const MyVector& copy);

	~MyVector();

	// ��� ��������� � ����������� ����������� � �������� ��� �����������

	size_t capacity() const;
	size_t size() const;
	float loadFactor();

	// ������ � ��������,
	// ������ �������� �� O(1)
	ValueType& operator[](const size_t i) const;

	// �������� � �����,
	// ������ �������� �� amort(O(1))
	void pushBack(const ValueType& value);

	// ��������,
	// ������ �������� �� O(n)
	void insert(const size_t i, const ValueType& value);	// ������ ��� ������ ��������
	void insert(const size_t i, const MyVector& value);		// ������ ��� �������

	// ������� � �����,
	// ������ �������� �� amort(O(1))
	void popBack();
	// �������
	// ������ �������� �� O(n)
	void erase(const size_t i);
	void erase(const size_t i, const size_t len);			// ������� len ��������� ������� � i

	// ����� �������,
	// ������ �������� �� O(n)
	// ���� isBegin == true, ����� ������ ������� ��������, ������� value, ����� ����������
	// ���� �������� �������� ���, ������� -1
	long long int find(const ValueType& value, bool isBegin = true) const;

	// ��������������� ������ (������������� ������ capacity)
	void reserve(const size_t capacity);

	// �������� ������
	// ���� ����� ������ ������ ��������, �� ����� �������� ���������� ���������� ����������
	// ���� ������ - �������� ������
	void resize(const size_t size, const ValueType value = 0.0);

	// ������� �������, ��� ��������� capacity
	void clear();

	//�������� ����������� �������.
    void shrink_fit();

	//������� ������� ����� ������� ��� ��������
    Show_ResizeStrategy() const;
    Show_Vector() const;

private:
	ValueType *_data;
	size_t _size;
	size_t _capacity;
	float _coef;
	ResizeStrategy _ResizeStrategy;
};


#endif // VECTOR_H_INCLUDED
