#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "TicTacToe.hpp"
#include "AIPlayerTestWrapper.hpp"
#include "History.hpp"
#include <vector>
#include <string>

TEST(TicTacToeTest, InitialBoardIsEmpty)
{
    TicTacToe game;
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            EXPECT_EQ(game.getCell(r, c), ' ');
}

TEST(TicTacToeTest, FirstPlayerIsX)
{
    TicTacToe game;
    EXPECT_EQ(game.getCurrentPlayer(), 'X');
}

TEST(TicTacToeTest, MakeValidMove)
{
    TicTacToe game;
    EXPECT_TRUE(game.makeMove(0, 0));
    EXPECT_EQ(game.getCell(0, 0), 'X');
}

TEST(TicTacToeTest, InvalidMoveOnTakenCell)
{
    TicTacToe game;
    game.makeMove(1, 1);
    EXPECT_FALSE(game.makeMove(1, 1));
}

TEST(TicTacToeTest, TurnSwitchesBetweenPlayers)
{
    TicTacToe game;
    game.makeMove(0, 0);
    EXPECT_EQ(game.getCurrentPlayer(), 'O');
    game.makeMove(1, 1);
    EXPECT_EQ(game.getCurrentPlayer(), 'X');
}

TEST(TicTacToeTest, WinInRow)
{
    TicTacToe game;
    game.makeMove(0, 0); // X
    game.makeMove(1, 0); // O
    game.makeMove(0, 1); // X
    game.makeMove(1, 1); // O
    game.makeMove(0, 2); // X wins
    EXPECT_EQ(game.checkWinner(), 'X');
}

TEST(TicTacToeTest, WinInColumn)
{
    TicTacToe game;
    game.makeMove(0, 0); // X
    game.makeMove(0, 1); // O
    game.makeMove(1, 0); // X
    game.makeMove(1, 1); // O
    game.makeMove(2, 0); // X wins
    EXPECT_EQ(game.checkWinner(), 'X');
}

TEST(TicTacToeTest, WinInDiagonal)
{
    TicTacToe game;
    game.makeMove(0, 0); // X
    game.makeMove(0, 1); // O
    game.makeMove(1, 1); // X
    game.makeMove(0, 2); // O
    game.makeMove(2, 2); // X wins
    EXPECT_EQ(game.checkWinner(), 'X');
}

TEST(TicTacToeTest, DetectDraw)
{
    TicTacToe game;
    game.makeMove(0, 0); // X
    game.makeMove(0, 1); // O
    game.makeMove(0, 2); // X
    game.makeMove(1, 1); // O
    game.makeMove(1, 0); // X
    game.makeMove(1, 2); // O
    game.makeMove(2, 1); // X
    game.makeMove(2, 0); // O
    game.makeMove(2, 2); // X
    EXPECT_EQ(game.checkWinner(), 'D');
}

TEST(TicTacToeTest, GameOngoing)
{
    TicTacToe game;
    game.makeMove(0, 0);
    game.makeMove(1, 1);
    EXPECT_EQ(game.checkWinner(), ' ');
}

// Helper to create a 3x3 board from a 9-character string
std::vector<std::vector<char>> createBoard(const std::string &state)
{
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = state[i * 3 + j];
    return board;
}

class AIPlayerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        aiEasy = new AIPlayerTestWrapper('X', 'O', "Easy");
        aiMedium = new AIPlayerTestWrapper('X', 'O', "Medium");
        aiHard = new AIPlayerTestWrapper('X', 'O', "Hard");
    }

    void TearDown() override
    {
        delete aiEasy;
        delete aiMedium;
        delete aiHard;
    }

    AIPlayerTestWrapper *aiEasy;
    AIPlayerTestWrapper *aiMedium;
    AIPlayerTestWrapper *aiHard;
};

TEST_F(AIPlayerTest, EasyAIMakesValidMove)
{
    auto board = createBoard("         ");
    int row = -1, col = -1;
    aiEasy->makeMove(board, row, col);
    EXPECT_TRUE(row >= 0 && row < 3 && col >= 0 && col < 3);
    EXPECT_EQ(board[row][col], 'X');
}

TEST_F(AIPlayerTest, MediumAIBlocksPlayerWin)
{
    auto board = createBoard("OO XX    ");
    int row = -1, col = -1;
    aiHard->makeMove(board, row, col); // Use "Hard" to ensure smart block
    EXPECT_EQ(row, 0);
    EXPECT_EQ(col, 2); // Correctly blocks 'O' from winning
}

TEST_F(AIPlayerTest, HardAIWinsImmediately)
{
    auto board = createBoard("XX  O O  ");
    int row = -1, col = -1;
    aiHard->makeMove(board, row, col);
    EXPECT_EQ(row, 0);
    EXPECT_EQ(col, 2); // Wins immediately by completing top row
}

TEST_F(AIPlayerTest, CheckWinFor_X)
{
    auto board = createBoard("XXXOO    ");
    EXPECT_TRUE(aiEasy->checkWin(board, 'X'));
    EXPECT_FALSE(aiEasy->checkWin(board, 'O'));
}

TEST_F(AIPlayerTest, CheckWinFor_O)
{
    auto board = createBoard("OOOXX    ");
    EXPECT_FALSE(aiEasy->checkWin(board, 'X'));
    EXPECT_TRUE(aiEasy->checkWin(board, 'O'));
}

