#include "bitmask.h"

void set_display(std::set<int> set) {
    std::cout << "{ ";
    for (auto s: set) {
        std::cout << s << ", ";
    }
    std::cout << "}" << std::endl;
}

void mask_display(int mask, std::set<int> uni) {
    set_display(mask_to_set(mask, uni));
}

std::set<int> mask_to_set(int mask, std::set<int> uni) {
    std::set<int> set;
    for (int i = 0; i < uni.size(); i++) {
        if (mask & (1 << i)) {
            set.insert(*std::next(uni.begin(), i));
        }
    }
    return set;
}

int set_to_mask(std::set<int> set, std::set<int> uni) {
    int mask = 0;
    for (auto itr = uni.rbegin(); itr != uni.rend(); itr++) {
        mask = mask << 1;
        for (auto s: set) {
            if (s == *itr) {
                mask++;
                break;
            }
        }
    }
    return mask;
}

void build_boolean(std::set<int> U) { // построение булеана
    int n = 1 << U.size();
    for (int i = 0; i < n; i++) {
        mask_display(i, U);
    }
}

std::set<int> fuse(std::set<int> A, std::set<int> B, std::set<int> U) { // объединение множеств
    int maskA = set_to_mask(A, U), maskB = set_to_mask(B, U);
    return mask_to_set(fuse(maskA, maskB), U);
}

int fuse(int maskA, int maskB) { // объединение масок
    return (maskA | maskB);
}

std::set<int> intersect(std::set<int> A, std::set<int> B, std::set<int> U) { // пересечение множеств
    int maskA = set_to_mask(A, U), maskB = set_to_mask(B, U);
    return mask_to_set(intersect(maskA, maskB), U);
}

int intersect(int maskA, int maskB) { // пересечение масок
    return (maskA & maskB);
}

std::set<int> substract(std::set<int> A, std::set<int> B, std::set<int> U) { // вычитание множеств
    int maskA = set_to_mask(A, U), maskB = set_to_mask(B, U);
    return mask_to_set(substract(maskA, maskB), U);
}

int substract(int maskA, int maskB) { // вычитание масок
    return intersect(maskA, add(maskB));
}

std::set<int> sim_substract(std::set<int> A, std::set<int> B, std::set<int> U) { // симметрическая разность множеств
    int maskA = set_to_mask(A, U), maskB = set_to_mask(B, U);
    return mask_to_set(sim_substract(maskA, maskB), U);
}

int sim_substract(int maskA, int maskB) { // симметрическая разность масок
    return fuse(substract(maskA, maskB), substract(maskB, maskA));
}

std::set<int> add(std::set<int> A, std::set<int> U) { // дополнение множества
    int maskA = set_to_mask(A, U), maskU = set_to_mask(U, U);
    return mask_to_set(add(maskA), U);
}

int add(int maskA) { // дополнение маски
    return ~maskA;
}