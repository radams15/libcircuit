//
// Created by rhys on 1/16/22.
//

#include <iostream>
#include "Component.h"
#include "Circuit.h"

int main(){
    auto bat = Component(0, 1, MNA_BATTERY, 10);
    auto res = Component(1, 0, MNA_RESISTOR, 4);

    Component list[] = {bat, res};

    auto cir = new Circuit(list, 2);

    std::map<int, double> vmap = {
            {0, 0.0},
            {1, 10.0},
    };

    auto dessol = new Solution(vmap, {bat});

    auto sol = cir->solve();

    if(!sol.equals(*dessol)){
        std::cerr << "FAIL 1\n";
    }

    if(sol.getCurrent(res) != 2.5){
        std::cerr << "FAIL 2\n";
    }
}