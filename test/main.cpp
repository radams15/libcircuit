#include <circuit/MNACircuit.h>

int main(){
	auto* b1 = new MNAComponent(0, 1, MNA_BATTERY, 2);
	auto* b2 = new MNAComponent(1, 2, MNA_BATTERY, 4);
	auto* r1 = new MNAComponent(2, 0, MNA_RESISTOR, 1);

	std::vector<MNAComponent *> vec = {b1, r1, b2};
	auto c = new MNACircuit(vec);
	//MNACircuit c(vec);
	auto b = c->solve();
}
