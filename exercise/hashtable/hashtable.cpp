
namespace lasd {

/* ************************************************************************** */

//voglio che l'hashing piu i dati sono simili piu li mappa lontani

template <>
class Hashable<int> {
public:
    unsigned long operator()(const int& dat) const noexcept {
        //un hashable di interi faccio il prodotto, voglio perdere meno bit possibili, crea un numero col doppio di bit
        return (dat * dat);
    }
};

//hashing di float come due interi, viene prima trattato la parte intera come intero e poi la parte dopo la virgola come interi
template <>
class Hashable<double> {
public:
    unsigned long operator()(const double& dat) const noexcept {
        //floor arrotonda
        long previrgola = floor(dat);
        //nello standard di rappresentazione dei dati la parte dopo la virgola sono gli ultimi 24 bit.
        long postvirgola = pow(2, 24) * (dat - previrgola);

        return (previrgola * postvirgola);
    }
};

//tratto le stringhe come array
template <>
class Hashable<std::string> {
public:
    unsigned long operator()(const std::string& dat) const noexcept {
        unsigned long hash = 5381;                                      //magic number
        for (unsigned long i = 0; i < dat.length(); ++i){
            hash = (hash << 5) + dat[i];                           //shift a sinistra, moltiplicazione 2^5 per perdere meno bit possibili
        }

        return hash;
    }
};

/************** Hash Table ******************/
template <typename Data>
HashTable<Data>::HashTable(){
    a = randA(gen);
    b = randB(gen);
}

template <typename Data>
HashTable<Data>::HashTable(const HashTable<Data>& table){
    this->size = table.size;
    this->tableSize = table.tableSize;
    this->a = table.a;
    this->b = table.b;
}

template <typename Data>
HashTable<Data>::HashTable(HashTable<Data>&& table) noexcept {
    std::swap(a, table.a);
    std::swap(b, table.b);
    std::swap(size, table.size);
    std::swap(tableSize, table.tableSize);
}

template <typename Data>
HashTable<Data>& HashTable<Data>::operator=(const HashTable<Data>& table){
    this->size = table.size;
    this->tableSize = table.tableSize;
    this->a = table.a;
    this->b = table.b;

    return *this;
}

template <typename Data>
HashTable<Data>& HashTable<Data>::operator=(HashTable<Data>&& table) noexcept{
    std::swap(a, table.a);
    std::swap(b, table.b);
    std::swap(size, table.size);
    std::swap(tableSize, table.tableSize);

    return *this;
}

template <typename Data>
unsigned long HashTable<Data>::HashKey(const Data& dat) const noexcept{
    return HashKey(encodingHash(dat));
}

template <typename Data>
unsigned long HashTable<Data>::HashKey(unsigned long encoding) const noexcept{
    return (((a * encoding + b) % prime) % tableSize);
}

/* ************************************************************************** */

}
