// SWIG file stattests_module.i

%module(package="openturns", docstring="Statistical tests.") stattests
#pragma SWIG nowarn=302,509
//%feature("autodoc","1");

%{
#include "OTconfig.hxx"
#include "OTBase.hxx"
#include "OTModel.hxx"
#include "OTDistribution.hxx"
#include "OTStatTests.hxx"
%}

%include typemaps.i
%include OTtypes.i
%include OTexceptions.i
%include std_vector.i

%import base_module.i

/* Uncertainty/Model */
/* Uncertainty/Distribution */
%include UncertaintyModelCopulaCollection.i
%import model_copula_module.i
%import UncertaintyModelCopulaTemplateDefs.i

/* Uncertainty/StatTests */
%include VisualTest.i
%include FittingTest.i
%include HypothesisTest.i
%include LinearModelTest.i
%include NormalityTest.i
%include DickeyFullerTest.i

/* At last we include template definitions */
%include UncertaintyStatTestsTemplateDefs.i
