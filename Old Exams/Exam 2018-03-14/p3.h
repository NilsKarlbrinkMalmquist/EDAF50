#include <memory>
template <typename T>
class Vector{
public:
    Vector() =default;
    Vector(int size) :sz(size),elem(new T[size]) {}
    //Vector(const Vector& other) {}
    Vector(std::initializer_list<T> l) :Vector(l.size()) {
    std::copy(begin(l), end(l), elem.get());}

    int size() const {return sz;}
    T& operator[](const int& i) const {return elem[i];}
    bool operator==(const Vector& v) const;
private:
    int sz{0};
    std::unique_ptr<T[]> elem{nullptr};
};

template<typename T>
bool Vector<T>::operator==(const Vector& v) const{
    if(sz != v.sz) return false;
    return std::equal(elem.get(), elem.get()+sz, v.elem.get());
}
