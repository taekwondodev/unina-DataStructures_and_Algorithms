#include "./test1a/test1a.hpp"
#include "./test1b/test1b.hpp"

#include "./test2a/test2a.hpp"
#include "./test2b/test2b.hpp"

#include "./test3/test3.hpp"
/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

void mytest() {
  cout << endl << "~*~#~*~ Welcome to the Personal LASD Test Suite ~*~#~*~ " << endl;

  int option = -1; 
  while (option != 0){
    std::cout << "Premi 1 e INVIO per TEST1A" << std::endl;
    std::cout << "Premi 2 e INVIO per TEST1B" << std::endl;
    std::cout << "Premi 3 e INVIO per TEST2A" << std::endl;
    std::cout << "Premi 4 e INVIO per TEST2B" << std::endl;
    std::cout << "Premi 5 e INVIO per TEST3" << std::endl;
    std::cout << "Premi 0 e INVIO per uscire dal test" << std::endl;
    std::cin >> option;

    if (option == 1){
      t::testPersonal1A();
    }
    if (option == 2){
      t::testPersonal1B();
    }
    if (option == 3){
      t::testPersonal2A();
    }
    if (option == 4){
      t::testPersonal2B();
    }
    if (option == 5){
      t::testPersonal3();
    }
  }

  cout << endl << "You are back in the Menu!" << endl;
}
