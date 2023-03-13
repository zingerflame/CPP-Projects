#include <iostream>
#include <string.h>
#include <unistd.h>
using namespace std;

int main() {

    char grid[3][3] = {'_','_','_','_','_','_','_','_','_'};

    char display[3][3] = {'1','2','3','4','5','6','7','8','9'};

    bool filled[9] = {false,false,false,false,false,false,false,false,false};
    int counter = 0; //use this to check if game is over

    //shows display numbers
    cout << "Here are the positions \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << display[i][j];
        }
        cout << "\n";
    }

    bool end = false; //dictates when game ends

    srand(time(0));
    int r = rand() % 2; //determine who goes first

    if (r==0) {
        cout << "You are going first \n";

        while (end == false) {
            reask1:
            //your move
            cout << "Where would you like to place (enter an integer 1-9) \n";
            int l;
            cin>>l;
            if (filled[l] == true) {
                cout << "You can't go there, try a different spot \n";
                goto reask1; 
            }
            else {
                switch(l) {
                    case 1: grid[0][0] = 'X'; break;
                    case 2: grid[0][1] = 'X'; break;
                    case 3: grid[0][2] = 'X'; break;
                    case 4: grid[1][0] = 'X'; break;
                    case 5: grid[1][1] = 'X'; break;
                    case 6: grid[1][2] = 'X'; break;
                    case 7: grid[2][0] = 'X'; break;
                    case 8: grid[2][1] = 'X'; break;
                    case 9: grid[2][2] = 'X'; break;
                }
                filled[l] = true;
                counter++;
            }
            //display
            cout << "\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << grid[i][j];
                }
                cout << "\n";
            }

            //Win Check
                if (grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X') {
                    end = true;
    
                    cout << "Congrats you won";
                    break;
                }
                if (grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X') {
                    end = true;

                    cout << "Congrats you won";
                    break;
                }
                if (grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X') {
                    end = true;
                    
                    cout << "Congrats you won";
                    break;
                }
                if (grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X') {
                    end = true;
                    
                    cout << "Congrats you won";
                    break;
                }
                if (grid[0][1] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X') {
                    end = true;
                    
                    cout << "Congrats you won";
                    break;
                }
                if (grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X') {
                    end = true;
                    
                    cout << "Congrats you won";
                    break;
                }
                if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') {
                    end = true;
                    
                    cout << "Congrats you won";
                    break;
                }
                if (grid[2][0] == 'X' && grid[1][1] == 'X' && grid[0][2] == 'X') {
                    end = true;
                    cout << "Congrats you won";
                    break;
                }
            //tie check - only needs to be here because odd turns, would only occur if a win didnt happen because of breaks
            if (counter > 8) {
                end = true;
                cout << "Result: draw\n ";
                break;
            }
            
            cout << "The computer is making a move... \n";
            rerand1:
            //bot move
            sleep(1);
            srand(time(0));
            int k = rand() % 9 +1; // picks grid it will go
            //checks grid - bot
            if (filled[k] == true) {
                goto rerand1; //respins
            }
            else {
                switch(k) {
                    case 1: grid[0][0] = 'O'; break;
                    case 2: grid[0][1] = 'O'; break;
                    case 3: grid[0][2] = 'O'; break;
                    case 4: grid[1][0] = 'O'; break;
                    case 5: grid[1][1] = 'O'; break;
                    case 6: grid[1][2] = 'O'; break;
                    case 7: grid[2][0] = 'O'; break;
                    case 8: grid[2][1] = 'O'; break;
                    case 9: grid[2][2] = 'O'; break;
                }   
                filled[k] = true;
                counter++;
            }
            //display
            cout << "\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << grid[i][j];
                }
                cout << "\n";
            }

            //Lose Check
            if (grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O') {
                end = true;
                cout << "You lost the game how did you lose to a bot";
            }
            if (grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O') {
                end = true;
                cout << "You lost the game how did you lose to a bot";
            }
            if (grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O') {
                end = true;
                cout << "You lost the game how did you lose to a bot";
            }
            if (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O') {
                end = true;
                cout << "You lost the game how did you lose to a bot";
            }
            if (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O') {
                end = true;
                cout << "You lost the game how did you lose to a bot";
            }
            if (grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O') {
                end = true;
                cout << "You lost the game how did you lose to a bot";
            }
            if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') {
                end = true;
                cout << "You lost the game how did you lose to a bot";
            }
            if (grid[2][0] == 'O' && grid[1][1] == 'O' && grid[0][2] == 'O') {
                end = true;
                cout << "You lost the game how did you lose to a bot";
            }
        }

    }
    else {
        cout << "The bot is going first \n";
        
        while (end == false) {

            cout << "The computer is making a move... \n";
            rerand2:
            //bot move
            //if two X in a row, then complete third X
            sleep(1);
            srand(time(0));
            int k = rand() % 9 +1; // picks grid it will go
            //checks grid - bot
            if (filled[k] == true) {
                goto rerand2; //respins
            }
            else {
                switch(k) {
                    case 1: grid[0][0] = 'O'; break;
                    case 2: grid[0][1] = 'O'; break;
                    case 3: grid[0][2] = 'O'; break;
                    case 4: grid[1][0] = 'O'; break;
                    case 5: grid[1][1] = 'O'; break;
                    case 6: grid[1][2] = 'O'; break;
                    case 7: grid[2][0] = 'O'; break;
                    case 8: grid[2][1] = 'O'; break;
                    case 9: grid[2][2] = 'O'; break;
                }   
                filled[k] = true;
                counter++;
            }
            //display
            cout << "\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << grid[i][j];
                }
                cout << "\n";
            }
            //Lose Check
                if (grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O') {
                    end = true;

                    cout << "You lost the game how did you lose to a bot";
                    break;
                }
                if (grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O') {
                    end = true;

                    cout << "You lost the game how did you lose to a bot";
                    break;
                }
                if (grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O') {
                    end = true;

                    cout << "You lost the game how did you lose to a bot";
                    break;
                }
                if (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O') {
                    end = true;

                    cout << "You lost the game how did you lose to a bot";
                    break;
                }
                if (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O') {
                    end = true;

                    cout << "You lost the game how did you lose to a bot";
                    break;
                }
                if (grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O') {
                    end = true;

                    cout << "You lost the game how did you lose to a bot";
                    break;
                }
                if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') {
                    end = true;

                    cout << "You lost the game how did you lose to a bot";
                    break;
                }
                if (grid[2][0] == 'O' && grid[1][1] == 'O' && grid[0][2] == 'O') {
                    end = true;

                    cout << "You lost the game how did you lose to a bot";
                    break;
                }

            //tie check
            if (counter > 8) {
                end = true;
                cout << "Result: draw";
                break;
            }
            

            reask2:
            //your move
            cout << "Where would you like to place (enter an integer 1-9) \n";
            int l;
            cin>>l;
            if (filled[l] == true) {
                cout << "You can't go there, try a different spot \n";
                goto reask2;
            }
            else {
                switch(l) {
                    case 1: grid[0][0] = 'X'; break;
                    case 2: grid[0][1] = 'X'; break;
                    case 3: grid[0][2] = 'X'; break;
                    case 4: grid[1][0] = 'X'; break;
                    case 5: grid[1][1] = 'X'; break;
                    case 6: grid[1][2] = 'X'; break;
                    case 7: grid[2][0] = 'X'; break;
                    case 8: grid[2][1] = 'X'; break;
                    case 9: grid[2][2] = 'X'; break;
                }
                filled[l] = true;
                counter++;
            }
            //display
            cout << "\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << grid[i][j];
                }
                cout << "\n";
            }

            //Win Check
            if (grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X') {
                end = true;
                cout << "Congrats you won";
            }
            if (grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X') {
                end = true;
                cout << "Congrats you won";
            }
            if (grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X') {
                end = true;
                cout << "Congrats you won";
            }
            if (grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X') {
                end = true;
                cout << "Congrats you won";
            }
            if (grid[0][1] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X') {
                end = true;
                cout << "Congrats you won";
            }
            if (grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X') {
                end = true;
                cout << "Congrats you won";
            }
            if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') {
                end = true;
                cout << "Congrats you won";
            }
            if (grid[2][0] == 'X' && grid[1][1] == 'X' && grid[0][2] == 'X') {
                end = true;
                cout << "Congrats you won";
            }
        }
    }


    return 0;
}


