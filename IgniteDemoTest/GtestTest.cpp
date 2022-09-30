#include "pch.h"

#include "Game.h"

using namespace Game;

TEST(RPS, Anything_AgainstItself_IsADraw) {
    static_assert(draw == Play(Move::Rock, Move::Rock), "Rock vs Rock should be a draw");
    static_assert(draw == Play(Move::Paper, Move::Paper), "Paper vs Paper should be a draw");
    static_assert(draw == Play(Move::Scissors, Move::Scissors), "Scissors vs Scissors should be a draw");
    static_assert(draw == Play(Move::Lizard, Move::Lizard), "Lizard vs Lizard should be a draw");
    static_assert(draw == Play(Move::Spock, Move::Spock), "Spock vs Spock should be a draw");
    
    ASSERT_EQ(draw, Play(Move::Rock, Move::Rock));
    ASSERT_EQ(draw, Play(Move::Paper, Move::Paper));
    ASSERT_EQ(draw, Play(Move::Scissors, Move::Scissors));
    ASSERT_EQ(draw, Play(Move::Lizard, Move::Lizard));
    ASSERT_EQ(draw, Play(Move::Spock, Move::Spock));
}

TEST(RPS, Rock_AgainstScissors_RockWins) {
    static_assert(p1Win == Play(Move::Rock, Move::Scissors), "Rock should beat Scissors");
    static_assert(p2Win == Play(Move::Scissors, Move::Rock), "Scissors should lose to Rock");

    ASSERT_EQ(p1Win, Play(Move::Rock, Move::Scissors));
    ASSERT_EQ(p2Win, Play(Move::Scissors, Move::Rock));
}

TEST(RPS, Rock_AgainstLizard_RockWins) {
    static_assert(p1Win == Play(Move::Rock, Move::Lizard), "Rock should beat Lizard");
    static_assert(p2Win == Play(Move::Lizard, Move::Rock), "Lizard should lose to Rock");

    ASSERT_EQ(p1Win, Play(Move::Rock, Move::Lizard));
    ASSERT_EQ(p2Win, Play(Move::Lizard, Move::Rock));
}

TEST(RPS, Rock_AgainstPaper_PaperWins) {
    static_assert(p1Win == Play(Move::Paper, Move::Rock), "Paper should beat Rock");
    static_assert(p2Win == Play(Move::Rock, Move::Paper), "Rock should lose to Paper");

    ASSERT_EQ(p1Win, Play(Move::Paper, Move::Rock));
    ASSERT_EQ(p2Win, Play(Move::Rock, Move::Paper));
}

TEST(RPS, Rock_AgainstSpock_SpockWins) {
    static_assert(p2Win == Play(Move::Rock, Move::Spock), "Rock should lose to Spock");
    static_assert(p1Win == Play(Move::Spock, Move::Rock), "Spock should beat Rock");

    ASSERT_EQ(p1Win, Play(Move::Spock, Move::Rock));
    ASSERT_EQ(p2Win, Play(Move::Rock, Move::Spock));
}

TEST(RPS, Paper_AgainstSpock_PaperWins) {
    static_assert(p1Win == Play(Move::Paper, Move::Spock), "Paper should beat Spock");
    static_assert(p2Win == Play(Move::Spock, Move::Paper), "Spock should lose to Paper");

    ASSERT_EQ(p1Win, Play(Move::Paper, Move::Spock));
    ASSERT_EQ(p2Win, Play(Move::Spock, Move::Paper));
}

TEST(RPS, Paper_AgainstScissors_ScissorsWins) {
    static_assert(p1Win == Play(Move::Scissors, Move::Paper), "Scissors should beat Paper");
    static_assert(p2Win == Play(Move::Paper, Move::Scissors), "Paper should lose to Scissors");

    ASSERT_EQ(p1Win, Play(Move::Scissors, Move::Paper));
    ASSERT_EQ(p2Win, Play(Move::Paper, Move::Scissors));
}

