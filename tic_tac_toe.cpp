#include "tic_tac_toe.h"

using namespace std;

namespace tic_tac_toe
{
	TicTacToe::TicTacToe(const Players& players)
		: players_(players)
	{
		for (size_t i = 0; i < SIZE; ++i)
		{
			for (size_t j = 0; j < SIZE; ++j)
			{
				game_[i][j] = Elements::EMPTY;
			}
		}
	}

	Point TicTacToe::CreatePoint() const
	{
		Line x = 0;
		Column y = 0;
		cin >> x >> y;
		if ((game_[x - 1][y - 1] == Elements::EMPTY && x > 0 && x < 4 && y > 0 && y < 4))
		{
			return { x - 1 , y - 1 };
		}
		else if ((game_[x - 1][y - 1] != Elements::EMPTY && x > 0 && x < 4 && y > 0 && y < 4))
		{
			cout << "You inputed incorrect coordinats. Place is busy. Try again"s << endl;
			return CreatePoint();
		}
		else
		{
			cout << "You inputed incorrect coordinats. Try again"s << endl;
			return CreatePoint();
		}

	}

	void TicTacToe::AddElement(const Point& p, const Elements& el)
	{
		game_[p.x][p.y] = el;
	}

	bool TicTacToe::Win(const Elements& el) const
	{
		return
			((game_[0][0] == el && game_[0][1] == el
				&& game_[0][2] == el)
				|| (game_[1][0] == el && game_[1][1] == el
					&& game_[1][2] == el)
				|| (game_[2][0] == el && game_[2][1] == el
					&& game_[2][2] == el)
				|| (game_[0][0] == el && game_[1][0] == el
					&& game_[2][0] == el)
				|| (game_[0][1] == el && game_[1][1] == el
					&& game_[2][1] == el)
				|| (game_[0][2] == el && game_[1][2] == el
					&& game_[2][2] == el)
				|| (game_[0][0] == el && game_[1][1] == el
					&& game_[2][2] == el)
				|| (game_[0][2] == el && game_[1][1] == el
					&& game_[2][0] == el));
	}

	void TicTacToe::PrintGame() const
	{
		cout << "\t   1   2   3\n"s << endl;
		cout << "\t1  "s << (char)game_[0][0] << " | "s
			<< (char)game_[0][1] << " | " << (char)game_[0][2] << endl;
		cout << "\t  -----------"s << endl;
		cout << "\t2  "s << (char)game_[1][0] << " | "s
			<< (char)game_[1][1] << " | "s << (char)game_[1][2] << endl;
		cout << "\t  -----------" << endl;
		cout << "\t3  "s << (char)game_[2][0] << " | "s
			<< (char)game_[2][1] << " | "s << (char)game_[2][2] << endl;
		cout << endl;
	}

	void TicTacToe::StepGame(const Elements& el)
	{
		AddElement(CreatePoint(), el);
		PrintGame();
		if (Win(el))

		{
			is_winer_ = true;
		}
	}

	bool TicTacToe::GetWiner() const
	{
		return is_winer_;
	}

	Players TicTacToe::GetPlayers() const
	{
		return players_;
	}

	TicTacToe::TicTacToe()
	{
		for (size_t i = 0; i < SIZE; ++i)
		{
			for (size_t j = 0; j < SIZE; ++j)
			{
				game_[i][j] = Elements::EMPTY;
			}
		}
	}

	bool TicTacToe::Process(const std::string& name, const Elements& player)
	{
		cout << name << " enter coordinates line x and column  from 1 to 3"s << endl;
		StepGame(player);
		if (GetWiner())
		{
			cout << name << " are winer"s << endl;			
		}
		return GetWiner();
	}

