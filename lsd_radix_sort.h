/**
 * \file lsd_radix_sort.h, Contains a least significant digit radix sort implementation.
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
#ifndef SORT_LSD_RADIX_SORT_H
#define SORT_LSD_RADIX_SORT_H

#include <vector>
#include <map>
#include <list>
#include <algorithm>

namespace sort {
  using namespace std;

  /**
   * Sorts the elements from begin to end in ascending order maintaining stability
   * and places the result into the output container.
   *
   * Complexity is O(d + k(n + d)) where k is the maximum number of digits a key may
   * have, n is the number of elements to be sorted, and d is the radix.
   *
   * \tparam iterator The type of the input iterator.
   * \tparam Container The type of the output container.
   *
   * \param begin The beginning of the elements.
   * \param end The end of the elements.
   * \param out The output container.
   * \param maxKeyLength The maximum length a key can have.
   * \param radix The radix of the keys.
   * \param asciiOffset The offset from 0 of the start of the keys in ascii.
   *
   * \return void.
   */
  template<typename iterator, typename Container>
  void lsd_radix_sort (const iterator& begin, const iterator& end, Container& out, unsigned int maxKeyLength, unsigned int radix = 10, unsigned int asciiOffset = 48) {
    iterator first = begin;
    iterator last = end;

    vector<list<typename iterator::value_type>> buckets (radix);
    for (int i = maxKeyLength - 1; i >= 0; --i) {
      unsigned int position = maxKeyLength - i;
      for_each (first, last, [&] (typename iterator::value_type& ele) {
        unsigned int keyEnd = ele.first.size ();
        buckets[(position > keyEnd) ? 0 : ele.first[keyEnd - position] - asciiOffset].push_back (ele);
      });

      Container res;
      for_each (buckets.begin (), buckets.end (), [&res] (list<typename iterator::value_type>& l) {
        res.splice (res.end (), l);
      });
      out.swap (res);
      
      first = out.begin ();
      last = out.end ();
    }
  }; //lsd_radix_sort
}; //sort

#endif //SORT_LSD_RADIX_SORT_H

