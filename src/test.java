import uk.co.therhys.MNA.*;

class test{
	static{
		System.load("/mnt/share/scripts/libcircuit/src/main/java/libMNA.so");
	}

	public static void main(String[] args){
		new test();
	}
	
	public test(){
		Component bat = new Component(0, 1, ComponentType.MNA_BATTERY, 9);
		Component res = new Component(1, 0, ComponentType.MNA_RESISTOR, 2);
		
		CompVector comps = new CompVector();
		comps.add(bat);
		comps.add(res);
		
		Circuit cir = new Circuit(comps);
		Solution sol = cir.solve();
		
		double i1 = sol.getCurrent(res);
		
		System.out.printf("I1: %f\n", i1);
	}
}
