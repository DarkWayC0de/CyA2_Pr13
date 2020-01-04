//
// Created by darkwayc0de on 4/1/20.
//

#ifndef PR13_SRC_MERGESORT_MERGESORT_H_
#define PR13_SRC_MERGESORT_MERGESORT_H_

#include <vector>
#include <iostream>

 class sorted_vector_t: public std::vector<int>
{
 public:
  sorted_vector_t(): vector<int>() {}
  explicit sorted_vector_t(const vector<int>& v): vector<int>(v) {}
  ~sorted_vector_t() = default;
  void merge_sort_r();
  void write(std::ostream& os) const;

 private:
  void create_vector_sentinel(int l, int r, vector<int>& v);
  void merge(const vector<int>& v1, const vector<int>& v2, int l);
  void merge_sort_r(int l, int r);
  void merge(int l, int c, int d);
};

std::ostream& operator<<(std::ostream& os, const sorted_vector_t& v);

#endif //PR13_SRC_MERGESORT_MERGESORT_H_
