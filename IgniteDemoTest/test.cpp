#include "pch.h"

#include "Game.h"

#include <cassert>
#include <iostream>

static void Chance_WithAnyNumbers_ReturnsSum() 
{
    assert(15   == Yahtzee().Chance(2, 3, 4, 5, 1));
}

static void Yahtzee_WithAllMatches_ReturnsFifty() 
{
    int* nums = new int[5]{4, 4, 4, 4, 4};
    assert(50   == Yahtzee().yahtzee(nums));

    delete[] nums;
}

static void Yahtzee_WithoutAllMatches_ReturnsZero() 
{
    int* nums = new int[5]{1, 2, 3, 4, 5};
    assert(0    == Yahtzee().yahtzee(nums));

    delete[] nums;
}

static void Ones_WithTwoOnes_ReturnsTwo() 
{
    assert(2    == Yahtzee().Ones(1, 2, 3, 2, 1));
}

static void Ones_WithZeroOnes_ReturnsZero() 
{
    assert(0    == Yahtzee().Ones(2, 3, 4, 5, 6));
}

static void Ones_WithAllOnes_ReturnsFive() 
{
    assert(5    == Yahtzee().Ones(1, 1, 1, 1, 1));
}

static void Twos_WithTwoTwos_ReturnsFour() 
{
    assert(4    == Yahtzee().Twos(2, 3, 4, 3, 2));
}

static void Twos_WithZeroTwos_ReturnsZero() 
{
    assert(0    == Yahtzee().Twos(1, 3, 4, 5, 6));
}

static void Twos_WithAllTwos_ReturnTen() 
{
    assert(10   == Yahtzee().Twos(2, 2, 2, 2, 2));
}

static void Threes_WithTwoThrees_ReturnsSix() 
{
    assert(6    == Yahtzee().Threes(3, 4, 5, 4, 3));
}

static void Threes_WithZeroThrees_ReturnsZero() 
{
    assert(0    == Yahtzee().Threes(1, 2, 4, 5, 6));
}

static void Threes_WithAllThrees_ReturnsFifteen() 
{
    assert(15   == Yahtzee().Threes(3, 3, 3, 3, 3));
}

static void Fours_WithTwoFours_ReturnsEight() 
{
    assert(8    == Yahtzee(4, 5, 6, 5, 4).Fours());
}

static void Fours_WithZeroFours_ReturnsZero() 
{
    assert(0    == Yahtzee(1, 2, 3, 5, 6).Fours());
}

static void Fours_WithAllFours_ReturnsTwenty() 
{
    assert(20   == Yahtzee(4, 4, 4, 4, 4).Fours());
}

static void Fives_WithTwoFives_ReturnsTen() 
{
    assert(10   == Yahtzee(5, 4, 3, 4, 5).Fives());
}

static void Fives_WithZeroFives_ReturnsZero() 
{
    assert(0    == Yahtzee(1, 2, 3, 4, 6).Fives());
}

static void Fives_WithAllFives_ReturnsTwentyFive() 
{
    assert(25   == Yahtzee(5, 5, 5, 5, 5).Fives());
}

static void Sixes_WithTwoSixes_ReturnsTwelve() 
{
    assert(12   == Yahtzee(6, 5, 4, 5, 6).sixes());
}

static void Sixes_WithZeroSixes_ReturnsZero() 
{
    assert(0    == Yahtzee(1, 2, 3, 4, 5).sixes());
}

static void Sixes_WithAllSixes_ReturnsThirty() 
{
    assert(30   == Yahtzee(6, 6, 6, 6, 6).sixes());
}

static void ScorePair_WithOneLowPair_SumsPair() 
{
    assert(6    == Yahtzee().ScorePair(3, 4, 5, 6, 3));
}

static void ScorePair_WithOneHighPair_SumsPair() 
{
    assert(12   == Yahtzee().ScorePair(6, 5, 4, 6, 3));
}

static void ScorePair_WithNoPairs_ReturnsZero() 
{
    assert(0    == Yahtzee().ScorePair(1, 2, 3, 4, 5));
}

static void TwoPair_WithTwoPairs_SumsPairs() 
{
    assert(16   == Yahtzee().TwoPair(3, 3, 5, 4, 5));
}

static void TwoPair_WithPairAndTriplet_ReturnsZero() 
{
    assert(0    == Yahtzee().TwoPair(3, 4, 3, 4, 3));
}

static void ThreeOfAKind_WithExactlyThreeMatches_ReturnsSum() 
{
    assert(12   == Yahtzee().ThreeOfAKind(4, 5, 6, 4, 4));
}

static void ThreeOfAKind_WithFourOfAKind_ReturnsZero() 
{
    assert(0    == Yahtzee().ThreeOfAKind(4, 4, 4, 4, 5));
}

static void ThreeOfAKind_WithNoMatches_ReturnsZero() 
{
    assert(0    == Yahtzee().ThreeOfAKind(1, 2, 3, 4, 5));
}

