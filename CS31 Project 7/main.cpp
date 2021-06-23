//
//  main.cpp
//  BeatThat
//
//

#include <iostream>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Board.h"
#include "BeatThat.h"

    using namespace cs31;
    using namespace std;
void clearScreen( );

int main()
{
/*
    using namespace cs31;
    using namespace std;

    clearScreen();

    BeatThat game;
    std::string action, message = "(r)oll (q)uit: ";
    std::cout << message;

    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'r':
            case 'R':
                game.humanPlay();
                game.computerPlay();
                game.endTurn();
                cout << game.display( message ) << endl;
                break;
        }
    } while( !game.isGameOver() );
    cout << game.endingMessage() << endl;
*/
    // Codeboard test cases
//    Die d1;
//    d1.setValue( 1 );
//    Die d2;
//    d2.setValue( 2 );
//    Player p;
//    p.roll( d1, d2 );
//    assert( p.largestDie( ).getValue( ) == 2 );
//    assert( p.smallestDie( ).getValue( ) == 1 );
//
//    assert( p.getRoundsWon( ) == 0 );
//    p.wonARound();
//    assert( p.getRoundsWon( ) == 1 );
//    p.wonARound();
//    assert( p.getRoundsWon( ) == 2 );
//
//    Board b;
//    b.setHumanRoundsWon( 3 );
//    b.setComputerRoundsWon( 2 );
//    b.markHumanAsWinner();
//    b.setTurnsLeft(0);
//    assert( b.getHumanRoundsWon() == 3);
//    assert( b.getComputerRoundsWon() == 2 );
//    assert( b.getTurnsLeft() == 0 );
//    assert( b.didHumanWin() );
//    assert( !b.didComputerWin() );
//    assert( b.isGameOver() );
//
//    BeatThat g;
//    assert( g.turnsLeft( ) == 5 );
//    assert( !g.isGameOver( ) );
//    assert( g.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );

    
/*
// Test Cases
    Die d1; d1.setValue( 1 );
    Die d2; d2.setValue( 2 );
    Die d3; d3.setValue( 3 );
    Die d4; d4.setValue( 4 );
    Die d5; d5.setValue( 5 );
    Die d6; d6.setValue( 6 );

    BeatThat game;
    // 5 forced rounds of play...
    game.humanPlay( d1, d2 );
    game.computerPlay( d2, d1 );
    game.endTurn( );
    assert( game.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game.humanPlay( d4, d4 );
    game.computerPlay( d6, d1 );
    game.endTurn( );
    assert( game.getComputer( ).getRoundsWon( ) == 1 );
    game.humanPlay( d6, d5 );
    game.computerPlay( d6, d2 );
    game.endTurn( );
    assert( game.getHuman( ).getRoundsWon( ) == 1 );
    game.humanPlay( d3, d3 );
    game.computerPlay( d3, d3 );
    game.endTurn( );
    game.humanPlay( d5, d4 );
    game.computerPlay( d4, d5 );
    game.endTurn( );
    assert( game.isGameOver() == true );
    assert( game.getHuman( ).getRoundsWon( ) == 1 );
    assert( game.getComputer( ).getRoundsWon( ) == 1 );
    assert( game.determineGameOutcome( ) == cs31::BeatThat::TIEDGAME );
 */
    Die one;   one.setValue(1);
    Die two;   two.setValue(2);
    Die three; three.setValue(3);
    Die four;  four.setValue(4);
    Die five;  five.setValue(5);
    Die six;   six.setValue(6);
    
    BeatThat game2;
    game2.humanPlay( one, two );
    game2.computerPlay( five, six );
    game2.endTurn( );
    game2.humanPlay( four, three );
    game2.computerPlay( two, one );
    game2.endTurn( );
    game2.humanPlay( six, five );
    game2.computerPlay( five, six );
    game2.endTurn( );
    game2.humanPlay( four, three );
    game2.computerPlay( two, four );
    game2.endTurn( );
    game2.humanPlay( six, one );
    game2.computerPlay( one, six );
    game2.endTurn( );
    assert(game2.determineGameOutcome( ) == cs31::BeatThat::HUMANWONGAME );
    Player p1;
    p1.roll( one, two );
    p1.roll( two, one );
    p1.wonARound( );
    assert(p1.getRoundsWon() == 1);
    Player p2;
    p2.roll( one, five );
    p2.roll( six, two );
    p2.wonARound( );
    assert(p2.largestDie().getValue() == 6);
    
    BeatThat game3;
    game3.humanPlay( one, two );
    game3.computerPlay( five, six );
    game3.endTurn( );
    game3.humanPlay( four, three );
    game3.computerPlay( two, six );
    game3.endTurn( );
    game3.humanPlay( six, five );
    game3.computerPlay( five, six );
    game3.endTurn( );
    game3.humanPlay( four, three );
    game3.computerPlay( two, four );
    game3.endTurn( );
    game3.humanPlay( six, one );
    game3.computerPlay( one, six );
    game3.endTurn( );
    assert(game3.determineGameOutcome() == cs31::BeatThat::COMPUTERWONGAME);
    Player p3;
    p3.roll( six, one );
    p3.roll( two, five );
    p3.wonARound( );
    assert(p3.smallestDie().getValue() == 2);
    
 cerr << "all tests passed!" << endl;

    return( 0 );
}
/*
string enum_to_string(cs31::BeatThat::GAMEOUTCOME type) {
   switch(type) {
      case cs31::BeatThat::GAMEOUTCOME::GAMENOTOVER:
         return "GAMENOTOVER";
       case cs31::BeatThat::GAMEOUTCOME::HUMANWONGAME:
         return "HUMANWONGAME";
       case cs31::BeatThat::GAMEOUTCOME::COMPUTERWONGAME:
         return "COMPUTERWONGAME";
       case cs31::BeatThat::GAMEOUTCOME::TIEDGAME:
         return "TIEDGAME";
      default:
         return "Invalid ENUM";
   }
}
*/

///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif


