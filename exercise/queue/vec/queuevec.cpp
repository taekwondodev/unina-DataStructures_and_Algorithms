
namespace lasd {

/* ************************************************************************** */

// ...   array circolare con sentinella (non viene saturata) con memoria dinamica -> migliore perchè non devo gestire i casi in cui è pieno o vuoto
//Riesce a circolare grazie all'operazione %=size; che controlla se è alla fine e lo riporta all'inizio.
//Ad ogni rimozione head aumenta e ad ogni inserimento tail aumenta

template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data>& con) : Vector<Data>(con.Size() + 1){   //aumento  perchè aggiungo la sentinella
    unsigned long int index = 1;                                                                 //1 perchè così il primo elemento è la sentinella

    con.Traverse(
        [this, &index](const Data& dat) {
            this->elements[index++] = dat;
        }
    );

    tail = size - 1;

    Vector<Data>::Resize(size * 2);           //perchè voglio un array pieno a metà
}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data>&& con) : Vector<Data>(con.Size() + 1) {        //aumento perchè aggiungo la sentinella
    unsigned long int index = 1;                                                                //1 perchè il primo elemento è la sentinella

    con.Map(
        [this, &index](Data& dat) {
            this->elements[index++] = std::move(dat);
        } 
    );
    
    tail = size - 1;                          

    Vector<Data>::Resize(size * 2);          //perchè voglio un array pieno a metà
}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& que) : Vector<Data>(que) {
    this->head = que.head;
    this->tail = que.tail;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& que) noexcept : Vector<Data>(std::move(que)) {
    std::swap(this->head, que.head);
    std::swap(this->tail, que.tail);
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& que) {
    Vector<Data>::operator=(que);
    this->head = que.head;
    this->tail = que.tail;

    return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& que) noexcept {
    Vector<Data>::operator=(std::move(que));
    std::swap(this->head, que.head);
    std::swap(this->tail, que.tail);

    return *this;
}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& que) const noexcept {
    if (Size() == que.Size()) {                      //il numero di elementi escluso sentinella
        unsigned long int q1 = this->head;           //per scorrere le code
        unsigned long int q2 = que.head;
        for (; q1 < this->tail; ++q1, ++q2) {        //aumento prima perchè non deve controllare la sentinella
            if (elements[q1] != que.elements[q2]) {
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
inline bool QueueVec<Data>::operator!=(const QueueVec<Data>& que) const noexcept {
    return !(*this == que);
}

template <typename Data>
const Data& QueueVec<Data>::Head() const {
    if (head != tail) {
        return elements[head];
    }
    else {
        throw std::length_error("Access to an Empty Queue");
    }
}

template <typename Data>
Data& QueueVec<Data>::Head() {
    if (head != tail) {
        return elements[head];
    }
    else {
        throw std::length_error("Access to an Empty Queue");
    }
}

template <typename Data>
void QueueVec<Data>::Dequeue() {
    if (head != tail) {
        Reduce();
        head++;
        head %= size;     //head deve aumentare dopo la rimozione, facendo così se è arrivato alla fine ricomincia il ciclo
    }
    else {
        throw std::length_error("Access to an Empty Queue");
    }
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
    if (head != tail) {
        Reduce();
        Data dat(std::move(elements[head]));
        head++;
        head %= size;

        return dat;
    }
    else {
        throw std::length_error("Access to an Empty Queue");
    }
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& dat) {
    Expand();
    elements[tail] = dat;
    tail++;

    tail %= size;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& dat) {
    Expand();
    elements[tail] = std::move(dat);
    tail++;

    tail %= size;
}

template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    return (head == tail);
}

template <typename Data>
unsigned long int QueueVec<Data>::Size() const noexcept {
    return (((size + tail) - head) % size);                  //returna la size di un array circolare - la sentinella
}

template <typename Data>
void QueueVec<Data>::Clear() {          //INSICURO SUL 4
    head = tail = 0;
    Vector<Data>::Resize(1);            //non c'è bisogno che faccio la Clear di Vector per come ho definito Resize()
}

template <typename Data>
void QueueVec<Data>::Expand() {
    unsigned long int num = Size();

    if (num + 1 == size){                 //num + 1 perchè include la sentinella
        Resize(size * 2, num);
    }
}

template <typename Data>
void QueueVec<Data>::Reduce() {
    unsigned long int num = Size();

    if (num + 1 == size / 4) {            //num + 1 perchè include la sentinella
        Resize(size / 2, num);
    }
}

template <typename Data>
void QueueVec<Data>::Resize(unsigned long int newsize, unsigned long int num) {     //num è il numero di elementi - sentinella
    Data* tmp_elements = new Data[newsize];                                         //creo un array temporaneo
    unsigned long int end_loop = (num <= newsize) ? num : newsize;                  //quanti cicli devo fare

    unsigned long int q1 = this->head;                                              //per scorrere le code
    unsigned long int q2 = 0;
    for(; q2 < end_loop; ++q1 %= size, ++q2 %= newsize){
        std::swap(elements[q1], tmp_elements[q2]);
    }

    std::swap(elements, tmp_elements);                                              //scambio i due array perchè quello che voglio è il tmp

    delete[] tmp_elements;
    head = 0;
    tail = num;
    size = newsize;
}
/* ************************************************************************** */

}
