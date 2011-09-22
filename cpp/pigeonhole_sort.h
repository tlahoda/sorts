/**
 * \file pigeonhole_sort.h, Contains a pigeonhole sort implementation.
 *
 * Copyright (C) 2011 Thomas P. Lahoda
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef SORT_PIGEONHOLE_SORT_H
#define SORT_PIGEONHOLE_SORT_H

#include <vector>
#include <list>
#include <algorithm>

namespace sort {
  using namespace std;

  /**
   * Sorts the elements from begin to end in ascending order maintaining stability
   * and places the result into the output container. 
   *
   * Complexity is O(k + n) where k is the number of unique keys and n is the
   * number of elements to sort.
   *
   * Space complexity is O(k + n) where k is the number of unique keys and n is
   * the number of elements to be sorted.
   *
   * \tparam iterator The type of the input iterator.
   * \tparam Container The type of the output container.
   *
   * \param begin The beginning of the elements.
   * \param end The end of the elements.
   * \param out The output list.
   * \param maxKey The maximum value a key can have.
   *
   * \return void.
   */
  template<typename iterator, typename Container>
  void pigeonhole_sort (const iterator& begin, const iterator& end, Container& out, unsigned int maxKey) {
    vector<list<typename iterator::value_type>> buckets (maxKey);

    for_each (begin, end, [&buckets] (typename iterator::value_type& ele) {
      buckets[ele.first - 1].push_back (ele);
    });

    Container res;
    for_each (buckets.begin (), buckets.end (), [&res] (list<typename iterator::value_type>& l) {
      res.splice (res.end (), l);
    });
    out.swap (res);
  }; //pigeonhole_sort
}; //sort

#endif //SORT_PIGEONHOLE_SORT_H

