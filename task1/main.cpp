#include <iostream>
#include <set>
#include "bitmask.h"

int main() {
    std::set<int> U = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::set<int> A = {2, 4, 10};
    std::cout << set_to_mask(A, U) << std::endl;
    A = mask_to_set(set_to_mask(A, U), U);
    set_display(A);
    return 0;
}
