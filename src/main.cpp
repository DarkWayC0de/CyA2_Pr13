#include <cstdio>
#include <vector>
#include <random>
#include <iostream>

#include "sorted_vector_t/sorted_vector_t.h"

#define LIMIT 999
#define SIZE   80



int main() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(-LIMIT, LIMIT);
  sorted_vector_t v;
  for (int i = 0; i < SIZE; i++) {
    v.push_back(distribution(generator));
  }

  std:: cout << "Vector a ordenar\n" << v << std::endl;
  std::cout << "Como desea ordenar el vector\n 1 Iterativo \n Cualquier otro Recursivo\nSeleciona un opcion: ";
  int a;
  std::cin >> a;
  if( a == 1){
    v.merge_sort_i();
  } else {
    v.merge_sort_r();
  }
  std:: cout << "Vector ya ordenado\n" << v << std::endl;
  return 0;
}