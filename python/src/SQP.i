// SWIG file SQP.i

%{
#include "SQP.hxx"
%}

%include SQP_doc.i

%include SQP.hxx
namespace OT{ %extend SQP { SQP(const SQP & other) { return new OT::SQP(other); } } }
