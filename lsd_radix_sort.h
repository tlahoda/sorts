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
   * and splices the result onto the output list.
   *
   * Complexity is O(k*(n + d)) where k is the maximum number of digits a key may
   * have, n is the number of elements to be sorted, and d is the radix.
   *
   * \tparam inIterator The type of the input iterator.
   * \tparam out The type of the output list.
   *
   * \param begin The beginning of the elements.
   * \param end The end of the elements.
   * \param o The output list.
   * \param maxKeyLength The maximum length a key can have.
   * \param radix The radix of the keys.
   * \param asciiOffset The offset from 0 of the start of the keys in ascii.
   *
   * \return void.
   */
  template<typename inIterator, typename out>
  void lsd_radix_sort (const inIterator& begin, const inIterator& end, out& o, unsigned int maxKeyLength, unsigned int radix = 10, unsigned int asciiOffset = 48) {
    inIterator first = begin;
    inIterator last = end;

    for (int i = maxKeyLength - 1; i >= 0; --i) {
      vector<list<typename inIterator::value_type>> buckets (radix);

      unsigned int position = maxKeyLength - i;
      for_each (first, last, [&] (typename inIterator::value_type& ele) {
        unsigned int keyEnd = ele.first.size ();
        buckets[(position > keyEnd) ? 0 : ele.first[keyEnd - position] - asciiOffset].push_back (ele);
      });

      o.clear ();
      for_each (buckets.begin (), buckets.end (), [&o] (list<typename inIterator::value_type>& l) {
        o.splice (o.end (), l);
      });

      first = o.begin ();
      last = o.end ();
    }
  }; //lsd_radix_sort
}; //sort

#endif //SORT_LSD_RADIX_SORT_H

