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

/****************************************/

#include "../../stack/vec/stackvec.hpp"
#include "../../stack/lst/stacklst.hpp"
#include "../../queue/vec/queuevec.hpp"
#include "../../queue/lst/queuelst.hpp"

namespace t {
  std::string tchars {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
  std::random_device rd2;
  std::mt19937 generator2(rd2());

  std::string rand_str2 (int length)
    {
      std::string output (tchars);
      std::shuffle(output.begin(), output.end(), generator2);
      return output.substr(0, length);
    }


  template<typename Data>
  void fill(lasd::StackVec<Data>& v, unsigned int dim)
  {
        Data dataRandom;
        srand ((unsigned int)time(NULL));
        std::string type_name = "";

        for(unsigned int i = 0; i < dim; i++)
        {
           dataRandom = (Data)rand() / 100 + 1;
           v.Push(dataRandom);
        }
}
  void fill(lasd::StackVec<std::string>& v, unsigned int dim)
  {
    for(unsigned int i=0; i < dim; i++)
    {
       v.Push(rand_str2(5));
    }
}
  template<typename Data>
  void fill(lasd::StackLst<Data>& v, unsigned int dim)
  {
        Data dataRandom;
        srand ((unsigned int)time(NULL));
        std::string type_name = "";
        for(unsigned int i = 0; i < dim; i++)
        {
           dataRandom = (Data)rand() / 100 + 1;
           v.Push(dataRandom);
        }
  }
  void fill(lasd::StackLst<std::string>& v, unsigned int dim)
  {
    for(unsigned int i=0; i < dim; i++)
    {
       v.Push(rand_str2(5));
    }
  }
  template<typename Data>
  void fill(lasd::QueueVec<Data>& v, unsigned int dim)
  {
        Data dataRandom;
        srand ((unsigned int)time(NULL));
        std::string type_name = "";

        for(unsigned int i = 0; i < dim; i++)
        {
           dataRandom = (Data)rand() / 100 + 1;
           v.Enqueue(dataRandom);
        }
}
  void fill(lasd::QueueVec<std::string>& v, unsigned int dim)
  {
    for(unsigned int i=0; i < dim; i++)
    {
       v.Enqueue(rand_str2(5));
    }
  }
  template<typename Data>
  void fill(lasd::QueueLst<Data>& v, unsigned int dim)
  {
        Data dataRandom;
        srand ((unsigned int)time(NULL));
        std::string type_name = "";
        for(unsigned int i = 0; i < dim; i++)
        {
           dataRandom = (Data)rand() / 100 + 1;
           v.Enqueue(dataRandom);
        }
  }
  void fill(lasd::QueueLst<std::string>& v, unsigned int dim)
  {
    for(unsigned int i=0; i < dim; i++)
    {
       v.Enqueue(rand_str2(5));
    }
  }

  void MenuQueue(int dato, int sceltaVettList, int n)
  {
    lasd::QueueVec<int>    queuevec_int;
    lasd::QueueVec<double> queuevec_double;
    lasd::QueueVec<float>  queuevec_float;
    lasd::QueueVec<std::string> queuevec_string;

    lasd::QueueLst<int>    queuelst_int;
    lasd::QueueLst<double> queuelst_double;
    lasd::QueueLst<float>  queuelst_float;
    lasd::QueueLst<std::string> queuelst_string;
    if(sceltaVettList == 1) //Caso Vettore
    {
        if(dato == 1)
        {
          fill(queuevec_int, n);
        }
        if(dato == 2)
        {
          fill(queuevec_double, n);
        }
        if(dato == 3)
        {
          fill(queuevec_float, n);
        }
        if(dato == 4)
        {
          fill(queuevec_string, n);
        }
      }
    if(sceltaVettList == 2) //Caso Lista
    {
      if(dato == 1)
      {
        fill(queuelst_int, n);
      }
      if(dato == 2)
      {
        fill(queuelst_double, n);
      }
      if(dato == 3)
      {
        fill(queuelst_float, n);
      }
      if(dato == 4)
      {
        fill(queuelst_string, n);
      }
  }
    int scelta = -1;
    while( scelta != 0)
    {
      if(sceltaVettList == 1)
        std::cout << "Benvenuto nello QueueVec - Menu" << std::endl;
      if(sceltaVettList == 2)
        std::cout << "Benvenuto nello QueueLst - Menu" << std::endl;

      std::cout << "1) Push " << std::endl;
      std::cout << "2) Pop " << std::endl;
      std::cout << "3) TopNPop" << std::endl;
      std::cout << "4) Top" << std::endl;
      std::cout << "5) Test Vuotezza" << std::endl;
      std::cout << "6) Dimensione Stack" << std::endl;
      std::cout << "7) Svuota Stack" << std::endl;
      std::cout << "0) Per uscire dal test" << std::endl;
      std::cin  >> scelta;

      if(sceltaVettList == 1)
      {
        if(scelta == 1 && dato == 1)
        {
          int num = 0;
          std::cout << "Che elemento vuoi inserire nella Queue?" << std::endl;
          std::cin  >> num;
          queuevec_int.Enqueue(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 2)
        {
          double num = 0;
          std::cout << "Che elemento vuoi inserire nello Queue?" << std::endl;
          std::cin  >> num;
          queuevec_double.Enqueue(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 3)
        {
          float num = 0;
          std::cout << "Che elemento vuoi inserire nello Queue?" << std::endl;
          std::cin  >> num;
          queuevec_float.Enqueue(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 4)
        {
          std::string num;
          std::cout << "Che elemento vuoi inserire nello Stack?" << std::endl;
          std::cin  >> num;
          queuevec_string.Enqueue(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 2 && dato == 1)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          queuevec_int.Dequeue();
        }
        if(scelta == 2 && dato == 2)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          queuevec_double.Dequeue();
        }
        if(scelta == 2 && dato == 3)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          queuevec_float.Dequeue();
        }
        if(scelta == 2 && dato == 4)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          queuevec_string.Dequeue();
        }
        if(scelta == 3 && dato == 1)
        {
          std::cout << "Elemento Rimosso: " << queuevec_int.HeadNDequeue() << std::endl;
        }
        if(scelta == 3 && dato == 2)
        {
          std::cout << "Elemento Rimosso: " << queuevec_double.HeadNDequeue() << std::endl;
        }
        if(scelta == 3 && dato == 3)
        {
          std::cout << "Elemento Rimosso: " << queuevec_float.HeadNDequeue() << std::endl;
        }
        if(scelta == 3 && dato == 4)
        {
          std::cout << "Elemento Rimosso: " << queuevec_string.HeadNDequeue() << std::endl;
        }
        if(scelta == 4 && dato == 1)
        {
          std::cout << "Elemento : " << queuevec_int.Head() << std::endl;
        }
        if(scelta == 4 && dato == 2)
        {
          std::cout << "Elemento : " << queuevec_double.Head() << std::endl;
        }
        if(scelta == 4 && dato == 3)
        {
          std::cout << "Elemento : " << queuevec_float.Head() << std::endl;
        }
        if(scelta == 4 && dato == 4)
        {
          std::cout << "Elemento : " << queuevec_string.Head() << std::endl;
        }
        unsigned int vuoto = 0;
        if(scelta == 5 && dato == 1)
        {
          vuoto = queuevec_int.Empty();
        }
        if(scelta == 5 && dato == 2)
        {
          vuoto = queuevec_double.Empty();
        }
        if(scelta == 5 && dato == 3)
        {
          vuoto = queuevec_float.Empty();
        }
        if(scelta == 5 && dato == 4)
        {
          vuoto = queuevec_string.Empty();
        }
        if(scelta == 5)
        {
          if( vuoto == 0) {
            std::cout << "StackVec vuoto" << std::endl;
          }
          else {
            std::cout << "StackVec non vuoto" << std::endl;
          }
        }
        unsigned long dimensione = 0;
        if(scelta ==6 && dato == 1)
        {
          dimensione = queuevec_int.Size();
        }
        if(scelta ==6 && dato == 2)
        {
          dimensione = queuevec_double.Size();
        }
        if(scelta ==6 && dato == 3)
        {
          dimensione = queuevec_float.Size();
        }
        if(scelta ==6 && dato == 4)
        {
          dimensione = queuevec_string.Size();
        }
        if(scelta == 6)
          std::cout << "Dimensione QueueVec: " << dimensione << std::endl;
        if(scelta == 7 && dato == 1)
          queuevec_int.Clear();
        if(scelta == 7 && dato == 2)
          queuevec_double.Clear();
        if(scelta == 7 && dato == 3)
          queuevec_float.Clear();
        if(scelta == 7 && dato == 4)
          queuevec_string.Clear();
        if(scelta == 7)
          std::cout << "QueueVec svuotato" << std::endl;
      }
      if(sceltaVettList == 2)
      {
        if(scelta == 1 && dato == 1)
        {
          int num = 0;
          std::cout << "Che elemento vuoi inserire nella Queue?" << std::endl;
          std::cin  >> num;
          queuelst_int.Enqueue(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 2)
        {
          double num = 0;
          std::cout << "Che elemento vuoi inserire nello Queue?" << std::endl;
          std::cin  >> num;
          queuelst_double.Enqueue(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 3)
        {
          float num = 0;
          std::cout << "Che elemento vuoi inserire nello Queue?" << std::endl;
          std::cin  >> num;
          queuelst_float.Enqueue(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 4)
        {
          std::string num;
          std::cout << "Che elemento vuoi inserire nello Stack?" << std::endl;
          std::cin  >> num;
          queuelst_string.Enqueue(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 2 && dato == 1)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          queuelst_int.Dequeue();
        }
        if(scelta == 2 && dato == 2)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          queuelst_double.Dequeue();
        }
        if(scelta == 2 && dato == 3)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          queuelst_float.Dequeue();
        }
        if(scelta == 2 && dato == 4)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          queuelst_string.Dequeue();
        }
        if(scelta == 3 && dato == 1)
        {
          std::cout << "Elemento Rimosso: " << queuelst_int.HeadNDequeue() << std::endl;
        }
        if(scelta == 3 && dato == 2)
        {
          std::cout << "Elemento Rimosso: " << queuelst_double.HeadNDequeue() << std::endl;
        }
        if(scelta == 3 && dato == 3)
        {
          std::cout << "Elemento Rimosso: " << queuelst_float.HeadNDequeue() << std::endl;
        }
        if(scelta == 3 && dato == 4)
        {
          std::cout << "Elemento Rimosso: " << queuelst_string.HeadNDequeue() << std::endl;
        }
        if(scelta == 4 && dato == 1)
        {
          std::cout << "Elemento : " << queuelst_int.Head() << std::endl;
        }
        if(scelta == 4 && dato == 2)
        {
          std::cout << "Elemento : " << queuelst_double.Head() << std::endl;
        }
        if(scelta == 4 && dato == 3)
        {
          std::cout << "Elemento : " << queuelst_float.Head() << std::endl;
        }
        if(scelta == 4 && dato == 4)
        {
          std::cout << "Elemento : " << queuelst_string.Head() << std::endl;
        }
        unsigned int vuoto = 0;
        if(scelta == 5 && dato == 1)
        {
          vuoto = queuelst_int.Size();
        }
        if(scelta == 5 && dato == 2)
        {
          vuoto = queuelst_double.Size();
        }
        if(scelta == 5 && dato == 3)
        {
          vuoto = queuelst_float.Size();
        }
        if(scelta == 5 && dato == 4)
        {
          vuoto = queuelst_string.Size();
        }
        if(scelta == 5)
        {
          if( vuoto == 0){
            std::cout << "StackVec vuoto" << std::endl;
          }
          else {
            std::cout << "StackVec non vuoto" << std::endl;
          }
        }
        unsigned long dimensione = 0;
        if(scelta ==6 && dato == 1)
        {
          dimensione = queuelst_int.Size();
        }
        if(scelta ==6 && dato == 2)
        {
          dimensione = queuelst_double.Size();
        }
        if(scelta ==6 && dato == 3)
        {
          dimensione = queuelst_float.Size();
        }
        if(scelta ==6 && dato == 4)
        {
          dimensione = queuelst_string.Size();
        }
        if(scelta == 6)
          std::cout << "Dimensione QueueVec: " << dimensione << std::endl;
        if(scelta == 7 && dato == 1)
          queuelst_int.Clear();
        if(scelta == 7 && dato == 2)
          queuelst_double.Clear();
        if(scelta == 7 && dato == 3)
          queuelst_float.Clear();
        if(scelta == 7 && dato == 4)
          queuelst_string.Clear();
        if(scelta == 7)
          std::cout << "QueueVec svuotato" << std::endl;
      }
    }

  }
  void MenuStack(int dato, int sceltaVettList, int n){
    lasd::StackVec<int>    stackvec_int;
    lasd::StackVec<double> stackvec_double;
    lasd::StackVec<float>  stackvec_float;
    lasd::StackVec<std::string> stackvec_string;

    lasd::StackLst<int>    stacklst_int;
    lasd::StackLst<double> stacklst_double;
    lasd::StackLst<float>  stacklst_float;
    lasd::StackLst<std::string> stacklst_string;

    if(sceltaVettList == 1) //Caso Vettor    if(dato == 1)
    {
      {
        fill(stackvec_int, n);
      }
      if(dato == 2)
      {
        fill(stackvec_double, n);
      }
      if(dato == 3)
      {
        fill(stackvec_float, n);
      }
      if(dato == 4)
      {
        fill(stackvec_string, n);
      }
    }
    if(sceltaVettList == 2) //Caso Lista
    {
      if(dato == 1)
      {
        fill(stacklst_int, n);
      }
      if(dato == 2)
      {
        fill(stacklst_double, n);
      }
      if(dato == 3)
      {
        fill(stacklst_float, n);
      }
      if(dato == 4)
      {
        fill(stacklst_string, n);
      }
    }

    //Inizia il Menu di Stack
    int scelta = -1;
    while( scelta != 0)
    {
      if(sceltaVettList == 1)
        std::cout << "Benvenuto nello StackVec - Menu" << std::endl;
      if(sceltaVettList == 2)
        std::cout << "Benvenuto nello StackLst - Menu" << std::endl;

      std::cout << "1) Push " << std::endl;
      std::cout << "2) Pop " << std::endl;
      std::cout << "3) TopNPop" << std::endl;
      std::cout << "4) Top" << std::endl;
      std::cout << "5) Test Vuotezza" << std::endl;
      std::cout << "6) Dimensione Stack" << std::endl;
      std::cout << "7) Svuota Stack" << std::endl;
      std::cout << "0) Per uscire dal test" << std::endl;
      std::cin  >> scelta;

      if(sceltaVettList == 1)
      {
        if(scelta == 1 && dato == 1)
        {
          int num = 0;
          std::cout << "Che elemento vuoi inserire nello Stack?" << std::endl;
          std::cin  >> num;
          stackvec_int.Push(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 2)
        {
          double num = 0;
          std::cout << "Che elemento vuoi inserire nello Stack?" << std::endl;
          std::cin  >> num;
          stackvec_double.Push(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 3)
        {
          float num = 0;
          std::cout << "Che elemento vuoi inserire nello Stack?" << std::endl;
          std::cin  >> num;
          stackvec_float.Push(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 4)
        {
          std::string num;
          std::cout << "Che elemento vuoi inserire nello Stack?" << std::endl;
          std::cin  >> num;
          stackvec_string.Push(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 2 && dato == 1)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          stackvec_int.Pop();
        }
        if(scelta == 2 && dato == 2)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          stackvec_double.Pop();
        }
        if(scelta == 2 && dato == 3)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          stackvec_float.Pop();
        }
        if(scelta == 2 && dato == 4)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          stackvec_string.Pop();
        }
        if(scelta == 3 && dato == 1)
        {
          std::cout << "Elemento Rimosso: " << stackvec_int.TopNPop() << std::endl;
        }
        if(scelta == 3 && dato == 2)
        {
          std::cout << "Elemento Rimosso: " << stackvec_double.TopNPop() << std::endl;
        }
        if(scelta == 3 && dato == 3)
        {
          std::cout << "Elemento Rimosso: " << stackvec_float.TopNPop() << std::endl;
        }
        if(scelta == 3 && dato == 4)
        {
          std::cout << "Elemento Rimosso: " << stackvec_string.TopNPop() << std::endl;
        }
        if(scelta == 4 && dato == 1)
        {
          std::cout << "Elemento : " << stackvec_int.Top() << std::endl;
        }
        if(scelta == 4 && dato == 2)
        {
          std::cout << "Elemento : " << stackvec_double.Top() << std::endl;
        }
        if(scelta == 4 && dato == 3)
        {
          std::cout << "Elemento : " << stackvec_float.Top() << std::endl;
        }
        if(scelta == 4 && dato == 4)
        {
          std::cout << "Elemento : " << stackvec_string.Top() << std::endl;
        }
        bool vuoto = false;
        if(scelta == 5 && dato == 1)
        {
          vuoto = stackvec_int.Empty();
        }
        if(scelta == 5 && dato == 2)
        {
          vuoto = stackvec_double.Empty();
        }
        if(scelta == 5 && dato == 3)
        {
          vuoto = stackvec_float.Empty();
        }
        if(scelta == 5 && dato == 4)
        {
          vuoto = stackvec_string.Empty();
        }
        if(scelta == 5)
        {
          if( !vuoto ){
            std::cout << "StackVec vuoto" << std::endl;
          }
          else {
            std::cout << "StackVec non vuoto" << std::endl;
          }
        }
        unsigned long dimensione = 0;
        if(scelta ==6 && dato == 1)
        {
          dimensione = stackvec_int.Size();
        }
        if(scelta ==6 && dato == 2)
        {
          dimensione = stackvec_double.Size();
        }
        if(scelta ==6 && dato == 3)
        {
          dimensione = stackvec_float.Size();
        }
        if(scelta ==6 && dato == 4)
        {
          dimensione = stackvec_string.Size();
        }
        if(scelta == 6)
          std::cout << "Dimensione StackVec: " << dimensione << std::endl;
        if(scelta == 7 && dato == 1)
          stackvec_int.Clear();
        if(scelta == 7 && dato == 2)
          stackvec_double.Clear();
        if(scelta == 7 && dato == 3)
          stackvec_float.Clear();
        if(scelta == 7 && dato == 4)
          stackvec_string.Clear();
        if(scelta == 7)
          std::cout << "StackVec svuotato" << std::endl;
      }
      if(sceltaVettList == 2)
      {
        if(scelta == 1 && dato == 1)
        {
          int num = 0;
          std::cout << "Che elemento vuoi inserire nello Stack?" << std::endl;
          std::cin  >> num;
          stacklst_int.Push(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 2)
        {
          double num = 0;
          std::cout << "Che elemento vuoi inserire nello Stack?" << std::endl;
          std::cin  >> num;
          stacklst_double.Push(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 3)
        {
          float num = 0;
          std::cout << "Che elemento vuoi inserire nello Stack?" << std::endl;
          std::cin  >> num;
          stacklst_float.Push(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 1 && dato == 4)
        {
          std::string num;
          std::cout << "Che elemento vuoi inserire nello Stack?" << std::endl;
          std::cin  >> num;
          stacklst_string.Push(num);
          std::cout << "Push effettuato" << std::endl;
        }
        if(scelta == 2 && dato == 1)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          stacklst_int.Pop();
        }
        if(scelta == 2 && dato == 2)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          stacklst_double.Pop();
        }
        if(scelta == 2 && dato == 3)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          stacklst_float.Pop();
        }
        if(scelta == 2 && dato == 4)
        {
          std::cout << "Pop eseguito con successo" << std::endl;
          stacklst_string.Pop();
        }
        if(scelta == 3 && dato == 1)
        {
          std::cout << "Elemento Rimosso: " << stacklst_int.TopNPop() << std::endl;
        }
        if(scelta == 3 && dato == 2)
        {
          std::cout << "Elemento Rimosso: " << stacklst_double.TopNPop() << std::endl;
        }
        if(scelta == 3 && dato == 3)
        {
          std::cout << "Elemento Rimosso: " << stacklst_float.TopNPop()<< std::endl;
        }
        if(scelta == 3 && dato == 4)
        {
          std::cout << "Elemento Rimosso: " << stacklst_string.TopNPop() << std::endl;
        }
        if(scelta == 4 && dato == 1)
        {
          std::cout << "Elemento : " << stacklst_int.Top() << std::endl;
        }
        if(scelta == 4 && dato == 2)
        {
          std::cout << "Elemento : " << stacklst_double.Top() << std::endl;
        }
        if(scelta == 4 && dato == 3)
        {
         std::cout << "Elemento : " << stacklst_float.Top()<< std::endl;
        }
        if(scelta == 4 && dato == 4)
        {
          std::cout << "Elemento : " << stacklst_string.Top()<< std::endl;
        }
        unsigned int vuoto = 0;
        if(scelta == 5 && dato == 1)
        {
          vuoto = stacklst_int.Size();
        }
        if(scelta == 5 && dato == 2)
        {
          vuoto = stacklst_double.Size();
        }
        if(scelta == 5 && dato == 3)
        {
          vuoto = stacklst_float.Size();
        }
        if(scelta == 5 && dato == 4)
        {
          vuoto = stacklst_string.Size();
        }
        if(scelta == 5)
        {
          if( vuoto == 0) {
            std::cout << "StackVec vuoto" << std::endl;
          }
          else{
            std::cout << "StackVec non vuoto" << std::endl;
          }
        }
        unsigned long dimensione = 0;
        if(scelta ==6 && dato == 1)
        {
          dimensione = stacklst_int.Size();
        }
        if(scelta ==6 && dato == 2)
        {
          dimensione = stacklst_double.Size();
        }
        if(scelta ==6 && dato == 3)
        {
          dimensione = stackvec_float.Size();
        }
        if(scelta ==6 && dato == 4)
        {
          dimensione = stacklst_string.Size();
        }
        if(scelta == 6)
          std::cout << "Dimensione StackVec: " << dimensione << std::endl;
        if(scelta == 7 && dato == 1)
          stacklst_int.Clear();
        if(scelta == 7 && dato == 2)
          stacklst_double.Clear();
        if(scelta == 7 && dato == 3)
          stacklst_float.Clear();
        if(scelta == 7 && dato == 4)
          stacklst_string.Clear();
        if(scelta == 7)
          std::cout << "StackVec svuotato";
      }
    }
}
void testPersonal1B(){
    int sceltaStruttura = 0;
    int sceltaVettList  = 0;
    int tipo = 0;
    int n = 0;
    std::cout << "Benvenuto" << std::endl;
    std::cout << "Scegli cosa utilizzare: " << std::endl;
    std::cout << "1) Stack" << std::endl;
    std::cout << "2) Queue" << std::endl;
    std::cin  >> sceltaStruttura;
    std::cout << std::endl;
    std::cout << "Scegli tra Vettori o Liste" << std::endl;
    std::cout << "1) Vettore" << std::endl;
    std::cout << "2) Liste" << std::endl;
    std::cin  >> sceltaVettList;
    std::cout << std::endl;
    std::cout << "Che tipo di dato vuoi utilizzare?" << std::endl;
    std::cout << "1) Int" << std::endl;
    std::cout << "2) Double" << std::endl;
    std::cout << "3) Float" << std::endl;
    std::cout << "4) String" << std::endl;
    std::cin  >> tipo;
    std::cout << "Quanti elementi vuoi inserire nella struttura?" << std::endl;
    std::cin  >> n;

    if(sceltaStruttura == 1)
      MenuStack(tipo, sceltaVettList, n);
    if(sceltaStruttura == 2)
      MenuQueue(tipo, sceltaVettList, n);
}

}