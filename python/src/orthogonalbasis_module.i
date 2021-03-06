// SWIG file orthogonalbasis_module.i

%module(package="openturns", docstring="Polynomial primitives.") orthogonalbasis
#pragma SWIG nowarn=302,509
//%feature("autodoc","1");

%{
#include "OTconfig.hxx"
#include "OTBase.hxx"
#include "OTModel.hxx"
#include "OTOrthogonalBasis.hxx"
%}

%include typemaps.i
%include OTtypes.i
%include OTexceptions.i
%include std_vector.i

%import base_module.i

/* Uncertainty/Model */
/* Uncertainty/Distribution */
%import model_copula_module.i
%import UncertaintyModelCopulaTemplateDefs.i

/* Uncertainty/Algorithm/WeightedExperiment */
%import weightedexperiment_module.i

/* Uncertainty/Algorithm/OrthogonalBasis */
%include OrthogonalUniVariatePolynomial.i
%include OrthogonalUniVariatePolynomialFactory.i
%include CharlierFactory.i
%include HermiteFactory.i
%include JacobiFactory.i
%include KrawtchoukFactory.i
%include LaguerreFactory.i
%include LegendreFactory.i
%include MeixnerFactory.i
%include OrthogonalUniVariatePolynomialFamily.i
%include OrthonormalizationAlgorithmImplementation.i
%include OrthonormalizationAlgorithm.i
%include AdaptiveStieltjesAlgorithm.i
%include ChebychevAlgorithm.i
%include GramSchmidtAlgorithm.i
%include StandardDistributionPolynomialFactory.i
%include OrthogonalFunctionFactory.i
%include OrthogonalProductPolynomialFactory.i
%include OrthogonalBasis.i

/* At last we include template definitions */
%include UncertaintyOrthogonalBasisTemplateDefs.i
