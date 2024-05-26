
namespace lasd {

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& nod) const noexcept {
  bool equal = false;
  equal = (this->Element() == nod.Element());

  if (equal){
    equal = false;

    if (this->HasLeftChild() && nod.HasLeftChild()){
      equal = (this->LeftChild() == nod.LeftChild());
    }
    else if (!this->HasLeftChild() && !nod.HasLeftChild()){
      equal = true;
    }
  }

  if (equal){
    equal = false;

    if (this->HasRightChild() && nod.HasRightChild()){
      equal = (this->RightChild() == nod.RightChild());
    }
    else if (!this->HasRightChild() && !nod.HasRightChild()){
      equal = true;
    }
  }

  return equal;
}

template <typename Data>
inline bool BinaryTree<Data>::Node::operator!=(const Node& nod) const noexcept {
    return !(*this == nod);
}

//specific node function
template <typename Data>
inline bool BinaryTree<Data>::Node::IsLeaf() const noexcept {
    return !(this->HasLeftChild() || this->HasRightChild());
}

/************* BINARY TREE ******************/
template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& alb) const noexcept {
    if (this->size == alb.size){
      if (this->size == 0){
        return true;
      }
      else { //return *root == *alb.root
        BTPreOrderIterator<Data> it1 (*this);
        BTPreOrderIterator<Data> it2 (alb);

        for (; !it1.Terminated(); ++it1, ++it2){
          if (*it1 != *it2){
            return false;
          }
        }

        return true;
      }
    }
    else {
      return false;
    }
}

template <typename Data>
inline bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& alb) const noexcept {
    return !(*this == alb);
}

