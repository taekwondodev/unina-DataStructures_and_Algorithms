
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data> {
  // Must extend HashTable<Data>

private:

  // ...

protected:

  using HashTable<Data>::tableSize;

  using HashTable<Data>::HashKey;

  enum class Status {Empty, Occupied, Removed};

  struct HashNode {
    friend class HashTableOpnAdr<Data>;

    Data element;
    Status state = Status::Empty;

    HashNode() = default;
    HashNode(const Data& dat) : element(dat), state(Status::Occupied) {};
    HashNode(Data&& dat) : element(std::move(dat)), state(Status::Occupied) {};
    HashNode(const HashNode&);
    HashNode(HashNode&& hn) noexcept;
    HashNode& operator=(const HashNode& hn);
    HashNode& operator=(HashNode&& hn) noexcept;

    virtual ~HashNode() = default;

    bool operator==(const HashNode& hn) const noexcept;
    inline bool operator!=(const HashNode& hn) const noexcept;
  };

  Vector<HashNode> table;

public:

  //Default constructor
  //HashTableOpnAdr() specifiers;
  HashTableOpnAdr();
  /* ************************************************************************ */

  // Specific constructors
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size
  HashTableOpnAdr(unsigned long);
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  HashTableOpnAdr(const TraversableContainer<Data>&);
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  HashTableOpnAdr(unsigned long, const TraversableContainer<Data>&);
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  HashTableOpnAdr(MappableContainer<Data>&&);
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
  HashTableOpnAdr(unsigned long, MappableContainer<Data>&&);
  /* ************************************************************************ */

  // Copy constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(const HashTableOpnAdr&);
  // Move constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(HashTableOpnAdr&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~HashTableOpnAdr() specifiers;
  virtual ~HashTableOpnAdr() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr& operator=(const HashTableOpnAdr&);
  // Move assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr& operator=(HashTableOpnAdr&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const HashTableOpnAdr&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const HashTableOpnAdr&) const noexcept;
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
protected:

  // Auxiliary member functions

  unsigned long HashKey(unsigned long, unsigned long) const noexcept;
  unsigned long Find(const Data&) const noexcept;
  unsigned long FindEmpty(const Data&) const noexcept;
  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
