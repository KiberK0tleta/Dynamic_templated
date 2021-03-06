//dynamic_fillrand_templated;
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename T>T** Allocate(const int m, const int n);
template<typename T>void Clear(T** arr, const int m);

template<typename T>void Random(T& variable);

template<typename T>void FillRand(T arr[], const int n, int maxRand = 100, int minRand = 0);
template<typename T>void FillRand(T** arr, const int m, const int n);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int m, const int n);

template<typename T>void push_back(T*& arr, int& n, T value);
template<typename T>void push_front(T*& arr, int& n, T value);
template<typename T>void insert(T*& arr, int& n, T value, int index);

template<typename T>void push_row_back(T**& arr, int& m, const int n);
template<typename T>void push_row_front(T**& arr, int& m, const int n);
template<typename T>void insert_row(T**& arr, int& m, const int n, int index);

template<typename T>void pop_row_back(T**& arr, int& m, const int n);
template<typename T>void pop_row_front(T**& arr, int& m, const int n);

template<typename T>void push_col_back(T** arr, const int m, int& n);
template<typename T>void push_col_front(T** arr, const int m, int& n);
template<typename T>void insert_col(T** arr, const int m, int& n, int index);

template<typename T>void pop_back(T*& arr, int& n);
template<typename T>void pop_front(T*& arr, int& n);




#define DYNAMIC_MEMORY_2

//typedef int DataType;
//typedef double DataType;
typedef char DataType;
//typedef float DataType;



void main()
{
	setlocale(LC_ALL, "Russian");


	int m;	//��������� �����
	int n;	//���������� �������� (��������� ������)
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������� ������: "; cin >> n;
	DataType** arr = Allocate<DataType>(m, n);


	FillRand(arr, m, n);
	Print(arr, m, n);
	cout << "��������� ������ � �����:\n";
	push_row_back(arr, m, n);
	FillRand(arr[m - 1], n, 0, 100);
	Print(arr, m, n);
	cout << "��������� ������ � ������:\n";
	push_row_front(arr, m, n);
	arr[0][3] = 123;
	Print(arr, m, n);

	int index;
	cout << "������� ������ ����������� ������: "; cin >> index;
	insert_row(arr, m, n, index);
	Print(arr, m, n);

	cout << "���������� ������� � ����� �������:\n";
	push_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "���������� ������� � ������ �������:\n";
	push_col_front(arr, m, n);
	Print(arr, m, n);

	cout << "������� ������ ������������ �������: "; cin >> index;
	insert_col(arr, m, n, index);
	Print(arr, m, n);

	cout << "�������� ��������� ������:\n";
	pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "�������� ������� ������:\n";
	pop_row_front(arr, m, n);
	Print(arr, m, n);

	Clear(arr, m);
}

template<typename T>T** Allocate(const int m, const int n)
{
	T** arr = new T * [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n];
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template<typename T>void Random(T& variable)
{
	if (typeid(variable) == typeid(int))
	{
		variable = rand() % 100;
	}
	else if (typeid(variable) == typeid(float) || typeid(variable) == typeid(double))
	{
		variable = double(rand() % 10000) / 100;
	}
	else if (typeid(variable) == typeid(char))
	{
		variable = rand();
	}
	else
	{
		variable = T();	//���������� � ���������� �������� �� ���������
	}
}

template<typename T>void FillRand(T arr[], const int n, int maxRand, int minRand)
{
	for (int i = 0; i < n; i++)
	{
		Random(arr[i]);
	}
}
template<typename T>void FillRand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Random(arr[i][j]);
		}
	}
}

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

template<typename T>void push_back(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
template<typename T>void push_front(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
template<typename T>void insert(T*& arr, int& n, T value, int index)
{
	if (index >= n)return;
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

template<typename T>void push_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[m] = new T[n]{};
	m++;
}
template<typename T>void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m + 1]{};
	for (int i = 0; i < m; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new T[n]{};
	m++;
}
template<typename T>void insert_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T * [m + 1];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < m; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = new T[n]{};
	m++;
}

template<typename T>void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T * [--m]{};
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i];
	delete[] arr[m];
	delete[] arr;
	arr = buffer;
}
template<typename T>void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [--m];
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}

template<typename T>void push_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
template<typename T>void push_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
template<typename T>void insert_col(T** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < index; j++)
			buffer[j] = arr[i][j];
		for (int j = index; j < n; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

template<typename T>void pop_back(T*& arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T>void pop_front(T*& arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
}