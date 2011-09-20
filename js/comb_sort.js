/**
 * \file comb_sort.js, Contains a comb_sort implementation.
 *
 * Copyright (C) 20011 Thomas P. Lahoda
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

/**
 * Comb sort's an array.
 *
 * @param list The array to sort.
 * @param shrink The shrink factor.
 */
function comb_sort (list, shrink) {
  var gap = list.length / shrink;
  var notSorted = true;

  while (gap > 1 || notSorted) {
    if (gap > 1)
      gap = gap / shrink;

    notSorted = false;
    for (var i = 0; i + gap < list.length; ++i) {
      var next = i + gap;

      if (list[i] > list[next]) {
        list.iter_swap (i, next);
        notSorted = true;
      }
    }
  }
}

