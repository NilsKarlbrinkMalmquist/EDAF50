#ifndef TEXT_ITERATOR_H
#define TEXT_ITERATOR_H

#include <string>
#include <vector>

using std::vector;
using std::string;

class TextIterator {
private:
    vector<string>* lines;
    size_t current_line;
    string::size_type current_pos;
public:
    TextIterator(vector<string>* l, size_t cl) 
    : lines(l), current_line(cl), current_pos(0){}

    
};

#endif