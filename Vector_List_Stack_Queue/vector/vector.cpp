
namespace lasd {

/* ************************************************************************** */

// ...
template <typename Data>
Vector<Data>::Vector(const unsigned long int num){
    this->size = num;
    this->elements = new Data[this->size]{};
}

template <typename Data>
Vector<Data>::Vector(const TraversableContainer<Data>& con) : Vector<Data>(con.Size()) {       //Creo un vettore a partire da TraversableContainer
    unsigned long int index = 0;

    con.Traverse(
        [this, &index](const Data& dat) {
            this->elements[index++] = dat;
        }
    );
}

template <typename Data>
Vector<Data>::Vector(MappableContainer<Data>&& con) : Vector<Data>(con.Size()) {
    unsigned long int index = 0;

    con.Map(
        [this, &index](Data& dat) {
            this->elements[index++] = std::move(dat);
        } 
    );
}

template <typename Data>
Vector<Data>::Vector(const Vector<Data>& arr) {
    this->size = arr.size;
    this->elements = new Data[size];

    std::copy(arr.elements, arr.elements + arr.size, elements); //i parametri sono: -puntatore all'origine sorgente
                                                                //                  -puntatore alla fine sorgente
                                                                //                  -puntatore all'origine destinazione
}

template <typename Data>
Vector<Data>::Vector(Vector<Data>&& arr) noexcept {
    std::swap(this->size, arr.size); //scambio i puntatori e le size
    std::swap(this->elements, arr.elements);
}

template <typename Data>
Vector<Data>::~Vector(){
    delete[] this->elements;
}

template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& arr) {
    Vector<Data>* tmp_arr = new Vector<Data>(arr);  //ho bisogno di un puntatore che punta arr come this

    std::swap(*tmp_arr, *this);  //scambio arr e il mio vector attraverso i loro puntatori

    delete tmp_arr;
    return *this;
}

template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& arr) noexcept {

    //Move constructor + return riferimento
    std::swap(size, arr.size);
    std::swap(elements, arr.elements);

    return *this;
}

template <typename Data>
bool Vector<Data>::operator==(const Vector<Data>& arr) const noexcept {
    if (this->size == arr.size) {
        for(unsigned long int i = 0; i < this->size; i++) {
            if (elements[i] != arr[i]) {
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
inline bool Vector<Data>::operator!=(const Vector<Data>& arr) const noexcept {
    return !(*this == arr);
}

template<typename Data>
void Vector<Data>::Clear() {
    delete[] elements;
    this->elements = nullptr;
    this->size = 0;
}

template<typename Data>
void Vector<Data>::Resize(const unsigned long int newsize) {
    if (newsize == 0) {
        Clear();
    }
    else if (size != newsize) {
        unsigned long int end_loop = (size < newsize) ? size : newsize; //quanti cicli devo fare? -> indice più piccolo

        Data* tmp_elements = new Data[newsize]{};
        for(unsigned long int i = 0; i < end_loop; i++) {  //scambio di elementi
            std::swap(elements[i], tmp_elements[i]);
        }

        std::swap(elements, tmp_elements);   //il mio array finale era quello temporaneo, non più ora

        size = newsize;
        delete[] tmp_elements;        //aggiornamento size e deallocazione del temporaneo
    }
}

template<typename Data>
const Data& Vector<Data>::operator[](const unsigned long int index) const {
    if (index < size) {
        return elements[index];
    }
    else {
        throw std::out_of_range("Access at index is out of range");
    }
}

template<typename Data>
Data& Vector<Data>::operator[](const unsigned long int index) {
    if (index < size) {
        return elements[index];
    }
    else {
        throw std::out_of_range("Access at index is out of range");
    }
}

template <typename Data>
const Data& Vector<Data>::Front() const {             //override per cambiare messaggio di errore
    if (size != 0) {
        return elements[0];
    }
    else {
        throw std::length_error("Access to an empty array");
    }
}

template <typename Data>
Data& Vector<Data>::Front() {
    if (size != 0) {
        return elements[0];
    }
    else {
        throw std::length_error("Access to an empty array");
    }
}

template <typename Data>
const Data& Vector<Data>::Back() const {
    if (size != 0) {
        return elements[size - 1];
    }
    else {
        throw std::length_error("Access to an empty array");
    }
}

template <typename Data>
Data& Vector<Data>::Back() {
    if (size != 0) {
        return elements[size - 1];
    }
    else {
        throw std::length_error("Access to an empty array");
    }
}

//Sortable -> molti richiamo quelli di Vector
template <typename Data>
SortableVector<Data>::SortableVector(const unsigned long int num) : Vector<Data>(num){}

template <typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& con) : Vector<Data>(con) {
    this->Sort();
}

template <typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& con) : Vector<Data>(std::move(con)) {
    this->Sort();
}

template <typename Data>
SortableVector<Data>::SortableVector(const SortableVector<Data>& arr) : Vector<Data>(arr) {}

template <typename Data>
SortableVector<Data>::SortableVector(SortableVector<Data>&& arr) noexcept : Vector<Data>(std::move(arr)) {}

template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data>& arr) {
    Vector<Data>::operator=(arr);

    return *this;
}

template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector&& arr) noexcept {
    Vector<Data>::operator=(std::move(arr));

    return *this;
}
/* ************************************************************************** */

}
