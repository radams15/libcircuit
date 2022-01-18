#include <stdio.h>

#include "../src/main/c/MNA.h"

int main(){
	Circuit* cir = Circuit_new();

	Component* bat = Circuit_addComponent(cir, 0, 1, MNA_BATTERY, 9);
	Component* res = Circuit_addComponent(cir, 1, 0, MNA_RESISTOR, 2);

	double i1 = Circuit_getCurrent(cir, bat);

	double i2 = Circuit_getCurrent(cir, res);

	printf("I1: %f, I2: %f\n", i1, i2);
}
