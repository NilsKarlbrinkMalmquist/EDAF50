#include <map>
#include <algorithm>

using std::map;

template<typename K, typename V>
map<V, K> invert_map(const map<K, V>& m){
    map<V, K> inverted_map;
    for(auto map : m){
        inverted_map.emplace(map.second, map.first);
    }
    return inverted_map;
}









/*#ifndef PROBLEM1_MAP_H
#define PROBLEM1_MAP_H

#include <map>

using std::map;

template<typename K, typename T>
class invert_map{
private:
    map<K, T> inverted_map;
public:
    invert_map(map<K, T> map) {

    }
};

#endif */