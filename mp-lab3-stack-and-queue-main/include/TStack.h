#pragma once
using namespace std;
template<class T>
class TStack
{
protected:
	T* data;
	int size;
	int count;
public:
	TStack(int _size = 10);          //конструктор инициализации и по умолчанию
	~TStack() { delete[] data; size = 0; count = 0; };       //деструктор
	TStack(const TStack<T>& p);      //конструктор копирования 
	bool IsEmpty();                  //проверка на пустоту
	bool IsFull();                  //проверка на полноту
	T Pull();                         //извлечь элемент
	void Push(const T& a);           //записать элемент в стек
	int GetCount();
};


template <class T>
TStack<T>::TStack(int _size)
{
	if (_size <= 0) throw ("error");
	size = _size;
	data = new T[size];
	count = 0;
}
template <class T>
TStack<T>::TStack(const TStack& p)
{
	size = p.size;
	count = p.count;
	data = new T[size];
	for (int i = 0; i < count; i++)
	{
		data[i] = p.data[i];
	}
}
template<class T>
inline bool TStack<T>::IsEmpty()
{
	if (count == 0)
		return true;
}
template<class T>
inline bool TStack<T>::IsFull()
{
	if (count == size)
		return true;
}
template <class T>
T TStack<T> ::Pull()
{
	if (count > 0)
	{
		count--;
		return data[count];
	}
	else throw("error");
}
template <class T>
void TStack<T> ::Push(const T& a)
{
	if (count < size)
	{
		data[count] = a;
		count++;
	}
	else throw("error");
}
template<class T>
inline int TStack<T>::GetCount()
{
	int res = count;
	return res;
}
