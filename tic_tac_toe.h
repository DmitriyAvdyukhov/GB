#pragma once
#include <iostream>
#include <memory>
#include <functional>

#define SIZE 3

using namespace std::literals; 

namespace tic_tac_toe
{
	enum class Elements
	{
		EMPTY = ' ',
		CROSS = 'X',
		ZERO = '0'
	};

	using Line = size_t;
	using Column = size_t;

	struct Point
	{
		Line x = 0;
		Column y = 0;
	};

	struct Players
	{
		std::string player1 = "Playr 1"s;
		std::string player2 = "Ai"s;
	};

	class TicTacToe
	{
	public:
		TicTacToe();		

		explicit TicTacToe(const Players& players);

		Point CreatePoint()const;

		void AddElement(const Point& p, const Elements& el);

		bool Win(const Elements& el)const;

		void PrintGame()const;

		void StepGame(const Elements& el);

		bool GetWiner()const;

		Players GetPlayers() const;

		bool Process(const std::string& name, const Elements& player);			
		
		void GameStart(std::function<bool()> func);
		
	protected:
		bool is_winer_ = false;
		Players players_;
		Elements game_[SIZE][SIZE];
	};

	class TicTacToeVsHumen : public TicTacToe
	{
	public:
		TicTacToeVsHumen(const Players& players);		

		void GameStartWithHuman();
	};

	class TicTacToeVsComputer : public TicTacToe
	{
	public:
		TicTacToeVsComputer(const Players& players);

		Point CreatePointAi();

		void StepGameAi(const Elements& el);		

		bool ProcessAi(const std::string& name, const Elements& player);
		
		void GameStartWithAi();
	};	
	
}
