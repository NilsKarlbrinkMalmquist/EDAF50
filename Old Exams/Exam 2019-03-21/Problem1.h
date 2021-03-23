#ifndef PROBLEM1_H
#define PROBLEM1_H

#include <string>

class string_view{
public:
    using size_type = std::string::size_type;
    using const_iterator = const char*;
    using iterator = const_iterator;

    constexpr static size_type npos = std::string::npos;

    string_view();
    ~string_view() =default;
    string_view(const string_view&) =default;
    string_view(const std::string&);
    string_view(const std::string&, size_type pos, size_type len);
    string_view(const char*, size_type len);
    string_view(const char*);
    bool empty() const;
    size_type size() const;
    const_iterator begin() const;
    const_iterator end() const;
    char operator[](size_type idx) const;
    char at(size_type idx) const;
    string_view substr(size_type pos) const;
    string_view substr(size_type pos, size_type len) const;
    size_type find(char ch, size_type pos=0) const;
    size_type find(string_view s, size_type pos=0) const;
private:
    const char* str;
    size_type sz;
};

#endif
