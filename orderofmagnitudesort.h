/**
 * \file orderofmagnitudesort.h, Contains a order of magnitude sort implementation.
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
#ifndef SORT_ORDEROFMAGNITUDESORT_H
#define SORT_ORDEROFMAGNITUDESORT_H

#include <string>
#include <vector>
#include <map>
#include <list>
#include <cmath>

namespace sort {
  using namespace std;

  /**
   * Counts the number of digits in an unsigned int.
   */
  struct IntDigitCounter {
    /**
     * Determines the number of digits of an integer key.
     *
     * \param number The key for which to determine the number of digits.
     *
     * \return The number of digits.
     */
    static unsigned int count (int number) { return floor (log10 (abs (number))); };
  };

  /**
   * Counts the number of digits in a string.
   */
  struct StringDigitCounter {
    /**
     * Determines the number of digits of a string key.
     *
     * \param number The key for which to determine the number of digits.
     *
     * \return The number of digits.
     */
    static unsigned int count (const string& number) { return number.size () - 1; };
  };

  /**
   * Sorts the elements from begin to end in ascending order maintaining stability
   * and splices the result onto the output list.
   *
   * Typical and worst case complexity is O(k + n log k) where k is the number of
   * unique keys and n is the number of elements to sort.
   *
   * Best case complexity is O(k + n) where k is the number of unique keys and n is
   * the number of elements to sort. This occurs when each key has a unique length.
   *
   * Space complexity is O(k + n) where k is the number of unique keys and n is
   * the number of elements to sort.
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
  template<typename keyType, typename DigitCounter, typename inIterator, typename out>
  void orderofmagnitudesort (const inIterator& begin, const inIterator& end, out& o, unsigned int maxKeyLength) {
    vector<map<keyType, list<typename inIterator::value_type>>> buckets (maxKeyLength);

    for (inIterator cur = begin; cur != end; ++cur)
      buckets[DigitCounter::count (cur->first)][cur->first].push_back (*cur);

    for (auto d = buckets.begin (), dEnd = buckets.end (); d != dEnd; ++d)
      for (auto p = d->begin (), pEnd = d->end (); p != pEnd; ++p)
        o.splice (o.end (), p->second);
  }; //orderofmagnitudesort
}; //sort

#endif //SORT_ORDEROFMAGNITUDESORT_H

