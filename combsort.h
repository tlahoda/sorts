/**
 * \file combsort.h, Contains a comb sort implementation.
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
#ifndef SORT_COMBSORT_H
#define SORT_COMBSORT_H

#include <algorithm>

namespace sort {
  using namespace std;

  /**
   * Sorts the elements in-place from begin to end in ascending order
   * maintaining stability. 
   *
   * Typical, best, and worst case complexities are O(n log n) where n is the
   * number of elements to sort.
   *
   * combsort can be made into bubblesort by passing in a shrink of 
   * distance (begin, end).
   *
   * \tparam iterator The type of the iterators.
   *
   * \param begin The beginning of the elements.
   * \param end The end of the elements.
   * \param shrink The shrink factor.
   *
   * \return void.
   */
  template<typename iterator>
  void combsort (const iterator& begin, const iterator& end, float shrink) {
    float gap = ((float)distance (begin, end)) / shrink;
    bool notSorted = true;

    while (gap > 1.0f || notSorted) {
      if (gap > 1.0f)
        gap = gap / shrink;
      
      notSorted = false;
      for (auto cur = begin; (cur + gap) != end; ++cur) {
        auto next = cur + (unsigned int)gap;

        if (*cur > *next) {
          swap (*cur, *next);
          notSorted = true;
        }
      }
    }
  }; //combsort
}; //sort

#endif //SORT_COMBSORT_H

