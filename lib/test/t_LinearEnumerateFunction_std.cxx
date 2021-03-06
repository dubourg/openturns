//                                               -*- C++ -*-
/**
 *  @brief The test file of class LinearEnumerateFunction for standard methods
 *
 *  Copyright 2005-2015 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "OT.hxx"
#include "OTtestcode.hxx"

using namespace OT;
using namespace OT::Test;

int main(int argc, char *argv[])
{
  TESTPREAMBLE;
  OStream fullprint(std::cout);

  try
  {
    UnsignedInteger size(10);
    for (UnsignedInteger dimension = 1; dimension < 4; ++dimension)
    {
      LinearEnumerateFunction f(dimension);
      fullprint << "First " << size << " values for dimension " << dimension << std::endl;
      for (UnsignedInteger index = 0; index < size; ++index)
      {
        Indices multiIndex(f(index));
        fullprint << "index=" << index << ", multi-index=" << multiIndex << ", linear index=" << f.inverse(multiIndex) << std::endl;
      }
    }
  }
  catch (TestFailed & ex)
  {
    std::cerr << ex << std::endl;
    return ExitCode::Error;
  }

  return ExitCode::Success;
}
