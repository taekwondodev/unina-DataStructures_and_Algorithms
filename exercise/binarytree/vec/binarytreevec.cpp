
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const NodeVec& nod) : element(nod.element), indexcur(nod.indexcur) {
    if (nod.v) {
        this->v = nod.v;  
    }
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(NodeVec&& nod) noexcept {
    std::swap(this->element, nod.element);
    std::swap(this->indexcur, nod.indexcur);
    std::swap(this->v, nod.v);
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& nod) {
    this->element = nod.element;
    this->indecur = nod.indexcur;

    if (!this->v) {
        if (nod.v) {
            this->v = nod.v;
        }
    }

    return *this;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& nod) noexcept {
    std::swap(this->element, nod.element);
    std::swap(this->indexcur, nod.indexcur);
    std::swap(this->v, nod.v);

    return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator==(const NodeVec& nod) const noexcept {
    return BinaryTree<Data>::Node::operator==(nod);
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::operator!=(const NodeVec& nod) const noexcept {
    return !(this->element == nod.element);
}

template <typename Data>
inline const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return element;
}

template <typename Data>
inline Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return element;
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return ((!HasLeftChild()) && (!HasRightChild()));
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return (2 * indexcur + 1 < v->Size());
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return (2 * indexcur + 2 < v->Size());
}

template <typename Data>
inline const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(HasLeftChild()){
        return *((*v)[2 * indexcur + 1]);        //prima dereferenzazione per accedere all'array dell'albero binario. Seconda per accedere al membro dell'array
    }
  else{
    throw std::out_of_range("No left child");
    }
}

template <typename Data>
inline typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(HasLeftChild()){
        return *((*v)[2 * indexcur + 1]);        //prima dereferenzazione per accedere all'array dell'albero binario. Seconda per accedere al membro dell'array
    }
  else{
    throw std::out_of_range("No left child");
    }
}

template <typename Data>
inline const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(HasRightChild()){
        return *((*v)[2 * indexcur + 2]);        //prima dereferenzazione per accedere all'array dell'albero binario. Seconda per accedere al membro dell'array
    }
  else{
    throw std::out_of_range("No left child");
    }
}

template <typename Data>
inline typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(HasRightChild()){
        return *((*v)[2 * indexcur + 2]);        //prima dereferenzazione per accedere all'array dell'albero binario. Seconda per accedere al membro dell'array
    }
  else{
    throw std::out_of_range("No left child");
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& con){
    size = con.Size();
    array.Resize(size);

    unsigned long int index = 0;
    con.Traverse(
        [this, &index](const Data& dat){
            this->array[index] = new NodeVec(dat);
            this->array[index]->indexcur = index;
            this->array[index]->v = &this->array;   //assegno l'indirizzo array

            ++index;
        }
    );
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& con){
    size = con.Size();
    array.Resize(size);

    unsigned long int index = 0;
    con.Map(
        [this, &index](Data& dat){
            this->array[index] = new NodeVec(std::move(dat));
            this->array[index]->indexcur = index;
            this->array[index]->v = &this->array;   //assegno l'indirizzo array

            ++index;
        }
    );
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& alb){
    this->size = alb.Size();
    array.Resize(size);
    
    for(unsigned int i = 0; i < size; i++){
        this->array[i] = new NodeVec(alb.array[i]->element);
        this->array[i]->indexcur = i;
        this->array[i]->v = &this->array;   //assegno l'indirizzo array
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& alb) noexcept {
    std::swap(this->size, alb.size);
    std::swap(this->array, alb.array);
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {            //necessario perchè uso una new nel costruttore
    for (unsigned int i = 0; i < size; ++i){
        delete this->array[i];
    }
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec& alb){
    if (this->size == 0){
        if (alb.size != 0) {
            array.Resize(alb.Size());
            for(unsigned int i = 0; i < alb.Size(); i++){
                this->array[i] = new NodeVec(alb.array[i]->element);
                this->array[i]->indexcur = i;
                this->array[i]->v = &this->array;   //assegno l'indirizzo array
            }
        }
    }
    else {
        if (alb.size == 0){
            Clear();
        }
        else {
            array.Resize(alb.Size());
            for(unsigned int i = 0; i < size; i++){
                this->array[i] = new NodeVec(alb.array[i]->element);
                this->array[i]->indexcur = i;
                this->array[i]->v = &this->array;   //assegno l'indirizzo array
            }
        }
    }

    this->size = alb.Size();
    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& alb) noexcept{
    std::swap(this->size, alb.size);
    std::swap(this->array, alb.array);

    return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& alb) const noexcept{
    return BinaryTree<Data>::operator==(alb);
}

template <typename Data>
inline bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& alb) const noexcept {
    return !(*this == alb);
}

template <typename Data>
const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::Root() const{
    if (size != 0){
        return *(array[0]);
    }
    else {
        throw std::length_error("Access to an empty Tree");
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
    if (size != 0){
        return *(array[0]);
    }
    else {
        throw std::length_error("Access to an empty Tree");
    }
}

template <typename Data>
void BinaryTreeVec<Data>::Clear(){
    for (unsigned int i = 0; i < size; ++i){
        delete this->array[i];
    }
    this->array.Clear();
    this->size = 0;
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun f) const {
    for (unsigned long i = 0; i < this->size; ++i){
        f(array[i]->Element());
    }
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun f) {
    for (unsigned long i = 0; i < this->size; ++i){
        f(array[i]->Element());
    }
}

/* ************************************************************************** */

}
