//                                               -*- C++ -*-
/**
 *  @brief This class is enables to build an exponential covariance
 *  model, a second order model's implementation
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
#ifndef OPENTURNS_EXPONENTIALLYDAMPEDCOSINEMODEL_HXX
#define OPENTURNS_EXPONENTIALLYDAMPEDCOSINEMODEL_HXX

#include "PersistentObject.hxx"
#include "StationaryCovarianceModel.hxx"
#include "NumericalPoint.hxx"
#include "CorrelationMatrix.hxx"
#include "Mesh.hxx"

BEGIN_NAMESPACE_OPENTURNS

class RegularGrid;

/**
 * @class ExponentiallyDampedCosineModel
 */

class OT_API ExponentiallyDampedCosineModel
  : public StationaryCovarianceModel
{

  CLASSNAME;

public:


  /** Constructor with spatial dimension */
  explicit ExponentiallyDampedCosineModel(const UnsignedInteger spatialDimension = 1);

  /** Standard constructor with amplitude and scale parameters */
  ExponentiallyDampedCosineModel(const UnsignedInteger spatialDimension,
                                 const NumericalScalar amplitude,
                                 const NumericalScalar scale,
                                 const NumericalScalar frequency);

  /** Standard constructor with amplitude and scale parameters */
  ExponentiallyDampedCosineModel(const NumericalPoint & amplitude,
                                 const NumericalPoint & scale,
                                 const NumericalScalar frequency);

  /** Virtual copy constructor */
  virtual ExponentiallyDampedCosineModel * clone() const;

  /** Computation of the covariance function, stationary interface */
  using StationaryCovarianceModel::computeStandardRepresentative;
  NumericalScalar computeStandardRepresentative(const NumericalPoint & tau) const;
  using StationaryCovarianceModel::operator();
  CovarianceMatrix operator() (const NumericalPoint & tau) const;
  NumericalScalar computeAsScalar(const NumericalPoint & tau) const;

  /** Discretize the covariance function on a given TimeGrid */
  using StationaryCovarianceModel::discretize;
  CovarianceMatrix discretize(const RegularGrid & regularGrid) const;

  /** Is it a stationary model ? */
  Bool isStationary() const;

  /** String converter */
  String __repr__() const;

  /** String converter */
  String __str__(const String & offset = "") const;

  /** Frequency accessor */
  NumericalScalar getFrequency() const;

protected:

  void setFrequency(const NumericalScalar frequency);

public:

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

private :

  /** Frequency */
  NumericalScalar frequency_;

} ; /* class ExponentiallyDampedCosineModel */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_EXPONENTIALLYDAMPEDCOSINEMODEL_HXX */
