
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
//#include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
//#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree: virtual public PreOrderTraversableContainer<Data>, virtual public PostOrderTraversableContainer<Data>, virtual public InOrderTraversableContainer<Data>, virtual public BreadthTraversableContainer<Data> {
  // Must extend PreOrderTraversableContainer<Data>,
  //             PostOrderTraversableContainer<Data>,
  //             InOrderTraversableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:

  // ...

protected:

  // ...
  using Container::size;

public:

  struct Node {

  protected:

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but is not visible.
    bool operator==(const Node&) const noexcept;
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but is not visible.
    inline bool operator!=(const Node&) const noexcept;

  public:

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~Node() specifiers
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.
    Node& operator=(const Node&) = delete;
    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.
    Node& operator=(Node&&) noexcept = delete;
    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions)
    virtual const Data& Element() const noexcept = 0;
    // type IsLeaf() specifiers; // (concrete function should not throw exceptions)
    virtual bool IsLeaf() const noexcept;
    // type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept = 0;
    // type HasRightChild() specifiers; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0;

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual const Node& LeftChild() const = 0;
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual const Node& RightChild() const = 0;
  };

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTree() specifiers
  virtual ~BinaryTree() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  BinaryTree& operator=(const BinaryTree&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  BinaryTree& operator=(BinaryTree&&) noexcept = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator==(const BinaryTree&) const noexcept;
  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.
  inline bool operator!=(const BinaryTree&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  virtual const Node& Root() const = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(arguments) specifiers; // Override TraversableContainer member
  void Traverse(TraverseFun) const override;
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member
  void PreOrderTraverse(TraverseFun) const override;
  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member
  void PostOrderTraverse(TraverseFun) const override;
  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  // type InOrderTraverse(arguments) specifiers; // Override InOrderTraversableContainer member
  void InOrderTraverse(TraverseFun) const override;
  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member
  void BreadthTraverse(TraverseFun) const override;
protected:

  // Auxiliary functions, if necessary!
  //Overloading Traverse
  void PreOrderTraverse(TraverseFun, const Node&) const;
  void PostOrderTraverse(TraverseFun, const Node&) const;
  void InOrderTraverse(TraverseFun, const Node&) const;
  void BreadthTraverse(TraverseFun, const Node&) const;

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree: virtual public ClearableContainer, virtual public BinaryTree<Data>, virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>, virtual public InOrderMappableContainer<Data>, virtual public BreadthMappableContainer<Data> {
  // Must extend ClearableContainer,
  //             BinaryTree<Data>,
  //             PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>,
  //             InOrderMappableContainer<Data>,
  //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...
  using Container::size;

public:

  struct MutableNode: virtual BinaryTree<Data>::Node {
    // Must extend Node

    using BinaryTree<Data>::Node::Element;
    using BinaryTree<Data>::Node::RightChild;
    using BinaryTree<Data>::Node::LeftChild;

    public:

    friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~MutableNode() specifiers
    virtual ~MutableNode() = default;
    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.
    MutableNode& operator=(const MutableNode&) = delete;
    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.
    MutableNode& operator=(MutableNode&&) noexcept = delete;
    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)
    virtual Data& Element() noexcept = 0;
    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& LeftChild() = 0;
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& RightChild() = 0;
  };

  /* ************************************************************************ */

  // Destructor
  // ~MutableBinaryTree() specifiers
  virtual ~MutableBinaryTree() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  MutableBinaryTree& operator=(const MutableBinaryTree&) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  MutableBinaryTree& operator=(MutableBinaryTree&&) noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  virtual MutableNode& Root() = 0;
  using BinaryTree<Data>::Root;
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member
  inline void Map(MapFun) override;
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
  inline void PreOrderMap(MapFun) override;
  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
  inline void PostOrderMap(MapFun) override;
  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Override InOrderMappableContainer member
  inline void InOrderMap(MapFun) override;
  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
  inline void BreadthMap(MapFun) override;
protected:

  // Auxiliary functions, if necessary!
  //Overloading
  void PreOrderMap(MapFun, MutableNode&);
  void PostOrderMap(MapFun, MutableNode&);
  void InOrderMap(MapFun, MutableNode&);
  void BreadthMap(MapFun, MutableNode&);

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator: virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  //uso typename per specificare al compilatore che è un tipo
  const typename BinaryTree<Data>::Node* root = nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stk;

public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPreOrderIterator(const BinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(const BTPreOrderIterator<Data>& itr) : root(itr.root), stk(itr.stk) {};
  // Move constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(BTPreOrderIterator<Data>&& itr) noexcept{
    std::swap(this->root, itr.root);
    std::swap(this->stk, itr.stk);
  }
  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;
  virtual ~BTPreOrderIterator() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator& operator=(const BTPreOrderIterator& itr) {
    this->root = itr.root;
    this->stk = itr.stk;

    return *this;
  }
  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator& operator=(BTPreOrderIterator&& itr) noexcept{
    std::swap(this->root, itr.root);
    std::swap(this->stk, itr.stk);

    return *this;
  }
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPreOrderIterator& itr) const noexcept { return this->root == itr.root; }
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTPreOrderIterator& itr) const noexcept {
    return !(*this == itr);
  }
  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  const Data& operator*() const override;
  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  ForwardIterator<Data>& operator++() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator: virtual public MutableIterator<Data>, virtual public BTPreOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTPreOrderIterator<Data>

