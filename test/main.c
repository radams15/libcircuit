#include <stdio.h>

#include "MNA_wrap.h"

int main(){
	CompVector* comps = CompVector_new();
	
	MNAComponent* bat = MNAComponent_new(0, 1, MNA_BATTERY, 9);
	MNAComponent* res = MNAComponent_new(1, 0, MNA_RESISTOR, 2);

	CompVector_push_back(comps, &bat);
	CompVector_push_back(comps, &res);

	MNACircuit* cir = MNACircuit_new(comps);

	MNASolution* sol = MNACircuit_solve(cir);
	
	double i1 = MNASolution_getCurrent(&cir, bat);
	double i2 = MNASolution_getCurrent(&cir, res);

	printf("I1: %f, I2: %f\n", i1, i2);
}