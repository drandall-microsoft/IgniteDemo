// IgniteDemoApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "AI.h"
#include "Controller.h"
#include "Game.h"
#include "StringUtils.h"

#include <iostream>

constexpr std::string_view Prompt = "Select One\n"
                                    "\tRock(1)\n"
                                    "\tPaper(2)\n"
                                    "\tScissors(3)\n"
                                    "\tLizard(4)\n"
                                    "\tSpock(5)\n"
                                    "\tExit(0)\n"
                                    "\n";

// int main() {
//     std::cout << Prompt;
//
//     auto playerMove{Game::Move::EndGame};
//     auto aiMove{Game::Move::Spock};
//
//     while(true) {
//         playerMove = GetPlayerMove();
//         if(playerMove == Game::Move::EndGame) {
//             return 0;
//         }
//         aiMove = GetOpponentMove();
//
//         std::cout << "You selected " << playerMove << "\n";
//         std::cout << "Your opponent selected " << aiMove << "\n";
//
//         Game::Outcome playerOutcome = Game::Play(playerMove, aiMove);
//         std::cout << "You " << playerOutcome << "!\n\n";
//         /*
//         char* outString;
//         StrUtil::Concat("Test", "One", &outString);
//         std::cout << outString;
//         */
//     }
// }
