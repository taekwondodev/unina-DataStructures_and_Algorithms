
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {            //una istanza diversa per ogni dato di cui conosco l'encoding, 1 int, 2 float, 3 string

public:

  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)  //hash di encoding
  unsigned long operator()(const Data& dat) const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer, virtual public DictionaryContainer<Data> {

private:

  // ...

protected:

  using Container::size;  //dictionary::size;

  //default value, i neutri delle rispettive operazioni
  unsigned long a = 1;
  unsigned long b = 0;

  std::default_random_engine gen = std::default_random_engine(std::random_device{}());
  std::uniform_int_distribution<unsigned long> randA = std::uniform_int_distribution<unsigned long>(1, prime - 1);
  std::uniform_int_distribution<unsigned long> randB = std::uniform_int_distribution<unsigned long>(0, prime - 1);

  //static const perchè anche se ho diverse istanze è sempre lo stesso, condivideranno sempre lo stesso encoding
  static const Hashable<Data> encodingHash;
  
  unsigned long tableSize = 128; //2^7
  static const unsigned long prime = 1000000016531;  //il primo più grande rappresentabile con 64 bit

  //costruttori in protected poichè non è richiesto
  //genera random a e b per ogni istanza di HashTable
  HashTable();
  HashTable(const HashTable&);
  HashTable(HashTable&&) noexcept;
  HashTable& operator=(const HashTable&);
  HashTable& operator=(HashTable&&) noexcept;

public:

  // Destructor
  // ~HashTable() specifiers
  virtual ~HashTable() = default;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  bool operator==(const HashTable&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable&) const noexcept = delete;
protected:

  // Auxiliary member functions
  //virtual perchè in opnadr ha una implementazione diversa

  // type HashKey(argument) specifiers;
  unsigned long HashKey(const Data&) const noexcept;

  unsigned long HashKey(unsigned long) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
