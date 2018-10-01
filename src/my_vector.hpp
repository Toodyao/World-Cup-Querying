// simple version of vector

#ifndef _MY_VECTOR_HPP_
#define _MY_VECTOR_HPP_

#include <iostream>
#include <cassert>

// TODO: Constructor, clear()
template<typename T>
class MyVector {
private:
	int arr_size;
	int max_size;
	T *arr_head; // Head of whole array
	T *arr_tail; // Tail of whole array
public:
	MyVector();
	MyVector(int n);
	MyVector(const MyVector& v);
	~MyVector();

	void push_back(T data);
	void erase(T data);
	int find(T data);
	inline int size();
	inline bool empty();
	void clear();
	void print();
	void resize(int n);
	void push_back_resize(int n); // Only for push_back() function

	inline T& operator[](int n);
	// MyVector<T>& operator=(const MyVector<T>& v);
};

template<typename T>
MyVector<T>::MyVector() {
	arr_tail = arr_head = new T[10]; // Default size: 10
	arr_size = 0;
	max_size = 10;
	// TODO: refine it.
}

template<typename T>
MyVector<T>::MyVector(int n) {
	// tail = arr = new T[(int)(n*1.5)];
	arr_head = new T[n];
	arr_tail = arr_head+n;
	arr_size = n;
	max_size = n;
}

template<typename T>
MyVector<T>::MyVector(const MyVector& v) {
	arr_head = new T[v.max_size];
	arr_tail = arr_head + arr_size;
	arr_size = v.arr_size;
	max_size = v.max_size;
}

template<typename T>
MyVector<T>::~MyVector() {
	delete [] arr_head;
	arr_head = arr_tail = nullptr;
	arr_size = 0;
	max_size = 0;
}

template<typename T>
void MyVector<T>::push_back(T data) {
	if (arr_tail - arr_head >= max_size) { // Vector full, resize it to 1.5x
		max_size = (int)max_size * 1.5;
		push_back_resize(max_size);
	}

	*arr_tail = data;
	arr_tail++;
	arr_size++;
}

template<typename T>
void MyVector<T>::erase(T data) {
	if (empty()) {
		std::cout << "vector empty" << std::endl;
		return;
	}

	int index = -1;
	for (int i = 0; i < arr_size; ++i) {
		if (arr_head[i] == data) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		std::cout << "can't find data" << std::endl;
		return;
	}

	for (int i = index; i < arr_size-1; ++i)
		arr_head[i] = arr_head[i+1];

	arr_size--;
	arr_tail--;
}

template<typename T>
inline bool MyVector<T>::empty() {
	return arr_size == 0;
}

template<typename T>
inline int MyVector<T>::size() {
	return arr_size;
}

template<typename T>
void MyVector<T>::clear() {
	// delete [] arr;
	arr_tail = &arr_head[0];
	arr_size = 0;
}

template<typename T>
void MyVector<T>::print() {
	if (empty()) {
		std::cout << "vector empty" << std::endl;
		return;
	}

	T *temp = arr_head;
	while (temp != arr_head + arr_size) {
		std::cout << *temp << " ";
		temp++;
	}
	std::cout << std::endl;
}

template<typename T>
void MyVector<T>::resize(int n) {
	assert(n > 0);
	T* temp_arr = new T[n];
	if (n >= arr_size)
		std::copy(arr_head, arr_head + size(), temp_arr);
	else // If downsize array
		std::copy(arr_head, arr_head + n, temp_arr);
	delete[] arr_head;
	arr_head = temp_arr;
	temp_arr = nullptr;

	// Different with push_back_resize():
	arr_tail = arr_head + n;
	arr_size = n;
}

template<typename T>
void MyVector<T>::push_back_resize(int n) {
	assert(n > 0);
	T* temp_arr = new T[n];
	if (n >= size())
		std::copy(arr_head, arr_head + size(), temp_arr);
	else // Downsize array
		std::copy(arr_head, arr_head + n, temp_arr);
	delete[] arr_head;
	arr_head = temp_arr;
	temp_arr = nullptr;

	// Different with resize():
	arr_tail = arr_head + arr_size;
}

template<typename T>
inline T& MyVector<T>::operator[](int n) {
	return arr_head[n];
}

// template<typename T>
// MyVector<T>& MyVector<T>::operator=(T data) {
// 	if (&v == this)
// 		return *this;
// 	this.arr[] // unfinished, return what?
// }

#endif // _MY_VECTOR_HPP_