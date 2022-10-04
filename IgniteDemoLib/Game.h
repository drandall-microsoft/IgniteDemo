#pragma once

#include <iostream>


namespace Game {
    enum struct Outcome { Invalid, Win, Lose, Draw };
    enum struct Move { EndGame, Rock, Paper, Scissors, Lizard, Spock };

    constexpr Outcome Play(Move p1Move, Move p2Move) {
        if(p1Move == Move::EndGame || p2Move == Move::EndGame) {
            return Outcome::Invalid;
        }
        if(p1Move == p2Move) {
            return Outcome::Draw;
        }

        switch(p1Move) {
        case Game::Move::Rock:
            if(p2Move == Game::Move::Scissors || p2Move == Game::Move::Lizard)
                return Outcome::Win;
            else
                return Outcome::Lose;
        case Game::Move::Paper:
            if(p2Move == Game::Move::Rock || p2Move == Game::Move::Spock)
                return Outcome::Win;
            else
                return Outcome::Lose;
        case Game::Move::Scissors:
            if(p2Move == Game::Move::Paper || p2Move == Game::Move::Lizard)
                return Outcome::Win;
            else
                return Outcome::Lose;
        case Game::Move::Lizard:
            if(p2Move == Game::Move::Paper || p2Move == Game::Move::Spock)
                return Outcome::Win;
            else
                return Outcome::Lose;
        case Game::Move::Spock:
            if(p2Move == Game::Move::Rock || p2Move == Game::Move::Scissors)
                return Outcome::Win;
            else
                return Outcome::Lose;
        default: return Outcome::Invalid;
        }
    }

} // namespace Game


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