// SWIG file OptimizationProblem.i

%{
#include "OptimizationProblem.hxx"
%}

%include OptimizationProblem_doc.i

%template(OptimizationProblemImplementationTypedInterfaceObject) OT::TypedInterfaceObject<OT::OptimizationProblemImplementation>;

%include OptimizationProblem.hxx
namespace OT{ %extend OptimizationProblem { OptimizationProblem(const OptimizationProblem & other) { return new OT::OptimizationProblem(other); } } }
