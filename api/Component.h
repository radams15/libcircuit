/** @brief Component class for the modified nodal analysis
 * @author Rhys Adams
 * @date 18/04/2021
 */

#ifndef CircuitTester_MNAELEMENT_H
#define CircuitTester_MNAELEMENT_H

enum ComponentType{
    MNA_BATTERY,
    MNA_RESISTOR
};

/**@brief Main class that holds circuit components for
 * modified nodal analysis (MNA).
 */
class Component {
public:
    /** @brief Start node.
     *
     * The node index of the beginning of this component.
     */
    int n0;

    /** @brief End node.
     *
     * The node index of the end of this component.
     */
    int n1;

    /** @brief Component value.
     *
     * This stores the resistance for resistors, the voltage for batteries
     * and the current for current sources.
     */
    double value;

    /** @brief Component Type
     *
     * This is set by derivative classes, can be MNA_BATTERY, MNA_RESISTOR or CURRENT_SRC
     */
    ComponentType type;

    /** @brief Initialiser
     *
     * @param n0 The start node
     * @param n1 The end node
     * @param type The component type
     * @param value The value of this component
     */
    Component(int n0, int n1, ComponentType type, double value);

    /** @brief Equality to another node.
     *
     * @param other The node to compare against.
     * @return Whether other has the same contents as this component.
     */
    bool equals(Component other);
};


#endif //CircuitTester_MNAELEMENT_H
