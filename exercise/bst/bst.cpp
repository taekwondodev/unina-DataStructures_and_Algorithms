
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BST<Data>::BST(const TraversableContainer<Data>& con){
    con.Traverse(
        [this](const Data& dat){
            Insert(dat);
        }
    );
}

template <typename Data>
BST<Data>::BST(MappableContainer<Data>&& con){
    con.Map(
        [this](Data& dat){
            Insert(std::move(dat));
        }
    );
}

template <typename Data>
bool BST<Data>::operator==(const BST& alb) const noexcept {     //in order perchè parte dal minimo
    if (this->size == alb.Size()){
        if (size == 0){
            return true;
        }
        else {
            BTInOrderIterator<Data> it1 (*this);
            BTInOrderIterator<Data> it2 (alb);

            for(; !it1.Terminated(); ++it1, ++it2){
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
const Data& BST<Data>::Min() const {
    if (root != nullptr){
        const NodeLnk* const& min = FindPointerToMin(root);       //*& è un riferimento di un puntatore

        return min->Element();
    }
    else {
        throw std::length_error("Access to an empty BST");
    }
}

template <typename Data>
Data BST<Data>::MinNRemove() {         //la exception la solleva Min
    Data min = Min();
    RemoveMin();

    return min;
}

template <typename Data>
void BST<Data>::RemoveMin() {
    if (root != nullptr) {
        if (size == 1) {
           Clear();
        }
        else {
            NodeLnk*& min = FindPointerToMin(root);

            if (!min->HasRightChild()){              //se è foglia aggiorno il puntatore a nullptr
                NodeLnk* tmp = min;
                min = nullptr;

                --size;
                delete tmp;
            }
            else {
                delete DetachMin(root);              //se ha figlio destro devo staccare il minimo e collegare nonno a figlio
            }
        }
    }
    else {
        throw std::length_error("Access to an empty BST");
    }
}

template <typename Data>
const Data& BST<Data>::Max() const {
    if (root != nullptr){
        const NodeLnk* const& max = FindPointerToMax(root);

        return max->Element();
    }
    else {
        throw std::length_error("Access to an empty BST");
    }
}

template <typename Data>
Data BST<Data>::MaxNRemove() {          //la exception la solleva Max
    Data max = Max();
    RemoveMax();

    return max;
}

template <typename Data>
void BST<Data>::RemoveMax() {
    if (root != nullptr) {
        if (size == 1) {
           Clear();
        }
        else {
            NodeLnk*& max = FindPointerToMax(root);

            if (!max->HasLeftChild()){            //se è foglia aggiorno il puntatore a nullptr
                NodeLnk* tmp = max;
                max = nullptr;

                delete tmp;
                --size;
            }
            else{
                delete DetachMax(root);          //se ha figlio sinistro stacco il max e collego nonno e figlio
            }
        }
    }
    else {
        throw std::length_error("Access to an empty BST");
    }
}

template <typename Data>
const Data& BST<Data>::Predecessor(const Data& dat) const{                  //nodo più grande minore del nodo in input
    if (FindPointerToPredecessor(root, dat) != nullptr) {
        const NodeLnk* const* predecessor = FindPointerToPredecessor(root, dat);
        return (*predecessor)->Element();
    }
    else {
        throw std::length_error("The node was not found");
    }
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& dat){
    Data predecessor = Predecessor(dat);
    RemovePredecessor(dat);

    return predecessor;
}

template <typename Data>
void BST<Data>::RemovePredecessor(const Data& dat){
    if (FindPointerToPredecessor(root, dat) != nullptr){
        NodeLnk*& predecessor = *FindPointerToPredecessor(root, dat);

        if(predecessor->HasLeftChild() && predecessor->HasRightChild()){
            NodeLnk*& predecessor2 = *(FindPointerToSuccessor(root, predecessor->Element()));
            NodeLnk* tmp = predecessor2;

            tmp = Detach(predecessor2);
            std::swap(tmp->Element(), predecessor->Element());

            delete tmp;
        }
        else {
            delete Detach(predecessor);
        }
    }
    else {
        throw std::length_error("The node was not found");
    }
}

template <typename Data>
const Data& BST<Data>::Successor(const Data& dat) const{    //nodo più piccolo maggiore del nodo in input
    if (FindPointerToSuccessor(root, dat) != nullptr){
        const NodeLnk* const * successor = FindPointerToSuccessor(root, dat);
        return (*successor)->Element();
    }
    else {
        throw std::length_error("The node was not found");
    }
}

template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& dat){
    Data successor = Successor(dat);
    RemoveSuccessor(dat);

    return successor;
}

template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& dat){         //non può avere figlio sinistro
    if (FindPointerToSuccessor(root, dat) != nullptr){
        NodeLnk*& successor = *FindPointerToSuccessor(root, dat);

        if (successor->HasLeftChild() && successor->HasRightChild()){
            NodeLnk*& successor2 = *(FindPointerToSuccessor(root, successor->Element()));
            NodeLnk* tmp = successor2;

            tmp = Detach(successor2);
            std::swap(tmp->Element(), successor->Element());

            delete tmp;
        }
        else {
            delete Detach(successor);
        }
    }
    else {
        throw std::length_error("The node was not found");
    }
}

template <typename Data>
const typename BST<Data>::Node& BST<Data>::Root() const {
    return *root;
}

template <typename Data>
bool BST<Data>::Insert(const Data& dat){
    if (root == nullptr) {                               //se è vuoto inserisco in radice
        root = new NodeLnk(dat);
        size++;

        return true;
    }

    if (Exists(dat)){             //non voglio duplicati
        return false;
    }
    else {
        NodeLnk* cur = root;

        while (true) {

            if (dat < cur->Element()){
                if (!cur->HasLeftChild()) {
                    cur->left = new NodeLnk(dat);
                    size++;

                    return true;
                }

                cur = cur->left;        //scorro cur se ha figlio sinistro, altrimenti inserisco
            }

            else {
                if (!cur->HasRightChild()) {
                    cur->right = new NodeLnk(dat);
                    size++;

                    return true;
                }

                cur = cur->right;      //scorro cur se ha figlio destro, altrimenti inserisco
            }
        }
    }
}

template <typename Data>
bool BST<Data>::Insert(Data&& dat){
        if (root == nullptr) {                               //se è vuoto inserisco in radice
        root = new NodeLnk(std::move(dat));
        size++;

        return true;
    }

    if (Exists(dat)){             //non voglio duplicati
        return false;
    }
    else {
        NodeLnk* cur = root;

        while (true) {

            if (dat < cur->Element()){
                if (!cur->HasLeftChild()) {
                    cur->left = new NodeLnk(std::move(dat));
                    size++;

                    return true;
                }

                cur = cur->left;        //scorro cur se ha figlio sinistro, altrimenti inserisco
            }

            else {
                if (!cur->HasRightChild()) {
                    cur->right = new NodeLnk(std::move(dat));
                    size++;

                    return true;
                }

                cur = cur->right;      //scorro cur se ha figlio destro, altrimenti inserisco
            }
        }
    }
}

template <typename Data>
bool BST<Data>::Remove(const Data& dat){
    if (root == nullptr) {                   //se vuoto
        return false;
    }

    NodeLnk*& nod = FindPointerTo(root, dat);
    if (nod == nullptr){                     //se non trovato
        return false;
    }
    else {
        //caso 1
        if (nod->IsLeaf()){
            NodeLnk* tmp = nod;
            nod = nullptr;
            
            delete tmp;
            --size;
            return true;
        }
        //caso 2 (solo un figlio)
        else if (!nod->HasRightChild() || !nod->HasLeftChild()){
            if (nod->HasRightChild()){
                delete Skip2Right(nod);
            }
            else {
                delete Skip2Left(nod);
            }
            
            return true;
        }
        //caso 3 (entrambi i figli)
        else if (nod->HasRightChild() && nod->HasLeftChild()){            //trovo il successore, lo stacco e poi prende il posto di nod
            NodeLnk*& successor = *(FindPointerToSuccessor(root, dat));
            NodeLnk* tmp = successor;

            tmp = Detach(successor);
            std::swap(tmp->Element(), nod->Element());

            delete tmp;
            return true;
        }
    }

    return false;   //valore di default
}

template <typename Data>
bool BST<Data>::Exists(const Data& dat) const noexcept {
    return (FindPointerTo(root, dat) != nullptr); 
}

template <typename Data>
void BST<Data>::Clear() {
    BinaryTreeLnk<Data>::Clear();
}

/******************* AUSILIARE **********************/
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& nod) noexcept{
    if (nod->HasLeftChild()){
        return Skip2Left(nod);
    }
    else if (nod->HasRightChild()){
        return Skip2Right(nod);
    }

    //se non ha figli
    NodeLnk* tmp = nod;
    nod = nullptr; 
    --size;
    return tmp;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& nod) noexcept {
    return Skip2Right(FindPointerToMin(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& nod) noexcept{
    return Skip2Left(FindPointerToMax(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& nod) noexcept{
    NodeLnk* tmp = nullptr;

    if (nod != nullptr){
        std::swap(tmp, nod->left);
        std::swap(tmp, nod);
        --size;
    }

    return tmp;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& nod) noexcept{
    NodeLnk* tmp = nullptr;

    if (nod != nullptr){
        std::swap(tmp, nod->right);
        std::swap(tmp, nod);
        --size;
    }

    return tmp;
}

template <typename Data>
const typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(const NodeLnk* const& nod) const noexcept{
    const NodeLnk* const* ptr = &nod;
    const NodeLnk* cur = nod;

    if (cur != nullptr){
        while (cur->HasLeftChild()){
            ptr = &cur->left;
            cur = cur->left;
        }
    }

    return *ptr;
}

//static_cast casta la funzione in non mutable per poter chiamare la funzione senza copiare il codice e poi con const_cast casto in mutable il return
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk *& nod) noexcept {
   return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(nod));
}

template <typename Data>
const typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMax(const NodeLnk* const & nod) const noexcept{
    const NodeLnk* const* ptr = &nod;
    const NodeLnk* cur = nod;

    if (cur != nullptr){
        while (cur->HasRightChild()){
            ptr = &cur->right;
            cur = cur->right;
        }
    }

    return *ptr;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& nod) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(nod));
}

template <typename Data>
const typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(const NodeLnk* const& nod, const Data& dat) const noexcept {
    const NodeLnk* const * ptr = &nod;
    const NodeLnk* cur = nod;

    while (cur != nullptr){
        if (dat > cur->Element()) {
            ptr = &cur->right;
            cur = cur->right;
        }
        else if (dat < cur->Element()){
            ptr = &cur->left;
            cur = cur->left;
        }
        else {          //se trovato break
            break;
        }
    }

    return *ptr;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& nod, const Data& dat) noexcept{
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerTo(nod, dat));
}

