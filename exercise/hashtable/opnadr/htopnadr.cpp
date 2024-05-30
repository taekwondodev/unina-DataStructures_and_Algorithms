
namespace lasd {

/* ************************************************************************** */
template <typename Data>
HashTableOpnAdr<Data>::HashNode::HashNode(const HashTableOpnAdr<Data>::HashNode& hn) : HashNode(){
    if (hn.state == Status::Occupied){
        element = hn.element;
        state = hn.state;
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashNode::HashNode(HashTableOpnAdr<Data>::HashNode&& hn) noexcept : HashNode() {
    if (hn.state == Status::Occupied){
        std::swap(element, hn.element);
        std::swap(state, hn.state);
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashNode& HashTableOpnAdr<Data>::HashNode::operator=(const HashTableOpnAdr<Data>::HashNode& hn){
    if (hn.state == Status::Occupied){
        element = hn.element;
        state = hn.state;
    }
    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>::HashNode& HashTableOpnAdr<Data>::HashNode::operator=(HashTableOpnAdr<Data>::HashNode&& hn) noexcept {
    if (hn.state == Status::Occupied){
        std::swap(element, hn.element);
        std::swap(state, hn.state);
    }
    return *this;
}

template <typename Data>
bool HashTableOpnAdr<Data>::HashNode::operator==(const HashTableOpnAdr<Data>::HashNode& hn) const noexcept {
    if (state == Status::Occupied && hn.state == Status::Occupied){
        return element == hn.element;
    }
      else {
        return ((state == Status::Empty && hn.state == Status::Empty) || (state == Status::Removed && hn.state == Status::Removed));
    }
}

template <typename Data>
inline bool HashTableOpnAdr<Data>::HashNode::operator!=(const HashTableOpnAdr<Data>::HashNode& hn) const noexcept{
    return !(*this == hn);
}

/******************** HASHTABLE *******************/
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() : HashTable<Data>() {
    table.Resize(tableSize);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long size) : HashTable<Data>(){
    tableSize = size;
    table.Resize(tableSize);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& con) : HashTableOpnAdr(){
    con.Traverse(
        [this](const Data& dat){
            Insert(dat);
        }
    );
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long size, const TraversableContainer<Data>& con) : HashTableOpnAdr(size){
    con.Traverse(
        [this](const Data& dat){
            Insert(dat);
        }
    );
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& con) : HashTableOpnAdr() {
    con.Map(
        [this](Data& dat){
            Insert(std::move(dat));
        }
    );
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long size, MappableContainer<Data>&& con) : HashTableOpnAdr(size) {
    con.Map(
        [this](Data& dat){
            Insert(std::move(dat));
        }
    );
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& ht) : HashTable<Data>(ht){
    table = ht.table;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept : HashTable<Data>(std::move(ht)) {
    std::swap(table, ht.table);
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& ht) {
    HashTableOpnAdr* tmp = new HashTableOpnAdr(ht);
    std::swap(*tmp, *this);
    delete tmp;

    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& ht) noexcept {
    HashTable<Data>::operator=(std::move(ht));
    std::swap(table, ht.table);

    return *this;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& ht) const noexcept {
    if (this->size == ht.size){
        bool equal = true;
        table.Traverse(
            [ht, &equal](const typename HashTableOpnAdr<Data>::HashNode& hn){             //deve controllare per ogni elemento delle liste di table se esiste in ht
                if (hn.state == Status::Occupied){
                    equal &= ht.Exists(hn.element);
                }
            }
        );

        return equal;
    }
    else {
        return false;
    }
}

template <typename Data>
inline bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& dat){
    unsigned long j = FindEmpty(dat);

    if (j != tableSize){
        table[j] = HashNode(dat);
        ++this->size;
        Expand();
        return true;
    }
    else {
        return false;
    }
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& dat){
    unsigned long j = FindEmpty(dat);

    if (j != tableSize){
        table[j] = HashNode(std::move(dat));
        ++this->size;
        Expand();
        return true;
    }
    else {
        return false;
    }
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& dat){
    unsigned long j = Find(dat);

    if (j != tableSize){
        table[j].state = Status::Removed;

        --this->size;
        Reduce();
        return true;
    }
    else {
        return false;
    }
}

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& dat) const noexcept{
    return (Find(dat) != tableSize);
}

template <typename Data>
void HashTableOpnAdr<Data>::Resize(const unsigned long newsize) {
    if (newsize == 0){
        Clear();
    }

    unsigned long setSize = this->size * 2;                                       //limite minimo tableSize
    if (newsize > setSize) {
        setSize = newsize;
    }
    HashTableOpnAdr* tmp = new HashTableOpnAdr(setSize);

    table.Map(
        [tmp](typename HashTableOpnAdr<Data>::HashNode& hn){                //copia solo se il nodo non era cancellato o rimosso
            if (hn.state == Status::Occupied){
                tmp->Insert(std::move(hn.element));
            }
        }
    );

    std::swap(*tmp, *this);
    delete tmp;
}

template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    for(unsigned long i = 0; i < tableSize; ++i){
        table[i].state = Status::Removed;
    }
    this->size = 0;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(unsigned long key, unsigned long probing) const noexcept {
    return (((key + (probing * probing + probing) / 2)) % tableSize);
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::Find(const Data& dat) const noexcept{
    unsigned long i = 0;
    unsigned long j;

    do {
        j = HashKey(HashKey(dat), i);

        if (table[j].state == Status::Empty){
            return tableSize;
        }

        if (table[j].state == Status::Occupied && table[j].element == dat){
            return j;
        }
        else { ++i; }
    }
    while (i < tableSize);

    return tableSize;
}

template <typename Data>
void HashTableOpnAdr<Data>::Remove(const Data& dat, unsigned long i){
    ++i;
    unsigned long j;

    do{
        j = HashKey(HashKey(dat), i);

        if (table[j].state == Status::Empty){
            return;
        }

        if (table[j].state == Status::Occupied && table[j].element == dat){
            table[j].state = Status::Removed;
            --this->size;
            return;
        }

        else { ++i; }
    }
    while(i < tableSize);

    return;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& dat) noexcept{
    unsigned long i = 0;

    do {
        unsigned long j = HashKey(HashKey(dat), i);
        
        if (table[j].state == Status::Occupied && table[j].element == dat){
            return tableSize;
        }
        //se è empty non c'è niente dopo
        else if (table[j].state == Status::Empty) {
            return j;
        }
        //se è removed inserisco ma devo controllare se c'è anche dopo
        else if (table[j].state == Status::Removed){
            Remove(dat, i);
            return j;
        }
        else { ++i; }
    }
    while (i < tableSize);

    return tableSize;
}

template <typename Data>
void HashTableOpnAdr<Data>::Expand() {
    if (this->size >= tableSize / 2) {
        Resize(tableSize * 2);
    }
}

template <typename Data>
void HashTableOpnAdr<Data>::Reduce(){
    if (this->size <= tableSize / 8){
        Resize(tableSize / 2);
    }
}

/* ************************************************************************** */

}
