/**
 * \file countingsort.h, Contains a counting sort implementation.
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
#ifndef SORT_COUNTINGSORT_H
#define SORT_COUNTINGSORT_H

#include <vector>
#include <map>
#include <list>

namespace sort {
  using namespace std;

  /**
   * Sorts the elements from begin to end in ascending order maintaining stability
   * and splices the result onto the output list. This is slightly different from
   * your normal counting sort. The difference being it doesn't directly count the
   * elements, instead it collects the elements in lists then joins those lists
   * together.
   *
   * Complexity is O(k + n) where k is the number of unique keys and n is the number
   * of elements to sort.
   *
   * Worst case space complexity is O(n + k).
   *
   * \tparam inIterator The type of the input iterator.
   * \tparam out The type of the output list.
   *
   * \param begin The beginning of the elements.
   * \param end The end of the elements.
   * \param o The output list.
   * \param maxKeyLength The maximum length a key can have.
   *
   * \return void.
   */
  template<typename inIterator, typename out>
  void countingsort (const inIterator& begin, const inIterator& end, out& o, unsigned int maxKey) {
    vector<list<typename inIterator::value_type>> bucket (maxKey);

    for (inIterator cur = begin; cur != end; ++cur)
      bucket[cur->first - 1].push_back (*cur);

    for (auto cur = bucket.begin (), end = bucket.end (); cur != end; ++cur)
      o.splice (o.end (), *cur);
  }; //countingsort
}; //sort

#endif //SORT_COUNTINGSORT_H

