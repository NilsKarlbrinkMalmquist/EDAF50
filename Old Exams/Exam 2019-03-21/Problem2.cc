#include<iostream>
#include<iomanip>
#include<initializer_list>
#include <algorithm>


template <typename T>
class Vektor{
public:
    Vektor(size_t sz) :size{sz},p{new T[size]{0}} {}
    Vektor(std::initializer_list<T> l) :Vektor(l.size()) {assign(l);}
    ~Vektor() {delete[] p;}
    T& operator[](size_t i) {return p[i];}
    size_t length() const {return size;}
    T* begin() {return p;}
    T* end() {return p+size;}
    const T* cbegin() const {return p;}
    const T* cend() const {return p+size;}
private:
    size_t size;
    T* p;
    void assign(const std::initializer_list<T>& l);
};

template <typename T>
void Vektor<T>::assign(const std::initializer_list<T>& l){
    size_t idx{0};
    for(const auto& e : l) {
        p[idx++] = e;
    }

    //std::copy(l.begin(), l.end(), p);
}

template <typename T>
void add(const Vektor<T>& c1, const Vektor<T>& c2, Vektor<T>& c3){
    //Problem 2 f)
    auto c1_smaller = c1.length() < c2.length();
    auto shortest = c1_smaller? c1 : c2;
    auto longest = c1_smaller? c2 : c1;
    auto it = std::transform(shortest.begin(), shortest.end(), longest.begin(), c3.begin(), std::plus<T>{});
    std::copy(longest.begin()+shortest.length(), longest.end(), it);
    // or, using std::distance and std::next
    // auto dist = std::distance(shortest.begin(), shortest.end());
    // std::copy(std::next(longest.begin(), dist), longest.end(), it);


    /*auto it1 = c1.cbegin();
    auto it2 = c2.cbegin();
    auto it3 = c3.begin();

    while( (it1 != c1.cend() || it2 != c2.cend()) && it3 != c3.end()){
        T tmp1{};
        if(it1 != c1.cend()){
            tmp1 += *it1;
            ++it1;
        }

        T tmp2{};
        if(it2 != c2.cend()){
            tmp2 += *it2;
            ++it2;
        }
        
        *it3 = tmp1 + tmp2;
        ++it3;
    }*/    
}

int main()
{
    Vektor<int> v1{1,2,3,4,5,6};
    Vektor<int> v2{10,20,30,40};
    Vektor<int> v3(v1.length());

    add(v1,v2,v3);
    for(auto e: v3){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}