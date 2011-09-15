/**
 * \file pigeonholesort.cpp, Contains an example of using pigeonholesort.
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
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

#include "countingsort.h"

int main (int argc, char** argv) {
  using namespace std;
  using namespace sort;

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

  vector<pair<int, string>> res2;
  countingsort (l2.begin (), l2.end (), res2, 7);
  for (auto cur = res2.begin (), end = res2.end (); cur != end; ++cur)
    cout << cur->second << endl;
  
  return 0;
};

