#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// assumes mostly clean input for now, will update later
int char_converter(char let){
    switch(let){
        case 'R':
            return 4;
        case 'P':
            return 2;
        case 'S':
            return 1;
        default:
            return 0;
    }

}

int game_decider(char p1ch, char p2ch){
    int p1 = 0;
    int p2 = 0;
    p1 = char_converter(toupper(p1ch));
    p2 = char_converter(toupper(p2ch));
    int comp = p1 + p2;
    switch(p1){
        case 4:
            switch(p2){
                case 4:
                    return 0;
                case 2:
                    return 2;
                case 1:
                    return 1;
                default:
                    return 3;
            }
        case 2:
            switch(p2){
                case 4:
                    return 1;
                case 2:
                    return 0;
                case 1:
                    return 2;
                default:
                    return 3;
            }
        case 1:
            switch(comp){
                case 4:
                    return 2;
                case 2:
                    return 1;
                case 1:
                    return 0;
                default:
                    return 3;
            }
        default:
            return 3;
    }
}


int main(){
    int game_on = 1;
    char game_let;
    cout << "welcome to RPS v1.0 \n";
    while(game_on == 1){
        char P1ch, P2ch;
        int winner;
        cout << "Player 1, enter \"R, P, or S\" \n"; 
        cin >> P1ch;
        cout << "Player 2, enter \"R, P, or S\" \n"; 
        cin >> P2ch;
        winner = game_decider(P1ch, P2ch);
        switch (winner)
        {
            case 0:
                cout << "There was a tie" << endl;
                break;
            case 1:
                cout << "Player 1 wins" << endl;
                break;
            case 2: 
                cout << "Player 2 wins" << endl;
                break;
            default:
                cout << "There was an error, please try again" << endl;
        }
        cout << "Play again? (y/n) \n" << endl;
        cin >> game_let;
        if(game_let != 'y'){
            game_on = 0;
        }
    }

}
