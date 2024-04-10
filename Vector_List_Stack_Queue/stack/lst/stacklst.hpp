
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst: virtual public Stack<Data>, virtual protected List<Data> {
  // Must extend Stack<Data>,
  //             List<Data>

private:

  // ...

protected:

  // ...

public:

  // Default constructor
  // StackLst() specifier;
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  // StackLst(argument) specifiers; // A stack obtained from a TraversableContainer
  StackLst(const TraversableContainer<Data>& con) : List<Data>(con){};
  // StackLst(argument) specifiers; // A stack obtained from a MappableContainer
  StackLst(MappableContainer<Data>&& con) : List<Data>(std::move(con)){};

  /* ************************************************************************ */

  // Copy constructor
  // StackLst(argument);
  StackLst(const StackLst& st) : List<Data>(st) {};

  // Move constructor
  // StackLst(argument);
  StackLst(StackLst&& st) noexcept : List<Data>(std::move(st)) {};

  /* ************************************************************************ */

  // Destructor
  // ~StackLst() specifier;
  virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  StackLst& operator=(const StackLst&);

  // Move assignment
  // type operator=(argument);
  StackLst& operator=(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const StackLst&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const StackLst&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline const Data& Top() const override;
  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline Data& Top() override;
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  inline void Pop() override;
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
  inline Data TopNPop() override;
  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  inline void Push(const Data&) override;
  // type Push(argument) specifiers; // Override Stack member (move of the value)
  inline void Push(Data&&) override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;      //ho bisogno di Clear, ma è protected quindi chiamo using

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
