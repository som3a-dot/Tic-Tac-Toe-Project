#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <functional>

class UserManager
{
public:
    bool registerUser(const std::string &username, const std::string &password)
    {
        loadUsers();
        if (users.count(username))
        {
            std::cout << "Username already exists.\n";
            return false;
        }
        users[username] = hashPassword(password);
        saveUsers();
        loggedInUser = username;
        return true;
    }

    bool loginUser(const std::string &username, const std::string &password)
    {
        loadUsers();
        if (users.count(username) && users[username] == hashPassword(password))
        {
            loggedInUser = username;
            return true;
        }
        std::cout << "Invalid credentials.\n";
        return false;
    }

    std::string getLoggedInUser() const
    {
        return loggedInUser;
    }

private:
    std::map<std::string, std::string> users;
    std::string loggedInUser;

    void loadUsers()
    {
        users.clear();
        std::ifstream file("users.txt");
        std::string line, uname, hash;
        while (getline(file, line))
        {
            std::istringstream iss(line);
            if (iss >> uname >> hash)
                users[uname] = hash;
        }
    }

    void saveUsers()
    {
        std::ofstream file("users.txt");
        for (const auto &[uname, hash] : users)
        {
            file << uname << " " << hash << "\n";
        }
    }

    std::string hashPassword(const std::string &password) const
    {
        std::hash<std::string> hasher;
        return std::to_string(hasher(password));
    }
};

class TicTacToe
{
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
    char human;
    char ai;
    bool vsAI;
    std::string winner;
    std::string player1Name;
    std::string player2Name;

public:
    TicTacToe(bool playWithAI)
        : board(3, std::vector<char>(3, ' ')), currentPlayer('X'), vsAI(playWithAI), winner("")
    {
        human = 'X';
        ai = 'O';
    }

    void printBoard() const
    {
        std::cout << "\n";
        for (int i = 0; i < 3; ++i)
        {
            std::cout << " ";
            for (int j = 0; j < 3; ++j)
            {
                char cell = board[i][j];
                if (cell == ' ')
                    std::cout << (i * 3 + j + 1);
                else
                    std::cout << cell;
                if (j < 2)
                    std::cout << " | ";
            }
            std::cout << "\n";
            if (i < 2)
                std::cout << "---+---+---\n";
        }
        std::cout << "\n";
    }

    bool makeMove(int move)
    {
        if (move < 1 || move > 9)
            return false;
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] != ' ')
            return false;
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin(char player) const
    {
        for (int i = 0; i < 3; ++i)
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player))
                return true;
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))
            return true;
        return false;
    }

    bool checkTie() const
    {
        return !isMovesLeft() && !checkWin(human) && !checkWin(ai);
    }

    bool isMovesLeft() const
    {
        for (const auto &row : board)
            for (char cell : row)
                if (cell == ' ')
                    return true;
        return false;
    }

    void switchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const
    {
        return currentPlayer;
    }

    void resetGame()
    {
        board.assign(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
        winner.clear();
    }

    void setWinner(std::string player)
    {
        winner = player;
    }

    std::string getWinner() const
    {
        return winner;
    }

    int minimax(int depth, bool isMax, int alpha, int beta)
    {
        if (checkWin(ai))
            return 10 - depth;
        if (checkWin(human))
            return depth - 10;
        if (!isMovesLeft())
            return 0;

        int bestScore = isMax ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = isMax ? ai : human;
                    int score = minimax(depth + 1, !isMax, alpha, beta);
                    board[i][j] = ' ';

                    if (isMax)
                    {
                        bestScore = std::max(bestScore, score);
                        alpha = std::max(alpha, bestScore);
                    }
                    else
                    {
                        bestScore = std::min(bestScore, score);
                        beta = std::min(beta, bestScore);
                    }

                    if (beta <= alpha)
                        return bestScore;
                }
            }
        }
        return bestScore;
    }

    std::pair<int, int> getBestMove()
    {
        int bestScore = std::numeric_limits<int>::min();
        std::pair<int, int> bestMove = {-1, -1};

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = ai;
                    int score = minimax(0, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                    board[i][j] = ' ';

                    if (score > bestScore)
                    {
                        bestScore = score;
                        bestMove = {i, j};
                    }
                }
            }
        }
        return bestMove;
    }

    void playGame()
    {
        std::cout << "Welcome to Tic Tac Toe!\n";
        while (true)
        {
            printBoard();
            if (vsAI && currentPlayer == ai)
            {
                std::cout << "AI is thinking...\n";
                auto [row, col] = getBestMove();
                board[row][col] = ai;
            }
            else
            {
                int move;
                std::cout << "Player " << currentPlayer << " (" << (currentPlayer == 'X' ? player1Name : player2Name) << "), enter your move (1-9): ";
                std::cin >> move;
                if (!makeMove(move))
                {
                    std::cout << "Invalid move. Try again.\n";
                    continue;
                }
            }

            if (checkWin(currentPlayer))
            {
                printBoard();
                std::cout << "Player " << currentPlayer << " wins!\n";
                setWinner(std::string(1, currentPlayer));
                break;
            }

            if (checkTie())
            {
                printBoard();
                std::cout << "It's a tie!\n";
                setWinner("Tie");
                break;
            }

            switchPlayer();
        }
        saveGame();
    }

    void saveGame()
    {
        std::ofstream file("games.txt", std::ios::app);
        file << "Game: " << (vsAI ? "Player vs AI" : "Player vs Player") << "\n";
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                file << board[i][j] << " ";
            }
            file << "\n";
        }
        file << "Winner: " << winner << "\n\n";
    }

    static void viewPastGames()
    {
        std::ifstream file("games.txt");
        std::string line;
        while (getline(file, line))
        {
            std::cout << line << "\n";
        }
    }

    void setPlayerNames(const std::string &name1, const std::string &name2)
    {
        player1Name = name1;
        player2Name = name2;
    }
};

int main()
{
    UserManager userManager;
    int authChoice;
    std::cout << "1. Register\n2. Login\nEnter choice: ";
    std::cin >> authChoice;

    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    bool authenticated = (authChoice == 1)
                             ? userManager.registerUser(username, password)
                             : userManager.loginUser(username, password);

    if (!authenticated)
        return 1;

    std::cout << "Welcome, " << userManager.getLoggedInUser() << "!\n";

    int mainChoice;
    std::cout << "Choose an option:\n1. Start a new game\n2. View past games\nEnter your choice: ";
    std::cin >> mainChoice;

    if (mainChoice == 2)
    {
        TicTacToe::viewPastGames();
        return 0;
    }

    int gameChoice;
    std::cout << "Choose game mode:\n1. Player vs Player\n2. Player vs AI\nEnter your choice: ";
    std::cin >> gameChoice;

    bool playWithAI = (gameChoice == 2);
    TicTacToe game(playWithAI);

    // Only ask for Player 2 name if playing Player vs Player
    if (gameChoice == 1)
    {
        std::string player2;
        std::cout << "Enter Player 2's name: ";
        std::cin >> player2;
        game.setPlayerNames(userManager.getLoggedInUser(), player2);
    }
    else
    {
        // If Player vs AI, Player 1 is the registered user
        game.setPlayerNames(userManager.getLoggedInUser(), "AI");
    }

    game.playGame();

    char replayChoice;
    std::cout << "Do you want to play again or view history? (P for play, H for history): ";
    std::cin >> replayChoice;

    if (replayChoice == 'H' || replayChoice == 'h')
    {
        TicTacToe::viewPastGames();
    }
    else
    {
        main();
    }

    return 0;
}