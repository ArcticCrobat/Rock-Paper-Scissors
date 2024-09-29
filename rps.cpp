#include <iostream>
#include <string>

using namespace std;

//R is 1
//P is 2
//S is 3

void playerInput(string &input, string &playerMove) {

    cout << "Pick a move (R for rock, P for paper, and S for scissors): " << endl;

    cin >> input;
    if (input == "R" || input == "r") {
        playerMove = "R";
    }
    else if (input == "P" || input == "p") {
        playerMove = "P";
    }
    else if (input == "S" || input == "s") {
        playerMove = "S";
    }
    else {
        cout << "Please enter a valid value" << endl;
        playerInput(input, playerMove);
    }

    //cout << playerMove << endl;
}

void gameStateOutput(string gamestate)
{
    cout << "The game was a " << gamestate << endl;
}

void checkResults(string playerMoveA, string gamestate, int compMove, int compPoints, int playerPoints){

     //If Player picks Rock
    if (playerMoveA == "R" && compMove == 1){
        gamestate = "tie.";
        gameStateOutput(gamestate); 
    }
    else if (playerMoveA == "R" && compMove == 2)
    {
        gamestate = "win for the computer.";
        gameStateOutput(gamestate); 
        compPoints = compPoints + 1;
    }
    else if (playerMoveA == "R" && compMove == 3)
    {
        gamestate = "loss for the player.";
        gameStateOutput(gamestate); 
        playerPoints = compPoints + 1;
    }
    //If Player picks Paper
    else if (playerMoveA == "P" && compMove == 1)
    {
        gamestate = "win for the player.";
        gameStateOutput(gamestate); 
        playerPoints = playerPoints + 1;
    }
    else if (playerMoveA == "P" && compMove == 2)
    {
        gamestate = "tie.";
        gameStateOutput(gamestate); 
    }
    else if (playerMoveA == "P" && compMove == 3)
    {
        gamestate = "win for the computer.";
        gameStateOutput(gamestate); 
        compPoints = compPoints + 1;
    }
    //If Player picks Scissor
    else if (playerMoveA == "S" && compMove == 1)
    {
        gamestate = "win for the computer.";
        gameStateOutput(gamestate); 
        compPoints = compPoints + 1;
    }
    else if (playerMoveA == "S" && compMove == 2)
    {
        gamestate = "win for the player.";
        gameStateOutput(gamestate); 
        playerPoints = playerPoints + 1;
    }
    else if (playerMoveA == "S" && compMove == 3)
    {
        gamestate = "tie.";
        gameStateOutput(gamestate); 
    }
}
int main()
{
    //Determines computer's move
    int compMove = 0;
    srand(time(NULL));
    compMove = rand() % 3 + 1;

    //Variable Definitions
    string inputA, gamestate="", playerMoveA;
    int playerPoints = 0, compPoints = 0;
    
    //Takes in player move
    playerInput(inputA, playerMoveA);

    //Determins game result
    checkResults(playerMoveA, gamestate, compMove, compPoints, playerPoints);
   
}
