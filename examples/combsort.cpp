/**
 * \file combsort.cpp, Contains an example of using combsort.
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
#include <vector>
#include <iostream>

#include "combsort.h"

int main (int argc, char** argv) {
  using namespace std;
  using namespace sort;

  vector<int> v;
  v.push_back (30);
  v.push_back (20);
  v.push_back (600);
  v.push_back (1);
  v.push_back (20);
  v.push_back (600);
  v.push_back (500);
  v.push_back (40);
  v.push_back (20);
  v.push_back (600);

  combsort (v.begin (), v.end (), 1.247330950103979f);
  for (auto cur = v.begin (), end = v.end (); cur != end; ++cur)
    cout << *cur << endl;
  
  return 0;
};

