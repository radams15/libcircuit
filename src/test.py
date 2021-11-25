from main import MNA

cir =[MNA.MNAComponent(0, 1, MNA.MNA_BATTERY, 9), MNA.MNAComponent(1, 0, MNA.MNA_RESISTOR, 2)]

a = MNA.MNACircuit(cir)

print(a.solve().getNodeVoltage(1))