template <typename Data>
const typename BST<Data>::NodeLnk* const* BST<Data>::FindPointerToPredecessor(const NodeLnk* const & nod, const Data& dat) const noexcept {
    const NodeLnk* const* ptr = &nod;
    const NodeLnk* const * parent = nullptr;

    //parent punta al candidato piu possibile

    while (true){
        const NodeLnk& cur = **ptr;

        if (dat > cur.Element()){
            parent = ptr;
            if (!cur.HasRightChild()){    //non è nell'albero dat, returna il max
                return parent;
            }
            else {
                ptr = &cur.right;
            }
        }
        else {
            if (!cur.HasLeftChild()){    //trovato e non ha un sottoalbero sinistro, il predecessore è il padre
                return parent;
            }
            else {
                if (dat < cur.Element()){
                    ptr = &cur.left;
                }
                else {
                    return &FindPointerToMax(cur.left);              //se ha sottoalbero sinistro, trovo il massimo del sottoalbero
                }
            }
        }
    }
}

template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(NodeLnk*& nod, const Data& dat) noexcept {
    return const_cast<NodeLnk**>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(nod, dat));
}

template <typename Data>
const typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToSuccessor(const NodeLnk* const & nod, const Data& dat) const noexcept {
    const NodeLnk* const* ptr = &nod;
    const NodeLnk* const * parent = nullptr;

    //parent punta sempre al candidato più possibile

    while(true){
        const NodeLnk& cur = **ptr;

        if (dat < cur.Element()){
            parent = ptr;
            if (!cur.HasLeftChild()){                   //se dat non è nell'albero returno il min
                return parent;
            }
            else {
                ptr = &cur.left;
            }
        }
        else {
            if (!cur.HasRightChild()){             //se trovato e non ha sottoalbero destro, il successore è il padre
                return parent;
            }
            else {
                if (dat > cur.Element()){
                    ptr = &cur.right;
                }
                else {
                    return &FindPointerToMin(cur.right);      //se ha sottoalbero destro, trovo il minimo del sottoalbero
                }
            }
        }
    }

}

template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(NodeLnk*& nod, const Data& dat) noexcept {
    return const_cast<NodeLnk**>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(nod, dat));
}

/* ************************************************************************** */

}