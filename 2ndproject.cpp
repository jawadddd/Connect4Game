#include<iostream>
#include<string>

using namespace std;


struct connect4{

    connect4(string Names[]){
        re_init(Names);
    }
    connect4(){
        string N[2] = {"P1", "P2"};
        re_init(N);
    }
    void re_init(string Names[]){

        for(int i = 0; i< 7; i++){
            ColumnMoves[i] = 5;
            for(int j = 0; j< 6; j++)
                Data[j][i] = 32; // 32 is code of space character
        }
        Result = 0;
        GameOver = 0;
        PlayerNames[0] = Names[0];
        PlayerNames[1] = Names[1];
        PlayerChar[0] = 'o';
        PlayerChar[1] = 'x';
        PlayerWinningChar[0] = 'O';
        PlayerWinningChar[1] = 'X';
    }

    int MakeMove(int Column){
    /*
        This Function must make a move in the Column given as a parameter
        The function will use the function GameOver() to mark is the game
        is completed and set the value of variables GameOver and Result.
        The function must also update the array ColumnMoves.

        The function must return 0 if the move has been made, 1 if the move
        is invalid (can not be done as the column is already filled) and 2
        if the game is already over.

        This function must also change the value of TurningPlayer if the move
        was successful;
    */

        int p=ColumnMoves[Column-1];
        int TP=WhosTurn();
        if(TP==0)
        {
            Data[p][Column-1]=PlayerChar[0];
        }
        else
        {
            Data[p][Column-1]=PlayerChar[1];
        }
        ColumnMoves[Column-1]=p-1;
        if(CheckIfGameOver(p,Column-1))
        {
            return 0;
        }
        return 1;
    }

    void ShowGame(){
    /*
        Function to display the game status on screen;
    */
        cout << "   1   " << "  2    " << " 3    " << " 4    " << " 5    " << " 6    " << " 7     " << endl;
        cout << "------------------------------------------" << endl;

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                cout << "|";
                cout << " " << Data[i][j] << "   ";
            }

            cout << endl;
            cout << "------------------------------------------" << endl;
        }
    }

    bool isGameOver(){
        return GameOver;
    }

    int WhosTurn()
    {
        //static int TurningPlayer=1;
        TurningPlayer++;
        if(TurningPlayer%2==0)
        {
            TurningPlayer=0;
        }
        else
        {
            TurningPlayer=1;
        }

        return TurningPlayer;
    }

    string getPlayerName(int id){
        if(id< 0 || id > 1 )
            return "";
        return PlayerNames[id];
    }
private:
    bool CheckIfGameOver(int r, int c){
    /*
        This function will check if the game is finished and set the values
        of variables GameOver and Result
        The parameters r and c specify the position of last move last
    */

        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r][c-1]==PlayerChar[TurningPlayer] && Data[r][c-2]==PlayerChar[TurningPlayer] && Data[r][c-3]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r][c-3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r][c-1]==PlayerChar[TurningPlayer] && Data[r][c-2]==PlayerChar[TurningPlayer] && Data[r][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r][c+1]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r][c-1]==PlayerChar[TurningPlayer] && Data[r][c+2]==PlayerChar[TurningPlayer] && Data[r][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r][c+1]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r][c+3]==PlayerChar[TurningPlayer] && Data[r][c+2]==PlayerChar[TurningPlayer] && Data[r][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r][c+1]=PlayerWinningChar[TurningPlayer];
            Data[r][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r][c+3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        //Vertically
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+3][c]==PlayerChar[TurningPlayer] && Data[r+2][c]==PlayerChar[TurningPlayer] && Data[r+1][c]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c]=PlayerWinningChar[TurningPlayer];
            Data[r+2][c]=PlayerWinningChar[TurningPlayer];
            Data[r+3][c]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        //Diagonally
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c+1]==PlayerChar[TurningPlayer] && Data[r+2][c+2]==PlayerChar[TurningPlayer] && Data[r+3][c+3]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c+1]=PlayerWinningChar[TurningPlayer];
            Data[r+2][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r+3][c+3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c+1]==PlayerChar[TurningPlayer] && Data[r+2][c+2]==PlayerChar[TurningPlayer] && Data[r-1][c-1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c+1]=PlayerWinningChar[TurningPlayer];
            Data[r+2][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r-3][c-3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c+1]==PlayerChar[TurningPlayer] && Data[r-2][c-2]==PlayerChar[TurningPlayer] && Data[r-1][c-1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c+1]=PlayerWinningChar[TurningPlayer];
            Data[r-2][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r-3][c-3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r-3][c-3]==PlayerChar[TurningPlayer] && Data[r-2][c-2]==PlayerChar[TurningPlayer] && Data[r-1][c-1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r-1][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r-2][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r-3][c-3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        //Right Diagonal
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c-1]==PlayerChar[TurningPlayer] && Data[r+2][c-2]==PlayerChar[TurningPlayer] && Data[r+3][c-3]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r+2][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r+3][c-3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c-1]==PlayerChar[TurningPlayer] && Data[r+2][c-2]==PlayerChar[TurningPlayer] && Data[r-1][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r+2][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r-1][c+1]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c-1]==PlayerChar[TurningPlayer] && Data[r-2][c+2]==PlayerChar[TurningPlayer] && Data[r-1][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r-2][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r-1][c+1]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r-3][c+3]==PlayerChar[TurningPlayer] && Data[r-2][c+2]==PlayerChar[TurningPlayer] && Data[r-1][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r-1][c+1]=PlayerWinningChar[TurningPlayer];
            Data[r-2][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r-3][c+3]=PlayerWinningChar[TurningPlayer];
            return true;
        }

        return false;

    }

    string PlayerNames[2]; // To Hold Name of Players Who are playing
    int TurningPlayer; // To save the players ID who is making a move; 0: First Player, 1: Second Player
    char PlayerChar[2]; // Characters to be shown for move
    char PlayerWinningChar[2]; // Character to be shown if player wins.
    int  ColumnMoves[7]; // An array to keep record of first empty cell in a column
    char Data[6][7]; // Array to hold game data.
    bool GameOver; // If true it means the game is over.
    int Result;// Variable to hold result of game {0: Drawn, -1: First Player Lost, 1: First Player Won}
};


int main(){
    /*
        This function use a single variable of type connect4
        and use it's functions to play the game
    */
    string N[2]={"Player 1 ","Player 2 "};
    //connect4 Game(N);
    connect4 Game;
    Game.re_init(N);
    int TurningPlayer=1;
    int n;
    do
    {
        Game.ShowGame();
        TurningPlayer++;
        if(TurningPlayer%2==0)
        {
            TurningPlayer=0;
        }
        else
        {
            TurningPlayer=1;
        }
        cout<<Game.getPlayerName(TurningPlayer);
        cout<<"Enter the Column Number ";
        cin>>n;

    }while(Game.MakeMove(n));
    Game.ShowGame();
    cout<<Game.getPlayerName(TurningPlayer)<<" Won "<<endl;


    return 0;
}




