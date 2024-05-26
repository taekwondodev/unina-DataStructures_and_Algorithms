
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr: virtual public HashTable<Data> {
  // Must extend HashTable<Data>

private:

  // ...

protected:

  using HashTable<Data>::tableSize;

  //size corrente ereditata da hashtable (size)

  //vettore di liste
  Vector<List<Data>> table;


  using HashTable<Data>::HashKey;

public:

  // Default constructor
  // HashTableClsAdr() specifiers
  HashTableClsAdr();
  /* ************************************************************************ */

  // Specific constructors
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size
  HashTableClsAdr(unsigned long); 
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  HashTableClsAdr(const TraversableContainer<Data>&);
  //uguale ma con una size fissata
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(unsigned long, const TraversableContainer<Data>&);
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  HashTableClsAdr(MappableContainer<Data>&&);
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
  HashTableClsAdr(unsigned long, MappableContainer<Data>&&);
  /* ************************************************************************ */

  // Copy constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(const HashTableClsAdr&);
  // Move constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(HashTableClsAdr&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~HashTableClsAdr() specifiers;
  virtual ~HashTableClsAdr() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr& operator=(const HashTableClsAdr&);
  // Move assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr& operator=(HashTableClsAdr&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const HashTableClsAdr&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const HashTableClsAdr&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  bool Insert(const Data&) override; 
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  bool Insert(Data&&) override;
  // type Remove(argument) specifiers; // Override DictionaryContainer member
  bool Remove(const Data&) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  bool Exists(const Data&) const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size
  void Resize(const unsigned long) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  // type Clear() specifiers; // Override Container member
  void Clear() override;
};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