//overloading
template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun f, const Node& nod) const {
    f(nod.Element());
    if (nod.HasLeftChild()){
        PreOrderTraverse(f, nod.LeftChild());
    }
    if (nod.HasRightChild()){
        PreOrderTraverse(f, nod.RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun f, const Node& nod) const {
    if (nod.HasLeftChild()){
        PostOrderTraverse(f, nod.LeftChild());
    }
    if (nod.HasRightChild()){
        PostOrderTraverse(f, nod.RightChild());
    }
    f(nod.Element());
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun f, const Node& nod) const {
    if (nod.HasLeftChild()){
        InOrderTraverse(f, nod.LeftChild());
    }
    f(nod.Element());
    if (nod.HasRightChild()){
        InOrderTraverse(f, nod.RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun f, const Node& nod) const {
    QueueVec<const Node*> que;
    que.Enqueue(&nod);

    while (!que.Empty()){
        const Node* cur = que.HeadNDequeue();
        f(cur->Element());

        if (cur->HasLeftChild()){
            que.Enqueue(&cur->LeftChild());
        }

        if (cur->HasRightChild()){
            que.Enqueue(&cur->RightChild());
        }
    }
}

//override
template <typename Data>
void BinaryTree<Data>::Traverse(TraverseFun f) const {
    if (size > 0){
        PreOrderTraverse(f, this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun f) const {
    if (size > 0){
        PreOrderTraverse(f, this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun f) const {
    if (size > 0){
        PostOrderTraverse(f, this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun f) const {
    if (size > 0){
        InOrderTraverse(f, this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun f) const {
    if (size > 0){
        BreadthTraverse(f, this->Root());
    }
}

/************** MUTABLE ***********************/

//overloading
template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun f, MutableNode& nod) {
    f(nod.Element());
    if (nod.HasLeftChild()){
        PreOrderMap(f, nod.LeftChild());
    }
    if (nod.HasRightChild()){
        PreOrderMap(f, nod.RightChild());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun f, MutableNode& nod) {
    if (nod.HasLeftChild()){
        PostOrderMap(f, nod.LeftChild());
    }
    if (nod.HasRightChild()){
        PostOrderMap(f, nod.RightChild());
    }
    f(nod.Element());
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun f, MutableNode& nod) {
    if (nod.HasLeftChild()){
        InOrderMap(f, nod.LeftChild());
    }
    f(nod.Element());
    if (nod.HasRightChild()){
        InOrderMap(f, nod.RightChild());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun f, MutableNode& nod) {
    QueueVec<MutableNode*> que;
    que.Enqueue(&nod);

    while (!que.Empty()){
        MutableNode* cur = que.HeadNDequeue();
        f(cur->Element());

        if (cur->HasLeftChild()){
            que.Enqueue(&cur->LeftChild());
        }

        if (cur->HasRightChild()){
            que.Enqueue(&cur->RightChild());
        }
    }
}

//override
template <typename Data>
inline void MutableBinaryTree<Data>::Map(MapFun f) {
    if (size > 0){
        PreOrderMap(f, this->Root());
    }
}

template <typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MapFun f) {
    if (size > 0){
        PreOrderMap(f, this->Root());
    }
}

template <typename Data>
inline void MutableBinaryTree<Data>::PostOrderMap(MapFun f) {
    if (size > 0){
        PostOrderMap(f, this->Root());
    }
}

template <typename Data>
inline void MutableBinaryTree<Data>::InOrderMap(MapFun f) {
    if (size > 0){
        InOrderMap(f, this->Root());
    }
}

template <typename Data>
inline void MutableBinaryTree<Data>::BreadthMap(MapFun f) {
    if (size > 0){
        BreadthMap(f, this->Root());
    }
}

/************ BTPREORDER *****************/

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& alb) {
    if (alb.Size() != 0){
      this->root = &alb.Root();
      stk.Push(root);
    }
}

template <typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const {
    if (!Terminated()){
      return stk.Top()->Element();        //viene applicato Element() a quello che returna Front()
    }
    else {
      throw std::out_of_range("Iterator is termined");
    }
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
  return stk.Empty();
}

template <typename Data>
ForwardIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if (Terminated()){
      throw std::out_of_range("Iterator is termined");
    }
    else {
      const typename BinaryTree<Data>::Node& cur = *stk.TopNPop();

      if (!cur.IsLeaf()) {                                                    //se current non è una foglia, inserisco prima i figli destri e poi i sinistri
        if (cur.HasRightChild()) {
          stk.Push(&cur.RightChild());
        }
        
        if (cur.HasLeftChild()) {
          stk.Push(&cur.LeftChild());
        }
      }
    }

    return *this;
}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    if (root != nullptr){
      stk.Clear();
      stk.Push(root);
    }
}

template <typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*() {
    if (!this->Terminated()){
      return const_cast<Data&>(stk.Top()->Element());       //const_cast è una keyword per castare stk da non mutable a mutable
    }
    else {
      throw std::out_of_range("Iterator is termined");
    }
}

/************** BTPOSTORDER ***************/
template <typename Data>
void BTPostOrderIterator<Data>::SetPostOrder() {
    //finchè cur non è nullptr o una foglia, non posso solo scoprire i figli sinistri e aggiornare il cur perchè nel caso in cui ha solo un figlio destro viene perso
    while (cur->HasLeftChild() || cur->HasRightChild()) {
      stk.Push(cur);

      if (cur->HasLeftChild()){           //cambio cur invece di pushare, perchè cur è il corrente e stk il precedente
        cur = &cur->LeftChild();
      }
      else {
        cur = &cur->RightChild();
      }
    }
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& alb) {
    if (alb.Size() != 0){
      this->root = &alb.Root();
      this->cur = this->root;
      SetPostOrder();
    }
}

template <typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const {
    if (!Terminated()){
      return cur->Element();        //viene applicato Element() a quello che returna Front()
    }
    else {
      throw std::out_of_range("Iterator is termined");
    }
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return cur == nullptr;
}

template <typename Data>
ForwardIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if (Terminated()){
      throw std::out_of_range("Iterator is termined");
    }
    else {
      if (stk.Empty()){           //ho finito la visita, devo settare il terminato
        cur = nullptr;
      }
      else {
        if (stk.Top()->HasRightChild() && &stk.Top()->RightChild() != cur){       //il primo controllo è verificare se il nodo precedente ha figlio destro e non visitato
            cur = &stk.Top()->RightChild();
            SetPostOrder();                                //se ha un figlio destro non visitato, devo visitare i figli
        }
        else {                //se il destro è stato già visitato, rimuovo, controllo solo per un figlio perchè è in postorder, se uno visitato anche l'altro
          cur = stk.TopNPop();
        }
      }
    }

    return *this;
}

template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    if (root != nullptr){
      stk.Clear();
      cur = root;
      SetPostOrder();
    }
}

template <typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*() {
    if (!this->Terminated()){
      return const_cast<Data&>(cur->Element());    //sto castando const Data& const a Data&
    }
    else {
      throw std::out_of_range("Iterator is termined");
    }
}

/************* BTINORDER ***************/

template <typename Data>
void BTInOrderIterator<Data>::SearchMostLeft() {
  const typename BinaryTree<Data>::Node* cur;          //uso puntatore e non riferimento perchè nel while lo inizializzo

  while ((cur = stk.Top())->HasLeftChild()) {
    stk.Push(&cur->LeftChild());
  }
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& alb) {
    if (alb.Size() != 0){
      root = &alb.Root();
      stk.Push(root);
      SearchMostLeft();
    }
}

template <typename Data>
const Data& BTInOrderIterator<Data>::operator*() const {
    if (!Terminated()){
      return stk.Top()->Element();        //viene applicato Element() a quello che returna Front()
    }
    else {
      throw std::out_of_range("Iterator is termined");
    }
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return stk.Empty();
}

template <typename Data>
ForwardIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if (Terminated()){
      throw std::out_of_range("Iterator is termined");
    }
    else {
      const typename BinaryTree<Data>::Node& cur = *stk.TopNPop();

      if (!cur.IsLeaf()) {                                                    //se current non è una foglia
        if (cur.HasRightChild()) {
          stk.Push(&cur.RightChild());
          SearchMostLeft();                                //se ha un figlio destro, metto in cima allo stack il più sinistro del sottoalbero destro
        }
      }
    }

    return *this;
}

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    if (root != nullptr){
      stk.Clear();
      stk.Push(root);
      SearchMostLeft();
    }
}

template <typename Data>
Data& BTInOrderMutableIterator<Data>::operator*() {
    if (!this->Terminated()){
      return const_cast<Data&>(stk.Top()->Element());       //const_cast è una keyword per castare stk da non mutable a mutable
    }
    else {
      throw std::out_of_range("Iterator is termined");
    }
}

/***************** BTBREADTH **********************/

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& alb) {
    if (alb.Size() != 0){
      root = &alb.Root();
      que.Enqueue(root);
    }
}

template <typename Data>
const Data& BTBreadthIterator<Data>::operator*() const {
    if (!Terminated()){
      return que.Head()->Element();        //viene applicato Element() a quello che returna Head()
    }
    else {
      throw std::out_of_range("Iterator is termined");
    }
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return que.Empty();
}

template <typename Data>
ForwardIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if (Terminated()){
      throw std::out_of_range("Iterator is termined");
    }
    else {
      const typename BinaryTree<Data>::Node& cur = *que.HeadNDequeue();

      if (cur.HasLeftChild()){
        que.Enqueue(&cur.LeftChild());
      }

      if(cur.HasRightChild()){
        que.Enqueue(&cur.RightChild());
      }
    }

    return *this;
}

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    if (root != nullptr) {
      que.Clear();
      que.Enqueue(root);
    }
}

template <typename Data>
Data& BTBreadthMutableIterator<Data>::operator*() {
    if (!this->Terminated()){
      return const_cast<Data&>(que.Head()->Element());       //const_cast è una keyword per castare que da non mutable a mutable
    }
    else {
      throw std::out_of_range("Iterator is termined");
    }
}
/* ************************************************************************** */

}
