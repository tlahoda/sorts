/**
 * \file counting_sort.h, Contains a counting sort implementation.
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
#ifndef SORT_COUNTING_SORT_H
#define SORT_COUNTING_SORT_H

#include <vector>
#include <algorithm>

namespace sort {
  using namespace std;

  /**
   * Sorts the elements from begin to end in ascending order maintaining stability
   * and places the result into the output container. 
   *
   * Complexity is O(2k + 3n) where k is the number of unique keys and n is the number
   * of elements to sort.
   *
   * \tparam iterator The type of the input iterator.
   * \tparam Container The type of the output container.
   *
   * \param begin The beginning of the elements.
   * \param end The end of the elements.
   * \param out The output container.
   * \param maxKey The maximum key.
   *
   * \return void.
   */
  template<typename iterator, typename Container>
  void counting_sort (const iterator& begin, const iterator& end, Container& out, unsigned int maxKey) {
    vector<unsigned int> counts (maxKey, 0);

    for_each (begin, end, [&counts] (typename iterator::value_type& ele) {
      ++counts[ele.first];
    });

    unsigned int pos = 0;
    for (unsigned int i = 0; i < maxKey; ++i) {
      unsigned int c = counts[i];
      counts[i] = pos;
      pos += c;
    }

    Container res (distance (begin, end));
    for_each (begin, end, [&res, &counts] (typename iterator::value_type& ele) {
      res[counts[ele.first]++] = ele;
    });
    out.swap (res);

  }; //counting_sort
}; //sort

#endif //SORT_COUNTING_SORT_H

