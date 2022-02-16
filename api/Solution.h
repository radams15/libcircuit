/**
 * @author Rhys Adams
 * @date 18/04/2021
 */

#ifndef CircuitTester_MNASOLUTION_H
#define CircuitTester_MNASOLUTION_H

#include <map>
#include <vector>
#include "Component.h"

/** @brief Stores the solution of a circuit.
 *
 * This class stores the voltage map, and every component that has
 * a known current so that voltages can be calculated through V=IR.
 *
 */
class Solution {
public:

    /** @brief Initialiser
     *
     * @param voltageMap A map of node:voltage
     * @param components A list of components in the solution which
     * have a known current.
     */
    Solution(std::map<int, double> voltageMap, std::vector<Component> components);

    /** @brief Get the voltage at a specific node.
     *
     * @param nodeIndex The node to check at.
     * @return The voltage at that node.
     */
    double getNodeVoltage(int nodeIndex);

    /** @brief Get the voltage of a specified component.
     *
     * @param component The Component to check at.
     * @return The voltage at that component.
     */
    double getVoltage(Component component);

    /** @brief Gets the current at a resistor through I=V/R
     *
     * @param resistor The resistor to get the current of
     * @return The current at that resistor.
     */
    double getCurrent(Component resistor);
};


#endif //CircuitTester_MNASOLUTION_H
