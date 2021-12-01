/** @brief Element class for the modified nodal analysis
 * @author Rhys Adams
 * @date 18/04/2021
 */

#ifndef CircuitTester_MNAELEMENT_H
#define CircuitTester_MNAELEMENT_H

#include <cmath>


enum ElementType{
    MNA_BATTERY,
    MNA_RESISTOR
};

/**@brief Main class that holds circuit elements for
 * modified nodal analysis (MNA).
 */
class MNAComponent {

public:
    /** @brief Start node.
     *
     * The node index of the beginning of this element.
     */
    int n0;

    /** @brief End node.
     *
     * The node index of the end of this element.
     */
    int n1;

    /** @brief Component value.
     *
     * This stores the resistance for resistors, the voltage for batteries
     * and the current for current sources.
     */
    double value;

    /** @brief Element Type
     *
     * This is set by derivative classes, can be MNA_BATTERY, MNA_RESISTOR or CURRENT_SRC
     */
    ElementType type;

    /** @brief Initialiser
     *
     * @param n0 The start node
     * @param n1 The end node
     * @param type The element type
     * @param value The value of this component
     * @param currentSolution The current solution if needed, otherwise it is just NAN
     */
    MNAComponent(int n0, int n1, ElementType type, double value, double currentSolution=NAN);
};

#endif //CircuitTester_MNAELEMENT_H
