// ---------------------------------------------------------------------
//
// Copyright (C) 2005 - 2015 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------


#include "../tests.h"
#include <deal.II/base/patterns.h>
#include <deal.II/base/logstream.h>
#include <deal.II/base/point.h>
#include <deal.II/base/numbers.h>
#include <boost/core/demangle.hpp>

#include <memory>

using namespace dealii;
using namespace Patterns::Tools;

// Try conversion on elementary types

template<class T>
void test(T t)
{
  auto p = Convert<T>::to_pattern();
  deallog << "Pattern  : " << p->description() << std::endl;
  auto s = Convert<T>::to_string(t);
  deallog << "To String: " << s << std::endl;
  deallog << "To value : " << Convert<T>::to_string(Convert<T>::to_value(s)) << std::endl;

}

int main()
{
  initlog();

  int                 t0 = 1;
  unsigned int        t1 = 2;
  types::boundary_id  t2 = 3;
  std::string         t3 = "Ciao";
  double              t4 = 4.0;
  bool                t5 = true;
  float               t6 = 5.5;

  test(t0);
  test(t1);
  test(t2);
  test(t3);
  test(t4);
  test(t5);
  test(t6);

  return 0;
}
