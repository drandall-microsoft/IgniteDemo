#pragma once

#include <utility>
#include <string>
#include <string_view>
using namespace std::string_view_literals;

namespace Game {
    enum struct Outcome { Invalid, Win, Lose, Draw };
    enum struct Move { Unset, Rock, Paper, Scissors, Lizard, Spock };

    constexpr auto invalid = std::make_pair(Outcome::Invalid, Outcome::Invalid);
    constexpr auto draw = std::make_pair(Outcome::Draw, Outcome::Draw);
    constexpr auto p1Win = std::make_pair(Outcome::Win, Outcome::Lose);
    constexpr auto p2Win = std::make_pair(Outcome::Lose, Outcome::Win);

    constexpr std::pair<Outcome, Outcome> Play(Move p1Move, Move p2Move) {
        if(p1Move == Move::Unset || p2Move == Move::Unset) {
            return invalid;
        }
        if(p1Move == p2Move) {
            return draw;
        }

        switch(p1Move) {
        case Game::Move::Rock:
            if(p2Move == Game::Move::Scissors || p2Move == Game::Move::Lizard)
                return p1Win;
            else
                return p2Win;
        case Game::Move::Paper:
            if(p2Move == Game::Move::Rock || p2Move == Game::Move::Spock)
                return p1Win;
            else
                return p2Win;
        case Game::Move::Scissors:
            if(p2Move == Game::Move::Paper || p2Move == Game::Move::Lizard)
                return p1Win;
            else
                return p2Win;
        case Game::Move::Lizard:
            if(p2Move == Game::Move::Paper || p2Move == Game::Move::Spock)
                return p1Win;
            else
                return p2Win;
        case Game::Move::Spock:
            if(p2Move == Game::Move::Rock || p2Move == Game::Move::Scissors)
                return p1Win;
            else
                return p2Win;
        default: return invalid;
        }
    }

    constexpr std::string_view ToString(const Game::Move move) {
        switch(move) {
        case Move::Rock: return "Rock"sv;
        case Move::Paper: return "Paper"sv;
        case Move::Scissors: return "Scissors"sv;
        case Move::Lizard: return "Lizard"sv;
        case Move::Spock: return "Spock"sv;
        default: return "Unset"sv;
        }
    }

    constexpr std::string_view ToString(const Outcome outcome) {
        switch (outcome) {
        case Outcome::Win: return "Win"sv;
        case Outcome::Lose: return "Lose"sv;
        case Outcome::Draw: return "Draw"sv;
        default: return "Invalid"sv;
        }
    }
} // namespace Game
