/**
 * \file order_of_magnitude_sort.h, Contains a order of magnitude sort implementation.
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
#ifndef SORT_ORDER_OF_MAGNITUDE_SORT_H
#define SORT_ORDER_OF_MAGNITUDE_SORT_H

#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>

namespace sort {
  using namespace std;

  /**
   * Determines the number of digits of an integer key. This will actually return the
   * number of digits - 1 for indexing from 0.
   *
   * \tparam KeyType The type of the key.
   *
   * \param number The key for which to determine the number of digits.
   *
   * \return The number of digits.
   */
  template<typename KeyType>
  unsigned int count_digits (const KeyType& key) { return 0; };

  /**
   * Specialization for unsigned int.
   */
  template<>
  unsigned int count_digits<unsigned int> (const unsigned int& key) { return floor (log10 (key)); };

  /**
   * Specialization for string.
   */
  template<>
  unsigned int count_digits<string> (const string& key) { return key.size () - 1; };

  /**
   * Sorts the elements from begin to end in ascending order maintaining stability
   * and splices the result onto the output list.
   *
   * Typical and worst case complexity is O(2k + n log k) where k is the number of
   * unique keys and n is the number of elements to sort.
   *
   * Best case complexity is O(2k + n) where k is the number of unique keys and n is
   * the number of elements to sort. This occurs when each key has a unique length.
   *
   * Space complexity is O(k + n) where k is the number of unique keys and n is
   * the number of elements to sort.
   *
   * \tparam keyType The type of the key.
   * \tparam iterator The type of the input iterator.
   * \tparam Container The type of the output containe.
   *
   * \param begin The beginning of the elements.
   * \param end The end of the elements.
   * \param o The output list.
   * \param maxKeyLength The maximum length a key can have.
   *
   * \return void.
   */
  template<typename KeyType, typename iterator, typename Container>
  void order_of_magnitude_sort (const iterator& begin, const iterator& end, Container& out, unsigned int maxKeyLength) {
    vector<map<KeyType, list<typename iterator::value_type>>> buckets (maxKeyLength);

    for_each (begin, end, [&buckets] (typename iterator::value_type& ele) {
      buckets[count_digits (ele.first)][ele.first].push_back (ele);
    });

    Container res;
    for_each (buckets.begin (), buckets.end (), [&res] (map<KeyType, list<typename iterator::value_type>>& d) {
      for_each (d.begin (), d.end (),[&res] (typename map<KeyType, list<typename iterator::value_type>>::value_type& p) {
        res.splice (res.end (), p.second);
      });
    });
    out.swap (res);
  }; //order_of_magnitude_sort
}; //sort

#endif //SORT_ORDER_OF_MAGNITUDE_SORT_H

