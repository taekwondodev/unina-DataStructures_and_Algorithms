
namespace lasd {

/* ************************************************************************** */

// ...  Sono tutti metodi di List
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& st) {
    List<Data>::operator=(st);

    return *this;
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& st) noexcept {
    List<Data>::operator=(std::move(st));

    return *this;
}

template <typename Data>
inline bool StackLst<Data>::operator==(const StackLst<Data>& st) const noexcept {
    return List<Data>::operator==(st);
}

template <typename Data>
inline bool StackLst<Data>::operator!=(const StackLst<Data>& st) const noexcept {
    return !(*this == st);
}

template <typename Data>
inline const Data& StackLst<Data>::Top() const {
    return List<Data>::Front();
}

template <typename Data>
inline Data& StackLst<Data>::Top() {
    return List<Data>::Front();
}

template <typename Data>
inline void StackLst<Data>::Pop() {
    return List<Data>::RemoveFromFront();
}

template <typename Data>
inline Data StackLst<Data>::TopNPop() {
    return List<Data>::FrontNRemove();
}

template <typename Data>
inline void StackLst<Data>::Push(const Data& dat) {
    return List<Data>::InsertAtFront(dat);
}

template <typename Data>
inline void StackLst<Data>::Push(Data&& dat) {
    return List<Data>::InsertAtFront(std::move(dat));
}

/* ************************************************************************** */

}
