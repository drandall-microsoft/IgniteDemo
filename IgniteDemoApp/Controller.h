#pragma once
#include <iostream>
#include <optional>

#include "Game.h"

constexpr Game::Move GetPlayerMove() {
    auto parseInput = [](char entry) -> std::optional<Game::Move> {
        switch(entry) {
        case '1': return Game::Move::Rock;
        case '2': return Game::Move::Paper;
        case '3': return Game::Move::Scissors;
        case '4': return Game::Move::Lizard;
        case '5': return Game::Move::Spock;
        case '0': return Game::Move::EndGame;
        default: return {};
        }
    };

    char input;
    std::optional<Game::Move> result;

    while(!result.has_value()) {
        std::cin >> input;
        result = parseInput(input);
    }
    return result.value();
}