#include <iostream>
#include <stdexcept>
#include "vector.hpp"

using Containers::Vector;

void Vector::f_realloc() {
  // std::cout << "reallocated" << std::endl;
  this->m_Capacity *= 2;
  int64_t* pkr_mery_ko = new int64_t[this->m_Capacity];
  for (size_t i = 0; i < this->size(); i++)
    pkr_mery_ko[i] = this->m_Array[i];

  delete[] this->m_Array;
  this->m_Array = pkr_mery_ko;
}

void Vector::f_shift_to_left(size_t _start) {
  for (size_t i = _start; i < this->size() - 1; i++)
    this->m_Array[i] = this->m_Array[i+1];

  this->m_Array[this->size() - 1] = 0LL;
  this->m_Size--;
}

void Vector::f_shift_to_right(size_t _start) {
  for (int64_t i = this->size(); i > _start; i--) {
    this->m_Array[i] = this->m_Array[i - 1];
  }
}

Vector::Vector(size_t _size, int64_t _value) 
  : m_Size(_size), 
    m_Capacity(_size), 
    m_Array(new int64_t[_size]) {
  for (size_t i = 0; i < _size; i++)
    this->m_Array[i] = _value;
}

Vector::Vector(const Vector& _other)
  : m_Size(_other.size()),
    m_Capacity(_other.capacity()),
    m_Array(new int64_t[this->capacity()]) {
  for (size_t i = 0; i < this->size(); i++)
    this->m_Array[i] = _other[i];
}

Vector::~Vector() {
  delete[] this->m_Array;
}

int64_t* Vector::begin() {
  return this->m_Array;
}

int64_t* Vector::end() {
  return (this->m_Array + this->size());
}

size_t Vector::size() const {
  return this->m_Size;
}

size_t Vector::capacity() const {
  return this->m_Capacity;
}

bool Vector::empty() const {
  return not this->size(); // 0
}

void Vector::push_back(int64_t _data) {
  if (not this->capacity()) { // not 0 = true;
    this->m_Capacity = 1UL;
    this->m_Array = new int64_t[this->m_Capacity];
  } else if (this->size() == this->capacity()) {
    this->f_realloc();
  }

  this->m_Array[this->size()] = _data;
  this->m_Size++;
}

int64_t Vector::pop() {
  if (this->empty()) {
    throw std::out_of_range("Empty vector\n");

  } else {
    auto popped{ this->m_Array[this->size() - 1] };
    this->m_Array[this->size() - 1] = 0LL;
    this->m_Size--;
    return popped;
  }
}

int64_t Vector::pop_front() {
  int64_t popped{};
  if (this->empty()) {
    throw std::out_of_range("Empty vector\n");

  } else {
    popped = this->m_Array[0];
    this->f_shift_to_left();
  }

  return popped;
}

void Vector::remove(size_t _idx) {
  if (_idx >= this->size()) {
    throw std::out_of_range("Out of bounds of the vector\n");

  } else {
    this->f_shift_to_left(_idx);
  }
}

int64_t& Vector::front() {
  if (this->empty()) {
    throw std::out_of_range("Empty vector\n");

  } else {
    return this->m_Array[0UL];
  }
}

int64_t& Vector::back() {
  if (this->empty()) {
    throw std::out_of_range("Empty vector\n");

  } else {
    return this->m_Array[this->size() - 1];
  }
}

void Vector::insert(int64_t _data, size_t _idx) {
  if (_idx > this->size()) 
    throw std::out_of_range("Out of bounds of the vector\n");

  if (this->size()+1 > this->capacity()) 
    this->f_realloc();

  this->f_shift_to_right(_idx);
  this->m_Array[_idx] = _data;
  this->m_Size++;
  
}

int64_t& Vector::operator[](size_t _idx) {
  return this->m_Array[_idx];
}

const int64_t& Vector::operator[](size_t _idx) const {
  return this->m_Array[_idx];
}

int64_t& Vector::at(size_t _idx) {
  if (_idx >= this->size())
    throw std::out_of_range("Out of bounds of the vector\n");
  
  return this->m_Array[_idx];
}

void Vector::operator=(const Vector& _other) {
  if (this != &_other) {
    this->m_Size = _other.size();
    this->m_Capacity = _other.capacity();
    delete[] this->m_Array;

    this->m_Array = new int64_t[this->capacity()];
    for (size_t i = 0; i < this->size(); i++)
      (*this)[i] = _other[i];
  }
}

void Vector::shrink_to_fit() {
  if (this->size() < this->capacity()) {
    int64_t* holder{ new int64_t[this->size()] };
    for (size_t i = 0; i < this->size(); i++)
      holder[i] = (*this)[i];

    delete[] this->m_Array;
    this->m_Array = holder;
    this->m_Capacity = this->size();
  }
}