	void TicTacToe::GameStart(std::function<bool()> func)
	{
		Elements player1 = Elements::CROSS;
		Elements player2 = Elements::ZERO;
		bool first_step = true;
		std::unique_ptr<std::string>name1 = std::make_unique<std::string>(GetPlayers().player1);
		std::unique_ptr<std::string>name2 = std::make_unique<std::string>(GetPlayers().player2);
		for (int i = 1; i < 10; ++i)
		{
			if (first_step)
			{
				std::cout << "This is place for the game\n"s;
				PrintGame();
				std::cout << *name1 << " plays with a cross\n"s;
				std::cout << *name2 << " plays with a zero\n"s;
				first_step = false;
			}
			if (i % 2 != 0)
			{
				if (Process(*name1, player1))
				{
					break;
				}
			}
			else
			{
				if (func())
				{
					break;
				}
			}
		}
		if (!GetWiner())
		{
			std::cout << "The game isn't hawe a' winer"s << std::endl;
		}
	}

	void TicTacToeVsHumen::GameStartWithHuman()		
	{
		std::function<bool()> func = [&]() {return Process(players_.player2, Elements::ZERO); };

		GameStart(func);
	}

	TicTacToeVsHumen::TicTacToeVsHumen(const Players& players)
		: TicTacToe(players)
	{}

	TicTacToeVsComputer::TicTacToeVsComputer(const Players& players)
		: TicTacToe(players)
	{}

	Point TicTacToeVsComputer::CreatePointAi()
	{
		for (size_t i = 0; i < SIZE; ++i)
		{
			for (size_t j = 0; j < SIZE; ++j)
			{
				if (game_[i][j] == Elements::EMPTY)
				{
					game_[i][j] = Elements::ZERO;
					if (Win(Elements::ZERO))
					{
						game_[i][j] = Elements::EMPTY;
						return { i, j };
					}
					game_[i][j] = Elements::EMPTY;
				}
				
				if (game_[i][j] == Elements::EMPTY)
				{
					game_[i][j] = Elements::CROSS;
					if (Win(Elements::CROSS))
					{
						game_[i][j] = Elements::EMPTY;
						return { i, j };
					}
					game_[i][j] = Elements::EMPTY;
				}				
			}
		}

		if (game_[1][1] == Elements::EMPTY)
		{
			return { 1, 1 };
		}
		Point buf[4];
		size_t count = 0;
		if (game_[0][2] == Elements::EMPTY)
		{
			buf[count] = { 0, 2 };
			++count;
		}
		if (game_[2][0] == Elements::EMPTY)
		{
			buf[count] = { 2, 0 };
			++count;
		}
		if (game_[2][2] == Elements::EMPTY)
		{
			buf[count] = { 2, 2 };
			++count;
		}
		if (game_[0][0] == Elements::EMPTY)
		{
			buf[count] = { 0, 0 };
			++count;
		}
		if (count > 0)
		{
			const size_t index = rand() % count;
			return buf[index];
		}
		if (game_[0][1] == Elements::EMPTY)
		{
			buf[count] = { 0, 1 };
			++count;
		}
		if (game_[1][0] == Elements::EMPTY)
		{
			buf[count] = { 1, 00 };
			++count;
		}
		if (game_[0][2] == Elements::EMPTY)
		{
			buf[count] = { 1, 2 };
			++count;
		}
		if (game_[0][2] == Elements::EMPTY)
		{
			buf[count] = { 2, 1 };
			++count;
		}
		if (count > 0)
		{
			const size_t index = rand() % count;
			return buf[index];
		}
		return { 0, 0 };
	}

	void TicTacToeVsComputer::StepGameAi(const Elements & el)
	{
		AddElement(CreatePointAi(), el);
		PrintGame();
		if (Win(el))

		{
			is_winer_ = true;
		}
	}

	bool TicTacToeVsComputer::ProcessAi(const std::string& name, const Elements& player)
	{
		cout << name << " is going now"s << endl;
		StepGameAi(player);
		if (GetWiner())
		{
			cout << name << " are winer"s << endl;
		}
		return GetWiner();
	}

	void TicTacToeVsComputer::GameStartWithAi()
	{
		std::function<bool()> func = [&]() {return ProcessAi(players_.player2, Elements::ZERO); };

		GameStart(func);
	}	
}