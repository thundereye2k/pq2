//
// Created by nbollom on 3/06/16.
//

#ifndef PQ2_NEWGAME_H
#define PQ2_NEWGAME_H

#include <stack>
#include <random>
#include <memory>
#include <string>
#include "types.h"
#include "character.h"

class NewGame {

private:
    std::shared_ptr<std::mt19937_64> _engine;
    std::shared_ptr<Character> _character;
    std::stack<std::array<uint64_t, 6>> _unrollBuffer;

    void RollEm();
    void RollStat(uint64_t *stat);

public:
    NewGame(std::shared_ptr<std::mt19937_64> engine);
    void GenerateName();
    std::string GetName();
    void SetName(std::string name);
    std::vector<std::string> GetAvailableRaces();
    std::string GetRace();
    void SetRace(std::string name);
    std::vector<std::string> GetAvailableClasses();
    std::string GetClass();
    void SetClass(std::string name);
    void ReRoll();
    bool CanUnroll();
    void UnRoll();
    uint64_t GetSTR();
    uint64_t GetCON();
    uint64_t GetDEX();
    uint64_t GetINT();
    uint64_t GetWIS();
    uint64_t GetCHA();
    uint64_t GetTotal();
    Color GetTotalColor();

};

#endif //PQ2_NEWGAME_H
