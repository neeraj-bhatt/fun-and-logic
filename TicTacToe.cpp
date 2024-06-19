/*
|  |  |  |
|  |  |  |
|  |  |  |

Tic Tac Toe is a Two Player Game.
One Player can place 'X' and second can place 'O' in a square box of 3X3 grid.
Gamer is over in either of the two conditions:-
1. One player wins when a line of symbol is formed in a row or column or diagonally.
2. Game is draw when all 9 places are filled, no one wins


One function is needed to draw Box
One to check if someone wins
*/

#include <iostream>
using namespace std;


void drawBox(char arr[3][3]){
    cout << "============="<<endl;
    for(int i=0; i<3; i++){
        cout << "| ";
        for(int j=0; j<3; j++){
            cout << arr[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "============="<<endl << endl;

}

bool checkWin(char arr[3][3], char player){
    if((arr[0][0] == player && arr[1][1] == player && arr[2][2] == player) || ((arr[0][2]) == player && arr[1][1] == player && arr[2][0] == player))
        return true;
    for(int i=0; i<3; i++){
        if(arr[0][i] == player && arr[1][i] == player && arr[2][i] == player)
            return true;
        if(arr[i][0] == player && arr[i][1] == player && arr[i][2] == player)
            return true;
    }

    return false;
}

int main(){

    //initialize an empty array of 3X3 for storing player inputs
    char box[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    char player = 'X';
    int x,y;
    int turns = 1;
    cout << "----Welcome----"<< endl;
    cout << "This is a basic game of TicTacToe without any graphics"<< endl;

    while(true){
        while(true){
            drawBox(box);
            cout << "Player " << player << ", Enter the value of x and y position." << endl;
            cin >> x >> y;
            if(box[x][y] != ' ' || x>2 || x<0 || y>2 || y<0)
                cout << "\n----!Invalid Input!----\n" << endl;
            else{
                box[x][y] = player;
                break;
            }
        }
        if(checkWin(box, player)){      //Checks if either of the players won
            drawBox(box);
            cout << "Player " << player << " wins." << endl;
            break;
        }

        if(player == 'X')
            player = 'O';
        else
            player = 'X';

        if(turns == 9){
            drawBox(box);
            cout << "It's a Draw" << endl;
            break;
        }
        turns++;

    }

    return 0;
}