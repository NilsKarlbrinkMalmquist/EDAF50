#include "Problem1.h"
#include <string>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <algorithm>

string_view::string_view() : sz(0), str{nullptr}{}

string_view::string_view(const std::string& s) : str{s.c_str()}, sz{s.size()} {}

string_view::string_view(const std::string& s, size_type pos, size_type len) : sz{len} {
    if(pos+len > s.size()) throw std::out_of_range("Out of range");
    std::string temp = s.substr(pos, len);
    str = temp.c_str();

    //Facits lösning:
    //str = s.c_str() + pos;
}

string_view::string_view(const char* c, size_type len) : str{c}, sz{len} {}

string_view::string_view(const char* c) : str{c}, sz{strlen(c)} {}

bool string_view::empty() const{
    return sz == 0;
}

inline string_view::size_type string_view::size() const{
    return sz;
}

string_view::const_iterator string_view::begin() const{
    return str;             //Fattar ej??????????????!!???????????????!?
}

string_view::const_iterator string_view::end() const {
    return str+sz;          //??????????????????????????????????????!?
}

char string_view::operator[](size_type idx) const{
    return str[idx];
}

char string_view::at(size_type idx) const{
    return str[idx];
    //Facit: return (*this)[idx];
}

string_view string_view::substr(size_type pos) const{
    //std::string temp = str.substr(pos, strlen(str));

    return substr(pos, sz);

}

string_view string_view::substr(size_type pos, size_type len) const{
    if(pos >= sz) throw std::out_of_range("Out of range");
    if((pos + len) > sz){
        return string_view(str+pos, sz-pos);
    }
    return string_view(&str[pos], len);
}

string_view::size_type string_view::find(char ch, size_type pos=0) const{
    if(pos >= sz) throw std::out_of_range("pos > size");
    auto index = std::find(begin()+pos, end(), ch);
    return index != end() ? std::distance(begin(),index) : npos;

    /*string_view sv = substr(pos);
    auto it = std::find_if(sv.begin(), sv.end(), [&ch] (const char* str){
        return ch == *str;
    });
    return it != sv.end() ? it : npos;*/
}

string_view::size_type string_view::find(string_view s, size_type pos=0) const{
    if(pos >= sz) throw std::out_of_range("pos > size");
    auto index = std::search(begin()+pos, end(), s.begin(), s.end());
    return index != end() ? std::distance(begin(), index): npos;
}

bool operator==(const string_view& sv1, const string_view& sv2){
    if(sv1.size() != sv2.size()) return false;
    return std::equal(sv1.begin(), sv1.end(), sv2.begin(), sv2.end());
}

std::ostream& operator<<(std::ostream& stream, const string_view& sv){
    for(auto x : sv){ 
        stream << x;
    }
    return stream;
}


int main(){
    string_view s1("bajs");
    std::cout << s1[1] << " " << s1.at(1) <<std::endl;;
}

/*Problem 2b)


*/





