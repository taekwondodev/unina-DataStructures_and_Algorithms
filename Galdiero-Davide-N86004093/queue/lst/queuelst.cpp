
namespace lasd {

/* ************************************************************************** */

// ...Sono tutti metodi di List
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& que) {
    List<Data>::operator=(que);

    return *this;
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& que) noexcept {
    List<Data>::operator=(std::move(que));

    return *this;
}

template <typename Data>
inline bool QueueLst<Data>::operator==(const QueueLst<Data>& que) const noexcept {
    return List<Data>::operator==(que);
}

template <typename Data>
inline bool QueueLst<Data>::operator!=(const QueueLst<Data>& que) const noexcept {
    return !(*this == que);
}

template <typename Data>
inline const Data& QueueLst<Data>::Head() const {
    return List<Data>::Front();
}

template <typename Data>
inline Data& QueueLst<Data>::Head() {
    return List<Data>::Front();
}

template <typename Data>
inline void QueueLst<Data>::Dequeue() {
    return List<Data>::RemoveFromFront();
}

template <typename Data>
inline Data QueueLst<Data>::HeadNDequeue() {
    return List<Data>::FrontNRemove();
}

template <typename Data>
inline void QueueLst<Data>::Enqueue(const Data& dat) {
    return List<Data>::InsertAtBack(dat);
}

template <typename Data>
inline void QueueLst<Data>::Enqueue(Data&& dat) {
    return List<Data>::InsertAtBack(std::move(dat));    //qui il prof non ha messo la move.
}
/* ************************************************************************** */

}
