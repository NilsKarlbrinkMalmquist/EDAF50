#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//Lägg till: operator=, operator cout, destruktor, copykonstruktor, är det rätt att initiera sz som ett argument?

class A {
    friend std::ostream& operator<<(std::ostream&, const A&);
public:
    A(size_t sz = 10) : storage(new int[size = sz]) {}
    ~A() {delete[] storage;}
    A(const A& a) {
        size = a.size;
        storage = new int[size];
        for(std::size_t i = 0 ; i != size ; ++i) {
            storage[i] = a.storage[i];
        }
    }
    int operator[](size_t pos) const { return storage[pos]; }
    int& operator[](size_t pos) { return storage[pos]; }
    A& operator=(const A& other) {
        if(this == &other) return *this;
        delete [] storage;
        size = other.size;
        storage = new int(size);
        for(size_t i = 0; i != size; i++){
            storage[i] = other.storage[i];
        }
        return *this;
    }
private:
    int* storage; 
    size_t size;
};

std::ostream& operator<<(std::ostream& stream, const A& other){
    for(size_t i = 0; i != other.size; i++){
        stream << other.storage[i] <<", ";
    }
    return stream;
}

void print(const string& msg, A& a) {
    cout << msg << " " << a << endl;
}
int main() {
    A a1;
    for (size_t i = 0; i != 10; ++i) { 
        a1[i] = i + 1;
    }
    print("This is a1: ", a1);
    A a2;
    a2 = a1;
    print("This is a2: ", a2);
}
