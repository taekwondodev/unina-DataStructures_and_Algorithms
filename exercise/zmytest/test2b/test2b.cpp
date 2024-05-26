#include <iostream>
#include <string.h>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

#include "../../container/container.hpp"
#include "../../container/dictionary.hpp"
#include "../../container/traversable.hpp"
#include "../../container/testable.hpp"
#include "../../container/mappable.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"
#include "../../binarytree/binarytree.hpp"
#include "../../iterator/iterator.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../bst/bst.hpp"

namespace t{
std::string zzchars {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
std::random_device rd4;
std::mt19937 generator4(rd4());

std::string rand_str4 (int length){
    std::string output (zzchars);
    std::shuffle(output.begin(), output.end(), generator4);
    return output.substr(0, length);
}

void pienoString(lasd::Vector<string>& v, unsigned int dim){
    for(unsigned int i=0; i < dim; i++)
    {
       v[i] = rand_str4(5);
    }
}

template<typename Data>
void pieno(lasd::Vector<Data>& v, unsigned int dim){
      Data dataRandom;
      srand ((unsigned int)time(NULL));
      std::string type_name = "";

      for(unsigned int i = 0; i < dim; i++)
      {
         dataRandom = (Data)rand() / 100 + 1;
         v[i] = dataRandom;
      }
}

void MenuBST(int n, int type){
    int scelta = -1;
    lasd::Vector<int> vecint(n);
    lasd::Vector<float> vecfloat(n);
    lasd::Vector<string> vecstring(n);

    if(type == 1)
      pieno(vecint, n);

    if(type == 2)
      pieno(vecfloat, n);

    if(type == 3)
      pienoString(vecstring, n);

    lasd::BST<int> bstint(vecint);
    lasd::BST<float> bstfloat(vecfloat);
    lasd::BST<string> bststring(vecstring);

    while (scelta != 0){
        cout << "Cosa vuoi testare?" << endl;

        cout << "1: Testa se i nodi sono sia Mutable che non Mutable" << endl;
        cout << "2: Testa se gli iteratori visitano correttamente" << endl;
        cout << "3: Testa le funzioni di Min e Max" << endl;
        cout << "4: Testa le funzioni di Successor e Predecessor" << endl;
        if (type == 1){ cout << "5: Testa il confronto tra iteratori" << endl; }
        if (type == 1){ cout << "6: Testa la Remove() di un nodo con due figli" << endl; }
        cout << "0: Per uscire dal test" << endl;
        cin >> scelta;
        cout << endl;

        if (scelta == 1){
          /* if (type == 1){
            int input = 0;
            cout << "La radice contiene: " << bstint.Root().Element() << endl;
            cout << "Elemento sinistro della radice: " << bstint.Root().LeftChild().Element() << endl;
            cout << "Inserisci il nuovo elemento: " << endl;
            cin >> input;
            bstint.Root().LeftChild().Element() = input;
            cout << "Controlla se è cambiato: " << bstint.Root().LeftChild().Element() << endl;

            cout << "Elemento destro della radice: " << bstint.Root().RightChild().Element() << endl;
            cout << "Inserisci il nuovo elemento: " << endl;
            cin >> input;
            bstint.Root().RightChild().Element() = input;
            cout << "Controlla se è cambiato: " << bstint.Root().RightChild().Element() << endl;
          }
          else if (type == 2){
            float input = 0.0;
            cout << "La radice contiene: " << bstfloat.Root().Element() << endl;
            cout << "Elemento sinistro della radice: " << bstfloat.Root().LeftChild().Element() << endl;
            cout << "Inserisci il nuovo elemento: " << endl;
            cin >> input;
            bstfloat.Root().LeftChild().Element() = input;
            cout << "Controlla se è cambiato: " << bstfloat.Root().LeftChild().Element() << endl;

            cout << "Elemento destro della radice: " << bstfloat.Root().RightChild().Element() << endl;
            cout << "Inserisci il nuovo elemento: " << endl;
            cin >> input;
            bstfloat.Root().RightChild().Element() = input;
            cout << "Controlla se è cambiato: " << bstfloat.Root().RightChild().Element() << endl;
          }
          else {
            string input = "";
            cout << "La radice contiene: " << bststring.Root().Element() << endl;
            cout << "Elemento sinistro della radice: " << bststring.Root().LeftChild().Element() << endl;
            cout << "Inserisci il nuovo elemento: " << endl;
            cin >> input;
            bststring.Root().LeftChild().Element() = input;
            cout << "Controlla se è cambiato: " << bststring.Root().LeftChild().Element() << endl;

            cout << "Elemento destro della radice: " << bststring.Root().RightChild().Element() << endl;
            cout << "Inserisci il nuovo elemento: " << endl;
            cin >> input;
            bststring.Root().RightChild().Element() = input;
            cout << "Controlla se è cambiato: " << bststring.Root().RightChild().Element() << endl;
          } */

          cout << "Test commentato perchè i nodi di un BST sono non-mutable" << endl;
          cout << "Correttamente veniva compilation error" << endl;
          cout << "Test mutable terminato" << endl; 
        }

        if (scelta == 2) {
          int test = -1;
          while (test != 0){
            cout << "Quale iteratore vuoi testare?" << endl;
            cout << "1: Preorder" << endl;
            cout << "2: Postorder" << endl;
            cout << "3: Inorder" << endl;
            cout << "4: Breadth" << endl;
            cout << "0: Per tornare al MenuBST" << endl;
            cin >> test;

            if (type == 1 && test == 1){
              cout << "Visita in PreOrder per verificare se è corretto con l'iteratore" << endl;
              bstint.PreOrderTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPreOrderIterator<int> preint1(bstint);
              while (!preint1.Terminated()){
                cout << "Elemento corrente: " << *preint1 << endl;
                ++preint1;
              }
              preint1.Reset();
            }
            else if (type == 2 && test == 1){
              cout << "Visita in PreOrder per verificare se è corretto con l'iteratore" << endl;
              bstfloat.PreOrderTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPreOrderIterator<float> prefloat(bstfloat);
              while (!prefloat.Terminated()){
                cout << "Elemento corrente: " << *prefloat << endl;
                ++prefloat;
              }
              prefloat.Reset();
            }
            else if (type == 3 && test == 1){
              cout << "Visita in PreOrder per verificare se è corretto con l'iteratore" << endl;
              bststring.PreOrderTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPreOrderIterator<string> prestring(bststring);
              while (!prestring.Terminated()){
                cout << "Elemento corrente: " << *prestring << endl;
                ++prestring;
              }
              prestring.Reset();
            }
            else if (type == 1 && test == 2){
              cout << "Visita in Postorder per verificare se è corretto con l'iteratore" << endl;
              bstint.PostOrderTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPostOrderIterator<int> postint(bstint);
              while (!postint.Terminated()){
                cout << "Elemento corrente: " << *postint << endl;
                ++postint;
              }
              postint.Reset();
            }
            else if (type == 2 && test == 2){
              cout << "Visita in Postorder per verificare se è corretto con l'iteratore" << endl;
              bstfloat.PostOrderTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPostOrderIterator<float> postfloat(bstfloat);
              while (!postfloat.Terminated()){
                cout << "Elemento corrente: " << *postfloat << endl;
                ++postfloat;
              }
              postfloat.Reset();
            }
            else if (type == 3 && test == 2){
              cout << "Visita in Postorder per verificare se è corretto con l'iteratore" << endl;
              bststring.PostOrderTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPostOrderIterator<string> poststring(bststring);
              while (!poststring.Terminated()){
                cout << "Elemento corrente: " << *poststring << endl;
                ++poststring;
              }
              poststring.Reset();
            }
            else if (type == 1 && test == 3){
              cout << "Visita in InOrder per verificare se è corretto con l'iteratore" << endl;
              bstint.InOrderTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTInOrderIterator<int> inoint(bstint);
              while (!inoint.Terminated()){
                cout << "Elemento corrente: " << *inoint << endl;
                ++inoint;
              }
              inoint.Reset();
            }
            else if (type == 2 && test == 3){
              cout << "Visita in InOrder per verificare se è corretto con l'iteratore" << endl;
              bstfloat.InOrderTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTInOrderIterator<float> inofloat(bstfloat);
              while (!inofloat.Terminated()){
                cout << "Elemento corrente: " << *inofloat << endl;
                ++inofloat;
              }
              inofloat.Reset();
            }
            else if (type == 3 && test == 3){
              cout << "Visita in InOrder per verificare se è corretto con l'iteratore" << endl;
              bststring.InOrderTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTInOrderIterator<string> inostring(bststring);
              while (!inostring.Terminated()){
                cout << "Elemento corrente: " << *inostring << endl;
                ++inostring;
              }
              inostring.Reset();
            }
            else if (type == 1 && test == 4){
              cout << "Visita in Breadth per verificare se è corretto con l'iteratore" << endl;
              bstint.BreadthTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTBreadthIterator<int> breint(bstint);
              while (!breint.Terminated()){
                cout << "Elemento corrente: " << *breint << endl;
                ++breint;
              }
              breint.Reset();
            }
            else if (type == 2 && test == 4){
              cout << "Visita in Breadth per verificare se è corretto con l'iteratore" << endl;
              bstfloat.BreadthTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTBreadthIterator<float> brefloat(bstfloat);
              while (!brefloat.Terminated()){
                cout << "Elemento corrente: " << *brefloat << endl;
                ++brefloat;
              }
              brefloat.Reset();
            }
            else if (type == 3 && test == 4){
              cout << "Visita in Breadth per verificare se è corretto con l'iteratore" << endl;
              bststring.BreadthTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTBreadthIterator<string> brestring(bststring);
              while (!brestring.Terminated()){
                cout << "Elemento corrente: " << *brestring << endl;
                ++brestring;
              }
              brestring.Reset();
            }
          }
        }

        if (scelta == 3){
          cout << "Test MINMAX" << endl;
          int test = -1;
          while (test != 0){
            cout << "1: Test Min() e RemoveMin()" << endl;
            cout << "2: Test Max() e RemoveMax()" << endl;
            cout << "0: Per tornare indietro" << endl;
            cin >> test;
            
            if (type == 1 && test == 1){
              cout << "Il minimo corrente dell'albero è: " << bstint.Min() << endl;
              bstint.RemoveMin();
              cout << "Avvenuta rimozione del minimo" << endl;
              cout << "Il minimo corrente dell'albero è: " << bstint.Min() << endl;
              cout << "Fine test Min" << endl;
            }
            else if (type == 2 && test == 1){
              cout << "Il minimo corrente dell'albero è: " << bstfloat.Min() << endl;
              bstfloat.RemoveMin();
              cout << "Avvenuta rimozione del minimo" << endl;
              cout << "Il minimo corrente dell'albero è: " << bstfloat.Min() << endl;
              cout << "Fine test Min" << endl;
            }
            else if (type == 3 && test == 1){
              cout << "Il minimo corrente dell'albero è: " << bststring.Min() << endl;
              bststring.RemoveMin();
              cout << "Avvenuta rimozione del minimo" << endl;
              cout << "Il minimo corrente dell'albero è: " << bststring.Min() << endl;
              cout << "Fine test Min" << endl;
            }
            else if (type == 1 && test == 2){
              cout << "Il massimo corrente dell'albero è: " << bstint.Max() << endl;
              bstint.RemoveMax();
              cout << "Avvenuta rimozione del massimo" << endl;
              cout << "Il massimo corrente dell'albero è: " << bstint.Max() << endl;
              cout << "Fine test Max" << endl;
            }
            else if (type == 2 && test == 2){
              cout << "Il massimo corrente dell'albero è: " << bstfloat.Max() << endl;
              bstfloat.RemoveMax();
              cout << "Avvenuta rimozione del massimo" << endl;
              cout << "Il massimo corrente dell'albero è: " << bstfloat.Max() << endl;
              cout << "Fine test Max" << endl;
            }
            else if (type == 3 && test == 2){
              cout << "Il massimo corrente dell'albero è: " << bststring.Max() << endl;
              bststring.RemoveMax();
              cout << "Avvenuta rimozione del massimo" << endl;
              cout << "Il massimo corrente dell'albero è: " << bststring.Max() << endl;
              cout << "Fine test Max" << endl;
            }
          }
        }
        if (scelta == 4){
          cout << "Test SuccessorPredecessor" << endl;
          int test = -1;
          while (test != 0){
            cout << "1: Test Successor e RemoveSuccessor" << endl;
            cout << "2: Test Predecessor e RemovePredecessor" << endl;
            cout << "0: Per tornare indietro" << endl;
            cin >> test;

            if (type == 1 && test == 1){
              cout << "Il successore corrente di 4 nell'albero è: " << bstint.Successor(4) << endl;
              bstint.RemoveSuccessor(4);
              cout << "Avvenuta rimozione successore di 4" << endl;
              cout << "Il successore corrente di 4 nell'albero è: " << bstint.Successor(4) << endl;
              cout << "Test Successor terminato" << endl;
            }
            else if (type == 2 && test == 1){
              cout << "Il successore corrente di 4.1 nell'albero è: " << bstfloat.Successor(4.1) << endl;
              bstfloat.RemoveSuccessor(4.1);
              cout << "Avvenuta rimozione successore di 4.1" << endl;
              cout << "Il successore corrente di 4.1 nell'albero è: " << bstfloat.Successor(4.1) << endl;
              cout << "Test Successor terminato" << endl;
            }
            else if (type == 3 && test == 1){
              cout << "Il successore corrente di A nell'albero è: " << bststring.Successor("A") << endl;
              bststring.RemoveSuccessor("A");
              cout << "Avvenuta rimozione successore di A" << endl;
              cout << "Il successore corrente di A nell'albero è: " << bststring.Successor("A") << endl;
              cout << "Test Successor terminato" << endl;
            }
            else if (type == 1 && test == 2){
              cout << "Il predecessore corrente di 4 nell'albero è: " << bstint.Predecessor(4) << endl;
              bstint.RemovePredecessor(4);
              cout << "Avvenuta rimozione predecessore di 4" << endl;
              cout << "Il predecessore corrente di 4 nell'albero è: " << bstint.Predecessor(4) << endl;
              cout << "Test Predecessor terminato" << endl;
            }
            else if (type == 2 && test == 2){
              cout << "Il predecessore corrente di 4.1 nell'albero è: " << bstfloat.Predecessor(4.1) << endl;
              bstfloat.RemovePredecessor(4.1);
              cout << "Avvenuta rimozione predecessore di 4.1" << endl;
              cout << "Il predecessore corrente di 4.1 nell'albero è: " << bstfloat.Predecessor(4.1) << endl;
              cout << "Test Predecessor terminato" << endl;
            }
            else if (type == 3 && test == 2){
              cout << "Il predecessore corrente di A nell'albero è: " << bststring.Predecessor("A") << endl;
              bststring.RemovePredecessor("A");
              cout << "Avvenuta rimozione predecessore di A" << endl;
              cout << "Il predecessore corrente di A nell'albero è: " << bststring.Predecessor("A") << endl;
              cout << "Test Predecessor terminato" << endl;
            }
          }
        }
        
        if (scelta == 5){
          lasd::BTPreOrderIterator<int> preint1(bstint);
          lasd::BTPreOrderIterator<int> preint2(bstint);

          cout << "Test confronto PreOrderIterator di interi" << endl;
          if (preint1 == preint2){
            cout << "Iteratori uguali" << endl;
          }
          else {
            cout << "Iteratori diversi" << endl;
          }
          ++preint2;
          cout << "Scorro in avanti il secondo iteratore" << endl;
          if (preint1 == preint2){
            cout << "Iteratori uguali" << endl;
          }
          else {
            cout << "Iteratori diversi" << endl;
          }
          cout << "Test confronto terminato" << endl;
        }

        if (scelta == 6){
          cout << "Inizio test Remove() di un nodo con due figli" << endl;
          lasd::Vector<int> vec7(7);
          vec7[0] = 5;
          vec7[1] = 2;
          vec7[2] = 9;
          vec7[3] = 8;
          vec7[4] = 14;
          vec7[5] = 11;
          vec7[6] = 12;

          lasd::BST<int> bst7(vec7);
          cout << "uso di una traverse in ampiezza per trovare il nodo con due figli" << endl;
          bst7.BreadthTraverse([](const int& dat){
                cout << dat << " ";
              });
          cout << endl;

          cout << "Rimozione di 9" << endl;
          int y = -1;
          cout << "Scrivi il dato che vuoi rimuovere" << endl;
          cin >> y;
          if (bst7.Exists(y))
          bst7.Remove(y);
          else {
            cout << "y non esiste" << endl;
            cout << "Rifai il test" << endl;
          }

          cout << "uso di una traverse in ampiezza per vedere se è corretta" << endl;
          bst7.BreadthTraverse([](const int& dat){
                cout << dat << " ";
              });
          cout << endl;
          cout << "Test Remove con due figli terminato" << endl;
        }
    }

}


void testPersonal2B(){
    cout << "Benvenuto nel test2B" << endl;

    int n = 0; int chooseType = 0;
    cout << "Che tipo di dati vuoi utilizzare in questo albero?" << endl;
    cout << "1: int" << endl;
    cout << "2: float" << endl;
    cout << "3: string" << endl;
    cin  >> chooseType;
    cout << "Quanti elementi vuoi inserire all'interno dell'albero?" << endl;
    cin  >> n;

    MenuBST(n, chooseType);

    cout << "Test terminato." << endl;
    cout << "Stai per tornare nel Menu" << endl;
}

}