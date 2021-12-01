#include <stdio.h>

#include "../src/main/MNA_wrap.h"

int main(){
	CompVector* comps = CompVector_new();
	
	MNAComponent* bat = MNAComponent_new(0, 1, MNA_BATTERY, 9);
	MNAComponent* res = MNAComponent_new(1, 0, MNA_RESISTOR, 2);

	CompVector_push_back(comps, (MNAComponent*) &bat);
	CompVector_push_back(comps, (MNAComponent*) &res);

	MNACircuit* cir = MNACircuit_new(comps);

	MNASolution* sol = MNACircuit_solve(cir);
	
	double i1 = MNASolution_getCurrent(sol, bat);
	double i2 = MNASolution_getCurrent(sol, res);

	printf("I1: %f, I2: %f\n", i1, i2);
}
