%module MNA

%{
#include "MNACircuit.h"
#include "MNASolution.h"
#include "MNAComponent.h"
#include <iostream>
%}

%include "std_vector.i"

namespace std {
	%template(CompVector) vector< MNAComponent * >;
}

%include "MNACircuit.h"
%include "MNASolution.h"
%include "MNAComponent.h"