static void FourOfAKind_WithExactlyFourMatches_ReturnsSum() 
{
    assert(20   == Yahtzee::FourOfAKind(5, 5, 5, 5, 4));
}

static void FourOfAKind_WithAllMatches_ReturnsZero() 
{
    assert(0    == Yahtzee::FourOfAKind(1, 1, 1, 1, 1));
}

static void FourOfAKind_WithNoMatches_ReturnsZero() 
{
    assert(0    == Yahtzee::FourOfAKind(1, 2, 3, 4, 5));
}

static void SmallStraight_WithSmallStraight_ReturnsFifteen() 
{
    assert(15   == Yahtzee::SmallStraight(1, 2, 3, 4, 5));
    assert(15   == Yahtzee::SmallStraight(5, 4, 3, 2, 1));
}

static void SmallStraight_WithLargeStraight_ReturnsZero() 
{
    assert(0    == Yahtzee::SmallStraight(2, 3, 4, 5, 6));
}

static void SmallStraight_WithoutStraight_ReturnsZero() 
{
    assert(0    == Yahtzee::SmallStraight(2, 2, 2, 2, 2));
}

static void LargeStraight_WithLargeStraight_ReturnsTwenty() 
{
    assert(20   == Yahtzee::LargeStraight(2, 3, 4, 5, 6));
    assert(20   == Yahtzee::LargeStraight(6, 5, 4, 3, 2));
}

static void LargeStraight_WithSmallStraight_ReturnsZero() 
{
    assert(0    == Yahtzee::LargeStraight(1, 2, 3, 4, 5));
}

static void LargeStraight_WithoutStraight_ReturnsZero() 
{
    assert(0    == Yahtzee::LargeStraight(2, 2, 2, 2, 2));
}

static void FullHouse_WithFullHouse_ReturnsSum() 
{
    assert(18   == Yahtzee::FullHouse(2, 2, 2, 6, 6));
}

static void FullHouse_WithTwoPairs_ReturnsZero() 
{
    assert(0    == Yahtzee::FullHouse(2, 2, 3, 3, 4));
}

typedef void test();

static test* tests[] = {
    Chance_WithAnyNumbers_ReturnsSum,
    Yahtzee_WithAllMatches_ReturnsFifty,
    Yahtzee_WithoutAllMatches_ReturnsZero,
    Ones_WithTwoOnes_ReturnsTwo,
    Ones_WithZeroOnes_ReturnsZero,
    Ones_WithAllOnes_ReturnsFive,
    Twos_WithTwoTwos_ReturnsFour,
    Twos_WithZeroTwos_ReturnsZero,
    Twos_WithAllTwos_ReturnTen,
    Threes_WithTwoThrees_ReturnsSix,
    Threes_WithZeroThrees_ReturnsZero,
    Threes_WithAllThrees_ReturnsFifteen,
    Fours_WithTwoFours_ReturnsEight,
    Fours_WithZeroFours_ReturnsZero,
    Fours_WithAllFours_ReturnsTwenty,
    Fives_WithTwoFives_ReturnsTen,
    Fives_WithZeroFives_ReturnsZero,
    Fives_WithAllFives_ReturnsTwentyFive,
    Sixes_WithTwoSixes_ReturnsTwelve,
    Sixes_WithZeroSixes_ReturnsZero,
    Sixes_WithAllSixes_ReturnsThirty,
    ScorePair_WithOneLowPair_SumsPair,
    ScorePair_WithOneHighPair_SumsPair,
    ScorePair_WithNoPairs_ReturnsZero,
    TwoPair_WithTwoPairs_SumsPairs,
    TwoPair_WithPairAndTriplet_ReturnsZero,
    ThreeOfAKind_WithExactlyThreeMatches_ReturnsSum,
    ThreeOfAKind_WithFourOfAKind_ReturnsZero,
    ThreeOfAKind_WithNoMatches_ReturnsZero,
    FourOfAKind_WithExactlyFourMatches_ReturnsSum,
    FourOfAKind_WithAllMatches_ReturnsZero,
    FourOfAKind_WithNoMatches_ReturnsZero,
    SmallStraight_WithSmallStraight_ReturnsFifteen,
    SmallStraight_WithLargeStraight_ReturnsZero,
    SmallStraight_WithoutStraight_ReturnsZero,
    LargeStraight_WithLargeStraight_ReturnsTwenty,
    LargeStraight_WithSmallStraight_ReturnsZero,
    LargeStraight_WithoutStraight_ReturnsZero,
    FullHouse_WithFullHouse_ReturnsSum,
    FullHouse_WithTwoPairs_ReturnsZero
};

int main() {
    size_t at = 0;
    while(tests[at]) {
        tests[at++]();
        std::cout << '.';
    }
    std::cout << std::endl << at << " tests passed" << std::endl;
    return 0;
}
