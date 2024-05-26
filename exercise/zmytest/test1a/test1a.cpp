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

/************************************************************/

#include "../../vector/vector.hpp"
#include "../../list/list.hpp"

namespace t {
  std::string chars {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
  std::random_device rd;
  std::mt19937 generator(rd());

  std::string rand_str (int length)
    {
      std::string output (chars);
      std::shuffle(output.begin(), output.end(), generator);
      return output.substr(0, length);
    }

  template<typename Data>
  Data getIndexOf(lasd::Vector<Data>& v, int index)
  {
    return v[index];
  }

  void fill(lasd::Vector<std::string>& v)
  {
       for(unsigned int i=0; i < v.Size(); i++)
       {
         v[i] =  rand_str(v.Size());
       }
  }
  template<typename Data>
  void fill(lasd::Vector<Data>& v)
  {
    Data dataRandom;
    srand ((unsigned int)time(NULL));
    std::string type_name = "";

    for(unsigned int i = 0; i < v.Size(); i++)
    {
       dataRandom = (Data)rand() / 100 + 1;
       v[i] = dataRandom;

       if (std::string(typeid(v[0]).name()) == "d")
       {
         v[i] = std::trunc(dataRandom);
       }
    }
  }

  template<typename Data>
  void fill(lasd::List<Data>& list, unsigned int dim)
  {
    Data dataRandom;
    srand ((unsigned int)time(NULL));

    for(unsigned int i = 0; i < dim; i++)
    {
       dataRandom = (Data)rand() / 100 + 1;
       list.InsertAtBack(dataRandom);
    }
  }

  void fill(lasd::List<std::string>& list, unsigned int dim)
  {
    for(unsigned int i=0; i < dim; i++)
    {
      list.InsertAtBack(rand_str(dim - 1));
    }
  }

void testPersonal1A()
  {
        int scelta, type = 0;
        int index = 0;
        int x = -1;
        int n = 0; //dimensione struttura

        //Scelta struttura da utilizzare Lista o Vettore
        std::cout << "Benvenuto, ti trovi nel esercizio 1A di - LASD" << std::endl;

        std::cout << "Scegli una struttura da utillizzare: " << std::endl << "1) Vettore" << std::endl << "2) Lista" << std::endl;
        std::cin  >>  scelta;
        std::cout << "Che tipo di dati vuoi utilizzare? "<< std::endl << "1) Int" << std::endl << "2) Double" << std::endl << "3) Float" << std::endl << "4) String" << std::endl;
        std::cin  >> type;
        std::cout << "Inserisci la sua dimensione " << std::endl;
        std::cin  >> n;

        lasd::Vector<int>         v1(n);
        lasd::Vector<double>      v2(n);
        lasd::Vector<float>       v3(n);
        lasd::Vector<std::string> v4(n);
        lasd::List<int>           l1;
        lasd::List<double>        l2;
        lasd::List<float>         l3;
        lasd::List<std::string>   l4;

        if( scelta == 1) // Scelta Vettore
        {
          if(type == 1) // INT
          {
              fill(v1);
          }
          if(type == 2)// DOUBLE
          {
              fill(v2);
          }
          if(type == 3)// FLOAT
          {
              fill(v3);
          }
          if(type == 4)// STRING
          {
              fill(v4);
          }
        }
        if( scelta == 2) // Scelta Lista
        {
          if(type == 1) // INT
          {
              fill(l1, n);
          }
          if(type == 2)// DOUBLE
          {
              fill(l2, n);
          }
          if(type == 3)// FLOAT
          {
              fill(l3, n);
          }
          if(type == 4)// STRING
          {
              fill(l4, n);
          }
        }

        if( scelta == 1)
          while( x != 0)
          {
            std::cout << "Benvenuto nel menu delle funzioni del vettore, puoi utilizzare le seguenti funzionalità:" << std::endl;
            std::cout << "1)Ottieni il primo elemento" << std::endl;
            std::cout << "2)Ottieni l'elemento in posizione che vuoi" << std::endl;
            std::cout << "3)Ottieni l'ultimo elemento" << std::endl;
            std::cout << "4)Stampa tutto il vettore" << std::endl;
            std::cout << "5)Vuoi cercare un elemento all'interno del vettore?" << std::endl;
            std::cout << "6)Testare la Resize e la Clear" << std::endl;
            std::cout << "0)Se vuoi terminare il test"<< std::endl;
            std::cin  >> x;

            if(type == 1 && x == 1)
            {
              int first;
              first = v1.Front();
              std::cout<<"Primo elemento[0] =" << first << std::endl;
            }
            if(type == 2 && x == 1)
            {
              double first;
              first = v2.Front();
              std::cout<<"Primo elemento[0] =" << first << std::endl;
            }
            if(type == 3 && x == 1)
            {
              float first;
              first = v3.Front();
              std::cout<<"Primo elemento[0] =" << first << std::endl;
            }
            if(type == 4 && x == 1)
            {
              std::string first;
              first = v4.Front();
              std::cout<<"Primo elemento[0] =" << first << std::endl;
            }
            if(x == 2)
            {
                std::cout << "Inserisci la index da trovare";
                std::cin >> index;
            }
            if(type == 1 && x == 2)
            {
              int first;
              first = getIndexOf(v1,index);
              std::cout<<"Elemento["<<index<<"]"<< "=" << first << std::endl;
            }
            if(type == 2 && x == 2)
            {
              double first;
              first = getIndexOf(v2,index);
              std::cout<<"Elemento["<<index<<"]"<< "=" << first << std::endl;
            }
            if(type == 3 && x == 2)
            {
              float first;
              first = getIndexOf(v3,index);
              std::cout<<"Elemento["<<index<<"]"<< "=" << first << std::endl;
            }
            if(type == 4 && x == 2)
            {
              std::string first;
              first = getIndexOf(v4,index);
              std::cout<<"Elemento["<<index<<"]"<< "=" << first << std::endl;
            }
            if(type == 1 && x == 3)
            {
              int first;
              first = v1.Back();
              std::cout<<"Ultimo elemento["<< v1.Size() - 1 << "=" << first << std::endl;
            }
            if(type == 2 && x == 3)
            {
              double first;
              first = v2.Back();
              std::cout<<"Ultimo elemento["<< v2.Size() - 1 << "=" << first << std::endl;
            }
            if(type == 3 && x == 3)
            {
              float first;
              first = v3.Back();
              std::cout<<"Ultimo elemento["<< v3.Size() - 1 << "=" << first << std::endl;
            }
            if(type == 4 && x == 3)
            {
              std::string first;
              first = v4.Back();
              std::cout<<"Ultimo elemento["<< v4.Size() - 1 << "=" << first << std::endl;
            }
            //PRINT VETTORE
            if(x == 4)
              std::cout << "Ecco il vettore:" << std::endl;
            if(type == 1 && x == 4)
            {
              v1.PreOrderTraverse([](const int& dat){std::cout << dat << std::endl;});
            }
            if(type == 2 && x == 4)
            {
              v2.PreOrderTraverse([](const double& dat){std::cout << dat<< std::endl;});
            }
            if(type == 3 && x == 4)
            {
              v3.PreOrderTraverse([](const float& dat){std::cout << dat<< std::endl;});
            }
            if(type == 4 && x == 4)
            {
              v4.PreOrderTraverse([](const std::string& dat){std::cout << dat<< std::endl;});
            }
            //EXIST ELEMENT
            if(x == 5)
            {
              std::cout << "Che elemento vuoi ricercare all'interno del vettore?" << std::endl;
            }
            bool exist;
            if(type == 1 && x == 5)
            {
              int search_element;
              std::cin  >> search_element;
              exist = v1.Exists(search_element);
              if(exist)
                std::cout << "Elemento " << search_element << " esiste" << std::endl;
              else
                std::cout << "Elemento " << search_element << " non esiste" << std::endl;
            }
            if(type == 2 && x == 5)
            {
              double search_element;
              std::cin  >> search_element;
              exist = v2.Exists(search_element);
              if(exist)
                std::cout << "Elemento " << search_element << " esiste" << std::endl;
              else
                std::cout << "Elemento " << search_element << " non esiste" << std::endl;
            }
            if(type == 3 && x == 5)
            {
              float search_element;
              std::cin  >> search_element;
              exist = v3.Exists(search_element);
              if(exist)
                std::cout << "Elemento " << search_element << " esiste" << std::endl;
              else
                std::cout << "Elemento " << search_element << " non esiste" << std::endl;
            }
            if(type == 4 && x == 5)
            {
              std::string search_element;
              std::cin  >> search_element;
              exist = v4.Exists(search_element);
              if(exist)
                std::cout << "Elemento " << search_element << " esiste" << std::endl;
              else
                std::cout << "Elemento " << search_element << " non esiste" << std::endl;
            }

            //Passo 6)
            if(x == 6 && type == 1)
            {
                v1.Resize(15);
                std::cout << "Funzione Resize(15) applicata alla tua struttura" << std::endl;
                v1.Clear();
                std::cout << "Funzione Clear() applicata alla tua struttura" << std::endl;
                std::cout << "Test Vettore terminato" << std::endl;
                break;
            }
            if (x == 6 && type == 2){
              v2.Resize(15);
              std::cout << "Funzione Resize(15) applicata alla tua struttura" << std::endl;
              v2.Clear();
              std::cout << "Funzione Clear() applicata alla tua struttura" << std::endl;
              std::cout << "Test Vettore terminato" << std::endl;
              break;
            }
            if( x == 6 && type == 3)
            {
                v3.Resize(15);
                std::cout << "Funzione Resize(15) applicata alla tua struttura" << std::endl;
                v3.Clear();
                std::cout << "Funzione Clear() applicata alla tua struttura" << std::endl;
                std::cout << "Test Vettore terminato" << std::endl;
                break;
            }
            if( x == 6 && type == 4)
            {
                v4.Resize(15);
                std::cout << "Funzione Resize(15) applicata alla tua struttura" << std::endl;
                v4.Clear();
                std::cout << "Funzione Clear() applicata alla tua struttura" << std::endl;
                std::cout << "Test Vettore terminato" << std::endl;
                break;
            }
          }

        if(scelta == 2)
        {
          while( x != 0)
          {
            std::cout << "Benvenuto nel menu delle funzioni della lista, puoi utilizzare le seguenti funzionalità:" << std::endl;
            std::cout << "1)Ottieni il primo elemento" << std::endl;
            std::cout << "2)Ottieni l'elemento in posizione che vuoi" << std::endl;
            std::cout << "3)Ottieni l'ultimo elemento" << std::endl;
            std::cout << "4)Stampa LISTA tramite MAP" << std::endl;
            std::cout << "5)Vuoi cercare un elemento all'interno della lista?" << std::endl;
            std::cout << "6)Vuoi utilizzare la funzione Remove?" << std::endl;
            std::cout << "7)Vuoi testare la Clear()?" << std::endl;
            std::cout << "0)Se vuoi uscire dal programma"<< std::endl;
            std::cin  >> x;

            if(type == 1 && x == 1)
            {
              std::cout << l1.Front() << std::endl;
            }
            if(type == 2 && x == 1)
            {
              std::cout << l2.Front() << std::endl;
            }
            if(type == 3 && x == 1)
            {
              std::cout << l3.Front() << std::endl;
            }
            if(type == 4 && x == 1)
            {
              std::cout << l4.Front() << std::endl;
            }

            if(x==2)
            {
              std::cout << "Che posizione vuoi ottenere?" << std::endl;
              std::cin  >> index;
            }
            if(type == 1 && x == 2)
            {
              std::cout << l1[index] << std::endl;
            }
            if(type == 2 && x == 2)
            {
              std::cout << l2[index] << std::endl;
            }
            if(type == 3 && x == 2)
            {
              std::cout << l3[index] << std::endl;
            }
            if(type == 4 && x == 2)
            {
              std::cout << l4[index] << std::endl;
            }

            if(type == 1 && x == 3)
            {
              std::cout << l1.Back() << std::endl;
            }
            if(type == 2 && x == 3)
            {
              std::cout << l2.Back() << std::endl;
            }
            if(type == 3 && x == 3)
            {
              std::cout << l3.Back() << std::endl;
            }
            if(type == 4 && x == 3)
            {
              std::cout << l4.Back() << std::endl;
            }


            if(type == 1 && x == 4)
            {
              std::cout << "Ecco la lista stampata" << std::endl;
              l1.PreOrderTraverse([](const int& dat){std::cout << dat << "->" << std::endl;});
            }
            if(type == 2 && x == 4)
            {
              std::cout << "Ecco la lista stampata" << std::endl;
              l2.PreOrderTraverse([](const double& dat){std::cout << dat << "->" << std::endl;});
            }
            if(type == 3 && x == 4)
            {
              std::cout << "Ecco la lista stampata" << std::endl;
              l3.PreOrderTraverse([](const float& dat){std::cout << dat << "->" << std::endl;});
            }
            if(type == 4 && x == 4)
            {
              std::cout << "Ecco la lista stampata" << std::endl;
              l4.PreOrderTraverse([](const std::string& dat){std::cout << dat << "->" << std::endl;});
            }
            //EXIST ELEMENT
            if(x == 5)
            {
              std::cout << "Che elemento vuoi ricercare all'interno della Lista?" << std::endl;
            }
            bool exist;
            if(type == 1 && x == 5)
            {
              int search_element;
              std::cin  >> search_element;
              exist = l1.Exists(search_element);
              if(exist)
                std::cout << "Elemento " << search_element << " esiste" << std::endl;
              else
                std::cout << "Elemento " << search_element << " non esiste" << std::endl;
            }
            if(type == 2 && x == 5)
            {
              double search_element;
              std::cin  >> search_element;
              exist = l2.Exists(search_element);
              if(exist)
                std::cout << "Elemento " << search_element << " esiste" << std::endl;
              else
                std::cout << "Elemento " << search_element << " non esiste" << std::endl;
            }
            if(type == 3 && x == 5)
            {
              float search_element;
              std::cin  >> search_element;
              exist = l3.Exists(search_element);
              if(exist)
                std::cout << "Elemento " << search_element << " esiste" << std::endl;
              else
                std::cout << "Elemento " << search_element << " non esiste" << std::endl;
            }
            if(type == 4 && x == 5)
            {
              std::string search_element;
              std::cin  >> search_element;
              exist = l4.Exists(search_element);
              if(exist)
                std::cout << "Elemento " << search_element << " esiste" << std::endl;
              else
                std::cout << "Elemento " << search_element << " non esiste" << std::endl;
            }
            
            if(x == 6 && type == 1)
            {
                std::cout << "L'elemento in quale posizione vuoi rimuovere?" << std::endl;
                unsigned int y;
                std::cin >> y;
                l1.Remove(l1[y]);
                std::cout << "Funzione Remove() applicata alla tua struttura" << std::endl;
            }
            if( x == 6 && type == 2)
            {
                std::cout << "L'elemento in quale posizione vuoi rimuovere?" << std::endl;
                unsigned int y;
                std::cin >> y;
                l2.Remove(l2[y]);
                std::cout << "Funzione Remove() applicata alla tua struttura" << std::endl;
            }
            if( x == 6 && type == 3)
            {
                std::cout << "L'elemento in quale posizione vuoi rimuovere?" << std::endl;
                unsigned int y;
                std::cin >> y;
                l3.Remove(l3[y]);
                std::cout << "Funzione Remove() applicata alla tua struttura" << std::endl;
            }
            if( x == 6 && type == 4)
            {
                std::cout << "L'elemento in quale posizione vuoi rimuovere?" << std::endl;
                unsigned int y;
                std::cin >> y;
                l4.Remove(l4[y]);
                std::cout << "Funzione Remove() applicata alla tua struttura" << std::endl;
            }

            if (x == 7 && type == 1) {
              l1.Clear();
              std::cout << "Funzione Clear() applicata alla tua struttura" << std::endl;
              std::cout << "Test sulle liste terminato" << std::endl;
              break;
            }
            if (x == 7 && type == 2) {
              l2.Clear();
              std::cout << "Funzione Clear() applicata alla tua struttura" << std::endl;
              std::cout << "Test sulle liste terminato" << std::endl;
              break;
            }
            if (x == 7 && type == 3) {
              l3.Clear();
              std::cout << "Funzione Clear() applicata alla tua struttura" << std::endl;
              std::cout << "Test sulle liste terminato" << std::endl;
              break;
            }
            if (x == 7 && type == 4) {
              l4.Clear();
              std::cout << "Funzione Clear() applicata alla tua struttura" << std::endl;
              std::cout << "Test sulle liste terminato" << std::endl;
              break;
            }
        }
      }
    }

}
