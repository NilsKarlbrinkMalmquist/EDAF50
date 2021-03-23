template <typename inputIt, typename outputIt, typename T, typename U>
void apply_all(inputIt readIt_begin, inputIt readIt_end, outputIt writeIt_begin, const T& arg1, const U& arg2){
    while(readIt_begin != readIt_end){
        *writeIt_begin = (*readIt_begin)(arg1, arg2);
        writeIt_begin++;
        readIt_begin++;
    }
}