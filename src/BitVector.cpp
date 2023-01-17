#include "../header/BitVector.h"

BitVector::BitVector()
{
    m_arr = nullptr;
    m_size = 0;
}

BitVector::BitVector(const BitVector& rhs)
{
    if (this->m_arr == rhs.m_arr)
    {
        return;
    }
    this->m_size = rhs.m_size;
    this->m_arr = new int[this->m_size];
    for (size_t i = 0; i < rhs.m_size; ++i)
    {
        this->m_arr[i] = rhs.m_arr[i];
    }
}

BitVector::BitVector(BitVector&& rhs)
{
    if (this->m_arr == rhs.m_arr)
    {
        return;
    }
    this->m_size = rhs.m_size;
    this->m_arr = rhs.m_arr;
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
}

std::ostream& operator<<(std::ostream& os, const BitVector& vec)
    {
        for (int i = 0; i <vec.size(); ++i)
        {
            os << vec.m_arr[i] << " ";
        }
        return os;
    }

BitVector::~BitVector()
{
    delete m_arr;
    m_arr = nullptr;
    m_size = 0;
}

int& BitVector::operator[](const int ind)
{
    if (ind >= m_size)
    {
        throw std::invalid_argument("Out of range");
    }
    return m_arr[ind];
}

void BitVector::resize(int size)
{
    int* new_arr = new int[size];
    for (int i = 0; i < m_size; ++i)
    {
        new_arr[i] = m_arr[i];
    }

    delete m_arr;
    m_arr = nullptr;
    m_size = 0;

    m_arr = new int[size];
    m_arr = new_arr;
    m_size = size;
    new_arr = nullptr;
}

int BitVector::size() const
{
    return m_size;
}

void BitVector::set(size_t ind, bool val)
{
    int zero = 0;
    int byte = ind / bitCount;
    int bit = ind % bitCount;

    if (ind > this->m_size) 
    { 
        resize(ind + 1); 
    }
    for (int i = m_size; i <= byte; ++i)
    {
        m_arr[i] = zero;
    }

    if (val) {
        m_arr[byte] |= (1 << bit);
        return;
    }

    int tmp = (1 << bit);
    tmp = ~tmp;
    m_arr[byte] &= tmp;
}

bool BitVector::get(int ind)
{
    int byte = ind / bitCount;
    int bit = ind % bitCount;

    return m_arr[byte] & (1 << bit);
}