TEST(RPS, Paper_AgainstLizard_LizardWins) {
    static_assert(p1Win == Play(Move::Lizard, Move::Paper), "Lizard should beat Paper");
    static_assert(p2Win == Play(Move::Paper, Move::Lizard), "Paper should lose to Lizard");

    ASSERT_EQ(p1Win, Play(Move::Lizard, Move::Paper));
    ASSERT_EQ(p2Win, Play(Move::Paper, Move::Lizard));
}

TEST(RPS, Scissors_AgainstLizard_ScissorsWins) {
    static_assert(p1Win == Play(Move::Scissors, Move::Lizard), "Scissors should beat Lizard");
    static_assert(p2Win == Play(Move::Lizard, Move::Scissors), "Lizard should lose to Scissors");

    ASSERT_EQ(p1Win, Play(Move::Scissors, Move::Lizard));
    ASSERT_EQ(p2Win, Play(Move::Lizard, Move::Scissors));
}

TEST(RPS, Scissors_AgainstSpock_SpockWins) {
    static_assert(p1Win == Play(Move::Spock, Move::Scissors), "Spock should beat Scissors");
    static_assert(p2Win == Play(Move::Scissors, Move::Spock), "Scissors should lose to Spock");

    ASSERT_EQ(p1Win, Play(Move::Spock, Move::Scissors));
    ASSERT_EQ(p2Win, Play(Move::Scissors, Move::Spock));
}

TEST(RPS, Lizard_AgainstSpock_LizardWins) {
    static_assert(p1Win == Play(Move::Lizard, Move::Spock), "Lizard should beat Spock");
    static_assert(p2Win == Play(Move::Spock, Move::Lizard), "Spock should lose to Lizard");

    ASSERT_EQ(p1Win, Play(Move::Lizard, Move::Spock));
    ASSERT_EQ(p2Win, Play(Move::Spock, Move::Lizard));
}

TEST(RPS, Unset_AgainstAnything_IsInvalid) {
    static_assert(invalid == Play(Move::Unset, Move::Rock), "Unset against Rock is Invalid");
    static_assert(invalid == Play(Move::Unset, Move::Paper), "Unset against Paper is Invalid");
    static_assert(invalid == Play(Move::Unset, Move::Scissors), "Unset against Scissors is Invalid");
    static_assert(invalid == Play(Move::Unset, Move::Lizard), "Unset against Lizard is Invalid");
    static_assert(invalid == Play(Move::Unset, Move::Spock), "Unset against Spock is Invalid");

    static_assert(invalid == Play(Move::Rock, Move::Unset), "Rock against Unset is Invalid");
    static_assert(invalid == Play(Move::Paper, Move::Unset), "Paper against Unset is Invalid");
    static_assert(invalid == Play(Move::Scissors, Move::Unset), "Scissors against Unset is Invalid");
    static_assert(invalid == Play(Move::Lizard, Move::Unset), "Lizard against Unset is Invalid");
    static_assert(invalid == Play(Move::Spock, Move::Unset), "Spock against Unset is Invalid");

    ASSERT_EQ(invalid, Play(Move::Unset, Move::Rock));
    ASSERT_EQ(invalid, Play(Move::Unset, Move::Paper));
    ASSERT_EQ(invalid, Play(Move::Unset, Move::Scissors));
    ASSERT_EQ(invalid, Play(Move::Unset, Move::Lizard));
    ASSERT_EQ(invalid, Play(Move::Unset, Move::Spock));

    ASSERT_EQ(invalid, Play(Move::Rock, Move::Unset));
    ASSERT_EQ(invalid, Play(Move::Paper, Move::Unset));
    ASSERT_EQ(invalid, Play(Move::Scissors, Move::Unset));
    ASSERT_EQ(invalid, Play(Move::Lizard, Move::Unset));
    ASSERT_EQ(invalid, Play(Move::Spock, Move::Unset));
}

