#ifndef WORLD_CUP_QUERYING_HASH_H
#define WORLD_CUP_QUERYING_HASH_H

#include <vector>
#include <string>
#include <functional>
using std::vector;


template <typename K, typename V> // Key and Value
class Hash {
private:
	struct inner_value {
		V value;
		K key;
		bool empty;
		inner_value() {empty = true;}
	};
	std::hash<std::string> str_hash;
	std::hash<int>         int_hash;
	const int MOD = 331;
public:
	vector<vector<inner_value> > v;
	Hash();
	explicit Hash(unsigned long n);
	size_t get_hash(std::string s);
	size_t get_hash(int n);
	void insert(K key, V value);
	V& find(K key);
	V* find_ptr(K key);
	int hash_conflict();
	void clear();
//	size_t count(K key);
};

template<typename K, typename V>
Hash<K,V>::Hash() {
	v.resize(331); // Default Hash Table size
}

template<typename K, typename V>
Hash<K,V>::Hash(unsigned long n) {
	v.resize(n);
}

template<typename K, typename V>
size_t Hash<K,V>::get_hash(std::string s) {
	return str_hash(s) % MOD;
}

template<typename K, typename V>
size_t Hash<K, V>::get_hash(int n) {
	return int_hash(n) % MOD;
}

template<typename K, typename V>
void Hash<K,V>::insert(K key, V value) {
	size_t hash_code = get_hash(key);
	inner_value iv;
	iv.empty = false;
	iv.value = value;
	iv.key = key;
	v[hash_code].push_back(iv);
}

template<typename K, typename V>
V& Hash<K,V>::find(K key) {
	// TODO: return 'NULL'
	size_t hash_code = get_hash(key);
	for (size_t i = 0; i < v[hash_code].size(); i++) {
		auto& list = v[hash_code];
		if (list[i].key == key) {
			return list[i].value;
		}
	}
}

template<typename K, typename V>
V* Hash<K, V>::find_ptr(K key) {
	size_t hash_code = get_hash(key);
	for (int i = 0; i < v[hash_code].size(); i++) {
		auto& list = v[hash_code];
		if (list[i].key == key) {
			return &(list[i].value);
		}
	}
	return nullptr;
}

template<typename K, typename V>
int Hash<K, V>::hash_conflict() {
	int count = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i].size() > 1)
			count++;
	return count;
}

template<typename K, typename V>
void Hash<K, V>::clear() {
	v.clear();
	v.resize((unsigned long) MOD);
}


#endif //WORLD_CUP_QUERYING_HASH_H
