
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: virtual public Queue<Data>, virtual protected Vector<Data> {
  // Must extend Queue<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  unsigned long int head = 0;          //sono gli indici di testa e coda
  unsigned long int tail = 0;

  using Vector<Data>::size;
  using Vector<Data>::elements;

  // ...

public:

  // Default constructor
  // QueueVec() specifier;
  QueueVec() : Vector<Data>(1) {}; //1 perchè c'è la sentinella

  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A stack obtained from a TraversableContainer
  QueueVec(const TraversableContainer<Data>&);
  // QueueVec(argument) specifiers; // A stack obtained from a MappableContainer
  QueueVec(MappableContainer<Data>&&);
  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);
  QueueVec(const QueueVec&);

  // Move constructor
  // QueueVec(argument);
  QueueVec(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;
  virtual ~QueueVec() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueVec& operator=(const QueueVec&);

  // Move assignment
  // type operator=(argument);
  QueueVec& operator=(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const QueueVec&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const QueueVec&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  const Data& Head() const override;
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  Data& Head() override;
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override;
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override;
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  void Enqueue(const Data&) override;
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  void Enqueue(Data&&) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  bool Empty() const noexcept override;

  // type Size() specifiers; // Override Container member
  unsigned long int Size() const noexcept override;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;
  
protected:

  // Auxiliary functions, if necessary!
  void Expand();
  void Reduce();

  //Overloading
  void Resize(unsigned long int newsize, unsigned long int num);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
