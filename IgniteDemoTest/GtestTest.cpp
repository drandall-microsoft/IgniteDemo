#include "pch.h"
#include "Game.h"

static int* ints(int a, int b, int c, int d, int e)
{
    int* r = new int[5];
    r[0] = a;
    r[1] = b;
    r[2] = c;
    r[3] = d;
    r[4] = e;
    return r;
}

TEST(YahtzeeTest, Chance_scores_sum_of_all_dice)
{
    int expected = 15;
    int actual = Yahtzee().Chance(2, 3, 4, 5, 1);
    ASSERT_TRUE(expected == actual);
    ASSERT_TRUE(16 == Yahtzee().Chance(3, 3, 4, 5, 1));
}

TEST(YahtzeeTest, Yahtzee_scores_50)
{
    int expected = 50;
    int actual = Yahtzee().yahtzee(ints(4, 4, 4, 4, 4));
    ASSERT_TRUE(expected == actual);
    ASSERT_TRUE(50 == Yahtzee().yahtzee(ints(6, 6, 6, 6, 6)));
    ASSERT_TRUE(0 == Yahtzee().yahtzee(ints(6, 6, 6, 6, 3)));
}

TEST(YahtzeeTest, Test_1s)
{
    ASSERT_TRUE(Yahtzee().Ones(1, 2, 3, 4, 5) == 1);
    ASSERT_TRUE(2 == Yahtzee().Ones(1, 2, 1, 4, 5));
    ASSERT_TRUE(0 == Yahtzee().Ones(6, 2, 2, 4, 5));
    ASSERT_TRUE(4 == Yahtzee().Ones(1, 2, 1, 1, 1));
}

TEST(YahtzeeTest, test_2s)
{
    ASSERT_TRUE(4 == Yahtzee().Twos(1, 2, 3, 2, 6));
    ASSERT_TRUE(10 == Yahtzee().Twos(2, 2, 2, 2, 2));
}

TEST(YahtzeeTest, test_threes)
{
    ASSERT_TRUE(6 == Yahtzee().Threes(1, 2, 3, 2, 3));
    ASSERT_TRUE(12 == Yahtzee().Threes(2, 3, 3, 3, 3));
}

TEST(YahtzeeTest, fours_test)
{
    ASSERT_TRUE(12 == (new Yahtzee(4, 4, 4, 5, 5))->Fours());
    ASSERT_TRUE(8 == (new Yahtzee(4, 4, 5, 5, 5))->Fours());
    ASSERT_TRUE(4 == (*new Yahtzee(4, 5, 5, 5, 5)).Fours());
}

TEST(YahtzeeTest, fives) {
    ASSERT_TRUE(10 == (new Yahtzee(4, 4, 4, 5, 5))->Fives());
    ASSERT_TRUE(15 == Yahtzee(4, 4, 5, 5, 5).Fives());
    ASSERT_TRUE(20 == Yahtzee(4, 5, 5, 5, 5).Fives());
}

TEST(YahtzeeTest, sixes_test)
{
    ASSERT_TRUE(0 == Yahtzee(4, 4, 4, 5, 5).sixes());
    ASSERT_TRUE(6 == Yahtzee(4, 4, 6, 5, 5).sixes());
    ASSERT_TRUE(18 == Yahtzee(6, 5, 6, 6, 5).sixes());
}

TEST(YahtzeeTest, one_pair)
{
    ASSERT_TRUE(6 == Yahtzee().ScorePair(3, 4, 3, 5, 6));
    ASSERT_TRUE(10 == Yahtzee().ScorePair(5, 3, 3, 3, 5));
    ASSERT_TRUE(12 == Yahtzee().ScorePair(5, 3, 6, 6, 5));
}

TEST(YahtzeeTest, two_Pair)
{
    ASSERT_TRUE(16 == Yahtzee().TwoPair(3, 3, 5, 4, 5));
    ASSERT_TRUE(0 == Yahtzee().TwoPair(3, 3, 5, 5, 5));
}

TEST(YahtzeeTest, three_of_a_kind)
{
    ASSERT_TRUE(9 == Yahtzee().ThreeOfAKind(3, 3, 3, 4, 5));
    ASSERT_TRUE(15 == Yahtzee().ThreeOfAKind(5, 3, 5, 4, 5));
    ASSERT_TRUE(0 == Yahtzee::ThreeOfAKind(3, 3, 3, 3, 5));
}

TEST(YahtzeeTest, four_of_a_knd)
{
    ASSERT_TRUE(12 == Yahtzee::FourOfAKind(3, 3, 3, 3, 5));
    ASSERT_TRUE(20 == Yahtzee::FourOfAKind(5, 5, 5, 4, 5));
    ASSERT_TRUE(0 == Yahtzee::FourOfAKind(3, 3, 3, 3, 3));
}

TEST(YahtzeeTest, smallStraight)
{
    ASSERT_TRUE(15 == Yahtzee::SmallStraight(1, 2, 3, 4, 5));
    ASSERT_TRUE(15 == Yahtzee::SmallStraight(2, 3, 4, 5, 1));
    ASSERT_TRUE(0 == Yahtzee().SmallStraight(1, 2, 2, 4, 5));
}

TEST(YahtzeeTest, largeStraight)
{
    ASSERT_TRUE(20 == Yahtzee::LargeStraight(6, 2, 3, 4, 5));
    ASSERT_TRUE(20 == Yahtzee().LargeStraight(2, 3, 4, 5, 6));
    ASSERT_TRUE(0 == Yahtzee::LargeStraight(1, 2, 2, 4, 5));
}


TEST(YahtzeeTest, fullHouse)
{
    ASSERT_TRUE(18 == Yahtzee().FullHouse(6, 2, 2, 2, 6));
    ASSERT_TRUE(0 == Yahtzee().FullHouse(2, 3, 4, 5, 6));
}

