#include <utility>

//
// Created by nbollom on 25/05/16.
//

#include "game.h"
#include "spells.h"
#include "offensiveattributes.h"
#include "defensiveattributes.h"
#include "character.h"
#include "newgame.h"
#include <iostream>
#include "utils.h"

using namespace std;
using namespace game;
using namespace data;
using namespace file;

Game::Game() {
    random_device random;
    engine = make_shared<mt19937_64>(random());
    game_state = GameStateNone;

    // NOTE: Temporary for debugging game screen
    auto ng = StartNewGame();
    ng->ConfirmCharacter();
}

void Game::SetDaemonMode() {
    function<void(int)> term_callback = [this](int signal){
        Close();
    };
    AddSignalCallback(SIGTERM, term_callback);
    AddSignalCallback(SIGINT, term_callback);
    AddSignalCallback(SIGQUIT, term_callback);
    AddSignalCallback(SIGKILL, term_callback);
}

LoadError Game::LoadGame(string filename_path) {
    filename = std::move(filename_path);
    // TODO: Load game state from file
    game_state = GameStateReady; //if loaded successfully
    return LoadErrorNone;
}

SaveError Game::SaveGame(string filename_path) {
    if (!filename_path.empty()) {
        filename = filename_path;
    }
    if (filename.empty()) {
        return SaveErrorInvalidPath;
    }
    return SaveErrorNone;
}

shared_ptr<NewGame> Game::StartNewGame() {
    return make_shared<NewGame>(engine, [this](shared_ptr<Character> character){
        this->character = character;
        this->character->Level = 1;
        this->character->Experience = 0;
        std::uniform_int_distribution<uint8_t> dist(0, 8);
        this->character->MAX_HP = dist(*engine) + character->CON / 6;
        this->character->MAX_MP = dist(*engine) + character->INT / 6;
        this->character->Equipment[Weapon] = {"Sharp Stick", 0};
        for (uint8_t i = Shield; i <= Sollerets; i++) {
            this->character->Equipment[i] = {"", 0};
        }
        this->character->Gold = 0;
        // NOTE: Temp
        this->character->Plot.emplace_back("Prologue");
        this->character->Plot.emplace_back("Act 1");
        game_state = GameStateReady;
    });
}

void Game::Tick(uint64_t ms) {
    if (game_state == GameStateReady) {

    }
}

GameState Game::GetState() {
    return game_state;
}

void Game::Close() {
    cout << "Closing" << endl;
    SaveGame();
    game_state = GameStateFinished;
}

std::shared_ptr<Character> Game::GetCharacter() {
    return character;
}
