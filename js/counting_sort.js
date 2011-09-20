/**
 * \file counting_sort.js, Contains a counting_sort implementation.
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
 * Counting sort's an array.
 *
 * @param list The array to sort.
 * @param maxKey The maximum key value.
 */
function counting_sort (list, maxKey) {
  var counts = new Array (maxKey);
  list.for_each (function (ele, counts) { 
    ++counts[ele.first];
  }, counts);

  var pos = new Number (0);
  counts.apply (function (count, pos) {
    var temp = pos;
    pos += count;
    return temp;
  }, pos);

  var res = new Array (list.length);
  list.for_each (function (ele, list, res, counts) {
    res[counts[ele.first]++] = ele;
  }, list, res, counts);
  return res;
}

