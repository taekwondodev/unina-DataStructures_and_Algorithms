
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;
  int option = -1;

  while(option != 0){
    std::cout << "Premi 1 e INVIO per zlasdtest" << std::endl;
    std::cout << "Premi 2 e INVIO per zmytest" << std::endl;
    std::cout << "Premi 0 e INVIO per uscire dal test" << std::endl;
    std::cin >> option;

    if (option == 1){
      lasdtest();
    }
    else if (option == 2) {
      mytest();
    }
  }

  return 0;
}
