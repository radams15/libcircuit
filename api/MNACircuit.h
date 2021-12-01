/** @brief
 * @author Rhys Adams
 * @date 18/04/2021
 */

#ifndef CircuitTester_MNACIRCUIT_H
#define CircuitTester_MNACIRCUIT_H

#include <vector>

#include "MNAComponent.h"
#include "MNASolution.h"

/** @brief Main class that holds a circuit for
 * modified nodal analysis (MNA).
 *
 */
class MNACircuit {

public:
    /** @brief Initialises MNACircuit object.
     *
     * This initialises the MNACircuit, as well as categorising
     * the elements into the batteries, resistors and currentSources
     * vectors. Also generates nodeSet, nodeCount and nodes variables.
     *
     * @param elements The list of all circuit elements.
    */
    explicit MNACircuit(std::vector<MNAComponent *> elements);

    /** @brief Solves the circuit using linear algebra and matrices.
     *
     * @return An MNASolution class for this circuit.
     */
    MNASolution* solve();
};

#endif //CircuitTester_MNACIRCUIT_H
