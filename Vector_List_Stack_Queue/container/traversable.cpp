
namespace lasd {

/* ************************************************************************** */

// ...
template <typename Data>
template <typename Accumulator>
inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> f, Accumulator acc) const {
    Traverse(
        [f, &acc](const Data& dat){
            acc = f(dat, acc);                                                     //exists con una qualsiasi operazione invece di |=
        }
    );

    return acc;
}

template <typename Data>
inline bool TraversableContainer<Data>::Exists(const Data& value) const noexcept {
    bool success = false;
    Traverse(
        [value, &success](const Data& dat) {                                                 //Funzione lambda: parentesi quadre = contesto
            success |= (dat==value);                                                         //uso il riferimento se voglio modificarlo
        }                                                                                // |= perchè basta che è true una volta
    );

    return success;
}

//PreOrder
template <typename Data>
template <typename Accumulator>
inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> f, Accumulator acc) const {
    PreOrderTraverse(
        [f, &acc](const Data& dat){
            acc = f(dat, acc);
        }
    );

    return acc;
}

template <typename Data>
inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun f) const {     //override perchè dall'heritage ho due copie di Traverse
    PreOrderTraverse(f);
}

//PostOrder
template <typename Data>
template <typename Accumulator>
inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> f, Accumulator acc) const {
    PostOrderTraverse(
        [f, &acc](const Data& dat) {
            acc = f(dat, acc);
        }
    );

    return acc;
}

template <typename Data>
inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun f) const {
    PostOrderTraverse(f);
}

//InOrder
template <typename Data>
template <typename Accumulator>
inline Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> f, Accumulator acc) const {
    InOrderTraverse(
        [f, &acc](const Data& dat) {
            acc = f(dat, acc);
        }
    );

    return acc;
}

template <typename Data>
inline void InOrderTraversableContainer<Data>::Traverse(TraverseFun f) const {
    InOrderTraverse(f);
}

//Breadth
template <typename Data>
template <typename Accumulator>
inline Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> f, Accumulator acc) const {
    BreadthTraverse(
        [f, &acc](const Data& dat) {
            acc = f(dat, acc);
        }
    );

    return acc;
}

template <typename Data>
inline void BreadthTraversableContainer<Data>::Traverse(TraverseFun f) const {
    BreadthTraverse(f);
}

/* ************************************************************************** */

}
