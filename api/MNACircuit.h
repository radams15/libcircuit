/** @brief
 * @author Rhys Adams
 * @date 18/04/2021
 */

#ifndef CircuitTester_MNACIRCUIT_H
#define CircuitTester_MNACIRCUIT_H

#include <vector>

#include "MNAComponent.h"
#include "MNASolution.h"
#include "Term.h"

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

    /** Finds the nodes that are connected to the passed node.
     *
     * @param node The node to search around.
     * @return
     */
    std::vector<int>* getConnectedNodes(int node);

    /** @brief Gets the terms that enter and leave a node.
     *
     * Incoming is negative, outgoing is positive
     *
     * @param node The node to search around.
     * @param side The side we are referring to - 1 for incoming, 0 for outgoing.
     * @return
     */
    std::vector<Term*>* getCurrents(int node, int side);
};

#endif //CircuitTester_MNACIRCUIT_H
