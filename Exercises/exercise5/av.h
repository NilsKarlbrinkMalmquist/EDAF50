#ifndef AV_H
#define AV_H
//WTF
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using std::pair;

template<typename Key, typename T>
class AV {
private:
    vector<pair<Key, T>> v;
    static bool first_less(const pair<Key, T>& p, const Key& s){
        return p.first < s;
    }
public:
    using iterator = typename vector<pair<Key, T>>::iterator;

    iterator begin() { return v.begin(); }
    iterator end() { return v.end(); }

    AV() {}
    pair<iterator, bool> insert(const pair<Key, T>& s);
    iterator find(const Key& k);
};

template<typename Key, typename T>
pair<typename AV<Key, T>::iterator, bool>
AV<Key, T>::insert(const pair<Key, T>& val) {
	auto it = lower_bound(v.begin(), v.end(), val.first, first_less);
	if (it != v.end() && it->first == val.first) {
		return make_pair(it, false);
	}
	v.insert(it, val);
	return make_pair(it, true);
}

template<typename Key, typename T>
typename AV<Key, T>::iterator
AV<Key, T>::find(const Key& k){
    auto it = lower_bound(v.begin(), v.end(), k, first_less);
	if (it == v.end() || it->first != k) {
		return v.end();
	}
	return it;
}

#endif
