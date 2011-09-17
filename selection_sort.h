/**
 * \file selection_sort.h, Contains a selection sort implementation.
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
#ifndef SORT_SELECTION_SORT_H
#define SORT_SELECTION_SORT_H

#include <algorithm>

namespace sort {
  using namespace std;

  /**
   * Sorts the elements in-place from begin to end in ascending order
   * maintaining stability. 
   *
   * Complexity is O(n^2) where n is the number of elements to sort.
   *
   * \tparam iterator The type of the iterators.
   *
   * \param begin The beginning of the elements.
   * \param end The end of the elements.
   *
   * \return void.
   */
  template<typename iterator>
  void selection_sort (const iterator& begin, const iterator& end) {
    for (auto cur = begin; cur != end; ++cur)
      swap (*min_element (cur, end), *cur);
  }; //selection_sort
}; //sort

#endif //SORT_SELECTION_SORT_H

