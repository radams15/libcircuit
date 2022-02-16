%module MNA

%{
#include "Circuit.h"
#include "Solution.h"
#include "Component.h"

%}

%include "std_vector.i"
%include "std_map.i"


namespace std {
	%template(CompVector) vector<Component>;
	%template(VoltageMap) std::map<int, double>;
}

%include "../../api/Circuit.h"
%include "../../api/Solution.h"
%include "../../api/Component.h"
