from main.python import MNA

cir =[MNA.Component(0, 1, MNA.MNA_BATTERY, 9), MNA.Component(1, 0, MNA.MNA_RESISTOR, 2)]

a = MNA.Circuit(cir)

print(a.solve().getNodeVoltage(1))
