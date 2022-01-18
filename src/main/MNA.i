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
}

%include "Circuit.h"
%include "Solution.h"
%include "Component.h"
