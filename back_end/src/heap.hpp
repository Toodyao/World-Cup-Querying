#ifndef DS_TREE_HEAP_HPP
#define DS_TREE_HEAP_HPP

#include <iostream>
#include <vector>
#include "compare.hpp"

using std::vector;

template <typename T>
class Heap {
private:
	Compare<T> *cmp;
	int heap_size;
	void percolate_down(int i);
public:

	vector<T> v;
	explicit Heap(Compare<T> *cmp_t = new MyLess<T>);
	explicit Heap(int n, Compare<T> *cmp_t = new MyLess<T>);
	explicit Heap(vector<T> a, Compare<T> *cmp_t = new MyLess<T>);
	~Heap();

	bool empty();
	int size();
	T top();
	void push(T x);
	void pop();
	int find(T x);
	void update_node(int index);


};

template<typename T>
Heap<T>::Heap(Compare<T> *cmp_t) {
	heap_size = 0;
	v.resize(5); // Default size set to 5
	cmp = cmp_t;
}

template<typename T>
Heap<T>::Heap(int n, Compare<T> *cmp_t) {
	heap_size = 0;
	v.resize((unsigned int)n);
	cmp = cmp_t;
}

template<typename T>
Heap<T>::Heap(vector<T> a, Compare<T> *cmp_t) {
	// create Heap using existing array
	int n = (int)a.size();
	v.resize((unsigned int)n);
	heap_size = n;
	cmp = cmp_t;

	// copy array
	for (int i = 0; i < n; i++) {
		v[i] = a[i];
	}

	for (int i = (n/2)-1; i >= 0; i--) {
		percolate_down(i);
	}

}

template<typename T>
Heap<T>::~Heap() {
	delete cmp;
}

template<typename T>
bool Heap<T>::empty() {
	return (bool)heap_size;
}

template<typename T>
int Heap<T>::size() {
	return heap_size;
}

template<typename T>
T Heap<T>::top() {
	return v[0];
}

template<typename T>
void Heap<T>::push(T x) {
	if (heap_size >= v.size()) {
		v.resize((unsigned int)(1.5*heap_size));
//		std::cout << "Heap full" << std::endl;
	}
	int i = heap_size; // add to the last
	while (i > 0 && (*cmp)(x, v[(i-1)/2])) { // swap up
		v[i] = v[(i-1)/2];
		i = (i-1)/2;
	}
	v[i] = x;
	heap_size++;
}

template<typename T>
void Heap<T>::pop() {
	// a little difference with percolate_down()
	int n = heap_size;
	T x = v[n-1]; // store the last element
	v[0]  = v[n-1]; // promote the last element to the top
	int parent, child;
	for (parent = 0; parent * 2 + 1 <= n - 1; parent = child) {
		child = parent*2+1;      // default left child
		if (child + 1 <= n - 1             // if has right child
			&& (*cmp)(v[child+1], v[child])) // select the largest child
			child++;

		// ... && v[child] < v[child+1]) -> max_heap
		// if (x >= v[child]) -> max_heap
		if ((*cmp)(x, v[child]) || v[child] == x) // found the proper place
			break;
		else
			v[parent] = v[child];  // swap down
	}
	v[parent] = x;
	v.pop_back();
	heap_size--;
}

template<typename T>
void Heap<T>::percolate_down(int i) {
	int n = heap_size;
	int x = v[i]; // store current element
//	v[i] = v[n-1];
	int parent, child;
	for (parent = i; parent * 2 + 1 <= n - 1; parent = child) {
		child = parent*2+1;
		if (child + 1 <= n - 1
			&& (*cmp)(v[child+1], v[child]))  // using Compare
			child++;
		if ((*cmp)(x, v[child]) || v[child] == x) // using Compare
			break;
		else
			v[parent] = v[child];
	}
	v[parent] = x;
}

template<typename T>
int Heap<T>::find(T x) { // TODO: Rewrite use bst or binary search
	for (int i = 0; i < v.size(); ++i)
		if (v[i] == x)
			return i;
	return -1;
}

template<typename T>
void Heap<T>::update_node(int index) {
	int i = index;
	T x = v[i];
	while (i > 0 && (*cmp)(x, v[(i-1)/2])) { // swap up
		v[i] = v[(i-1)/2];
		i = (i-1)/2;
	}
	v[i] = x;
}

#endif //DS_TREE_HEAP_HPP
