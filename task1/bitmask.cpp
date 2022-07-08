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