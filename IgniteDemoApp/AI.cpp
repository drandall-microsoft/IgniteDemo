#include "AI.h"
#include <random>

Game::Move GetOpponentMove() {
    static std::random_device rd;
    static auto gen = std::default_random_engine(rd());
    static auto rand = std::uniform_int_distribution{static_cast<int>(Game::Move::EndGame) + 1, static_cast<int>(Game::Move::Spock)};
    return static_cast<Game::Move>(rand(gen));
}
