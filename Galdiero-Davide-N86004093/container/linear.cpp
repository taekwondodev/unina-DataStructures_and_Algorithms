
namespace lasd {

/* ************************************************************************** */

// ...
template <typename Data>
inline const Data& LinearContainer<Data>::Front() const {
    return operator[](0);
}

template <typename Data>
inline Data& LinearContainer<Data>::Front() {
    return operator[](0);
}

template <typename Data>
inline const Data& LinearContainer<Data>::Back() const {
    return operator[](size - 1);
}

template <typename Data>
inline Data& LinearContainer<Data>::Back() {
    return operator[](size - 1);
}

//Traverse e Map
template <typename Data>
inline void LinearContainer<Data>::Traverse(TraverseFun f) const{
    PreOrderTraverse(f);
}

template <typename Data>
inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun f) const{
    for(unsigned long int i = 0; i < size; i++) {
        f(operator[](i));
    }
}

template <typename Data>
inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun f) const{
    for(unsigned long int i = size; i > 0; i--) {
        f(operator[](i));
    }
}

template <typename Data>
inline void LinearContainer<Data>::Map(MapFun f) {
    PreOrderMap(f);
}

template <typename Data>
inline void LinearContainer<Data>::PreOrderMap(MapFun f) {
    for(unsigned long int i = 0; i < size; i++) {
        f(operator[](i));
    }
}

template <typename Data>
inline void LinearContainer<Data>::PostOrderMap(MapFun f) {
    for(unsigned long int i = size; i > 0; i--) {
        f(operator[](i));
    }
}

//Sortable
template <typename Data>
void SortableLinearContainer<Data>::Sort() noexcept {
    QuickSort(0, size - 1);
}

template <typename Data>
void SortableLinearContainer<Data>::QuickSort(unsigned long int p, unsigned long int r) noexcept {
    if (p < r) {
        unsigned long int q = Partition(p, r);
        QuickSort(p, q);
        QuickSort(q+1, r);
    }
}

template <typename Data>
unsigned long int SortableLinearContainer<Data>::Partition(unsigned long int p, unsigned long int r) noexcept {
    Data x = operator[](p);
    unsigned long int i = p-1;
    unsigned long int j = r+1;

    do {
        do { j--; }
        while (x < operator[](j));

        do { i++; }
        while (x > operator[](i));

        if (i < j) {
            std::swap(operator[](i), operator[](j));
        }
    }
    while (i < j);

    return j;
}

/* ************************************************************************** */

}
