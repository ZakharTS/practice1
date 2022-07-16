#include "bitmask.h"
#include <iostream>
#include <set>


int main() {
    std::set<int> U = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // универсум
    std::set<int> A = {1, 3, 4, 7}; // множества A, B, C согласно варианту
    std::set<int> B = {3, 5, 6, 7, 8};
    std::set<int> C = {2, 4, 5, 7};
    int maskA = set_to_mask(A, U), maskB = set_to_mask(B, U),
            maskC = set_to_mask(C, U), maskU = set_to_mask(U, U);

    std::cout << std::endl << "Boolean";
    build_boolean(A); // построение булеана
    std::cout << "End of boolean" << std::endl << std::endl;

    // примеры работы операций над множествами
    set_display(fuse(A, B, U));
    set_display(intersect(A, B, U));
    set_display(substract(A, B, U));
    set_display(sim_substract(A, B, U));
    set_display(add(A, U));
    std::cout << std::endl;

    // примеры работы операций над масками
    mask_display(fuse(maskA, maskB), U);
    mask_display(intersect(maskA, maskB), U);
    mask_display(substract(maskA, maskB), U);
    mask_display(sim_substract(maskA, maskB), U);
    mask_display(add(maskA), U);
    std::cout << std::endl;

    mask_display(intersect(maskA, substract(maskB, maskC)), U);// результат выражения согласно варианту
    return 0;
}