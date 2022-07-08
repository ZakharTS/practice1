#ifndef TASK1_BITMASK_H
#define TASK1_BITMASK_H

#include <set>
#include <iostream>

void set_display(std::set<int> set);

std::set<int> mask_to_set(int mask, std::set<int> uni);

int set_to_mask(std::set<int> set, std::set<int> uni);

#endif