#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayBoard() {
    
		cout<<"\t\tTIC TAC TOE GAME"<<endl;
	cout<<"Payer1[X]"<<endl;
	cout<<"Player2[O]"<<endl;
	cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

int main() {
    int player, choice;
    cout<<"Enter number of player 1 or 2 :"<<endl;
    cin>>player;

    char mark;
    bool gameover = false;

    do {
        displayBoard();
        if(player%2){
        	player=1;
		}
		else{
			player=2;
		}
        cout << "Player " << player << ", enter a number: ";
        cin >> choice;
        if(player == 1){
        	mark ='X';
		}
		else{
			mark ='0';
		}

        if (choice == 1 && board[0][0] == '1')
            board[0][0] = mark;
        else if (choice == 2 && board[0][1] == '2')
            board[0][1] = mark;
        else if (choice == 3 && board[0][2] == '3')
            board[0][2] = mark;
        else if (choice == 4 && board[1][0] == '4')
            board[1][0] = mark;
        else if (choice == 5 && board[1][1] == '5')
            board[1][1] = mark;
        else if (choice == 6 && board[1][2] == '6')
            board[1][2] = mark;
        else if (choice == 7 && board[2][0] == '7')
            board[2][0] = mark;
        else if (choice == 8 && board[2][1] == '8')
            board[2][1] = mark;
        else if (choice == 9 && board[2][2] == '9')
            board[2][2] = mark;
        else {
            cout << "Invalid move!";
            player--;
        }
        // Switch player
            if(player == 1)
            player=2;
            else
            player=1;

        gameover = false;
        
    } while (!gameover);

    return 0;
}
