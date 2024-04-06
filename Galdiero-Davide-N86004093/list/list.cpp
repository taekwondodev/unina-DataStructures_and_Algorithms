
namespace lasd {

/* ************************************************************************** */

// ...
template <typename Data>
List<Data>::Node::Node(const Data& dat){
    this->element = dat;
}

template <typename Data>
List<Data>::Node::Node(Data&& dat) noexcept{
    std::swap(this->element, dat);
}

template <typename Data>
List<Data>::Node::Node(const Node& nod){
    this->element = nod.element;
}

template <typename Data>
List<Data>::Node::Node(Node&& nod) noexcept {
    std::swap(element, nod.element);
    std::swap(next, nod.next);
}

template <typename Data>
List<Data>::Node::~Node(){
    delete next;
}

template <typename Data>
bool List<Data>::Node::operator==(const Node& nod) const noexcept{
    if ((this->element == nod.element) && ((this->next == nullptr && nod.next == nullptr) || (this->next != nullptr && nod.next != nullptr))) {
        return true;
    }
    else {
        return false;
    }
}

template <typename Data>
inline bool List<Data>::Node::operator!=(const Node& nod) const noexcept{
    return !(*this == nod);
}

template <typename Data>
typename List<Data>::Node* List<Data>::Node::Copy(Node* tail){       //copia un nodo in coda, se non è l'ultimo scorre i nodi
    if (this->next == nullptr){                                      
        return tail;
    }
    else {
        Node* nod = new Node(this->element);
        nod->next = this->next->Copy(tail);

        return nod;
    }
}

//List
template <typename Data>
List<Data>::List(const TraversableContainer<Data>& con){
    con.Traverse(
        [this](const Data& dat){
            InsertAtBack(dat);
        }
    );
}

template <typename Data>
List<Data>::List(MappableContainer<Data>&& con){
    con.Map(
        [this](Data& dat){
            InsertAtBack(std::move(dat));
        }
    );
}

template <typename Data>                     //copy constructor 
List<Data>::List(const List& l){
    if (l.tail != nullptr){                  //se l ha almeno un elemento
        for(unsigned long int i = 0; i < l.size; i++){
            this->tail = new Node(*l.tail);
            this->head = l.head->Copy(this->tail);
        }

        this->size = l.size;
    }
}

template <typename Data>                        //move constructor -> scambio puntatori e size
List<Data>::List(List&& l) noexcept{
    std::swap(this->head, l.head);
    std::swap(this->tail, l.tail);
    std::swap(this->size, l.size);
}

template <typename Data>
List<Data>::~List(){
    delete head;
}

template <typename Data>                                    //copy assignment
List<Data>& List<Data>::operator=(const List<Data>& l){
    List<Data>* tmp_l = new List<Data>(l);           //scambio le due liste, solo che per non modificare l, creo una temporanea
    std::swap(*tmp_l, *this);

    delete tmp_l;

    return *this;
}

template <typename Data>
List<Data>& List<Data>::operator=(List<Data>&& l) noexcept{
    std::swap(this->head, l.head);
    std::swap(this->tail, l.tail);                             //move constructor + riferimento
    std::swap(this->size, l.size);   

    return *this;
}

template <typename Data>
bool List<Data>::operator==(const List<Data>& l) const noexcept{
    if ((this->size == l.size) && (this->head == l.head) && (this->tail == l.tail)){
        return true;
    }
    else{
        return false;
    }
}

template <typename Data>
inline bool List<Data>::operator!=(const List<Data>& l) const noexcept{
    return !(*this==l);
}

template <typename Data>
void List<Data>::InsertAtFront(const Data& dat){
    Node* tmp = new Node(dat);
    tmp->next = this->head;
    this->head = tmp;

    if (this->tail == nullptr){              //aggiornamento dei puntatori e size
        this->tail = this->head;
    }

    this->size++;
}

template <typename Data>
void List<Data>::InsertAtFront(Data&& dat){
    Node* tmp = new Node(std::move(dat));
    tmp->next = this->head;
    this->head = tmp;

    if (this->tail == nullptr){              //aggiornamento dei puntatori e size
        this->tail = this->head;
    }

    this->size++;
}

template <typename Data>
void List<Data>::RemoveFromFront(){
    if (this->head != nullptr){                          //se lista non vuota
        Node* tmp = this->head;
        if (this->tail == this->head){                   //se ha solo un elemento
            this->head = this->tail = nullptr;
        }
        else {
            this->head = this->head->next;
        }

        this->size--;

        tmp->next = nullptr;                 //devo fare questo step in più altrimenti elimina tutta la lista
        delete tmp;
    }
    else {
        throw std::length_error("Cant Remove Node from an Empty list");
    }

}

template <typename Data>
Data List<Data>::FrontNRemove(){
    if (this->head != nullptr){            //se lista non vuota
        Node* tmp = this->head;

        if (this->tail == this->head){     //se ha solo un elemento
            this->head = this->tail = nullptr;
        }
        else{
            this->head = this->head->next;
        }

        this->size--;

        tmp->next = nullptr;              //fino a qui come sopra, solo che returna element prima di essere distrutto
        Data dat(std::move(tmp->element));
        delete tmp;

        return dat;
    }
    else{
        throw std::length_error("Cant Remove Node from an Empty list");
    }
}

template <typename Data>
void List<Data>::InsertAtBack(const Data& dat){
    Node* tmp = new Node(dat);
    if (this->tail == nullptr){                   //se lista vuota
        this->head = tmp;
    }
    else{
        this->tail->next = tmp;                  //aggiorno il puntatore di coda
    }
    this->tail = tmp;                           //lo farei in entrambi i casi

    this->size++;
}


template <typename Data>
void List<Data>::InsertAtBack(Data&& dat){
    Node* tmp = new Node(std::move(dat));
    if (this->tail == nullptr){                   //se lista vuota
        this->head = tmp;
    }
    else{
        this->tail->next = tmp;                  //aggiorno il puntatore di coda
    }
    this->tail = tmp;                           //lo farei in entrambi i casi

    this->size++;
}

template <typename Data>
void List<Data>::Clear(){    //dopo una Clear non è anche de-allocata
    delete head;
    head = tail = nullptr;
    size = 0;
}

template <typename Data>
bool List<Data>::Insert(const Data& dat){
    Node* current_node = this->head;
    for(; current_node != nullptr; current_node = current_node->next){    //scorro la lista con un nodo temporaneo che tiene traccia
        if (current_node->element == dat){                             //di quello corrente per verificare se ci sono ripetizioni
            return false;                      
        }
    }

    InsertAtBack(dat);
    return true;
}

template <typename Data>
bool List<Data>::Insert(Data&& dat){
    Node* current_node = this->head;
    for(; current_node != nullptr; current_node = current_node->next){    //scorro la lista con un nodo temporaneo che tiene traccia
        if (current_node->element == dat){                             //di quello corrente per verificare se ci sono ripetizioni
            return false;                      
        }
    }

    InsertAtBack(std::move(dat));
    return true;
}

template <typename Data>
bool List<Data>::Remove(const Data& dat){
    Node* end = nullptr;
    Node** current_node = &this->head;            //puntatore che punta al puntatore head, più facile modificare head in un ciclo così

    for(; *current_node != nullptr; end = *current_node, current_node = &this->head->next){     //scorro lista e puntatore
        if ((*current_node)->element == dat){
            Node* tmp = *current_node;                                    //puntatore temporaneo e scorro current_node
            *current_node = tmp->next;

            tmp->next = nullptr;
            delete tmp;

            this->size--;

            if (this->tail == *current_node){            //se rimane un solo elemento
                tail = end;
            }

            return true;
        }
    }

    return false;
}

template <typename Data>
const Data& List<Data>::operator[](const unsigned long int index) const{
    if (index < this->size) {
        Node* current_node = this->head;

        for(unsigned long int i = 0; i < index; i++, current_node = current_node->next){}    //scorro la lista fino a quando i è = index
        return current_node->element;
    }
    else {
        throw std::out_of_range("Acces at the index is out of range");
    }
}

template <typename Data>
Data& List<Data>::operator[](const unsigned long int index){
    if (index < this->size) {
        Node* current_node = this->head;

        for(unsigned long int i = 0; i < index; i++, current_node = current_node->next){}    //scorro la lista fino a quando i è = index
        return current_node->element;
    }
    else {
        throw std::out_of_range("Acces at the index is out of range");
    }
}

template <typename Data>
inline const Data& List<Data>::Front() const{
    if (this->head != nullptr){         //se lista non vuota
        return this->head->element;
    }
    else {
        throw std::length_error("Access at Empty list");
    }
}

template <typename Data>
inline Data& List<Data>::Front() {
    if (this->head != nullptr){         //se lista non vuota
        return this->head->element;
    }
    else {
        throw std::length_error("Access at Empty list");
    }
}

template <typename Data>
inline const Data& List<Data>::Back() const{
    if (this->tail != nullptr) {
        return this->tail->element;
    }
    else {
        throw std::length_error("Access at Empty list");
    }
}

template <typename Data>
inline Data& List<Data>::Back() {
    if (this->tail != nullptr) {
        return this->tail->element;
    }
    else {
        throw std::length_error("Access at Empty list");
    }
}

//questo perchè ho piu copie dei vari Traverse e dei vari Map
template <typename Data>
inline void List<Data>::Traverse(TraverseFun f) const{
    PreOrderTraverse(f, this->head);
}

template <typename Data>
inline void List<Data>::PreOrderTraverse(TraverseFun f) const {
    PreOrderTraverse(f, this->head);
}

template <typename Data>
inline void List<Data>::PostOrderTraverse(TraverseFun f) const {
    PostOrderTraverse(f, this->head);
}

template <typename Data>
inline void List<Data>::Map(MapFun f){
    PreOrderMap(f, this->head);
}

template <typename Data>
inline void List<Data>::PreOrderMap(MapFun f){
    PreOrderMap(f, this->head);
}

template <typename Data>
inline void List<Data>::PostOrderMap(MapFun f){
    PostOrderMap(f, this->head);
}

//Overloading
template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun f, const Node* current_node) const{
    for(; current_node != nullptr; current_node = current_node->next){   //scorro la lista e applico TraverseFun
        f(current_node->element);
    }
}

template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun f, const Node* current_node) const{
    if (current_node != nullptr){
        PostOrderTraverse(f, current_node->next);            //gli do la testa, dalla testa arriva alla fine e poi inizia TraverseFun
        f(current_node->element);
    }

}

template <typename Data>
void List<Data>::PreOrderMap(MapFun f, Node* current_node){
    for(; current_node != nullptr; current_node = current_node->next){   //scorro la lista e applico MapFun
        f(current_node->element);
    }
}

template <typename Data>
void List<Data>::PostOrderMap(MapFun f, Node* current_node){
    if (current_node != nullptr){
        PostOrderMap(f, current_node->next);            //gli do la testa, dalla testa arriva alla fine e poi inizia MapFun
        f(current_node->element);
    }
}


/* ************************************************************************** */

}