TEST_F(AIPlayerTest, CheckDraw)
{
    auto board = createBoard("XOXOXOOXO"); // Correct draw board
    EXPECT_TRUE(aiEasy->isBoardFull(board));
    EXPECT_FALSE(aiEasy->checkWin(board, 'X'));
    EXPECT_FALSE(aiEasy->checkWin(board, 'O'));
}

TEST(GameHistoryTest, SaveAndLoadSingleSession)
{
    GameHistory history;
    history.clearHistory();

    GameSession session;
    session.player1Name = "Alice";
    session.player2Name = "Bob";
    session.gameMode = "PvP";
    session.outcome = "Alice wins";
    session.timestamp = "2025-06-20T15:30:00";
    session.winnerSymbol = "X";
    session.moves = {{0, 0}, {1, 1}, {2, 2}};

    history.saveGame(session);
    auto games = history.loadGames();

    ASSERT_EQ(games.size(), 1);
    EXPECT_EQ(games[0].player1Name, "Alice");
    EXPECT_EQ(games[0].winnerSymbol, "X");
    EXPECT_EQ(games[0].moves.size(), 3);
    EXPECT_EQ(games[0].moves[1], std::make_pair(1, 1));
}

TEST(GameHistoryTest, ClearHistory)
{
    GameHistory history;
    history.clearHistory();

    GameSession session;
    session.player1Name = "Test";
    session.player2Name = "Test2";
    session.gameMode = "TestMode";
    session.outcome = "Draw";
    session.timestamp = "2025-06-20T12:00:00";
    session.winnerSymbol = "";
    session.moves = {{0, 1}};

    history.saveGame(session);
    history.clearHistory();
    auto games = history.loadGames();
    EXPECT_TRUE(games.empty());
}

// Integration test simulating a full PvP game with win
TEST(IntegrationTest, PvPGameWithWin)
{
    TicTacToe game;
    EXPECT_TRUE(game.makeMove(0, 0)); // X
    EXPECT_TRUE(game.makeMove(1, 0)); // O
    EXPECT_TRUE(game.makeMove(0, 1)); // X
    EXPECT_TRUE(game.makeMove(1, 1)); // O
    EXPECT_TRUE(game.makeMove(0, 2)); // X wins
    EXPECT_EQ(game.checkWinner(), 'X');
}

// Integration test simulating a PvP draw
TEST(IntegrationTest, PvPGameDraw)
{
    TicTacToe game;
    game.makeMove(0, 0); // X
    game.makeMove(0, 1); // O
    game.makeMove(0, 2); // X
    game.makeMove(1, 1); // O
    game.makeMove(1, 0); // X
    game.makeMove(1, 2); // O
    game.makeMove(2, 1); // X
    game.makeMove(2, 0); // O
    game.makeMove(2, 2); // X
    EXPECT_EQ(game.checkWinner(), 'D');
}

// Integration test: Save and Load History after full game
TEST(IntegrationTest, SaveAndLoadHistory)
{
    GameHistory history;
    history.clearHistory();

    GameSession session;
    session.player1Name = "X";
    session.player2Name = "O";
    session.gameMode = "PvP";
    session.outcome = "X wins";
    session.timestamp = "2025-06-20T20:00:00";
    session.winnerSymbol = "X";
    session.moves = {{0, 0}, {1, 0}, {0, 1}, {1, 1}, {0, 2}};

    history.saveGame(session);
    auto loaded = history.loadGames();
    ASSERT_EQ(loaded.size(), 1);
    EXPECT_EQ(loaded[0].player1Name, "X");
    EXPECT_EQ(loaded[0].winnerSymbol, "X");
    EXPECT_EQ(loaded[0].moves[2], std::make_pair(0, 1));
}

TEST(AIIntegration, PlayerVsAI_FullGameSimulation)
{
    TicTacToe game;
    AIPlayerTestWrapper ai('O', 'X', "Hard");
    GameSession session;
    session.player1Name = "Human";
    session.player2Name = "AI";
    session.gameMode = "PvAI";
    session.timestamp = "2025-06-20T15:45:00";

    while (game.checkWinner() == ' ')
    {
        if (game.getCurrentPlayer() == 'X')
        {
            for (int r = 0; r < 3; ++r)
            {
                for (int c = 0; c < 3; ++c)
                {
                    if (game.getCell(r, c) == ' ')
                    {
                        game.makeMove(r, c);
                        session.moves.emplace_back(r, c);
                        goto next;
                    }
                }
            }
        }
        else
        {
            std::vector<std::vector<char>> board(3, std::vector<char>(3));
            for (int r = 0; r < 3; ++r)
                for (int c = 0; c < 3; ++c)
                    board[r][c] = game.getCell(r, c);

            int aiRow = -1, aiCol = -1;
            ai.makeMove(board, aiRow, aiCol);
            game.makeMove(aiRow, aiCol);
            session.moves.emplace_back(aiRow, aiCol);
        }
    next:;
    }

    char result = game.checkWinner();
    session.outcome = (result == 'X') ? "Human wins" : (result == 'O') ? "AI wins"
                                                                       : "Draw";
    session.winnerSymbol = (result == 'X' || result == 'O') ? std::string(1, result) : "";

    GameHistory history;
    history.clearHistory();
    history.saveGame(session);
    auto games = history.loadGames();

    ASSERT_FALSE(games.empty());
    EXPECT_EQ(games[0].player2Name, "AI");
    EXPECT_EQ(games[0].winnerSymbol, session.winnerSymbol);
    EXPECT_EQ(games[0].moves.size(), session.moves.size());
}

int main()
{

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}