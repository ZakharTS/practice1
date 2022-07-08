#ifndef TASK1_BITMASK_H
#define TASK1_BITMASK_H

#include <set>
#include <iostream>

void set_display(std::set<int> set);

std::set<int> mask_to_set(int mask, std::set<int> uni);

int set_to_mask(std::set<int> set, std::set<int> uni);

void build_boolean(std::set<int> U); // построение булеана

std::set<int> fuse(std::set<int> A, std::set<int> B, std::set<int> U); // объединение

std::set<int> intersect(std::set<int> A, std::set<int> B, std::set<int> U); // пересечение

std::set<int> substract(std::set<int> A, std::set<int> B, std::set<int> U); // вычитание

std::set<int> sim_substract(std::set<int> A, std::set<int> B, std::set<int> U); // симметрическая разность

std::set<int> add(std::set<int> A, std::set<int> U); // дополнение
#endif