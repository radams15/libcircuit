//
// Created by rhys on 1/16/22.
//

#include <iostream>
#include "Component.h"
#include "Circuit.h"

int main(){
    auto cir = new Circuit();

    auto bat = cir->addComponent(0, 1, MNA_BATTERY, 10);
    auto res = cir->addComponent(1, 0, MNA_RESISTOR, 4);

    std::map<int, double> vmap = {
            {0, 0.0},
            {1, 10.0},
    };

    auto dessol = new Solution(vmap, {bat});

    auto sol = cir->solve();

    if(!sol.equals(*dessol)){
        std::cerr << "FAIL 1\n";
    }

    if(cir->getCurrent(res) != 2.5){
        std::cerr << "FAIL 2\n";
    }
}