/**
 * \file lsdradix.h, Contains a least significant digit radix sort implementation.
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
#ifndef SORT_LSDRADIXSORT_H
#define SORT_LSDRADIXSORT_H

#include <vector>
#include <map>
#include <list>

namespace sort {
  using namespace std;

  /**
   * Sorts the elements from begin to end in ascending order maintaining stability
   * and splices the result onto the output list.
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
  void lsdradixsort (const inIterator& begin, const inIterator& end, out& o, unsigned int maxKeyLength, unsigned int radix = 10, unsigned int asciiOffset = 48) {
    inIterator first = begin;
    inIterator last = end;

    list<typename inIterator::value_type> a;
    for (int i = maxKeyLength - 1; i >= 0; --i) {
      vector<list<typename inIterator::value_type>> buckets (radix);

      for (auto cur = first; cur != last; ++cur) {
        unsigned int keyEnd = cur->first.size ();
        unsigned int position = maxKeyLength - i;
        buckets[(position > keyEnd) ? 0 : cur->first[keyEnd - position] - asciiOffset].push_back (*cur);
      }

      a.clear ();
      for (auto cur = buckets.begin (), end = buckets.end (); cur != end; ++cur)
        a.splice (a.end (), *cur);

      first = a.begin ();
      last = a.end ();
    }
    o.splice (o.end (), a);
  }; //lsdradixsort
}; //sort

#endif //SORT_LSDRADIXSORT_H

