class test{
	static{
		System.load("/home/ubuntu/scripts/libcircuit/src/main/java/_MNA.so");
	}

	public static void main(String[] args){
		new test();
	}
	
	public test(){
		MNAComponent bat = new MNAComponent(0, 1, ElementType.MNA_BATTERY, 9);
		MNAComponent res = new MNAComponent(1, 0, ElementType.MNA_RESISTOR, 2);
		
		CompVector comps = new CompVector();
		comps.add(bat);
		comps.add(res);
		
		MNACircuit cir = new MNACircuit(comps);
		MNASolution sol = cir.solve();
		
		double i1 = sol.getCurrent(res);
		
		System.out.printf("I1: %f\n", i1);
	}
}
