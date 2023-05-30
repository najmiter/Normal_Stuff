#pragma once

#include <typeinfo>

namespace Containers {
  class Vector {
  public:
    Vector() = default;
    Vector(size_t _size, int64_t _value = 0LL);
    Vector(const Vector& _other);
    
    int64_t* begin();
    int64_t* end();
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    void push_back(int64_t _data);
    int64_t pop();
    int64_t pop_front();
    void remove(size_t _idx);
    int64_t& front();
    int64_t& back();
    void insert(int64_t _data, size_t _idx);
    int64_t& at(size_t _idx);
    void shrink_to_fit();

    int64_t& operator[](size_t _idx);
    const int64_t& operator[](size_t _idx) const;
    void operator=(const Vector& _other);


    ~Vector();

  private:
    void f_realloc();
    void f_shift_to_left(size_t _start = 0UL);
    void f_shift_to_right(size_t _start = 0UL);

  private:
    size_t m_Size{};
    size_t m_Capacity{};
    int64_t* m_Array{};
  };
}