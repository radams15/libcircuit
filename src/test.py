from main.python import MNA

cir = MNA.Circuit()

bat = cir.addComponent(0, 1, MNA.MNA_BATTERY, 9)
res = cir.addComponent(1, 0, MNA.MNA_RESISTOR, 2)

print(cir.getCurrent(res))
