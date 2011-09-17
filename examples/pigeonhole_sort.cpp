/**
 * \file pigeonhole_sort.cpp, Contains an example of using pigeonhole_sort.
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
#include <algorithm>
#include <iostream>

#include "pigeonhole_sort.h"

int main (int argc, char** argv) {
  using namespace std;
  using namespace sort;

  list<pair<int, string>> l;
  l.push_back (make_pair (3, "3"));
  l.push_back (make_pair (2, "2a"));
  l.push_back (make_pair (6, "6c"));
  l.push_back (make_pair (1, "1"));
  l.push_back (make_pair (2, "2b"));
  l.push_back (make_pair (6, "6a"));
  l.push_back (make_pair (5, "5"));
  l.push_back (make_pair (4, "4"));
  l.push_back (make_pair (2, "2c"));
  l.push_back (make_pair (6, "6b"));

  pigeonhole_sort (l.begin (), l.end (), l, 6);
  for (auto cur = l.begin (), end = l.end (); cur != end; ++cur)
    cout << cur->second << endl;
  
  return 0;
};

