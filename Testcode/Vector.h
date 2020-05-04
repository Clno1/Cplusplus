#pragma once
#include<iostream>
#include<cassert>
#include<algorithm>
using namespace std;

const int DEAULT_CAPACITY = 5;

template<typename T>
class Vector {
public:
	//各种构造函数和析构函数 
	Vector(int cap = DEAULT_CAPACITY, int sz = 0, const T v = T()) :
		capacity(cap), size(sz) {
		data = new T[capacity];
		for (int i = 0; i < size; i++) data[i] = v;
	}
	Vector(const T *arr, int n) {
		size = n;
		capacity = n;
		data = new T[capacity];
		for (int i = 0; i < size; i++) data[i] = arr[i];
	}
	Vector(const T *arr, int l, int r);
	Vector(const Vector<T> &v) {
		size = v.size;
		capacity = v.capacity;
		data = new T[capacity];
		for (int i = 0; i < size; i++) data[i] = v.data[i];
	}
	Vector(const Vector<T> &v, int l, int r) {
		size = r - l;
		capacity = size;
		data = new T[capacity];
		for (int i = 0; i < size; i++) data[i] = v.data[i + l];
	}
	~Vector() { delete[] data; }
	Vector<T>& operator = (const Vector<T> &v);

	//获取信息 
	int GetCapacity() const { return capacity; }
	int GetSize() const { return size; }
	bool empty() const { return (size == 0); }
	int find(const T &v) const;

	//改变元素 
	void insert(int p, const T &v);
	void remove(int p);
	void CopyFrom(const T *v, int l, int r);
	void push_back(const T &v);
	void pop_back();
	void clear();
	void sort();

	//重载运算符
	/*T& operator [] (const int p) {
		assert(p >= 0 && p < size);
		return data[p];
	}*/
	template<typename T>
	friend ostream& operator << (ostream &o, const Vector<T> &v);

private:
	void expand();
	static void swap(T &a, T &b) { T tmp = a; a = b; b = tmp; }

protected:
	int capacity;	//容量 
	int size;		//Vector大小 
	T *data;		//实际数据 
};

template<typename T>
ostream& operator << (ostream &o, const Vector<T> &v) {
	for (int i = 0; i < v.GetSize(); i++)
		o << v.data[i] << " ";
	return o;
}

template<typename T>
Vector<T>& Vector<T>::operator= (const Vector<T> &v) {
	if (data == v.data) return *this;
	delete[]data;
	size = v.size;
	capacity = v.capacity;
	data = new T[v.capacity];
	CopyFrom(v.data, 0, size);
}

template<typename T>
void Vector<T>::CopyFrom(const T *v, int l, int r) {
	size = 0;
	for (int i = l; i < r; i++)
		data[size++] = v[i];
}

template<typename T>
void Vector<T>::expand() {
	if (size == capacity) {
		T *OldData = data;
		if (capacity < DEAULT_CAPACITY) capacity = DEAULT_CAPACITY;		//防止capacity为0时候出错
		capacity <<= 1;
		data = new T[capacity];
		CopyFrom(OldData, 0, size);
		delete[] OldData;
	}
}

template<typename T>
void Vector<T>::insert(int p, const T& v) {
	assert(p >= 0 && p <= size);
	expand();
	for (int i = size - 1; i >= p; i--) data[i + 1] = data[i];
	data[p] = v;
	size++;
}

template<typename T>
void Vector<T>::push_back(const T &v) {
	insert(size, v);
}

template<typename T>
void Vector<T>::remove(int p) {
	for (int i = p; i < size-1; i++)
		data[i] = data[i + 1];
	size--;
}

template<typename T>
void Vector<T>::pop_back() {
	assert(size > 0);
	remove(size - 1);
}

template<typename T>
void Vector<T>::clear() {
	while (size) pop_back();
}

template<typename T>
int Vector<T>::find(const T &p) const {
	for (int i = 0; i < size; i++)
		if (p == data[i]) return i;
	return -1;
}

template<typename T>
void Vector<T>::sort() {
	std::sort(data, data + size);
}