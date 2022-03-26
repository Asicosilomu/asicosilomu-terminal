// Asicosilomu Terminal by the all-mighty Asicosilomu.
// Just a wacky, no file operation, for-the-fun-of-it terminal
// Do not try to compile this for Mac / Linux, it won't work! (see #include <windows.h> below)

#include <iostream>
#include <windows.h>
#include <algorithm>
#include <stdlib.h>
#include <limits>
#include<string.h>
#include <sstream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>

using namespace std;

string cmd;
string orig;
string tc;

bool hasStarted = false;
bool title_isCustomTitleSet = false;

string promptInputCommand() {
    if (hasStarted == true) {
        cout << endl << endl << "Asicosilomu$ ";
    } else {
        cout << "Asicosilomu Terminal version 1.0, by the all-mighty Asicosilomu. No rights reserved." << endl << endl << "Asicosilomu$ ";
        hasStarted = true;
    }
    getline(cin, cmd);
    cout << endl;
    return cmd;
}

int main()
{
    if (title_isCustomTitleSet != true) { SetConsoleTitleA("Asicosilomu Terminal"); };
    while (true) {
        if (title_isCustomTitleSet != true) { SetConsoleTitleA("Asicosilomu Terminal"); };
        cmd = promptInputCommand();
        tc = cmd;
        stringstream paramParser(cmd);
        paramParser >> cmd;
        orig = cmd;
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
        string finalTitleStr = tc + " - Asicosilomu Terminal";
        int titleDisplayLength = finalTitleStr.length();
        char titleDisplayFinal[titleDisplayLength + 1];
        strcpy(titleDisplayFinal, finalTitleStr.c_str());
        if (title_isCustomTitleSet != true) { SetConsoleTitleA(titleDisplayFinal); };
        if (cmd == "help") {
            cout << "Basic Asicosilomu Terminal commands:" << endl << "help - Displays this message." << endl << "cls - Clears the terminal screen." << endl << "echo <text> - Prints a message to the output." << endl << "exit - Exits Asicosilomu Terminal." << endl << "winrun <code> - Executes the provided code using the windows.h system function." << endl << "ewwrat - theres a rat amogus" << endl << "title <text> - Sets the window title to the specified text." << endl << "countdown <time> <endMessage> - Counts down <time> seconds, displaying <endMessage> when finished.";
        } else if (cmd == "cls") {
            hasStarted = false;
            system("cls");
        } else if (cmd == "echo") {
            string echo_str;
            bool echo_hasStarted;
            while (paramParser >> echo_str) {
                if (echo_hasStarted == true) {
                    cout << " ";
                } else {
                    echo_hasStarted = true;
                }
                cout << echo_str;
            }
        } else if (cmd == "exit") {
            return 0;
        } else if (cmd == "winrun") {
             string winrun_str;
             string winrun_finalcmd = "";
            bool winrun_hasStarted;
            while (paramParser >> winrun_str) {
                if (winrun_hasStarted == true) {
                    winrun_finalcmd = winrun_finalcmd + " ";
                } else {
                    winrun_hasStarted = true;
                }
                winrun_finalcmd = winrun_finalcmd + winrun_str;
            }
            int winrun_cmdLength = winrun_finalcmd.length();
            char winrun_arr[winrun_cmdLength + 1];
            strcpy(winrun_arr, winrun_finalcmd.c_str());
            system(winrun_arr);
        } else if (cmd == "ewwrat") {
            cout << "Mom: eww theres a rat in the house get rid of it, NOW!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "Me: not a big deal" << endl;
            cout << endl;
            cout << "               _     __,..---''''-._                 ';-,";
            cout << endl;
            cout << "        ,    _/_),-''              '-.                `\\";
            cout << endl;
            cout << "       \|.-''`    -_)                 '.                ||";
            cout << endl;
            cout << "       /`   a   ,                      \              .'/";
            cout << endl;
            cout << "       '.___,__/                 .-'    \_        _.-'.'";
            cout << endl;
            cout << "          |\  \      \         /`        _`''''''''''''`_.-'";
            cout << endl;
            cout << "             _/;--._, >        |   --.__/ `''''''''''''`";
            cout << endl;
            cout << "           (((-'  __//`'-......-;\      )";
            cout << endl;
            cout << "                (((-'       __//  '--. /";
            cout << endl;
            cout  << "        jgs               (((-'    __//";
            cout << endl;
            cout << "                                 (((-'";
            cout << endl;
            cout << endl;
            cout << "Me: DAD, THERE'S A RAT IN THE HOUSE!!!!!!!!!!";
        } else if (cmd == "title") {
            string title_t;
            string title_f = "";
            bool title_hasStarted;
            while (paramParser >> title_t) {
                if (title_hasStarted == true) {
                    title_f = title_f + " ";
                } else {
                    title_hasStarted = true;
                }
                title_f = title_f + title_t;
            };
            if (title_f != "") {
                int title_length = title_f.length();
                char title_arr[title_length + 1];
                strcpy(title_arr, title_f.c_str());
                title_isCustomTitleSet = true;
                SetConsoleTitleA(title_arr);
            } else {
                cout << "No title provided. Console title not changed.";
            }
        } else if (cmd == "countdown") {
            int countdown_countdownTime;
            int countdown_curTime;
            string countdown_timesUpMessage = "";
            if (paramParser >> countdown_countdownTime) {
                bool countdown_tumh = false;
                string countdown_tmg = "";
                while (paramParser >> countdown_tmg) {
                    if (countdown_tumh == true) {
                        countdown_timesUpMessage = countdown_timesUpMessage + " ";
                    } else {
                        countdown_tumh = true;
                    }
                    countdown_timesUpMessage = countdown_timesUpMessage + countdown_tmg;
                }
                if (countdown_timesUpMessage == "") {
                    cout << "WARNING: No countdown ending message specified. Using default: Time's up!" << endl << endl;
                    countdown_timesUpMessage = "Time's up!";
                }
                countdown_curTime = countdown_countdownTime;
                while (countdown_curTime > 0) {
                    Sleep(1000);
                    cout << countdown_curTime << endl;
                    countdown_curTime = countdown_curTime - 1;
                }
                cout << endl << countdown_timesUpMessage;
            } else {
                cout << "Specify a valid countdown time!";
            }
        } else {
            cout << "'" << orig << "' is not recognized as a valid command. Type 'help' for a list of available commands.";
        }
    }
    return 0;
}
