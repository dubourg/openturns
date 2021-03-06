// SWIG file CenteredFiniteDifferenceHessian.i

%{
#include "CenteredFiniteDifferenceHessian.hxx"
%}

%include CenteredFiniteDifferenceHessian_doc.i

%include CenteredFiniteDifferenceHessian.hxx
namespace OT {  
%extend CenteredFiniteDifferenceHessian {

 CenteredFiniteDifferenceHessian(const CenteredFiniteDifferenceHessian & other)
 {
   return new OT::CenteredFiniteDifferenceHessian(other);
 }

 CenteredFiniteDifferenceHessian(const NumericalPoint & epsilon,
                                 const NumericalMathEvaluationImplementation & evaluation)
 {
   return new OT::CenteredFiniteDifferenceHessian(epsilon, evaluation.clone());
 }

 CenteredFiniteDifferenceHessian(const NumericalScalar epsilon,
                                 const NumericalMathEvaluationImplementation & evaluation)
 {
   return new OT::CenteredFiniteDifferenceHessian(epsilon, evaluation.clone());
 }

}

}
