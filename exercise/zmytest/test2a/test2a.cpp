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

#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../vector/vector.hpp"

namespace t {
std::string bchars {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
std::random_device rdb;
std::mt19937 generatorb(rdb());

std::string rand_strb (int length){
    std::string output (bchars);
    std::shuffle(output.begin(), output.end(), generatorb);
    return output.substr(0, length);
}

void riempiString(lasd::Vector<string>& v, unsigned int dim){
    for(unsigned int i=0; i < dim; i++)
    {
       v[i] = rand_strb(5);
    }
}

template<typename Data>
void riempi(lasd::Vector<Data>& v, unsigned int dim){
      Data dataRandom;
      srand ((unsigned int)time(NULL));
      std::string type_name = "";

      for(unsigned int i = 0; i < dim; i++)
      {
         dataRandom = (Data)rand() / 100 + 1;
         v[i] = dataRandom;
      }
}

void MenuVec(int type, int dim)
  {
    int scelta = -1;
    lasd::Vector<int> vecint(dim);
    lasd::Vector<float> vecfloat(dim);
    lasd::Vector<string> vecstring(dim);

    if(type == 1){
      riempi(vecint, dim);
    }

    if(type == 2){
      riempi(vecfloat, dim);
    }

    if(type == 3){
      riempiString(vecstring, dim);
    }

    lasd::BinaryTreeVec<int> treeint(vecint);
    lasd::BinaryTreeVec<float> treefloat(vecfloat);
    lasd::BinaryTreeVec<string> treestring(vecstring);
    cout << "Benevenuto nel menu del BinaryTreeVec" << endl;
    
    while(scelta != 0)
    {
      cout << endl;
      cout << "Cosa vuoi testare?" << endl;

      cout << "1: Navigazione Albero con gli Iteratori + Test Traverse" << endl;
      cout << "2: Testare le Map Function" << endl;
      cout << "3: Controllo di esistenza di un valore" << endl;
      cout << "4: Test mutable" << endl;
      cout << "0: Per uscire dal programma" << endl;
      cin >> scelta;
      cout << endl;

      if(scelta == 1)
      {
        int test = -1;
          while (test != 0){
            cout << "Quale iteratore vuoi testare?" << endl;
            cout << "1: Preorder" << endl;
            cout << "2: Postorder" << endl;
            cout << "3: Inorder" << endl;
            cout << "4: Breadth" << endl;
            cout << "0: Per tornare al Menu" << endl;
            cin >> test;

            if (type == 1 && test == 1){
              cout << "Visita in PreOrder per verificare se è corretto con l'iteratore" << endl;
              treeint.PreOrderTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPreOrderIterator<int> preorder_int(treeint);
              while (!preorder_int.Terminated()){
                cout << "Elemento corrente: " << *preorder_int << endl;
                ++preorder_int;
              }
              preorder_int.Reset();
            }
            else if (type == 2 && test == 1){
              cout << "Visita in PreOrder per verificare se è corretto con l'iteratore" << endl;
              treefloat.PreOrderTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPreOrderIterator<float> preorder_float(treefloat);
              while (!preorder_float.Terminated()){
                cout << "Elemento corrente: " << *preorder_float << endl;
                ++preorder_float;
              }
              preorder_float.Reset();
            }
            else if (type == 3 && test == 1){
              cout << "Visita in PreOrder per verificare se è corretto con l'iteratore" << endl;
              treestring.PreOrderTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPreOrderIterator<string> preorder_string(treestring);
              while (!preorder_string.Terminated()){
                cout << "Elemento corrente: " << *preorder_string << endl;
                ++preorder_string;
              }
              preorder_string.Reset();
            }
            else if (type == 1 && test == 2){
              cout << "Visita in Postorder per verificare se è corretto con l'iteratore" << endl;
              treeint.PostOrderTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPostOrderIterator<int> postorder_int(treeint);
              while (!postorder_int.Terminated()){
                cout << "Elemento corrente: " << *postorder_int << endl;
                ++postorder_int;
              }
              postorder_int.Reset();
            }
            else if (type == 2 && test == 2){
              cout << "Visita in Postorder per verificare se è corretto con l'iteratore" << endl;
              treefloat.PostOrderTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPostOrderIterator<float> postorder_float(treefloat);
              while (!postorder_float.Terminated()){
                cout << "Elemento corrente: " << *postorder_float << endl;
                ++postorder_float;
              }
              postorder_float.Reset();
            }
            else if (type == 3 && test == 2){
              cout << "Visita in Postorder per verificare se è corretto con l'iteratore" << endl;
              treestring.PostOrderTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPostOrderIterator<string> postorder_string(treestring);
              while (!postorder_string.Terminated()){
                cout << "Elemento corrente: " << *postorder_string << endl;
                ++postorder_string;
              }
              postorder_string.Reset();
            }
            else if (type == 1 && test == 3){
              cout << "Visita in InOrder per verificare se è corretto con l'iteratore" << endl;
              treeint.InOrderTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTInOrderIterator<int> inorder_int(treeint);
              while (!inorder_int.Terminated()){
                cout << "Elemento corrente: " << *inorder_int << endl;
                ++inorder_int;
              }
              inorder_int.Reset();
            }
            else if (type == 2 && test == 3){
              cout << "Visita in InOrder per verificare se è corretto con l'iteratore" << endl;
              treefloat.InOrderTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTInOrderIterator<float> inorder_float(treefloat);
              while (!inorder_float.Terminated()){
                cout << "Elemento corrente: " << *inorder_float << endl;
                ++inorder_float;
              }
              inorder_float.Reset();
            }
            else if (type == 3 && test == 3){
              cout << "Visita in InOrder per verificare se è corretto con l'iteratore" << endl;
              treestring.InOrderTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTInOrderIterator<string> inorder_string(treestring);
              while (!inorder_string.Terminated()){
                cout << "Elemento corrente: " << *inorder_string << endl;
                ++inorder_string;
              }
              inorder_string.Reset();
            }
            else if (type == 1 && test == 4){
              cout << "Visita in Breadth per verificare se è corretto con l'iteratore" << endl;
              treeint.BreadthTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTBreadthIterator<int> breadth_int(treeint);
              while (!breadth_int.Terminated()){
                cout << "Elemento corrente: " << *breadth_int << endl;
                ++breadth_int;
              }
              breadth_int.Reset();
            }
            else if (type == 2 && test == 4){
              cout << "Visita in Breadth per verificare se è corretto con l'iteratore" << endl;
              treefloat.BreadthTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTBreadthIterator<float> breadth_float(treefloat);
              while (!breadth_float.Terminated()){
                cout << "Elemento corrente: " << *breadth_float << endl;
                ++breadth_float;
              }
              breadth_float.Reset();
            }
            else if (type == 3 && test == 4){
              cout << "Visita in Breadth per verificare se è corretto con l'iteratore" << endl;
              treestring.BreadthTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTBreadthIterator<string> breadth_string(treestring);
              while (!breadth_string.Terminated()){
                cout << "Elemento corrente: " << *breadth_string << endl;
                ++breadth_string;
              }
              breadth_string.Reset();
            }
          }
      }
      if(scelta == 2)
      {
        int choose = 0;
        cout << "1. Ampiezza" << endl;
        cout << "2. Pre-Ordine" << endl;
        cout << "3. Ordine" << endl;
        cout << "4. Post-Ordine" << endl;
        cin  >> choose;
        if(choose == 1)
        {
          if(type == 1)
          {
            cout << "Albero  In Ampiezza =  ";
            treeint.BreadthMap([](int & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
          if(type == 2)
          {
            cout << "Albero  In Ampiezza =  ";
            treefloat.BreadthMap([](float & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
          if(type == 3)
          {
              cout << "Albero In Ampiezza =  ";
            treestring.BreadthMap([](string & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
        }
        if(choose == 2)
        {
          if(type == 1)
          {
            cout << "Albero  In Pre-Ordine =  ";
            treeint.PreOrderMap([](int & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
          if(type == 2)
          {
              cout << "Albero  In Pre-Ordine =  ";
            treefloat.PreOrderMap([](float & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
          if(type == 3)
          {
              cout << "Albero  In Pre-Ordine =  ";
            treestring.PreOrderMap([](string & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
        }
        if(choose == 3)
        {
          if(type == 1)
          {
              cout << "Albero  InOrder =  ";
            treeint.InOrderMap([](int & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
          if(type == 2)
          {
            cout << "Albero  InOrder =  ";
            treefloat.InOrderMap([](float & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
          if(type == 3)
          {
            cout << "Albero  InOrder =  ";
            treestring.InOrderMap([](string & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
        }
        if(choose == 4)
        {
          if(type == 1)
          {
            cout << "Albero  In PostOrder =  ";
            treeint.PostOrderMap([](int & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
          if(type == 2)
          {
            cout << "Albero  In PostOrder =  ";
            treefloat.PostOrderMap([](float & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
          if(type == 3)
          {
            cout << "Albero  In PostOrder =  ";
            treestring.PostOrderMap([](string & dat) {
              cout << dat << "  ";
            });
            cout << endl;
          }
        }

      }
      if(scelta == 3)
      {
        cout << "Che Elemento vuoi cercare nell'albero?" << endl;
        if(type == 1)
        {
          int search = 0;
          cin >> search;
          if(treeint.Exists(search))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
        if(type == 2)
        {
          float search = 0;
          cin >> search;
          if(treefloat.Exists(search))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
        if(type == 3)
        {
          string search;
          cin >> search;
          if(treestring.Exists(search))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
      }

      if (scelta == 4){
        int test = -1;
        while(test != 0){
          cout << "1: Vuoi visitare l'elemento figlio destro della radice?" << endl;
          cout << "2: Vuoi visitare l'elemento figlio sinistro della radice?" << endl;
          cout << "0: Se vuoi uscire dal test Mutable" << endl;
          cin >> test;

          if (type == 1 && test == 2){
            cout << "L'elemento è: " << treeint.Root().LeftChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treeint.Root().LeftChild().Element();
            cout << "Il nuovo elemento in left è: " << treeint.Root().LeftChild().Element() << endl;
          }
          else if (type == 1 && test == 1){
            cout << "L'elemento è: " << treeint.Root().RightChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treeint.Root().RightChild().Element();
            cout << "Il nuovo elemento in right è: " << treeint.Root().RightChild().Element() << endl;
          }
          else if (type == 2 && test == 2){
            cout << "L'elemento è: " << treefloat.Root().LeftChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treefloat.Root().LeftChild().Element();
            cout << "Il nuovo elemento in left è: " << treefloat.Root().LeftChild().Element() << endl;
          }
          else if (type == 2 && test == 1){
            cout << "L'elemento è: " << treefloat.Root().RightChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treefloat.Root().RightChild().Element();
            cout << "Il nuovo elemento in right è: " << treefloat.Root().RightChild().Element() << endl;
          }
          else if (type == 3 && test == 2){
            cout << "L'elemento è: " << treestring.Root().LeftChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treestring.Root().LeftChild().Element();
            cout << "Il nuovo elemento in left è: " << treestring.Root().LeftChild().Element() << endl;
          }
          else if (type == 3 && test == 1){
            cout << "L'elemento è: " << treestring.Root().RightChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treestring.Root().RightChild().Element();
            cout << "Il nuovo elemento in right è: " << treestring.Root().RightChild().Element() << endl;
          }
        }
      }
    }
  }
  void MenuLnk(int type, int dim)
  {
  int scelta = -1;
  lasd::Vector<int> vecint(dim);
  lasd::Vector<float> vecfloat(dim);
  lasd::Vector<string> vecstring(dim);

  if(type == 1){
    riempi(vecint, dim);
  }

  if(type == 2) {
    riempi(vecfloat, dim);
  }

  if(type == 3){
    riempiString(vecstring, dim);
  }

  lasd::BinaryTreeLnk<int> treeint(vecint);
  lasd::BinaryTreeLnk<float> treefloat(vecfloat);
  lasd::BinaryTreeLnk<string> treestring(vecstring);
  cout << "Benevenuto nel menu del BinaryTreeLnk" << endl;

  while(scelta != 0)
  {

    cout << endl;
    cout << "Cosa vuoi testare?" << endl;

    cout << "1: Navigazione Albero con gli Iteratori + Test Traverse" << endl;
    cout << "2: Testare le Map Function" << endl;
    cout << "3: Controllo di esistenza di un valore" << endl;
    cout << "4: Test mutable" << endl;
    cout << "0. Per uscire dal programma" << endl;
    cin >> scelta;
    cout << endl;

    if(scelta == 1)
    {
      int test = -1;
          while (test != 0){
            cout << "Quale iteratore vuoi testare?" << endl;
            cout << "1: Preorder" << endl;
            cout << "2: Postorder" << endl;
            cout << "3: Inorder" << endl;
            cout << "4: Breadth" << endl;
            cout << "0: Per tornare al Menu" << endl;
            cin >> test;

            if (type == 1 && test == 1){
              cout << "Visita in PreOrder per verificare se è corretto con l'iteratore" << endl;
              treeint.PreOrderTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPreOrderIterator<int> preorder_int(treeint);
              while (!preorder_int.Terminated()){
                cout << "Elemento corrente: " << *preorder_int << endl;
                ++preorder_int;
              }
              preorder_int.Reset();
            }
            else if (type == 2 && test == 1){
              cout << "Visita in PreOrder per verificare se è corretto con l'iteratore" << endl;
              treefloat.PreOrderTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPreOrderIterator<float> preorder_float(treefloat);
              while (!preorder_float.Terminated()){
                cout << "Elemento corrente: " << *preorder_float << endl;
                ++preorder_float;
              }
              preorder_float.Reset();
            }
            else if (type == 3 && test == 1){
              cout << "Visita in PreOrder per verificare se è corretto con l'iteratore" << endl;
              treestring.PreOrderTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPreOrderIterator<string> preorder_string(treestring);
              while (!preorder_string.Terminated()){
                cout << "Elemento corrente: " << *preorder_string << endl;
                ++preorder_string;
              }
              preorder_string.Reset();
            }
            else if (type == 1 && test == 2){
              cout << "Visita in Postorder per verificare se è corretto con l'iteratore" << endl;
              treeint.PostOrderTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPostOrderIterator<int> postorder_int(treeint);
              while (!postorder_int.Terminated()){
                cout << "Elemento corrente: " << *postorder_int << endl;
                ++postorder_int;
              }
              postorder_int.Reset();
            }
            else if (type == 2 && test == 2){
              cout << "Visita in Postorder per verificare se è corretto con l'iteratore" << endl;
              treefloat.PostOrderTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPostOrderIterator<float> postorder_float(treefloat);
              while (!postorder_float.Terminated()){
                cout << "Elemento corrente: " << *postorder_float << endl;
                ++postorder_float;
              }
              postorder_float.Reset();
            }
            else if (type == 3 && test == 2){
              cout << "Visita in Postorder per verificare se è corretto con l'iteratore" << endl;
              treestring.PostOrderTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTPostOrderIterator<string> postorder_string(treestring);
              while (!postorder_string.Terminated()){
                cout << "Elemento corrente: " << *postorder_string << endl;
                ++postorder_string;
              }
              postorder_string.Reset();
            }
            else if (type == 1 && test == 3){
              cout << "Visita in InOrder per verificare se è corretto con l'iteratore" << endl;
              treeint.InOrderTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTInOrderIterator<int> inorder_int(treeint);
              while (!inorder_int.Terminated()){
                cout << "Elemento corrente: " << *inorder_int << endl;
                ++inorder_int;
              }
              inorder_int.Reset();
            }
            else if (type == 2 && test == 3){
              cout << "Visita in InOrder per verificare se è corretto con l'iteratore" << endl;
              treefloat.InOrderTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTInOrderIterator<float> inorder_float(treefloat);
              while (!inorder_float.Terminated()){
                cout << "Elemento corrente: " << *inorder_float << endl;
                ++inorder_float;
              }
              inorder_float.Reset();
            }
            else if (type == 3 && test == 3){
              cout << "Visita in InOrder per verificare se è corretto con l'iteratore" << endl;
              treestring.InOrderTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTInOrderIterator<string> inorder_string(treestring);
              while (!inorder_string.Terminated()){
                cout << "Elemento corrente: " << *inorder_string << endl;
                ++inorder_string;
              }
              inorder_string.Reset();
            }
            else if (type == 1 && test == 4){
              cout << "Visita in Breadth per verificare se è corretto con l'iteratore" << endl;
              treeint.BreadthTraverse([](const int& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTBreadthIterator<int> breadth_int(treeint);
              while (!breadth_int.Terminated()){
                cout << "Elemento corrente: " << *breadth_int << endl;
                ++breadth_int;
              }
              breadth_int.Reset();
            }
            else if (type == 2 && test == 4){
              cout << "Visita in Breadth per verificare se è corretto con l'iteratore" << endl;
              treefloat.BreadthTraverse([](const float& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTBreadthIterator<float> breadth_float(treefloat);
              while (!breadth_float.Terminated()){
                cout << "Elemento corrente: " << *breadth_float << endl;
                ++breadth_float;
              }
              breadth_float.Reset();
            }
            else if (type == 3 && test == 4){
              cout << "Visita in Breadth per verificare se è corretto con l'iteratore" << endl;
              treestring.BreadthTraverse([](const string& dat){
                cout << dat << " ";
              });
              cout << endl;

              lasd::BTBreadthIterator<string> breadth_string(treestring);
              while (!breadth_string.Terminated()){
                cout << "Elemento corrente: " << *breadth_string << endl;
                ++breadth_string;
              }
              breadth_string.Reset();
            }
          }
    }
    if(scelta == 2)
    {
      int choose = 0;
      cout << "1. Ampiezza" << endl;
      cout << "2. Pre-Ordine" << endl;
      cout << "3. Ordine" << endl;
      cout << "4. Post-Ordine" << endl;
      cin  >> choose;
      if(choose == 1)
      {
        if(type == 1)
        {
          cout << "Albero  In Ampiezza =  ";
          treeint.BreadthMap([](int& dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
        if(type == 2)
        {
          cout << "Albero  In Ampiezza =  ";
          treefloat.BreadthMap([](float & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
        if(type == 3)
        {
            cout << "Albero In Ampiezza =  ";
          treestring.BreadthMap([](string & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
      }
      if(choose == 2)
      {
        if(type == 1)
        {
          cout << "Albero  In Pre-Ordine =  ";
          treeint.PreOrderMap([](int & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
        if(type == 2)
        {
            cout << "Albero  In Pre-Ordine =  ";
          treefloat.PreOrderMap([](float & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
        if(type == 3)
        {
            cout << "Albero  In Pre-Ordine =  ";
          treestring.PreOrderMap([](string & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
      }
      if(choose == 3)
      {
        if(type == 1)
        {
            cout << "Albero  InOrder =  ";
          treeint.InOrderMap([](int & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
        if(type == 2)
        {
          cout << "Albero  InOrder =  ";
          treefloat.InOrderMap([](float & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
        if(type == 3)
        {
          cout << "Albero  InOrder =  ";
          treestring.InOrderMap([](string & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
      }
      if(choose == 4)
      {
        if(type == 1)
        {
          cout << "Albero  In PostOrder =  ";
          treeint.PostOrderMap([](int & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
        if(type == 2)
        {
          cout << "Albero  In PostOrder =  ";
          treefloat.PostOrderMap([](float & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
        if(type == 3)
        {
          cout << "Albero  In PostOrder =  ";
          treestring.PostOrderMap([](string & dat) {
            cout << dat << "  ";
          });
          cout << endl;
        }
      }

    }
    if(scelta == 3)
    {
      cout << "Che Elemento vuoi cercare nell'albero?" << endl;
      if(type == 1)
      {
        int search = 0;
        cin >> search;
        if(treeint.Exists(search))
          cout << "Elemento trovato" << endl;
        else
          cout << "Elemento non trovato" << endl;
      }
      if(type == 2)
      {
        float search = 0;
        cin >> search;
        if(treefloat.Exists(search))
          cout << "Elemento trovato" << endl;
        else
          cout << "Elemento non trovato" << endl;
      }
      if(type == 3)
      {
        string search;
        cin >> search;
        if(treestring.Exists(search))
          cout << "Elemento trovato" << endl;
        else
          cout << "Elemento non trovato" << endl;
      }
    }

    if (scelta == 4){
        int test = -1;
        while(test != 0){
          cout << "1: Vuoi visitare l'elemento figlio destro della radice?" << endl;
          cout << "2: Vuoi visitare l'elemento figlio sinistro della radice?" << endl;
          cout << "0: Se vuoi uscire dal test Mutable" << endl;
          cin >> test;

          if (type == 1 && test == 2){
            cout << "L'elemento è: " << treeint.Root().LeftChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treeint.Root().LeftChild().Element();
            cout << "Il nuovo elemento in left è: " << treeint.Root().LeftChild().Element() << endl;
          }
          else if (type == 1 && test == 1){
            cout << "L'elemento è: " << treeint.Root().RightChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treeint.Root().RightChild().Element();
            cout << "Il nuovo elemento in right è: " << treeint.Root().RightChild().Element() << endl;
          }
          else if (type == 2 && test == 2){
            cout << "L'elemento è: " << treefloat.Root().LeftChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treefloat.Root().LeftChild().Element();
            cout << "Il nuovo elemento in left è: " << treefloat.Root().LeftChild().Element() << endl;
          }
          else if (type == 2 && test == 1){
            cout << "L'elemento è: " << treefloat.Root().RightChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treefloat.Root().RightChild().Element();
            cout << "Il nuovo elemento in right è: " << treefloat.Root().RightChild().Element() << endl;
          }
          else if (type == 3 && test == 2){
            cout << "L'elemento è: " << treestring.Root().LeftChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treestring.Root().LeftChild().Element();
            cout << "Il nuovo elemento in left è: " << treestring.Root().LeftChild().Element() << endl;
          }
          else if (type == 3 && test == 1){
            cout << "L'elemento è: " << treestring.Root().RightChild().Element() << endl;
            cout << "Con cosa lo vuoi modificare?" << endl;
            cin >> treestring.Root().RightChild().Element();
            cout << "Il nuovo elemento in right è: " << treestring.Root().RightChild().Element() << endl;
          }
        }
      }
  }
}

void MutableIterator(int type, int dim){
  int scelta = -1;
  lasd::Vector<int> vecint(dim);
  lasd::Vector<float> vecfloat(dim);
  lasd::Vector<string> vecstring(dim);

  if(type == 1){
    riempi(vecint, dim);
  }

  if(type == 2) {
    riempi(vecfloat, dim);
  }

  if(type == 3){
    riempiString(vecstring, dim);
  }

  lasd::BinaryTreeLnk<int> treeLint(vecint);
  lasd::BinaryTreeLnk<float> treeLfloat(vecfloat);
  lasd::BinaryTreeLnk<string> treeLstring(vecstring);

  lasd::BinaryTreeVec<int> treeVint(vecint);
  lasd::BinaryTreeVec<float> treeVfloat(vecfloat);
  lasd::BinaryTreeVec<string> treeVstring(vecstring);

  cout << "Inizio mutable iterator test" << endl;

  while (scelta != 0){
    cout << "1: Test no segmentation" << endl;
    cout << "2: Test su albero vuoto" << endl;
    cout << "0: Per terminare il test" << endl;

    cin >> scelta;

    if(scelta == 1 && type == 1){
      cout << "Inizio pre order" << endl;
      lasd::BTPreOrderMutableIterator<int> btL(treeLint);
      lasd::BTPreOrderMutableIterator<int> btV(treeVint);

      while(!btL.Terminated()){
        *btL;
        ++btL;
      }
      btL.Reset();

      while(!btV.Terminated()){
        *btV;
        ++btV;
      }
      btV.Reset();
      cout << "Fine Preorder" << endl;

      cout << "Inizio post order" << endl;
      lasd::BTPostOrderMutableIterator<int> postL(treeLint);
      lasd::BTPostOrderMutableIterator<int> postV(treeVint);

      while(!postL.Terminated()){
        *postL;
        ++postL;
      }
      postL.Reset();

      while(!postV.Terminated()){
        *postV;
        ++postV;
      }
      postV.Reset();
      cout << "Fine Postorder" << endl;

      cout << "Inizio in order" << endl;
      lasd::BTInOrderMutableIterator<int> inL(treeLint);
      lasd::BTInOrderMutableIterator<int> inV(treeVint);

      while(!inL.Terminated()){
        *inL;
        ++inL;
      }
      inL.Reset();

      while(!inV.Terminated()){
        *inV;
        ++inV;
      }
      inV.Reset();
      cout << "Fine inorder" << endl;

      cout << "Inizio breadth order" << endl;
      lasd::BTBreadthMutableIterator<int> breL(treeLint);
      lasd::BTBreadthMutableIterator<int> breV(treeVint);

      while(!breL.Terminated()){
        *breL;
        ++breL;
      }
      breL.Reset();

      while(!breV.Terminated()){
        *breV;
        ++breV;
      }
      breV.Reset();
      cout << "Fine breadth order" << endl;
    }
    else if(type == 2 && scelta == 1){
      cout << "Inizio pre order" << endl;
      lasd::BTPreOrderMutableIterator<float> btL(treeLfloat);
      lasd::BTPreOrderMutableIterator<float> btV(treeVfloat);

      while(!btL.Terminated()){
        *btL;
        ++btL;
      }
      btL.Reset();

      while(!btV.Terminated()){
        *btV;
        ++btV;
      }
      btV.Reset();
      cout << "Fine Preorder" << endl;

      cout << "Inizio post order" << endl;
      lasd::BTPostOrderMutableIterator<float> postL(treeLfloat);
      lasd::BTPostOrderMutableIterator<float> postV(treeVfloat);

      while(!postL.Terminated()){
        *postL;
        ++postL;
      }
      postL.Reset();

      while(!postV.Terminated()){
        *postV;
        ++postV;
      }
      postV.Reset();
      cout << "Fine Postorder" << endl;

      cout << "Inizio in order" << endl;
      lasd::BTInOrderMutableIterator<float> inL(treeLfloat);
      lasd::BTInOrderMutableIterator<float> inV(treeVfloat);

      while(!inL.Terminated()){
        *inL;
        ++inL;
      }
      inL.Reset();

      while(!inV.Terminated()){
        *inV;
        ++inV;
      }
      inV.Reset();
      cout << "Fine inorder" << endl;

      cout << "Inizio breadth order" << endl;
      lasd::BTBreadthMutableIterator<float> breL(treeLfloat);
      lasd::BTBreadthMutableIterator<float> breV(treeVfloat);

      while(!breL.Terminated()){
        *breL;
        ++breL;
      }
      breL.Reset();

      while(!breV.Terminated()){
        *breV;
        ++breV;
      }
      breV.Reset();
      cout << "Fine breadth order" << endl;
    }
    else if (scelta == 1 && type == 3){
      cout << "Inizio pre order" << endl;
      lasd::BTPreOrderMutableIterator<string> btL(treeLstring);
      lasd::BTPreOrderMutableIterator<string> btV(treeVstring);

      while(!btL.Terminated()){
        *btL;
        ++btL;
      }
      btL.Reset();

      while(!btV.Terminated()){
        *btV;
        ++btV;
      }
      btV.Reset();
      cout << "Fine Preorder" << endl;

      cout << "Inizio post order" << endl;
      lasd::BTPostOrderMutableIterator<string> postL(treeLstring);
      lasd::BTPostOrderMutableIterator<string> postV(treeVstring);

      while(!postL.Terminated()){
        *postL;
        ++postL;
      }
      postL.Reset();

      while(!postV.Terminated()){
        *postV;
        ++postV;
      }
      postV.Reset();
      cout << "Fine Postorder" << endl;

      cout << "Inizio in order" << endl;
      lasd::BTInOrderMutableIterator<string> inL(treeLstring);
      lasd::BTInOrderMutableIterator<string> inV(treeVstring);

      while(!inL.Terminated()){
        *inL;
        ++inL;
      }
      inL.Reset();

      while(!inV.Terminated()){
        *inV;
        ++inV;
      }
      inV.Reset();
      cout << "Fine inorder" << endl;

      cout << "Inizio breadth order" << endl;
      lasd::BTBreadthMutableIterator<string> breL(treeLstring);
      lasd::BTBreadthMutableIterator<string> breV(treeVstring);

      while(!breL.Terminated()){
        *breL;
        ++breL;
      }
      breL.Reset();

      while(!breV.Terminated()){
        *breV;
        ++breV;
      }
      breV.Reset();
      cout << "Fine breadth order" << endl;
    }
    else if (scelta == 2 && type == 1){
      lasd::BinaryTreeLnk<int> bt1{};
      try{
        lasd::BTPreOrderMutableIterator<int> pre(bt1);
        ++pre;
      } catch(const out_of_range& e){
        cout << e.what() << endl;
      }

      try {
        lasd::BTPostOrderMutableIterator<int> post(bt1);
        ++post;
      }catch (const out_of_range& e){
        cout << e.what() << endl;
      }

      try {
        lasd::BTInOrderMutableIterator<int> in(bt1);
        ++in;
      }catch(const out_of_range& e){
        cout << e.what() << endl;
      }

      try {
        lasd::BTBreadthMutableIterator<int> bre(bt1);
        ++bre;
      }catch(const out_of_range& e){
        cout << e.what() << endl;
      }
    }
    else if (scelta == 2 && type == 2){
      lasd::BinaryTreeLnk<float> bt1{};

      try{
        lasd::BTPreOrderMutableIterator<float> pre(bt1);
        ++pre;
      } catch(const out_of_range& e){
        cout << e.what() << endl;
      }

      try {
        lasd::BTPostOrderMutableIterator<float> post(bt1);
        ++post;
      }catch (const out_of_range& e){
        cout << e.what() << endl;
      }

      try {
        lasd::BTInOrderMutableIterator<float> in(bt1);
        ++in;
      }catch(const out_of_range& e){
        cout << e.what() << endl;
      }

      try {
        lasd::BTBreadthMutableIterator<float> bre(bt1);
        ++bre;
      }catch(const out_of_range& e){
        cout << e.what() << endl;
      }
    }
    else if (scelta == 2 && type == 3){
      lasd::BinaryTreeLnk<string> bt1{};

      try{
        lasd::BTPreOrderMutableIterator<string> pre(bt1);
        ++pre;
      } catch(const out_of_range& e){
        cout << e.what() << endl;
      }

      try {
        lasd::BTPostOrderMutableIterator<string> post(bt1);
        ++post;
      }catch (const out_of_range& e){
        cout << e.what() << endl;
      }

      try {
        lasd::BTInOrderMutableIterator<string> in(bt1);
        ++in;
      }catch(const out_of_range& e){
        cout << e.what() << endl;
      }

      try {
        lasd::BTBreadthMutableIterator<string> bre(bt1);
        ++bre;
      }catch(const out_of_range& e){
        cout << e.what() << endl;
      }
    }
  }
}

void testPersonal2A() {
    std::cout << "Benvenuto" << std::endl;

    int chooseTree = 0;
    int chooseType = 0;
    int n = 0;
    cout << "Che albero vuoi testare?"<< endl;
    cout << "1: BinaryTreeVec" << endl;
    cout << "2: BinaryTreeLnk" << endl;
    cout << "3: MutableIterator" << endl;
    cin  >> chooseTree;
    cout << endl;
    cout << "Che tipo di dati vuoi utilizzare in questo albero?" << endl;
    cout << "1: int" << endl;
    cout << "2: float" << endl;
    cout << "3: String" << endl;
    cin  >> chooseType;
    cout << "Quanti elementi vuoi inserire all'interno dell'albero?" << endl;
    cin  >> n;

    if(chooseTree == 1)
      MenuVec(chooseType, n);
    if(chooseTree == 2)
      MenuLnk(chooseType, n);

    if(chooseTree == 3)
      MutableIterator(chooseType, n);
 
    std::cout << "Test2A Terminato" << std::endl;
}

}