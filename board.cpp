#include "board.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int board_selection = 0;
string symbol;

const vector<vector<Cell>> Board::BOARD_1 =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Board::Board()
{
    // TODO
}

Board::~Board()
{
    // TODO
}

void Board::load(int boardId)
{
    board_selection = boardId;
}

bool Board::placePlayer(Position position)
{
    bool exit_code = false;

    if (BOARD_1[position.x][position.y] == EMPTY){exit_code = true;}

    return exit_code;
}

PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    return PLAYER_MOVED;
}

void Board::display(Player* player)
{
    int tx = player->position.x;
    int ty = player->position.y;
    int td = player->direction ;
    bool check = false;

    cout << "| ";
    for (int j = 0; j < DEFAULT_BOARD_DIMENSION; ++j){
        cout << "|" << j;
    }
    cout << "|" << endl;

    if (!board_selection){
            for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i){
            cout << "|" << i;
            for (int j = 0; j < DEFAULT_BOARD_DIMENSION; ++j){
                cout << "| ";
            }
            cout << "|" << endl;

        }
    }else if (board_selection == 1){

        for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i){
            cout << "|" << i;

            for (int j = 0; j < DEFAULT_BOARD_DIMENSION; ++j){
                cout << "|";

                if(i == ty and j == tx){
                    if(BOARD_1[i][j] == EMPTY){
                        if       (td == 0){
                            symbol = DIRECTION_ARROW_OUTPUT_NORTH;
                        } else if(td == 1){
                            symbol = DIRECTION_ARROW_OUTPUT_EAST;
                        } else if(td == 2){
                            symbol = DIRECTION_ARROW_OUTPUT_SOUTH;
                        } else if(td == 3){
                            symbol = DIRECTION_ARROW_OUTPUT_WEST;
                        }
                    } else{
                        check = true;
                    }




                } else if (BOARD_1[i][j] == 0){
                    symbol = ' ';
                } else if (BOARD_1[i][j] == 1){
                    symbol = '*';
                }

                cout << symbol;
            }

            cout << "|" << endl;
        }
    
    }else if (board_selection == 2){

        for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i){
            cout << "|" << i;

            for (int j = 0; j < DEFAULT_BOARD_DIMENSION; ++j){
                cout << "|";

                if(i == ty and j == tx){
                    if(BOARD_2[i][j] == EMPTY){
                        if       (td == 0){
                            symbol = DIRECTION_ARROW_OUTPUT_NORTH;
                        } else if(td == 1){
                            symbol = DIRECTION_ARROW_OUTPUT_EAST;
                        } else if(td == 2){
                            symbol = DIRECTION_ARROW_OUTPUT_SOUTH;
                        } else if(td == 3){
                            symbol = DIRECTION_ARROW_OUTPUT_WEST;
                        }
                    } else{
                        check = true;
                    }




                } else if (BOARD_2[i][j] == 0){
                    symbol = ' ';
                } else if (BOARD_2[i][j] == 1){
                    symbol = '*';
                }

                cout << symbol;
            }

            cout << "|" << endl;
        }
    
    }

    if(check){
        cout << endl;
        Helper::printInvalidInput();
    }

    cout << endl;
}


