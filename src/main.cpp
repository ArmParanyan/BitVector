#include "../header/BitVector.h"

int main()
{
    BitVector vec;
    vec.set(7, 1);
    std::cout << vec.get(7) << std::endl;
}