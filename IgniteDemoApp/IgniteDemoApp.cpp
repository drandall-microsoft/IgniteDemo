// IgniteDemoApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Game.h"
#include "AI.h"
#include "Controller.h"

#include <iostream>


constexpr std::string_view Prompt = "Select One\n"
                                    "\tRock(1)\n"
                                    "\tPaper(2)\n"
                                    "\tScissors(3)\n"
                                    "\tLizard(4)\n"
                                    "\tSpock(5)\n"
                                    "\tExit(0)\n"
                                    "\n";

 


int main() {
    std::cout << Prompt;

    auto playerMove{Game::Move::EndGame};
    auto aiMove{Game::Move::Spock};

    while(true) {
        playerMove = GetPlayerMove();
        if(playerMove == Game::Move::EndGame) {
            return 0;
        }
        aiMove = GetOpponentMove();

        std::cout << "You selected " << playerMove << "\n";
        std::cout << "Your opponent selected " << aiMove << "\n";

        const auto [p1, p2] = Game::Play(playerMove, aiMove);
        std::cout << "You " << p1 << "!\n\n";

        //Game::Outcome outcome = Game::Play(playerMove, aiMove);
        //std::cout << "The winner is: " << Game::Play(playerMove, aiMove);

        //char* outString;
        //StrUtil::Concat("You", std::string(Game::ToString(p1)).c_str(), &outString);
        //std::cout << outString << "\n\n";
        

        //std::cout << StrUtil::Concat("You", std::string(Game::ToString(p1)).c_str());
        //std::cout << "You " << Game::ToString(p1) << "!\n\n";
    }
}
