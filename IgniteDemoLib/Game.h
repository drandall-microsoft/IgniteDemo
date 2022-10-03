#pragma once

#include <utility>
#include <string>
#include <string_view>
#include <iostream>

using namespace std::string_view_literals;

namespace Game {
    enum struct Outcome { Invalid, Win, Lose, Draw };
    enum struct Move { EndGame, Rock, Paper, Scissors, Lizard, Spock };

    constexpr auto invalid = std::make_pair(Outcome::Invalid, Outcome::Invalid);
    constexpr auto draw = std::make_pair(Outcome::Draw, Outcome::Draw);
    constexpr auto p1Win = std::make_pair(Outcome::Win, Outcome::Lose);
    constexpr auto p2Win = std::make_pair(Outcome::Lose, Outcome::Win);

    constexpr std::pair<Outcome, Outcome> Play(Move p1Move, Move p2Move) {
        if(p1Move == Move::EndGame || p2Move == Move::EndGame) {
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

} // namespace Game

namespace StrUtil {
    void Concat(const char* lhs, const char* rhs, char** buffer);
}


inline std::ostream& operator<<(std::ostream& stream, const Game::Outcome& outcome) {
    switch(outcome) {
    case Game::Outcome::Win: stream << "Win"; break;
    case Game::Outcome::Lose: stream << "Lose"; break;
    case Game::Outcome::Draw: stream << "Draw"; break;
    default: stream << "Invalid"; break;
    }

    return stream;
}

inline std::ostream& operator<<(std::ostream& stream, const Game::Move& move) {
    switch(move) {
    case Game::Move::Rock: stream << "Rock"; break;
    case Game::Move::Paper: stream << "Paper"; break;
    case Game::Move::Scissors: stream << "Scissors"; break;
    case Game::Move::Lizard: stream << "Lizard"; break;
    case Game::Move::Spock: stream << "Spock"; break;
    default: stream << "Unset"; break;
    }

    return stream;
}

/*
std::string OutcomeToString(Outcome outcome) {
    return "";
}

std::string MoveToString(Move move) {

}
*/