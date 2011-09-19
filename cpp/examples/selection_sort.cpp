/**
 * \file selection_sort.cpp, Contains an example of using selection_sort.
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
#include <list>
#include <iostream>

#include "selection_sort.h"

int main (int argc, char** argv) {
  using namespace std;
  using namespace sort;

  list<int> l;
  l.push_back (30);
  l.push_back (20);
  l.push_back (600);
  l.push_back (1);
  l.push_back (20);
  l.push_back (600);
  l.push_back (500);
  l.push_back (40);
  l.push_back (20);
  l.push_back (600);

  list<int> res;
  selection_sort (l.begin (), l.end ());
  for (auto cur = l.begin (), end = l.end (); cur != end; ++cur)
    cout << (*cur) << endl;
  
  return 0;
};

