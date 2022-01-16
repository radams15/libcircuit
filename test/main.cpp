//
// Created by rhys on 1/16/22.
//

#include <iostream>
#include "MNAComponent.h"
#include "MNACircuit.h"

int main(){
    MNAComponent bat(0, 1, MNA_BATTERY, 10);
    MNAComponent res(1, 0, MNA_RESISTOR, 4);

    auto comps = new std::vector<MNAComponent>;
    comps->push_back(bat);
    comps->push_back(res);

    MNACircuit cir(*comps);

    /*std::map<int, double> vmap = {
            {0, 0.0},
            {1, 10.0},
    };

    auto sol = cir.solve();

    if(sol.getCurrent(res) != 2.5){
        std::cerr << "FAIL 1\n";
    }*/
}