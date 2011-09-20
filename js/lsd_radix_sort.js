/**
 * \file lsd_radix_sort.js, Contains a lsd_radix_sort implementation.
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
 * lsd radix sort's an array.
 *
 * @param list The array to sort
 * @param maxKeyLength The maximum length of a key.
 * @param radix The radix of the keys.
 * @param asciiOffset The offset into the ascii table of the lowest char in
 *                    a key.
 *
 * @return The sorted array.
 */
function lsd_radix_sort (list, maxKeyLength, radix, asciiOffset) {
  var l = list
  var res = new Array ();

  for (var i = maxKeyLength - 1; i >= 0; --i) {
    var buckets = new Array (radix);
    var pos = maxKeyLength - i;

    l.for_each (function (ele, buckets, asciiOffset) {
      var key = ele.first.toString ();
      var keyLength = key.length;
      buckets[(pos > keyLength) ? 0 : key.charAt (keyLength - pos) - asciiOffset].push (ele);
    }, buckets, asciiOffset);

    buckets.for_each (function (bucket, res) {
      bucket.unshift (bucket.length);
      bucket.unshift (res.length);
      res.push.apply (res, bucket);
    }, res);
    l = res;
  }
  return res;
}

