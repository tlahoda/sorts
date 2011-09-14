/**
 * \file example.cpp, Contains an example of using radixsort and countingsort.
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
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>

#include "radixsort.h"
#include "pigeonholesort.h"

int main (int argc, char** argv) {
  using namespace std;
  using namespace sort;

  cout << "radix sort:" << endl;
  list<pair<string, string>> l;
  l.push_back (make_pair ("30", "3"));
  l.push_back (make_pair ("20", "2a"));
  l.push_back (make_pair ("600", "6c"));
  l.push_back (make_pair ("1", "1"));
  l.push_back (make_pair ("20", "2b"));
  l.push_back (make_pair ("600", "6a"));
  l.push_back (make_pair ("500", "5"));
  l.push_back (make_pair ("40", "4"));
  l.push_back (make_pair ("20", "2c"));
  l.push_back (make_pair ("600", "6b"));

  list<pair<string, string>> res;
  radixsort (l.begin (), l.end (), res, 3);
  for (auto cur = res.begin (), end = res.end (); cur != end; ++cur)
    cout << cur->second << endl;

  cout << endl << "pigeon hole sort:" << endl;
  list<pair<int, string>> l2;
  l2.push_back (make_pair (3, "3"));
  l2.push_back (make_pair (2, "2a"));
  l2.push_back (make_pair (6, "6c"));
  l2.push_back (make_pair (1, "1"));
  l2.push_back (make_pair (2, "2b"));
  l2.push_back (make_pair (6, "6a"));
  l2.push_back (make_pair (5, "5"));
  l2.push_back (make_pair (4, "4"));
  l2.push_back (make_pair (2, "2c"));
  l2.push_back (make_pair (6, "6b"));

  list<pair<int, string>> res2;
  pigeonholesort (l2.begin (), l2.end (), res2, 6);
  for (auto cur = res2.begin (), end = res2.end (); cur != end; ++cur)
    cout << cur->second << endl;
  
  return 0;
};

