#include <iostream>
#include <set>
#include "bitmask.h"

int main() {
    std::set<int> U = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::set<int> A = {1, 3, 4, 7};
    std::set<int> B = {3, 5, 6, 7, 8};
    std::set<int> C = {2, 4, 5, 7};
    build_boolean(A); // построение булеана
    // примеры работы операций:
    set_display(fuse(A, B, U));
    set_display(intersect(A, B, U));
    set_display(substract(B, A, U));
    set_display(sim_substract(A, B, U));
    set_display(add(A, U));
    std::cout << std::endl;
    set_display(intersect(A, substract(B, C, U), U));// результат выражения согласно варианту
    return 0;
}
