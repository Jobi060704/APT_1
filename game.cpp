#include "game.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

Board btest;
Position postest(-1,-1);
Player ptest;
Direction dtest;

int bID = -1;

Game::Game()
{
    // TODO
}
Game::~Game()
{
    // TODO
}

bool digitTest(vector<string> test_vec){
    bool exit_code = true;
    if(!(test_vec[0].length() == 1 and Helper::isNumber(test_vec[0]) and stoi(test_vec[0]) >= 0 and stoi(test_vec[0]) <= 9)){exit_code = false;}

    if(!(test_vec[1].length() == 1 and Helper::isNumber(test_vec[1]) and stoi(test_vec[1]) >= 0 and stoi(test_vec[1]) <= 9)){exit_code = false;}

    return exit_code;
}
bool directionTest(vector<string> test_vec){
    bool exit_code = false;
    
    if (test_vec[2] == "north" or test_vec[2] == "east" or test_vec[2] == "south" or test_vec[2] == "west"){
        exit_code = true;
    }

    return exit_code;
}

void Game::start()
{
    bool game_choice_check = false;
    string game_selection;

    ptest.initialisePlayer(&postest,dtest);

    while(!game_choice_check){ // Repetitive game display and selector
        cout << "----------------------------------------------------------------------------"  << endl << endl;
        cout << "You can use the following commands to play the game:"                          << endl;
        cout << "load <g>"                                                                      << endl;
        cout << "       g: number of the game board to load"                                    << endl;
        cout << "init <x>,<y>,<direction>"                                                      << endl;
        cout << "       x: horizontal position of the car on the board (between 0 & 9."         << endl;
        cout << "       y: vertical position of the car on the board (between 0 & 9)"           << endl;
        cout << "       direction: direction of the car's movement (north, east, south, west)"  << endl;
        cout << "forward (or f)"                                                                << endl;
        cout << "turn left (or 1)"                                                              << endl;
        cout << "turn right (or r)"                                                             << endl;
        cout << "quit"                                                                          << endl << endl;

        btest.display(&ptest);

        cout << "Please enter your choice: ";

        string game_input = Helper::readInput();

        if      (game_input == "quit"){ 
            game_choice_check = true;
            cout << "----------------------------------------------------------------------------"    << endl << endl;
        }
        else if (game_input == "load 1" or game_input == "load 2"){
            bID = game_input[5] - 48;
            btest.load(bID);
        }
        
        else if (game_input.substr(0,5) == "init " and game_input.length() > 9){
            vector<string> init_ins;

            Helper::splitString(game_input.substr(5),init_ins,",");

            if (!(digitTest(init_ins) and directionTest(init_ins) and btest.placePlayer(Position{stoi(init_ins[0]),stoi(init_ins[1])}) )){
            cout << "----------------------------------------------------------------------------"    << endl << endl;

            cout << "\033[4m" << "Invalid player initialisation input, please try again." << "\033[24m" << endl << endl;
            }

            else{

                               
                postest = Position{stoi(init_ins[0]),stoi(init_ins[1])};

                if     (init_ins[2] == "north"){
                    dtest = NORTH;
                }
                else if(init_ins[2] == "east"){
                    dtest = EAST;
                }
                else if(init_ins[2] == "south"){
                    dtest = SOUTH;
                }
                else if(init_ins[2] == "west"){
                    dtest = WEST;
                }

                ptest.initialisePlayer(&postest,dtest);

                
            }

        }
        
        else if (game_input == "f" or game_input == "l" or game_input == "r" or game_input == "forward" or game_input == "turn_left" or game_input == "turn_right"){

            if(game_input == "f" or game_input == "forward"){

                bool act_code = false;
                

                if     (dtest == NORTH){
                    if (btest.placePlayer(Position{postest.x + 0, postest.y -1})) {
                        postest = Position{postest.x + 0,postest.y - 1};
                        act_code = true;
                    }                    
                }
                else if(dtest == EAST){
                    if (btest.placePlayer(Position{postest.x + 1, postest.y + 0})) {
                        postest = Position{postest.x + 1,postest.y + 0};
                        act_code = true;
                    }
                }
                else if(dtest == SOUTH){
                    if (btest.placePlayer(Position{postest.x + 0, postest.y + 1})) {
                        postest = Position{postest.x + 0,postest.y + 1};
                        act_code = true;
                    }
                }
                else if(dtest == WEST){
                    if (btest.placePlayer(Position{postest.x - 1, postest.y + 0})) {
                        postest = Position{postest.x - 1,postest.y + 0};
                        act_code = true;
                    }
                }

                
                if (act_code){ptest.initialisePlayer(&postest,dtest);}
                else{
                    cout << "----------------------------------------------------------------------------"    << endl << endl;

                    cout << "\033[4m" << "Invalid move, please try again." << "\033[24m" << endl << endl;
                }
                






            }
            else if(game_input == "l" or game_input == "turn_left"){
                if     (dtest == NORTH){
                    dtest = WEST;
                }
                else if(dtest == EAST){
                    dtest = NORTH;
                }
                else if(dtest == SOUTH){
                    dtest = EAST;
                }
                else if(dtest == WEST){
                    dtest = SOUTH;
                }
                ptest.initialisePlayer(&postest,dtest);
                
            }
            else if(game_input == "r" or game_input == "turn_right"){
                if     (dtest == NORTH){
                    dtest = EAST;
                }
                else if(dtest == EAST){
                    dtest = SOUTH;
                }
                else if(dtest == SOUTH){
                    dtest = WEST;
                }
                else if(dtest == WEST){
                    dtest = NORTH;
                }
                ptest.initialisePlayer(&postest,dtest);

            }
            


        }

        else{
            cout << "----------------------------------------------------------------------------"    << endl << endl;

            cout << "\033[4m" << "Invalid input, please try again." << "\033[24m" << endl;

            cout << endl;
        }
    }
}

bool Game::loadBoard()
{
    return false; // feel free to revise this line, depending on your implementation.
}
bool Game::initializePlayer()
{
    //TODO
    return false; // feel free to revise this line.
}
void Game::play()
{
    //TODO
}