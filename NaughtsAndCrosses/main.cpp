#include <iostream>
#include <array>

//using namespace std;

void displayBoard(std::array<int, 9>& board)
{

	std::cout << "\n==================================\n";

	for (int i = 0; i < 9; i++)
	{
		char space = ' ';

		switch (board[i])
		{
		case 0:
			space = i+49;
			break;
		case 1:
			space = 'X';
			break;
		case 2:
			space = 'O';
			break;
		default:
			break;
		}

		if ((i+1) % 3 == 0)
		{
			std::cout << space << "\n";
		}
		else
		{
			
			std::cout << space << "|";
		}
	
	}

	std::cout << "\n==================================";

}

int getPlacement(std::array<int, 9>& board, int player)
{
	int placement;
	std::cout << "\nEnter a placement (Player " << player << "): ";
	std::cin >> placement;
	--placement;
	while ( (placement <= 0) || (placement >= 8) )
	{
		if ((placement >= 0) && (placement <= 8))
		{
			if (board[placement] == 0)
			{
				return placement;
			}
			else
			{
				placement = 0;
			}
		}
		placement = 0;

		std::cout << "\nThis spot is invalid or taken. Please enter a new spot (Player " << player << "): ";
		std::cin >> placement;
		--placement;
	}

	return placement;
}

int changeTurn(int player)
{
	if (player == 1)
	{
		player = 2;
	}
	else
	{
		player = 1;
	}
	return player;
}

int checkWin(std::array<int, 9>& board, int player)
{
	int connected = 0;
	//Check left to right for wins
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[x + (i * 3)] == player)
			{
				connected++;
				if (connected >= 3)
				{
					return player;
				}
			}
		}
		connected = 0;
	}

	//Check up to down for wins
	connected = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[(x * 3) + i] == player)
			{
				connected++;
				if (connected >= 3)
				{
					return player;
				}
			}
			else
			{
				connected == 0;
			}
		}
		connected = 0;
	}

	//Check "\" diagonal for win
	connected = 0;
	for (int i = 0; i < 3; i++)
	{
		if (board[i * 4] == player)
		{
			connected++;
			if (connected >= 3)
			{
				return player;
			}
			
		}
		else
		{
			connected = 0;
		}
	}
	//Check "/" diagonal for win
	connected = 0;
	for (int i = 0; i < 3; i++)
	{
		if (board[2 + (i * 2)] == player)
		{
			connected++;
			if (connected >= 3)
			{
				return player;
			}
		}
		else
		{
			connected = 0;
		}
	}
	return 0;
}

int main()
{
	//Initialise vars
	int gameState = 0;
	int player = 1;
	std::array<int, 9> board = { 0 };

	//Game loop
	while (gameState == 0)
	{

		displayBoard(board);
		int placement = getPlacement(board, player);

		board[placement] = player;

		gameState = checkWin(board, player);
		player = changeTurn(player);

	}
	displayBoard(board);

	//Display the winner
	switch (gameState)
	{
	case 1:
		std::cout << "\nPlayer 1 wins!";
		break;
	case 2:
		std::cout << "\nPlayer 2 wins!";
		break;
	}
	return 0;
}