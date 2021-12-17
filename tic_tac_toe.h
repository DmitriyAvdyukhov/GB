#pragma once
#include <iostream>

namespace tic_tac_toe
{
	enum class Elements
	{
		EMPTY = ' ',
		CROSS = 'X',
		ZERO = '0'
	};

	using Line = int;
	using Column = int;

	struct Point
	{
		Line x = 0;
		Column y = 0;
	};

	class TicTacToe
	{
	public:
		TicTacToe();

		Point CreatePoint()const;

		void AddElement(const Point& p, Elements el);

		bool Win(Elements el)const;

		void PrintGame()const;

		void StepGame(Elements el);

		bool GetWiner()const;

	private:
		bool is_winer_ = false;
		Elements game_[3][3];
	};

	void GameStart();
}
