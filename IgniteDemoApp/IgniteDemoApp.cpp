// IgniteDemoApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"

#include <iostream>
#include <string_view>
#include <optional>
#include <random>

constexpr std::string_view Prompt = "Select One\n"
                                    "\tRock(1)\n"
                                    "\tPaper(2)\n"
                                    "\tScissors(3)\n"
                                    "\tLizard(4)\n"
                                    "\tSpock(5)\n"
                                    "\tExit(0)\n"
                                    "\n";

constexpr Game::Move GetPlayerMove() {
    auto parseInput = [](char entry) -> std::optional<Game::Move> {
        switch(entry) {
        case '1': return Game::Move::Rock;
        case '2': return Game::Move::Paper;
        case '3': return Game::Move::Scissors;
        case '4': return Game::Move::Lizard;
        case '5': return Game::Move::Spock;
        case '0': return Game::Move::Unset;
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

Game::Move GetOpponentMove() {
    static std::random_device rd;
    static auto gen = std::default_random_engine(rd());
    static auto rand = std::uniform_int_distribution{static_cast<int>(Game::Move::Unset) + 1, static_cast<int>(Game::Move::Spock)};
    return static_cast<Game::Move>(rand(gen));
}

int main() {
    std::cout << Prompt;

    auto selectedMove{Game::Move::Unset};
    auto opponentMove{Game::Move::Spock};

    while(true) {
        selectedMove = GetPlayerMove();
        if(selectedMove == Game::Move::Unset) {
            return 0;
        }
        opponentMove = GetOpponentMove();

        std::cout << "You selected " << Game::ToString(selectedMove) << "\n";
        std::cout << "Your opponent selected " << Game::ToString(opponentMove) << "\n";

        auto [p1, p2] = Game::Play(selectedMove, opponentMove);

        std::cout << "You " << Game::ToString(p1) << "!\n\n";
    }
}
