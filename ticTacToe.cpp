// TicTacToe game
#include<bits/stdc++.h>
using namespace std;

void printBoard(char board[]) {
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int XcheckWinner(char board[]) {
    
    for(int i = 0; i<7; i = i+3) {
        if( (board[i] == board[i+1]) && (board[i+1] == board[i+2] ) && ( board[i+2] == 'X' ) ) {
            return 1;
        }
    }
    for(int i = 0; i<3; i++) {
        if( (board[i] == board[i+3]) && (board[i+3] == board[i+6]) && (board[i+6] == 'X')) {
            return 1;
        }
        
    }
    if((board[0] == board[4]) && ( board[4] == board[8]) && (board[8] == 'X')) {
        return 1;
    }
    if((board[2] == board[4]) && ( board[4] == board[6]) && (board[6] == 'X')) {
        return 1;
    }
    return -1;
}

int OcheckWinner(char board[]) {
    
    for(int i = 0; i<7; i = i+3) {
        if( (board[i] == board[i+1]) && (board[i+1] == board[i+2] ) && ( board[i+2] == 'O' ) ) {
            return 1;
        }
    }
    for(int i = 0; i<3; i++) {
        if( (board[i] == board[i+3]) && (board[i+3] == board[i+6]) && (board[i+6] == 'O')) {
            return 1;
        }
        
    }
    if((board[0] == board[4]) && ( board[4] == board[8]) && (board[8] == 'O')) {
        return 1;
    }
    if((board[2] == board[4]) && ( board[4] == board[6]) && (board[6] == 'O')) {
        return 1;
    }
    return -1;
}

int checkPlace(char board[], int p) {
    if(board[p] == '_') {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    char board[] = {'_', '_', '_', '_', '_', '_', '_', '_', '_' };

    //printBoard(board);
    int chance;
    int x, o;
    char ch;
    std::cout << "\tWELCOME TO TIC TAC TOE\n\n";
    while(true) {
        std::cout << "What you want to choose X/O ?? : ";
        std::cin >> ch;
        if(ch == 'x' || ch == 'X') {
            chance = 1;
            break;
        } else if(ch == 'o' || ch == 'O') {
            chance = 0;
            break;
        } else {
            std::cout << "Enter a valid choice" << std::endl;
        }
    }
    
    int counter = 0;
    while(true) {
        printBoard(board);
        if(chance == 1) {
            printf("X's chance(1-9): ");
            scanf("%d", &x);
            if(checkPlace(board, x-1)) {
                board[x-1] = 'X';
                chance = 1 - chance;
            } else {
                std::cout << "This place is already filled" << std::endl;
            }
            
        } else {
            printf("O'x chance(1-9): ");
            scanf("%d", &o);
            if(checkPlace(board, o-1)) {
                board[o-1] = 'O';
                chance = 1 - chance;
            } else {
                std::cout << "This place is already filled" << std::endl;
            }
            
        }
        int xWin = XcheckWinner(board);
        if(xWin != -1) {
            printBoard(board);
            std::cout << "X is the winner" << std::endl;
            break;
        }
        int oWin = OcheckWinner(board);
        if(oWin != -1) {
            printBoard(board);
            std::cout << "O is the winner" << std::endl;
            break;
        }
        
        //chance = 1 - chance;
        counter++;
        if(counter >= 9) {
            printBoard(board);
            std::cout << "\nMatch Draw\n";
            break;
        }
    }

    std::cout << "\n-----GAME OVER-----\n";
    
}