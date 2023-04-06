#include "game.h"
#include "helper.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define STUDENT_NAME    "Jabbar Baloghlan"
#define STUDENT_NUMBER  "s3890406"
#define STUDENT_EMAIL   "s3890406@student.rmit.edu.au"

string menu_input;
bool menu_choice_check;

void showStudentInformation(string name, string id, string email){ // Show all student info
    cout << "--------------------------------------------------" << endl;
    cout << "Name: "   << name  << endl;
    cout << "NO: "     << id    << endl;
    cout << "Enmail: " << email << endl;
    cout << "--------------------------------------------------" << endl << endl;

}

void goodbye_output(){ // Goodbye output shortcut
    cout << "Good bye!\n\n";
}

void menu(){ // Menu shortcut
    menu_choice_check = false;

    while(!menu_choice_check){ // Repetitive menu display and selector
        cout << "Welcome to Car Board"          << endl;
        cout << "--------------------"          << endl;
        cout << "1. Play Game"                  << endl;
        cout << "2. Show student's information" << endl;
        cout << "3. Quit"                       << endl << endl;

        cout << "Please enter your choice: ";

        menu_input = Helper::readInput();

        if      (menu_input == "1"){ // Start game
            Game game_class;
            game_class.start();
        }
        else if (menu_input == "2"){ // Output student info
            showStudentInformation(STUDENT_NAME, STUDENT_NUMBER, STUDENT_EMAIL);
        }
        else if (menu_input == "3"){
            menu_choice_check = true;
        }
    }
    
    goodbye_output();
}

int main()
{
    menu();

    return EXIT_SUCCESS;
}

