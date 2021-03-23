#ifndef BIDIR_MAP
#define BIDIR_MAP

#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <iterator>


template<typename K, typename V>
class bidir_map : public std::map<K, V> {
public:
    using std::map<K, V>::map;
    using std::map<K, V>::at;

    const K& at(const V& v) const{
        using map_tt = std::map<K,V>;
        using vals = typename map_tt::value_type;
        auto it = std::find_if(this->begin(), this->end(), [&v](const vals& m){
            return m.second == v;
        });
        if(it != this->end()){
            return it->first;
        }
        throw std::out_of_range("Value not found");
    }

    using std::map<K, V>::find;

    std::pair<K, V> find(const V& v) const{
        return {key_iter(*this, v), key_iter(*this)};
    }
private:



};

#endif