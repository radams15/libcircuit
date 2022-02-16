/** @brief
 * @author Rhys Adams
 * @date 18/04/2021
 */

#ifndef CircuitTester_MNACIRCUIT_H
#define CircuitTester_MNACIRCUIT_H

#include <vector>

#include "Component.h"
#include "Solution.h"

/** @brief Main class that holds a circuit for
 * modified nodal analysis (MNA).
 *
 */
class Circuit {

public:
    /** @brief Initialises Circuit object.
     *
     * This initialises the Circuit, as well as categorising
     * the components into the batteries, resistors and currentSources
     * vectors. Also generates nodeSet, nodeCount and nodes variables.
     *
     * @param components The list of all circuit components.
    */
    Circuit(std::vector<Component> components);

    /** @brief Solves the circuit using linear algebra and matrices.
     *
     * @return An Solution class for this circuit.
     */
    Solution solve();
};

#endif //CircuitTester_MNACIRCUIT_H
