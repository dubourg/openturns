// SWIG file CompositeProcess.i

%{
#include "CompositeProcess.hxx"
%}

%include CompositeProcess_doc.i

%include CompositeProcess.hxx
namespace OT { %extend CompositeProcess { CompositeProcess(const CompositeProcess & other) { return new OT::CompositeProcess(other); } } }
