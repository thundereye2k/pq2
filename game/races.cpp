//
// Created by nbollom on 2/06/16.
//

#include "races.h"
#include <vector>

using namespace std;

namespace data {

    static const vector<Race> races = {
            {"Half Orc",             {"HP Max"}},
            {"Half Man",             {"CHA"}},
            {"Half Halfling",        {"DEX"}},
            {"Double Hobbit",        {"STR"}},
            {"Hob-Hobbit",           {"DEX",    "CON"}},
            {"Low Elf",              {"CON"}},
            {"Dung Elf",             {"WIS"}},
            {"Talking Pony",         {"MP Max", "INT"}},
            {"Gyrognome",            {"DEX"}},
            {"Lesser Dwarf",         {"CON"}},
            {"Crested Dwarf",        {"CHA"}},
            {"Eel Man",              {"DEX"}},
            {"Panda Man",            {"CON",    "STR"}},
            {"Trans-Kobold",         {"WIS"}},
            {"Enchanted Motorcycle", {"MP Max"}},
            {"Will o' the Wisp",     {"WIS"}},
            {"Battle-Finch",         {"DEX",    "INT"}},
            {"Double Wookiee",       {"STR"}},
            {"Skraeling",            {"WIS"}},
            {"Demicanadian",         {"CON"}},
            {"Land Squid",           {"STR",    "HP Max"}}
    };

    static uniform_int_distribution<unsigned long> distribution(0, races.size() - 1);

    const Race get_random_race(std::shared_ptr<std::mt19937_64> engine) {
        unsigned long value = distribution(*engine);
        return races[value];
    }

    const vector<Race> get_race_list() {
        return races;
    }

}
