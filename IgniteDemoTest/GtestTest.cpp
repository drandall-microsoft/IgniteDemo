#include "pch.h"

#include "Game.h"

using namespace Game;

TEST(RPS, Anything_AgainstItself_IsADraw) {
    static_assert(Outcome::Draw == Play(Move::Rock, Move::Rock), "Rock vs Rock should be a draw");
    static_assert(Outcome::Draw == Play(Move::Paper, Move::Paper), "Paper vs Paper should be a draw");
    static_assert(Outcome::Draw == Play(Move::Scissors, Move::Scissors), "Scissors vs Scissors should be a draw");
    static_assert(Outcome::Draw == Play(Move::Lizard, Move::Lizard), "Lizard vs Lizard should be a draw");
    static_assert(Outcome::Draw == Play(Move::Spock, Move::Spock), "Spock vs Spock should be a draw");
    
    ASSERT_EQ(Outcome::Draw, Play(Move::Rock, Move::Rock));
    ASSERT_EQ(Outcome::Draw, Play(Move::Paper, Move::Paper));
    ASSERT_EQ(Outcome::Draw, Play(Move::Scissors, Move::Scissors));
    ASSERT_EQ(Outcome::Draw, Play(Move::Lizard, Move::Lizard));
    ASSERT_EQ(Outcome::Draw, Play(Move::Spock, Move::Spock));
}

TEST(RPS, Rock_AgainstScissors_RockWins) {
    static_assert(Outcome::Win == Play(Move::Rock, Move::Scissors), "Rock should beat Scissors");
    static_assert(Outcome::Lose == Play(Move::Scissors, Move::Rock), "Scissors should lose to Rock");

    ASSERT_EQ(Outcome::Win, Play(Move::Rock, Move::Scissors));
    ASSERT_EQ(Outcome::Lose, Play(Move::Scissors, Move::Rock));
}

TEST(RPS, Rock_AgainstLizard_RockWins) {
    static_assert(Outcome::Win == Play(Move::Rock, Move::Lizard), "Rock should beat Lizard");
    static_assert(Outcome::Lose == Play(Move::Lizard, Move::Rock), "Lizard should lose to Rock");

    ASSERT_EQ(Outcome::Win, Play(Move::Rock, Move::Lizard));
    ASSERT_EQ(Outcome::Lose, Play(Move::Lizard, Move::Rock));
}

TEST(RPS, Rock_AgainstPaper_PaperWins) {
    static_assert(Outcome::Win == Play(Move::Paper, Move::Rock), "Paper should beat Rock");
    static_assert(Outcome::Lose == Play(Move::Rock, Move::Paper), "Rock should lose to Paper");

    ASSERT_EQ(Outcome::Win, Play(Move::Paper, Move::Rock));
    ASSERT_EQ(Outcome::Lose, Play(Move::Rock, Move::Paper));
}

TEST(RPS, Rock_AgainstSpock_SpockWins) {
    static_assert(Outcome::Lose == Play(Move::Rock, Move::Spock), "Rock should lose to Spock");
    static_assert(Outcome::Win == Play(Move::Spock, Move::Rock), "Spock should beat Rock");

    ASSERT_EQ(Outcome::Win, Play(Move::Spock, Move::Rock));
    ASSERT_EQ(Outcome::Lose, Play(Move::Rock, Move::Spock));
}

TEST(RPS, Paper_AgainstSpock_PaperWins) {
    static_assert(Outcome::Win == Play(Move::Paper, Move::Spock), "Paper should beat Spock");
    static_assert(Outcome::Lose == Play(Move::Spock, Move::Paper), "Spock should lose to Paper");

    ASSERT_EQ(Outcome::Win, Play(Move::Paper, Move::Spock));
    ASSERT_EQ(Outcome::Lose, Play(Move::Spock, Move::Paper));
}

TEST(RPS, Paper_AgainstScissors_ScissorsWins) {
    static_assert(Outcome::Win == Play(Move::Scissors, Move::Paper), "Scissors should beat Paper");
    static_assert(Outcome::Lose == Play(Move::Paper, Move::Scissors), "Paper should lose to Scissors");

    ASSERT_EQ(Outcome::Win, Play(Move::Scissors, Move::Paper));
    ASSERT_EQ(Outcome::Lose, Play(Move::Paper, Move::Scissors));
}

