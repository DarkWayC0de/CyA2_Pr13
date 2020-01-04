#include "sorted_vector_t.h"
#include <climits>
#include <iomanip>

void sorted_vector_t::merge_sort_r() {
  merge_sort_r(0, size() - 1);
}

void sorted_vector_t::write( std::ostream& os) const {
  const int sz = size();
  os << "< ";
  for(int i = 0; i < sz; i++)
    os << std::setw(5) << at(i);
  os << "> ";
}

void sorted_vector_t::merge_sort_r(int l, int r) {
  if (l < r) {
    int c = (l + r) / 2;
    merge_sort_r(l, c);
    merge_sort_r(c + 1, r);
    merge(l, c, r);
  }
}

////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::create_vector_sentinel(int l, int r, vector<int>& v) {
  for (int kI = l; kI <= r; ++kI) {
    v.push_back(this ->at(kI));
  }
}

void sorted_vector_t::merge(int l, int c, int d) {
  std::vector<int> copiavector1;
  std::vector<int> copiavector2;
  create_vector_sentinel(l,c,copiavector1);
  create_vector_sentinel(c+1,d,copiavector2);
  merge(copiavector1,copiavector2,l);
}

void sorted_vector_t::merge(const std::vector<int> &v1, const std::vector<int> &v2, int l) {
  int j = 0;
  int k = 0;
  for (int i = 0;!(k == v2.size() && j == v1.size()); i++){
    if(((v1[j] < v2[k])&&  j < v1.size())|| k == v2.size()) {
      this->at(l + i) = v1[j];
      j++;
    } else {
      this->at(l + i) = v2[k];
      k++;
    }
  }
}

////////////////// FORMA iterativa
void sorted_vector_t::merge_sort_i() {
  merge_sort_i(0, size() - 1);
}

void sorted_vector_t::merge_sort_i(int l, int r) {
  int kI = 2;
  int final_dispar;
  for ( ; kI <= r ; kI = kI*2) {
    for (int inicio = l; inicio < r ; ) {
      int final = inicio + kI-1;
      if (!(inicio >= r || final > r)) {
        merge(inicio, (inicio + final) / 2, final);
        final_dispar =final;
      }
      inicio = final+1;
    }
  }
  if(final_dispar != r) {
    merge(l, final_dispar, r);
  }
}

////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const sorted_vector_t& v) {
  v.write(os);
  return os;
}