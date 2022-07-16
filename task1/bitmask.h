#ifndef TASK1_BITMASK_H
#define TASK1_BITMASK_H

#include <set>
#include <iostream>

void set_display(std::set<int> set);

void mask_display(int mask, std::set<int> uni);

std::set<int> mask_to_set(int mask, std::set<int> uni);

int set_to_mask(std::set<int> set, std::set<int> uni);

void build_boolean(std::set<int> U); // построение булеана

std::set<int> fuse(std::set<int> A, std::set<int> B, std::set<int> U); // объединение множеств
int fuse(int maskA, int maskB); // объединение масок

std::set<int> intersect(std::set<int> A, std::set<int> B, std::set<int> U); // пересечение множеств
int intersect(int maskA, int maskB); // пересечение масок

std::set<int> substract(std::set<int> A, std::set<int> B, std::set<int> U); // вычитание множеств
int substract(int maskA, int maskB); // вычитание масок

std::set<int> sim_substract(std::set<int> A, std::set<int> B, std::set<int> U); // симметрическая разность множеств
int sim_substract(int maskA, int maskB); // симметрическая разность масок

std::set<int> add(std::set<int> A, std::set<int> U); // дополнение множества
int add(int maskA); // дополнение маски

#endif