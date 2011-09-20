/**
 * \file pigeonhole_sort.js, Contains a pigeonhole_sort implementation.
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
 * pigeonhole sort's an array.
 *
 * @param list The array to sort.
 * @param maxKey The maximum key.
 *
 * @return The sorted array.
 */
function pigeonhole_sort (list, maxKey) {
  var key = new Number (0);
  var buckets = new Array (maxKey).for_each (function (bucket, key) {
    bucket[(key++).toString ()] = new Array ();
  }, key);

  list.for_each (function (ele, buckets) {
    buckets[ele.first - 1].push (ele);
  }, buckets);

  var res = new Array ();
  buckets.for_each (function (bucket, res) {
    bucket.unshift (bucket.length);
    bucket.unshift (res.length);
    res.splice.apply (res, bucket);
  });
  return res;
}

