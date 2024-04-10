
namespace lasd {

/* ************************************************************************** */

// ...
//PreOrder
template <typename Data>
void PreOrderMappableContainer<Data>::Map(MapFun f) {
    PreOrderMap(f);
}

//PostOrder
template <typename Data>
void PostOrderMappableContainer<Data>::Map(MapFun f) {
    PostOrderMap(f);
}

//InOrder
template <typename Data>
void InOrderMappableContainer<Data>::Map(MapFun f) {
    InOrderMap(f);
}

//Breadth
template <typename Data>
void BreadthMappableContainer<Data>::Map(MapFun f) {
    BreadthMap(f);
}

/* ************************************************************************** */

}
