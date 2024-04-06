
namespace lasd {

/* ************************************************************************** */

// ...
template <typename Data>
inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& con) {
    bool success = true;

    con.Traverse(
        [this, &success](const Data& dat){
            success &= Insert(dat);                    //&= operazione AND bit a bit
        }
    );

    return success;
}

template <typename Data>
inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& con) {
    bool success = true;

    con.Map(
        [this, &success](Data& dat){
            success &= Insert(std::move(dat));
        }
    );

    return success;
}

template <typename Data>
inline bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& con) {
    bool success = true;

    con.Traverse(
        [this, &success](const Data& dat){
            success &= Remove(dat);
        }
    );

    return success;
}

template <typename Data>
inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& con) {
    bool success = false;

    con.Traverse(
        [this, &success](const Data& dat){
            success |= Insert(dat);
        }
    );

    return success;
}

template <typename Data>
inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& con) {
    bool success = false;

    con.Map(
        [this, &success](Data& dat){
            success |= Insert(std::move(dat));
        }
    );

    return success;
}

template <typename Data>
inline bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& con) {
    bool success = false;

    con.Traverse(
        [this, &success](const Data& dat){
            success |= Remove(dat);
        }
    );

    return success;
}
/* ************************************************************************** */

}
