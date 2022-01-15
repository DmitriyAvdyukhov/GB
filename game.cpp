#include "tic_tac_toe.h"
#include <memory>

int main() {
	std::string comand;
	std::cout << "Who do you want to play wits? Human or Computer"s << std::endl;
	std::cout << "If it human enter Human else enter Ai"s << std::endl;
	std::cin >> comand;
	
	if (comand == "Human")
	{
		tic_tac_toe::Players players;
		std::cout << "Enter name first player"s << std::endl;
		std::cin >> players.player1;
		std::cout << "Enter name second player"s << std::endl;
		std::cin >> players.player2;
		std::unique_ptr<tic_tac_toe::TicTacToeVsHumen> t 
			= std::make_unique<tic_tac_toe::TicTacToeVsHumen>(players);
		t->GameStart();
	}
	else if (comand == "Ai")
	{
		tic_tac_toe::Players players;
		std::cout << "Enter name  player"s << std::endl;
		std::cin >> players.player1;
		std::unique_ptr<tic_tac_toe::TicTacToeVsComputer> t 
			= std::make_unique<tic_tac_toe::TicTacToeVsComputer>(players);
		t->GameStart();
	}
	return 0;
}