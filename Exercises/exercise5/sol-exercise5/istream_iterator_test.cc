#include <iostream>
#include <sstream>
#include <iterator>
#include <iomanip>




void example()
{
    using std::cout;
    using std::endl;
    using std::istream_iterator;

    std::stringstream ss{"1 17 kalle 2 nisse 3 pelle\n"};
    istream_iterator<int> iit(ss);
    istream_iterator<int> iit_end{};
    while(!ss.eof()) {
        while(iit != iit_end) { cout << *iit++ << '\n'; }
        if(ss.fail()){
            ss.clear();
            std::string s;
            ss >> s;
            cout << "[ss: not an int: " << s << "]\n";
            iit = istream_iterator<int>(ss); // create new iterator
        }
    }
    cout << std::boolalpha << "ss.eof(): " << ss.eof() << endl;
}

int main()
{
    example();
}
