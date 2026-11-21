#include <iostream>
#include <string>
#include "Vector3D.h"
#include "Set.h"

/**
 * @brief Runs the 3D Vector operations module.
 *
 * Reads two vectors and a scalar from the user,
 * performs mathematical operations and displays the results.
 */
void runVectorModule() {
    double x1, y1, z1, x2, y2, z2, factor;

    std::cout << "\n=========================================" << std::endl;
    std::cout << "         3D VECTOR TESTING MODULE        " << std::endl;
    std::cout << "=========================================" << std::endl;

    // Collect coordinates for the first vector.
    std::cout << "--- Enter Coordinates for Vector 1 ---" << std::endl;
    std::cout << "Enter X1: "; std::cin >> x1;
    std::cout << "Enter Y1: "; std::cin >> y1;
    std::cout << "Enter Z1: "; std::cin >> z1;

    // Collect coordinates for the second vector.
    std::cout << "\n--- Enter Coordinates for Vector 2 ---" << std::endl;
    std::cout << "Enter X2: "; std::cin >> x2;
    std::cout << "Enter Y2: "; std::cin >> y2;
    std::cout << "Enter Z2: "; std::cin >> z2;

    // Collect the scalar value.
    std::cout << "\n--- Enter a Scaling Factor (Number) ---" << std::endl;
    std::cout << "Enter Number: "; std::cin >> factor;

    // Create vector objects.
    Vector3D v1(x1, y1, z1);
    Vector3D v2(x2, y2, z2);

    // Perform vector operations.
    Vector3D addResult = v1 + v2;
    Vector3D subResult = v1 - v2;
    Vector3D crossResult = v1 * v2;
    Vector3D mulScalarResult = v1 * factor;
    Vector3D divScalarResult = v1 / factor;

    // Display vector measurements.
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "            VECTOR RESULTS               " << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "V1 Length: " << v1.length() << " | V2 Length: " << v2.length() << std::endl;
    std::cout << "Cosine of Angle between V1 and V2: " << v1.cosineWith(v2) << std::endl;

    // Display arithmetic results.
    std::cout << "\n[Arithmetic Operations]:" << std::endl;
    std::cout << "V1 + V2 -> X: " << addResult.getx() << ", Y: " << addResult.gety() << ", Z: " << addResult.getz() << std::endl;
    std::cout << "V1 - V2 -> X: " << subResult.getx() << ", Y: " << subResult.gety() << ", Z: " << subResult.getz() << std::endl;
    std::cout << "V1 * V2 (Cross Product) -> X: " << crossResult.getx() << ", Y: " << crossResult.gety() << ", Z: " << crossResult.getz() << std::endl;

    // Display scalar operation results.
    std::cout << "\n[Scalar Operations]:" << std::endl;
    std::cout << "V1 * " << factor << " -> X: " << mulScalarResult.getx() << ", Y: " << mulScalarResult.gety() << ", Z: " << mulScalarResult.getz() << std::endl;
    std::cout << "V1 / " << factor << " -> X: " << divScalarResult.getx() << ", Y: " << divScalarResult.gety() << ", Z: " << divScalarResult.getz() << std::endl;

    // Display vector length comparisons.
    std::cout << "\n[Length Comparisons]:" << std::endl;
    std::cout << "Is V1 > V2 ? : " << (v1 > v2 ? "TRUE" : "FALSE") << std::endl;
    std::cout << "Is V1 < V2 ? : " << (v1 < v2 ? "TRUE" : "FALSE") << std::endl;
}

/**
 * @brief Runs the Unordered Cantor Set operations module.
 *
 * Reads two sets, parses their string representations,
 * performs set operations and displays the results.
 */
void runSetModule() {
    std::string input1, input2;

    std::cout << "\n=========================================" << std::endl;
    std::cout << "         CANTOR SET TESTING MODULE       " << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "Example of valid input format: {a, b, {c, d}, {}}" << std::endl;

    // Clear the input buffer before reading complete lines.
    std::cin.ignore();

    std::cout << "Enter Set 1: ";
    std::getline(std::cin, input1);

    std::cout << "Enter Set 2: ";
    std::getline(std::cin, input2);

    // Parse the input strings into sets.
    Set s1 = Set::fromString(input1);
    Set s2 = Set::fromString(input2);
// Perform set operations.
    Set unionSet = s1 + s2;
    Set intersectSet = s1 * s2;
    Set diffSet = s1 - s2;
    Set powerSet1 = s1.powerSet();

    // Display the results.
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "              SET RESULTS                " << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Parsed Set 1: " << s1.toString() << " (Cardinality = " << s1.cardinality() << ")" << std::endl;
    std::cout << "Parsed Set 2: " << s2.toString() << " (Cardinality = " << s2.cardinality() << ")" << std::endl;

    std::cout << "\n[Set Operations]:" << std::endl;
    std::cout << "Union (Set 1 + Set 2)        : " << unionSet.toString() << std::endl;
    std::cout << "Intersection (Set 1 * Set 2) : " << intersectSet.toString() << std::endl;
    std::cout << "Difference (Set 1 - Set 2)   : " << diffSet.toString() << std::endl;

    // Display advanced set operations.
    std::cout << "\n[Advanced Requirements]:" << std::endl;
    std::cout << "Power Set of Set 1           : " << powerSet1.toString() << std::endl;
}

/**
 * @brief Main entry point of the laboratory program.
 *
 * Displays the interactive menu and allows the user
 * to select a module or exit the program.
 * @return 0 when the program terminates successfully.
 */
int main() {
    int choice = 0;

    while (true) {
        std::cout << "\n=========================================" << std::endl;
        std::cout << "   BSUIR LAB 1 - PPOIS INTERACTIVE MENU  " << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "1. Run 3D Vector Module (Variant 1.1)" << std::endl;
        std::cout << "2. Run Unordered Cantor Set Module (Variant 1.4)" << std::endl;
        std::cout << "3. Exit Program" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

        if (choice == 1) {
            runVectorModule();
        }
        else if (choice == 2) {
            runSetModule();
        }
        else if (choice == 3) {
            std::cout << "\nExiting laboratory program. Goodbye, Nathan!" << std::endl;
            break;
        }
        else {
            std::cout << "\n[ERROR] Invalid entry. Please enter a number between 1 and 3." << std::endl;
        }

        std::cout << "\n\n";
    }

    return 0;
}
