
namespace lasd {

/* ************************************************************************** */

// ...
template <typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data>& con) : Vector<Data>(con) {
    this->i = this->size;
}

template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data>&& con) : Vector<Data>(std::move(con)) {
    this->i = this->size;
}

template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& st) : Vector<Data>(st) {
    this->i = st.i;
}

template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& st) noexcept : Vector<Data>(std::move(st)){
    std::swap(this->i, st.i);
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& st) {
    Vector<Data>::operator=(st);
    this->i = st.i;

    return *this;
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& st) noexcept{
    Vector<Data>::operator=(std::move(st));
    std::swap(this->i, st.i);

    return *this;
}

template <typename Data>
inline bool StackVec<Data>::operator==(const StackVec<Data>& st) const noexcept {
    if (this->i == st.i) {
        for(unsigned long int index = 0; index < i; ++index) {
            if (elements[index] != st.elements[index]) {
                return false;
            }
        }

        return true;
    }
    else {
        return false;
    }
}

template <typename Data>
inline bool StackVec<Data>::operator!=(const StackVec<Data>& st) const noexcept {
    return !(*this == st);
}

template <typename Data>
const Data& StackVec<Data>::Top() const {
    if (i != 0) {                   //se non è vuoto
        return elements[i - 1];
    }
    else {
        throw std::length_error("Access to an Empty Stack");
    }
}

template <typename Data>
Data& StackVec<Data>::Top() {
    if (i != 0) {                   //se non è vuoto
        return elements[i - 1];
    }
    else {
        throw std::length_error("Access to an Empty Stack");
    }
}

template <typename Data>
void StackVec<Data>::Pop(){
    if (i != 0) {
        Reduce();
        i--;
    }
    else {
        throw std::length_error("Access to an Empty Stack");
    }
}

template <typename Data>
Data StackVec<Data>::TopNPop() {
    if (i != 0) {
        Reduce();
        i--;

        return std::move(elements[i]);
    }
    else {
        throw std::length_error("Access to an Empty Stack");
    }
}

template <typename Data>
void StackVec<Data>::Push(const Data& dat){
    Expand();
    elements[i] = dat;
    i++;
}

template <typename Data>
void StackVec<Data>::Push(Data&& dat){
    Expand();
    elements[i] = std::move(dat);
    i++;
}

template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
    return (i == 0);
}

template <typename Data>
unsigned long int StackVec<Data>::Size() const noexcept {
    return i;
}

template <typename Data>
void StackVec<Data>::Clear() {
    i = 0;
    Vector<Data>::Resize(1); //per la sentinella
}

template <typename Data>
void StackVec<Data>::Expand(){
    if (i == size) {                      //se ha raggiunto il limite
        Vector<Data>::Resize(size * 2);
    }
}

template <typename Data>
void StackVec<Data>::Reduce() {
    if (i == size / 4) {                  //se è 1/4 più piccolo ridimensiono per efficienza memoria, non a metà perchè non sarebbe efficiente
        Vector<Data>::Resize(size / 2);
    }
}

/* ************************************************************************** */

}
