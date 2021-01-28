#include "foo.h"
#include "bar.h"

int main()
{
    Bar b{"testing"};
    Foo f(b,17);

    f.print();
    return 0;
}
