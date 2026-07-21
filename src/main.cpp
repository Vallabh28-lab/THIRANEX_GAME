#include <iostream>
#include <vector>

using namespace std;

class TicTacToe
{
private:
    char board[3][3];
    char currentPlayer;

public:

    TicTacToe()
    {
        resetBoard();
        currentPlayer = 'X';
    }

    void resetBoard()
    {
        char value = '1';

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                board[i][j] = value++;
            }
        }
    }

    void displayBoard()
    {
        cout << "\n";
        cout << "-------------\n";

        for(int i = 0; i < 3; i++)
        {
            cout << "| ";

            for(int j = 0; j < 3; j++)
            {
                cout << board[i][j] << " | ";
            }

            cout << "\n-------------\n";
        }

        cout << endl;
    }

    bool placeMark(int position)
    {
        if(position < 1 || position > 9)
            return false;

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if(board[row][col] == 'X' || board[row][col] == 'O')
            return false;

        board[row][col] = currentPlayer;
        return true;
    }

    void switchPlayer()
    {
        if(currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

    char getCurrentPlayer()
    {
        return currentPlayer;
    }

    bool checkRows()
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[i][0] == board[i][1] &&
               board[i][1] == board[i][2])
            {
                return true;
            }
        }

        return false;
    }

    bool checkColumns()
    {
        for(int i = 0; i < 3; i++)
        {
            if(board[0][i] == board[1][i] &&
               board[1][i] == board[2][i])
            {
                return true;
            }
        }

        return false;
    }

    bool checkDiagonals()
    {
        if(board[0][0] == board[1][1] &&
           board[1][1] == board[2][2])
            return true;

        if(board[0][2] == board[1][1] &&
           board[1][1] == board[2][0])
            return true;

        return false;
    }

    bool checkWinner()
    {
        return checkRows() ||
               checkColumns() ||
               checkDiagonals();
    }

    bool boardFull()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] != 'X' &&
                   board[i][j] != 'O')
                {
                    return false;
                }
            }
        }

        return true;
    }
};

void playGame()
{
    TicTacToe game;

    int position;

    while (true)
    {
        game.displayBoard();

        cout << "Player " << game.getCurrentPlayer()
             << ", enter your move (1-9): ";

        cin >> position;

        while (!game.placeMark(position))
        {
            cout << "\nInvalid Move! Try Again: ";
            cin >> position;
        }

        if (game.checkWinner())
        {
            game.displayBoard();

            cout << "\n****************************\n";
            cout << "Player " << game.getCurrentPlayer()
                 << " Wins!\n";
            cout << "****************************\n";

            break;
        }

        if (game.boardFull())
        {
            game.displayBoard();

            cout << "\n****************************\n";
            cout << "Game Draw!\n";
            cout << "****************************\n";

            break;
        }

        game.switchPlayer();
    }
}

int main()
{
    char choice;

    cout << "=========================================\n";
    cout << "        TIC TAC TOE GAME\n";
    cout << "=========================================\n";

    do
    {
        playGame();

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank you for playing!\n";

    return 0;
}

