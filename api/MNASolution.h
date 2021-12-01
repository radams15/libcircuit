/**
 * @author Rhys Adams
 * @date 18/04/2021
 */

#ifndef CircuitTester_MNASOLUTION_H
#define CircuitTester_MNASOLUTION_H

#include <map>
#include <vector>

#include "MNAComponent.h"

/** @brief Stores the solution of a circuit.
 *
 * This class stores the voltage map, and every element that has
 * a known current so that voltages can be calculated through V=IR.
 *
 */
class MNASolution {

public:
    /** @brief A list of elements in the solution which
     * have a known current.
     */
    std::vector<MNAComponent*> elements;

    /** @brief Get the voltage at a specific node.
     *
     * @param nodeIndex The node to check at.
     * @return The voltage at that node.
     */
    double getNodeVoltage(int nodeIndex);

    /** @brief Get the voltage of a specified element.
     *
     * @param element The MNAComponent to check at.
     * @return The voltage at that element.
     */
    double getVoltage(MNAComponent element);

    /** @brief Gets the current at a resistor through I=V/R
     *
     * @param resistor The resistor to get the current of
     * @return The current at that resistor.
     */
    double getCurrent(MNAComponent resistor);
};


#endif //CircuitTester_MNASOLUTION_H
