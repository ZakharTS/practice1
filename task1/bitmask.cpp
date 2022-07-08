#include "bitmask.h"

void set_display(std::set<int> set) {
    for (auto s : set) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
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
    std::cout << std::endl << "<<<<<<<<<<<<<<<";
    for (int i = 0; i < n; i++) {
        set_display(mask_to_set(i, U));
    }
    std::cout << ">>>>>>>>>>>>>>>" << std::endl;
}

std::set<int> fuse(std::set<int> A, std::set<int> B, std::set<int> U) { // объединение
    return mask_to_set(set_to_mask(A, U) | set_to_mask(B, U), U);
}

std::set<int> intersect(std::set<int> A, std::set<int> B, std::set<int> U) { // пересечение
    return mask_to_set(set_to_mask(A, U) & set_to_mask(B, U), U);
}

std::set<int> substract(std::set<int> A, std::set<int> B, std::set<int> U) { // вычитание
    return mask_to_set(set_to_mask(A, U) ^ set_to_mask(intersect(A, B, U), U), U);
}

std::set<int> sim_substract(std::set<int> A, std::set<int> B, std::set<int> U) { // симметрическая разность
    return fuse(substract(A, B, U), substract(B, A, U), U);
}

std::set<int> add(std::set<int> A, std::set<int> U) { // дополнение
    return substract(U, A, U);
}