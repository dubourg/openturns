// SWIG file HistoryStrategyImplementation.i

%{
#include "HistoryStrategyImplementation.hxx"
%}

%include HistoryStrategyImplementation_doc.i

%include HistoryStrategyImplementation.hxx
namespace OT{ %extend HistoryStrategyImplementation { HistoryStrategyImplementation(const HistoryStrategyImplementation & other) { return new OT::HistoryStrategyImplementation(other); } } }
