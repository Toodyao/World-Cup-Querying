#ifndef WORLD_CUP_QUERYING_RANKS_HPP
#define WORLD_CUP_QUERYING_RANKS_HPP

#include <vector>
#include <algorithm>
#include "compare.hpp"

using std::vector;

template <typename T>
class Rank {
public:
	Rank() = default;

	explicit Rank(int size) {
		v.resize((unsigned long)(size));
	}

	vector<T> v;
	int size();
	void add(T x);
	void update();
	void clear();
	T& operator [] (int index);
};

template<typename T>
int Rank<T>::size() {
	return (int)v.size();
}

template<typename T>
void Rank<T>::add(T x) {
	v.push_back(x);
}

template<typename T>
void Rank<T>::update() {
	std::sort(v.begin(), v.end(), std::greater<T>());
}

template<typename T>
void Rank<T>::clear() {
	v.clear();
}

template<typename T>
T& Rank<T>::operator[](int index) {
	return v[index];
}

#endif //WORLD_CUP_QUERYING_RANKS_HPP