TEST(RPS, Paper_AgainstLizard_LizardWins) {
    static_assert(Outcome::Win == Play(Move::Lizard, Move::Paper), "Lizard should beat Paper");
    static_assert(Outcome::Lose == Play(Move::Paper, Move::Lizard), "Paper should lose to Lizard");

    ASSERT_EQ(Outcome::Win, Play(Move::Lizard, Move::Paper));
    ASSERT_EQ(Outcome::Lose, Play(Move::Paper, Move::Lizard));
}

TEST(RPS, Scissors_AgainstLizard_ScissorsWins) {
    static_assert(Outcome::Win == Play(Move::Scissors, Move::Lizard), "Scissors should beat Lizard");
    static_assert(Outcome::Lose == Play(Move::Lizard, Move::Scissors), "Lizard should lose to Scissors");

    ASSERT_EQ(Outcome::Win, Play(Move::Scissors, Move::Lizard));
    ASSERT_EQ(Outcome::Lose, Play(Move::Lizard, Move::Scissors));
}

TEST(RPS, Scissors_AgainstSpock_SpockWins) {
    static_assert(Outcome::Win == Play(Move::Spock, Move::Scissors), "Spock should beat Scissors");
    static_assert(Outcome::Lose == Play(Move::Scissors, Move::Spock), "Scissors should lose to Spock");

    ASSERT_EQ(Outcome::Win, Play(Move::Spock, Move::Scissors));
    ASSERT_EQ(Outcome::Lose, Play(Move::Scissors, Move::Spock));
}

TEST(RPS, Lizard_AgainstSpock_LizardWins) {
    static_assert(Outcome::Win == Play(Move::Lizard, Move::Spock), "Lizard should beat Spock");
    static_assert(Outcome::Lose == Play(Move::Spock, Move::Lizard), "Spock should lose to Lizard");

    ASSERT_EQ(Outcome::Win, Play(Move::Lizard, Move::Spock));
    ASSERT_EQ(Outcome::Lose, Play(Move::Spock, Move::Lizard));
}

TEST(RPS, EndGame_AgainstAnything_IsInvalid) {
    static_assert(Outcome::Invalid == Play(Move::EndGame, Move::Rock), "Unset against Rock is Invalid");
    static_assert(Outcome::Invalid == Play(Move::EndGame, Move::Paper), "Unset against Paper is Invalid");
    static_assert(Outcome::Invalid == Play(Move::EndGame, Move::Scissors), "Unset against Scissors is Invalid");
    static_assert(Outcome::Invalid == Play(Move::EndGame, Move::Lizard), "Unset against Lizard is Invalid");
    static_assert(Outcome::Invalid == Play(Move::EndGame, Move::Spock), "Unset against Spock is Invalid");

    static_assert(Outcome::Invalid == Play(Move::Rock, Move::EndGame), "Rock against Unset is Invalid");
    static_assert(Outcome::Invalid == Play(Move::Paper, Move::EndGame), "Paper against Unset is Invalid");
    static_assert(Outcome::Invalid == Play(Move::Scissors, Move::EndGame), "Scissors against Unset is Invalid");
    static_assert(Outcome::Invalid == Play(Move::Lizard, Move::EndGame), "Lizard against Unset is Invalid");
    static_assert(Outcome::Invalid == Play(Move::Spock, Move::EndGame), "Spock against Unset is Invalid");

    ASSERT_EQ(Outcome::Invalid, Play(Move::EndGame, Move::Rock));
    ASSERT_EQ(Outcome::Invalid, Play(Move::EndGame, Move::Paper));
    ASSERT_EQ(Outcome::Invalid, Play(Move::EndGame, Move::Scissors));
    ASSERT_EQ(Outcome::Invalid, Play(Move::EndGame, Move::Lizard));
    ASSERT_EQ(Outcome::Invalid, Play(Move::EndGame, Move::Spock));

    ASSERT_EQ(Outcome::Invalid, Play(Move::Rock, Move::EndGame));
    ASSERT_EQ(Outcome::Invalid, Play(Move::Paper, Move::EndGame));
    ASSERT_EQ(Outcome::Invalid, Play(Move::Scissors, Move::EndGame));
    ASSERT_EQ(Outcome::Invalid, Play(Move::Lizard, Move::EndGame));
    ASSERT_EQ(Outcome::Invalid, Play(Move::Spock, Move::EndGame));
}