private:

  // ...

protected:

  using BTPreOrderIterator<Data>::stk;

public:

  // Specific constructors
  // BTPreOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTPreOrderMutableIterator(const BinaryTree<Data>& alb) : BTPreOrderIterator<Data>(alb) {};
  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderMutableIterator(argument) specifiers;
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator& itr) : BTPreOrderIterator<Data>(itr) {};
  // Move constructor
  // BTPreOrderMutableIterator(argument) specifiers;
  BTPreOrderMutableIterator(BTPreOrderMutableIterator&& itr) noexcept : BTPreOrderIterator<Data>(std::move(itr)) {};
  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderMutableIterator() specifiers;
  virtual ~BTPreOrderMutableIterator() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator& itr) {
    return BTPreOrderIterator<Data>::operator=(itr);
  }
  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&& itr) noexcept {
    return BTPreOrderIterator<Data>::operator=(std::move(itr));
  }
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPreOrderMutableIterator& itr) const noexcept {
    return BTPreOrderIterator<Data>::operator==(itr);
  }
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTPreOrderMutableIterator& itr) const noexcept {
    return !(*this == itr);
  }
  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator: virtual public ForwardIterator<Data>, ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root = nullptr;
  //dichiaro globalmente cur perchè ho bisogno di un puntatore al nodo precedente nel ++ per controllare se ho gia visitato i nodi figli, stk punterà al precedente
  const typename BinaryTree<Data>::Node* cur = nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stk;

  void SetPostOrder();

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPostOrderIterator(const BinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(const BTPostOrderIterator& itr) : root(itr.root), cur(itr.cur), stk(itr.stk) {};
  // Move constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(BTPostOrderIterator&& itr) noexcept {
    std::swap(this->root, itr.root);
    std::swap(this->cur, itr.cur);
    std::swap(this->stk, itr.stk);
  }
  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;
  virtual ~BTPostOrderIterator() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(const BTPostOrderIterator& itr){
    this->root = itr.root;
    this->cur = itr.cur;
    this->stk = itr.stk;

    return *this;
  }
  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(BTPostOrderIterator&& itr) noexcept {
    std::swap(this->root, itr.root);
    std::swap(this->cur, itr.cur);
    std::swap(this->stk, itr.stk);

    return *this;
  }
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPostOrderIterator& itr) const noexcept { return this->root == itr.root; }
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTPostOrderIterator& itr) const noexcept {
    return !(*this == itr);
  }
  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  const Data& operator*() const override;

  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  ForwardIterator<Data>& operator++() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator: virtual public MutableIterator<Data>, virtual public BTPostOrderIterator<Data>{
  // Must extend MutableIterator<Data>,
  //             BTPostOrderIterator<Data>

private:

  // ...

protected:

  using BTPostOrderIterator<Data>::cur;

public:

  // Specific constructors
  // BTPostOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTPostOrderMutableIterator(const BinaryTree<Data>& alb) : BTPostOrderIterator<Data>(alb) {};
  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderMutableIterator(argument) specifiers;
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator& itr) : BTPostOrderIterator<Data>(itr) {};
  // Move constructor
  // BTPostOrderMutableIterator(argument) specifiers;
  BTPostOrderMutableIterator(BTPostOrderMutableIterator&& itr) noexcept : BTPostOrderIterator<Data>(std::move(itr)) {};
  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderMutableIterator() specifiers;
  virtual ~BTPostOrderMutableIterator() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator& itr) {
    return BTPostOrderIterator<Data>::operator=(itr);
  }
  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderMutableIterator& operator=(BTPostOrderMutableIterator&& itr) noexcept {
    return BTPostOrderIterator<Data>::operator=(std::move(itr));
  }
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPostOrderMutableIterator& itr) const noexcept {
    return BTPostOrderIterator<Data>::operator==(itr);
  }
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTPostOrderMutableIterator& itr) const noexcept{
    return !(*this == itr);
  }
  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator: virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  //uso typename per specificare al compilatore che è un tipo
  const typename BinaryTree<Data>::Node* root = nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stk;

  void SearchMostLeft();

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTInOrderIterator(const BinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(const BTInOrderIterator& itr) : root(itr.root), stk(itr.stk) {}; 
  // Move constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(BTInOrderIterator&& itr) noexcept {
    std::swap(this->root, itr.root);
    std::swap(this->stk, itr.stk);
  }
  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;
  virtual ~BTInOrderIterator() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator& operator=(const BTInOrderIterator& itr){
    this->root = itr.root;
    this->stk = itr.stk;

    return *this;
  }
  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator& operator=(BTInOrderIterator&& itr) noexcept{
    std::swap(this->root, itr.root);
    std::swap(this->stk, itr.stk);

    return *this;
  }
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTInOrderIterator& itr) const noexcept { return this->root == itr.root; }
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTInOrderIterator& itr) const noexcept {
    return !(*this == itr);
  }
  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  const Data& operator*() const override;
  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  ForwardIterator<Data>& operator++() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator: virtual public MutableIterator<Data>, virtual public BTInOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTInOrderIterator<Data>

