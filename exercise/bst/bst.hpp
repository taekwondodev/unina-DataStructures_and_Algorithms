
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST: virtual public ClearableContainer, virtual public DictionaryContainer<Data>, virtual public BinaryTree<Data>, virtual protected BinaryTreeLnk<Data> {
  // Must extend ClearableContainer,
  //             DictionaryContainer<Data>,
  //             BinaryTree<Data>,
  //             BinaryTreeLnk<Data>

private:

  // ...

protected:

  using typename BinaryTreeLnk<Data>::NodeLnk;

  using BinaryTreeLnk<Data>::root;
  using Container::size;

public:

  // Default constructor
  // BST() specifiers;
  BST() = default;
  /* ************************************************************************ */

  // Specific constructors
  // BST(argument) specifiers; // A bst obtained from a TraversableContainer
  BST(const TraversableContainer<Data>&);
  // BST(argument) specifiers; // A bst obtained from a MappableContainer
  BST(MappableContainer<Data>&&);
  /* ************************************************************************ */

  // Copy constructor
  // BST(argument) specifiers;
  BST(const BST& alb) : BinaryTreeLnk<Data>::BinaryTreeLnk(alb) {};
  // Move constructor
  // BST(argument) specifiers;
  BST(BST&& alb) noexcept : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(alb)) {};
  /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;
  virtual ~BST() = default;   //viene chiamato quello di BinaryTreeLnk
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BST& operator=(const BST& alb) {
    BinaryTreeLnk<Data>::operator=(alb);
    return *this;
  }
  // Move assignment
  // type operator=(argument) specifiers;
  BST& operator=(BST&& alb) noexcept {
    BinaryTreeLnk<Data>::operator=(std::move(alb));
    return *this;
  };
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BST&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BST& alb) const noexcept {
    return !(*this == alb);
  }
  /* ************************************************************************ */

  // Specific member functions

  // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
  const Data& Min() const;
  // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  Data MinNRemove();
  // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)
  void RemoveMin();
  // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
  const Data& Max() const;
  // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove();
  // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)
  void RemoveMax();
  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  const Data& Predecessor(const Data&) const;
  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data&);
  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data&);
  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  const Data& Successor(const Data&) const;
  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data&);
  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data&);
  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  // type Root(argument) specifiers; // Override BinaryTree member
  using typename BinaryTree<Data>::Node;

  const Node& Root() const override;
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
  bool Exists(const Data&) const noexcept;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear(argument) specifiers; // Override ClearableContainer member
  void Clear() override;

protected:

  // Auxiliary functions, if necessary!
  //*& è riferimento di un puntatore

  // type Detach(argument) specifiers; //stacca nodo, utile quando devi rimuovere il genitore
  NodeLnk* Detach(NodeLnk*&) noexcept;
  // type DetachMin(argument) specifiers;
  NodeLnk* DetachMin(NodeLnk*&) noexcept;
  // type DetachMax(argument) specifiers;
  NodeLnk* DetachMax(NodeLnk*&) noexcept;
  // type Skip2Left(argument) specifiers;  //serve a controllare il figlio sinistro subito dopo per eventuali bilanciamenti
  NodeLnk* Skip2Left(NodeLnk*&) noexcept;
  // type Skip2Right(argument) specifiers;
  NodeLnk* Skip2Right(NodeLnk*&) noexcept;
  // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
  const NodeLnk* const & FindPointerToMin(const NodeLnk* const&) const noexcept;
  NodeLnk*& FindPointerToMin(NodeLnk*&) noexcept;
  // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions
  const NodeLnk* const & FindPointerToMax(const NodeLnk* const&) const noexcept;
  NodeLnk*& FindPointerToMax(NodeLnk*&) noexcept;
  // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions
  const NodeLnk* const & FindPointerTo(const NodeLnk* const&, const Data&) const noexcept;
  NodeLnk*& FindPointerTo(NodeLnk*&, const Data&) noexcept;
  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
  const NodeLnk* const * FindPointerToPredecessor(const NodeLnk* const&, const Data&) const noexcept;
  NodeLnk** FindPointerToPredecessor(NodeLnk*&, const Data&) noexcept;
  // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions
  const NodeLnk* const * FindPointerToSuccessor(const NodeLnk* const&, const Data&) const noexcept;
  NodeLnk** FindPointerToSuccessor(NodeLnk*&, const Data&) noexcept;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
