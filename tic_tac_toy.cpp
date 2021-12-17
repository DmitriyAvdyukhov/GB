#include "tic_tac_toy.h"
using namespace std;

void GameStart()
{
	TicTacToy t;
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
			cout << "Player1 enter coordinates line x and column  from 1 to 3" << endl;
			t.StepGame(player1);
			if (t.GetWiner())
			{
				cout << "Player1 are winer" << endl;
				break;
			}
		}
		else
		{
			cout << "Player2  enter coordinates line x and column  from 1 to 3" << endl;
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
		cout << "The game isn't hawe a' winer" << endl;
	}

}

TicTacToy::TicTacToy()
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

Point TicTacToy::CreatePoint() const
{
	Line x = 0;
	Column y = 0;
	cin >> x >> y;
	if ((game_[x - 1][y - 1] == Elements::EMPTY && x > 0 && x <= 3 && y > 0 && y <= 3))
	{
		return { x - 1 , y - 1 };
	}
	else if ((game_[x - 1][y - 1] != Elements::EMPTY && x > 0 && x <= 3 && y > 0 && y <= 3))
	{
		cout << "You inputed incorrect coordinats. Place is busy. Try again" << endl;
		return CreatePoint();
	}
	else
	{
		cout << "You inputed incorrect coordinats. Try again" << endl;
		return CreatePoint();
	}

}

void TicTacToy::AddElement(const Point& p, Elements el)
{
	game_[p.x][p.y] = el;
}

bool TicTacToy::Win(Elements el) const
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

void TicTacToy::PrintGame() const
{
	cout << "\t   1   2   3\n" << endl;
	cout << "\t1  " << (char)game_[0][0] << " | "
		<< (char)game_[0][1] << " | " << (char)game_[0][2] << endl;
	cout << "\t  -----------" << endl;
	cout << "\t2  " << (char)game_[1][0] << " | "
		<< (char)game_[1][1] << " | " << (char)game_[1][2] << endl;
	cout << "\t  -----------" << endl;
	cout << "\t3  " << (char)game_[2][0] << " | "
		<< (char)game_[2][1] << " | " << (char)game_[2][2] << endl;
	cout << endl;
}

void TicTacToy::StepGame(Elements el)
{
	AddElement(CreatePoint(), el);
	PrintGame();
	if (Win(el))

	{
		is_winer_ = true;
	}
}

bool TicTacToy::GetWiner() const
{
	return is_winer_;
}
