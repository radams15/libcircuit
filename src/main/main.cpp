//
// Created by rhys on 1/16/22.
//

#include <iostream>
#include "MNAComponent.h"
#include "MNACircuit.h"

int main(){
    auto bat = MNAComponent(0, 1, MNA_BATTERY, 10);
    auto res = MNAComponent(1, 0, MNA_RESISTOR, 4);

    auto cir = new MNACircuit({bat, res});

    std::map<int, double> vmap = {
            {0, 0.0},
            {1, 10.0},
    };

    MNASolution dessol(vmap, {bat});

    auto sol = cir->solve();

    if(!sol.equals(dessol)){
        std::cerr << "FAIL 1\n";
    }

    if(sol.getCurrent(res) != 2.5){
        std::cerr << "FAIL 2\n";
    }
}