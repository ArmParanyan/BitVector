#pragma once 

#include <iostream>
#include <vector>

class BitVector
{
public:
    BitVector();
    BitVector(const BitVector& rhs);
    BitVector(BitVector&&);
    ~BitVector();

public:
    int& operator[](const int ind);

public:
    friend std::ostream& operator<<(std::ostream& os, const BitVector& vec);

public:
    const static size_t bitCount = 64;
    void set(size_t ind, bool val);
    bool get(int ind);
    int size() const;

private:
    void resize(int);

private:
    int* m_arr;
    size_t m_size;
};
