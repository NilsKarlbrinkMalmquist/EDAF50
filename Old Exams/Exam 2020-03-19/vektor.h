template <typename Con, typename Gen>
void generate2(Con& c, Gen gen){
    for(auto& x : c) {
        x = gen();
    }
}


template <typename T>
struct Vektor{
    explicit Vektor(int s) :sz{s}, e{new T[sz]} {}
    ~Vektor() {delete[] e;}
    T* begin() {return sz > 0 ? e : nullptr;}
    T* end() {return begin()+sz;}
    const T* begin() const {return sz > 0 ? e : nullptr;}
    const T* end() const {return begin()+sz;}
    int sz;
    T* e;
};


template <typename T>
struct Counter{
    Counter(T start, T stride) :s{start-stride},d{stride} {}
    T operator()() {return s+=d;}
private:
    T s{};
    T d{};
};
