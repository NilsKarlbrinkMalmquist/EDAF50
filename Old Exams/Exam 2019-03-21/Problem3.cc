#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <cassert>

using MapStringInt = std::map<std::string, unsigned int>;

void test(MapStringInt& m, const std::string& text){
    //auto mit = std::find(m.begin(), m.end(), text);
    auto mit = m.find(text);
    if (mit == m.end()) m.insert(std::make_pair(text, 1));
}

int main(){
    MapStringInt ml;
    test(ml, "foo");
    test(ml, "bar");
    assert(ml["foo"]== 1);
    assert(ml["bar"]== 1);
    std::cout << "success!\n";
}