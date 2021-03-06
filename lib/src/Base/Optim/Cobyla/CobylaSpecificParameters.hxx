//                                               -*- C++ -*-
/**
 *  @brief CobylaSpecificParameters is an encapsulation of the Cobyla specific
 *         parameters.
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
#ifndef OPENTURNS_COBYLASPECIFICPARAMETERS_HXX
#define OPENTURNS_COBYLASPECIFICPARAMETERS_HXX

#include "OTprivate.hxx"
#include "PersistentObject.hxx"

BEGIN_NAMESPACE_OPENTURNS



/**
 * @class CobylaSpecificParameters
 * Specific parameters of the cobyla library
 */
class OT_API CobylaSpecificParameters
  : public PersistentObject
{

  CLASSNAME;

public:
  /** Default constructor */
  CobylaSpecificParameters();

  /** Parameters constructor */
  explicit CobylaSpecificParameters(const NumericalScalar rhoBeg);

  /** Virtual constructor */
  virtual CobylaSpecificParameters * clone() const;

  /** RhoBeg accessor */
  NumericalScalar getRhoBeg() const;
  void setRhoBeg(const NumericalScalar rhoBeg);

  /** String converter */
  String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

private:

  NumericalScalar rhoBeg_;
}; /* class CobylaSpecificParameters */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_COBYLASPECIFICPARAMETERS_HXX */
