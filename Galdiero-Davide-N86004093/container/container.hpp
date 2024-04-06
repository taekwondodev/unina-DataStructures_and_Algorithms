
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  unsigned long int size;

  /* ************************************************************************ */

  // Default constructor
  Container() = default;
  // Container() specifiers;
  Container(unsigned long int num){
    this->size = num;
  }

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  Container& operator=(const Container&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  Container& operator=(Container&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const Container&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const Container&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)
  virtual bool Empty() const noexcept {
    return (this->size==0);
  }

  // type Size() specifiers; // (concrete function should not throw exceptions)
  virtual unsigned long int Size() const noexcept {
    return this->size;
  }
};

/* ************************************************************************** */

class ClearableContainer: virtual public Container {
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ClearableContainer() specifiers
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ClearableContainer& operator=(const ClearableContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ClearableContainer& operator=(ClearableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ClearableContainer&) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const ClearableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Clear() specifiers;
  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer: virtual public ClearableContainer {
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ResizableContainer() specifiers
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ResizableContainer& operator=(const ResizableContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ResizableContainer& operator=(ResizableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ResizableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const ResizableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Resize(argument) specifiers;
  virtual void Resize(const unsigned long int size) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  virtual void Clear() override = 0;
};

/* ************************************************************************** */

}

#endif
