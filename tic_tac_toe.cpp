#include "tic_tac_toe.h"
using namespace std;


 int a = 5;
 int b = 3;
 int c = 8;
 int d = 7;

namespace tic_tac_toe
{
	void GameStart()
	{
		TicTacToe t;
		Elements player1 = Elements::CROSS;
		Elements player2 = Elements::ZERO;
		bool first_step = true;
		for (int i = 1; i < 10; ++i)
		{
			Line x = 0;
			Column y = 0;
			if (first_step)
			{
				cout << "This is place for the game\n";
				t.PrintGame();
				cout << "Player1 plays with a cross\n";
				cout << "Player2 plays with a zero\n" << endl;
				first_step = false;
			}
			if (i % 2 != 0)
			{
				cout << "Player1 enter coordinates line is first number and column is second number from 1 to 3" << endl;
				t.StepGame(player1);
				if (t.GetWiner())
				{
					cout << "Player1 are winer" << endl;
					break;
				}
			}
			else
			{
				cout << "Player2 enter coordinates line is first number and column is second number from 1 to 3" << endl;
				t.StepGame(player2);
				if (t.GetWiner())
				{
					cout << "Player2 are winer" << endl;
					break;
				}
			}
		}
		if (t.GetWiner())
		{
			cout << "The game isn't have a winer" << endl;
		}

	}

	TicTacToe::TicTacToe()
	{
		game_[0][0] = Elements::EMPTY;
		game_[0][1] = Elements::EMPTY;
		game_[0][2] = Elements::EMPTY;
		game_[1][0] = Elements::EMPTY;
		game_[1][1] = Elements::EMPTY;
		game_[1][2] = Elements::EMPTY;
		game_[2][0] = Elements::EMPTY;
		game_[2][1] = Elements::EMPTY;
		game_[2][2] = Elements::EMPTY;
	}

	Point TicTacToe::CreatePoint() const
	{
		Line x = 0;
		Column y = 0;
		cin >> x >> y;
		if ((game_[x][y] == Elements::EMPTY && x > 0 && x < 3 && y > 0 && y < 3))
		{
			return { x , y };
		}
		else if ((game_[x][y] != Elements::EMPTY && x > 0 && x < 3 && y > 0 && y < 3))
		{
			cout << "You inputed incorrect coordinates. Place is busy. Try again" << endl;
			return CreatePoint();
		}
		else
		{
			cout << "You inputed incorrect coordinates. Try again" << endl;
			return CreatePoint();
		}

	}

	void TicTacToe::AddElement(const Point& p, Elements el)
	{
		game_[p.x][p.y] = el;
	}

	bool TicTacToe::Win(Elements el) const
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
		cout << "\t   0   1   2\n" << endl;
		cout << "\t0  " << (char)game_[0][0] << " | "
			<< (char)game_[0][1] << " | " << (char)game_[0][2] << endl;
		cout << "\t  -----------" << endl;
		cout << "\t1  " << (char)game_[1][0] << " | "
			<< (char)game_[1][1] << " | " << (char)game_[1][2] << endl;
		cout << "\t  -----------" << endl;
		cout << "\t2  " << (char)game_[2][0] << " | "
			<< (char)game_[2][1] << " | " << (char)game_[2][2] << endl;
		cout << endl;
	}

	void TicTacToe::StepGame(Elements el)
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

}