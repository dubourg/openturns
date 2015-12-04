// SWIG file RegularGrid.i

%{
#include "PythonWrappingFunctions.hxx"
#include "RegularGrid.hxx"
%}


%include RegularGrid_doc.i

%include RegularGrid.hxx

namespace OT { %extend RegularGrid { RegularGrid(const RegularGrid & other) { return new OT::RegularGrid(other); } } }