private:

  // ...

protected:

  using BTInOrderIterator<Data>::stk;

public:

  // Specific constructors
  // BTInOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTInOrderMutableIterator(const BinaryTree<Data>& alb) : BTInOrderIterator<Data>(alb) {};
  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderMutableIterator(argument) specifiers;
  BTInOrderMutableIterator(const BTInOrderMutableIterator& itr) : BTInOrderIterator<Data>(itr) {};
  // Move constructor
  // BTInOrderMutableIterator(argument) specifiers;
  BTInOrderMutableIterator(BTInOrderMutableIterator&& itr) noexcept : BTInOrderIterator<Data>(std::move(itr)) {};
  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderMutableIterator() specifiers;
  virtual ~BTInOrderMutableIterator() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTInOrderMutableIterator& operator=(const BTInOrderMutableIterator& itr) {
    return BTInOrderIterator<Data>::operator=(itr);
  }
  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderMutableIterator& operator=(BTInOrderMutableIterator&& itr) noexcept{
    return BTInOrderIterator<Data>::operator=(std::move(itr));
  }
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTInOrderMutableIterator& itr) {
    return BTInOrderIterator<Data>::operator==(itr);
  }
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTInOrderMutableIterator& itr){
    return !(*this == itr);
  }
  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator: virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:
  
  //uso typename per specificare al compilatore che è un tipo
  const typename BinaryTree<Data>::Node* root = nullptr;
  QueueVec<const typename BinaryTree<Data>::Node*> que;

public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree
  BTBreadthIterator(const BinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator(const BTBreadthIterator& itr) : root(itr.root), que(itr.que) {};
  // Move constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator(BTBreadthIterator&& itr) noexcept {
    std::swap(this->root, itr.root);
    std::swap(this->que, itr.que);
  }
  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;
  virtual ~BTBreadthIterator() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator& operator=(const BTBreadthIterator& itr){
    this->root = itr.root;
    this->que = itr.que;

    return *this;
  } 

  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator& operator=(BTBreadthIterator&& itr) noexcept{
    std::swap(this->root, itr.root);
    std::swap(this->que, itr.que);

    return *this;
  }
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTBreadthIterator& itr) const noexcept{ return this->root == itr.root; }
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTBreadthIterator& itr) const noexcept{
    return !(*this == itr);
  }
  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  const Data& operator*() const override;
  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  ForwardIterator<Data>& operator++() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator: virtual public MutableIterator<Data>, virtual public BTBreadthIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTBreadthIterator<Data>

private:

  // ...

protected:

  // ...
  using BTBreadthIterator<Data>::que;

public:

  // Specific constructors
  // BTBreadthMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTBreadthMutableIterator(const MutableBinaryTree<Data>& alb) : BTBreadthIterator<Data>(alb) {}; 
  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthMutableIterator(argument) specifiers;
  BTBreadthMutableIterator(const BTBreadthMutableIterator& itr) : BTBreadthIterator<Data>(itr) {};
  // Move constructor
  // BTBreadthMutableIterator(argument) specifiers;
  BTBreadthMutableIterator(BTBreadthMutableIterator&& itr) noexcept : BTBreadthIterator<Data>(std::move(itr)) {};
  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthMutableIterator() specifiers;
  virtual ~BTBreadthMutableIterator() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator& itr) {
    return BTBreadthIterator<Data>::operator=(itr);
  }
  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&& itr) noexcept{
    return BTBreadthIterator<Data>::operator=(std::move(itr));
  }
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTBreadthMutableIterator& itr) const noexcept {
    return BTBreadthIterator<Data>::operator==(itr);
  }
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTBreadthMutableIterator& itr) const noexcept {
    return !(*this == itr);
  }
  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() override;

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
