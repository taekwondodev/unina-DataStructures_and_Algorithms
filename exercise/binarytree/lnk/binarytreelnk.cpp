
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& dat) noexcept {
    std::swap(element, dat);
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& nod){
    this->element = nod.element;

    if (nod.left != nullptr) {
        this->left = new NodeLnk(*nod.left);
    }
    if (nod.right != nullptr){
        this->right = new NodeLnk(*nod.right);
    }
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& nod) noexcept{
    std::swap(left, nod.left);
    std::swap(right, nod.right);
    std::swap(element, nod.element);
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
    delete this->left;
    delete this->right;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& nod){
    this->element = nod.element;

    if (left == nullptr){
        if (nod.left != nullptr){
            left = new NodeLnk(*nod.left);
        }
    }
    else {
        if (nod.left != nullptr){
            *left = *nod.left;
        }
        else {
            delete left;
            left = nullptr;
        }
    }

    if (right == nullptr){
        if (nod.right != nullptr){
            right = new NodeLnk(*nod.right);
        }
    }
    else {
        if (nod.right != nullptr){
            *right = *nod.right;
        }
        else {
            delete right;
            right = nullptr;
        }
    }

    return *this;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& nod) noexcept {
    std::swap(left, nod.left);
    std::swap(right, nod.right);
    std::swap(element, nod.element);

    return *this;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk& nod) const noexcept{
    return BinaryTree<Data>::Node::operator==(nod);
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk& nod) const noexcept {
    return !(*this == nod);
}

template <typename Data>
inline const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
    return this->element;
}

template <typename Data>
inline Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
    return this->element;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{
    return ((left == nullptr) && (right == nullptr));
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
    return (left != nullptr);
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
    return (right != nullptr);
}

template <typename Data>
inline const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {      //devo usare typename per far capire al compilatore che è un tipo poichè è un template
    if (left != nullptr){
        return *left;
    }
    else {
        throw std::out_of_range("Dont have left child");
    }
}

template <typename Data>
inline const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
    if (right != nullptr){
        return *right;
    }
    else {
        throw std::out_of_range("Dont have right child");
    }
}

template <typename Data>
inline typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {      //devo usare typename per far capire al compilatore che è un tipo poichè è un template
    if (left != nullptr){
        return *left;
    }
    else {
        throw std::out_of_range("Dont have left child");
    }
}

template <typename Data>
inline typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild(){
    if (right != nullptr){
        return *right;
    }
    else {
        throw std::out_of_range("Dont have right child");
    }
}

/************************ Binary Tree LNK **************************/
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& con) {
    size = con.Size();
    QueueVec<NodeLnk**> que;                            //puntatori a puntatori perchè cosi mi salvo l'indirizzo e non l'oggetto
    que.Enqueue(&root);

    con.Traverse(
        [&que](const Data& dat){
            NodeLnk *& cur = *que.HeadNDequeue();        //cur è un riferimento perchè returna un riferimento, ma anche puntatore perchè poi lo devi encodare
            cur = new NodeLnk(dat);
            que.Enqueue(&cur->left);
            que.Enqueue(&cur->right);
        }
    );
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& con) {
    size = con.Size();
    QueueVec<NodeLnk**> que;                          //puntatori a puntatori perchè cosi mi salvo l'indirizzo e non l'oggetto
    que.Enqueue(&root);

    con.Map(
        [&que](Data & dat){
            NodeLnk *& cur = *que.HeadNDequeue();    //cur è un riferimento perchè returna un riferimento, ma anche puntatore perchè poi lo devi encodare
            cur = new NodeLnk(std::move(dat));
            que.Enqueue(&cur->left);
            que.Enqueue(&cur->right);
        }
    );
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& alb){
    if (alb.root != nullptr) {
        this->root = new NodeLnk(*alb.root);
        this->size = alb.size;
    }
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& alb) noexcept{
    std::swap(this->root, alb.root);
    std::swap(this->size, alb.size);
}

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk(){
    delete root;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& alb) {
    if (this->root == nullptr){
        if (alb.root != nullptr){
            this->root = new NodeLnk(*alb.root);
        }
    }

    else {
        if (alb.root == nullptr) {
            delete root;
            root = nullptr;
        }
        else {
            *root = *(alb.root);
        }
    }

    this->size = alb.size;
    return *this;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& alb) noexcept {
    std::swap(this->root, alb.root);
    std::swap(this->size, alb.size);

    return *this;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& alb) const noexcept{
    return BinaryTree<Data>::operator==(alb);
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& alb) const noexcept {
    return !(*this == alb);
}

template <typename Data>
const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::Root() const {       //typename perchè devo far capire al compilatore che è un tipo
    if (root != nullptr) {
        return *root;
    }
    else {
        throw std::length_error("Access to an empty tree");
    }
}

template <typename Data>
typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::Root() {       //typename perchè devo far capire al compilatore che è un tipo
    if (root != nullptr) {
        return *root;
    }
    else {
        throw std::length_error("Access to an empty tree");
    }
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    delete root;
    root = nullptr;
    size = 0;
}

/* ************************************************************************** */

}
