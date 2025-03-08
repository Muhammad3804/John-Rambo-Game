#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include <fstream>

using namespace std;

// Constants for the map size
const int ROWS = 40;
const int COLUMNS = 30;

int highScore, tankBulletX, speed = 30, lives = 6, cratesDestroy = 0, tanksDestroy = 0;
int obstacleSpeed = 0, tankHits = 0, bulletTemp, obstacleY, obstacleX, cratesY, cratesX;
int tankBulletY, tankX, tankY;

void Menu(bool& gameOver);
void loadingScreen();

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setup() {
    setColor(8);
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t   * * * *" << "    * *    " << "  *     * " << "  *    *" << endl;
    cout << "\t\t\t\t\t      *   " << "  *     *  " << "  *     * " << "  **   *" << endl;
    cout << "\t\t\t\t\t      *   " << " *       * " << "  * * * * " << "  * *  *" << endl;
    cout << "\t\t\t\t\t      *   " << " *       * " << "  *     * " << "  *  * *" << endl;
    cout << "\t\t\t\t\t  *   *   " << "  *     *  " << "  *     * " << "  *   **" << endl;
    cout << "\t\t\t\t\t   * *    " << "    * *    " << "  *     * " << "  *    *" << endl;
    cout << "\n\n\n";
    cout << "\t\t\t\t    * * *  " << "       *     " << "  *     * " << "  * * *  " << "    * *    " << endl;
    cout << "\t\t\t\t    *    * " << "      * *    " << "  **   ** " << "  *    * " << "  *     *  " << endl;
    cout << "\t\t\t\t    *   *  " << "     *   *   " << "  * * * * " << "  * * *  " << " *       * " << endl;
    cout << "\t\t\t\t    * *    " << "    * * * *  " << "  *  *  * " << "  *    * " << " *       * " << endl;
    cout << "\t\t\t\t    *   *  " << "   *       * " << "  *     * " << "  *    * " << "  *     *  " << endl;
    cout << "\t\t\t\t    *     *" << "  *         *" << "  *     * " << "  * * *  " << "    * *    " << endl;
    cout << "\n\n\t\t\t\t\t     ";

    system("pause");
}

void Instructions()
{
    bool ah;
    system("cls");

    cout << "Movement Instructions:\n";
    cout << "\t\t- Use WASD to move.\n";
    cout << "\t\t- Press Space to jump.\n";
    cout << "\t\t- Press ESC to end the game.\n";
    cout << "\t\t- Press K to shoot\n\n\n\n";
    setColor(7);
    cout << "Game Instructions:\n";
    cout << "\t\t- Tanks can shoot you. Dodge the bullets and shoot back to destroy the tanks.\n";
    cout << "\t\t- It takes 4 bullets to destroy a tank. For each tank destroyed, the player will get additional health and 80 score.\n";
    cout << "\t\t- 2 health bar will be lost if you hit the tank.\n";
    cout << "\t\t- Dodge # shaped crates or destroy crates to get 10 score.\n";
    cout << "\t\t- Jump over the |---| shaped obstacles or destroy them to get 20 score.\n";
    cout << "\t\t- Destroy 5 crates or obstacles to get health.\n\n\n\n";
    setColor(14);
    cout << "LEVEL 1:\t";
    cout << "Destroy 5 tanks or score 2500 points to complete level 1.\n";
    cout << "LEVEL 2:\tThis level will be harder than the first one. Obstacles will move faster\n\n\n\n";
    setColor(7);
    system("pause");
    system("cls");
    Menu(ah);

}

void Menu(bool& gameOver)
{
    setColor(14);
    system("cls");
    int choice;
    cout << "***************************\n\tJOHN RAMBO\n***************************\n\n";
    setColor(7);
    cout << "1. Start Game.\n";
    cout << "2. Instructions.\n";
    cout << "3. Quit game.\n\n";
    setColor(14);
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 2)
    {
        Instructions();
    }
    else if (choice == 3)
    {
        gameOver = true;
    }
    else if (choice == 1)
    {
        system("cls");
        loadingScreen();
    }
    else
    {
        cout << "\nAre you autistic???!!!!\nThe program clearly says pick from 1-3.\nI won't allow retarded people to play this game.\nEnding Program.\n";
        gameOver = true;
    }
}

void loadingScreen()
{
    setColor(7);
    cout << "\n\n\n\n\t\t    TIP: It is advised to zoom out and maximize your console screen for better experience";
    setColor(8);
    cout << "\n\n\n\n\n";
    cout << "\t\t\t   *      " << "    * *    " << "     *     " << "  * * *    " << " * * * " << "  *    * " << "     * *    " << endl;
    cout << "\t\t\t   *      " << "  *     *  " << "    * *    " << "  *     *  " << "   *   " << "  **   * " << "   *     *  " << endl;
    cout << "\t\t\t   *      " << " *       * " << "   *   *   " << "  *      * " << "   *   " << "  * *  * " << "  *         " << endl;
    cout << "\t\t\t   *      " << " *       * " << "  * * * *  " << "  *      * " << "   *   " << "  *  * * " << "  *    * *  " << endl;
    cout << "\t\t\t   *      " << "  *     *  " << " *       * " << "  *     *  " << "   *   " << "  *   ** " << "   *     *  " << endl;
    cout << "\t\t\t   * * * *" << "    * *    " << "*         *" << "  * * *    " << " * * * " << "  *    * " << "     * * *  " << endl;
    cout << "\n\n\n\t\t\t  ";
    for (int i = 0; i < 70; i++)
    {
        cout << static_cast<char>(178);
    }
    cout << "\r\t\t\t ";
    setColor(10);
    for (int i = 0; i < 70; ++i) {
        cout << static_cast<char>(219);
        Sleep(69);
    }
    setColor(14);
    system("cls");

}

void DeathScreen()
{
    setColor(7);
    cout << "\n\n\n";
    cout << "\t\t\t\t     * * *  " << "       *     " << "  *     * " << "  * * *  " << "    * *    " << endl;
    cout << "\t\t\t\t     *    * " << "      * *    " << "  **   ** " << "  *    * " << "  *     *  " << endl;
    cout << "\t\t\t\t     *   *  " << "     *   *   " << "  * * * * " << "  * * *  " << " *       * " << endl;
    cout << "\t\t\t\t     * *    " << "    * * * *  " << "  *  *  * " << "  *    * " << " *       * " << endl;
    cout << "\t\t\t\t     *   *  " << "   *       * " << "  *     * " << "  *    * " << "  *     *  " << endl;
    cout << "\t\t\t\t     *     *" << "  *         *" << "  *     * " << "  * * *  " << "    * *    " << endl;
    cout << "\n\n\n";
    setColor(4);  
    cout << "\t\t\t\t\t   * * *    " << " * * * " << "  * * * * " << "  * * *    " << endl;
    cout << "\t\t\t\t\t   *     *  " << "   *   " << "  *       " << "  *     *  " << endl;
    cout << "\t\t\t\t\t   *      * " << "   *   " << "  * * *   " << "  *      * " << endl;
    cout << "\t\t\t\t\t   *      * " << "   *   " << "  *       " << "  *      * " << endl;
    cout << "\t\t\t\t\t   *     *  " << "   *   " << "  *       " << "  *     *  " << endl;
    cout << "\t\t\t\t\t   * * *    " << " * * * " << "  * * * * " << "  * * *    " << endl;
    setColor(7);


}

//hide cursor to reduce flickering
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

//position cursor instead of clearing screen to reduce flickering
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, pos);
}

void Map(const int rows, const int columns, int& moveRow, int yaxis, int xaxis, bool& gameOver, bool& playerBullet, bool& obstacle, bool& tank, bool& crates, bool& tankBullet, int& score, int& level, bool& tankXmovement) {
    // Use cursor positioning instead of clearing screen to reduce flickering
    setCursorPosition(0, 0);

    char map[ROWS][COLUMNS];
    obstacleSpeed++;

    //initialize the whole array with spaces first
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j] = ' ';
        }
    }

    //now replace it with boundries and obstacles
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            // ye wali condition for upper and lower yes
            if (i == 0 || i == rows - 1) {
                map[i][j] = 220;
            }

            // left or right yes
            else if (j == 0) {
                map[i][j] = 221;
            }
            else if (j == columns - 1) {
                map[i][j] = 222;
            }

            // character print hojaye phir?
            else if (i == yaxis && j == xaxis) {
                map[i][j] = 'X';

                // conditions for adding bullets
                if (playerBullet) {
                    if (map[i - 1 - moveRow][bulletTemp] == ' ') {
                        map[i - 1 - moveRow][bulletTemp] = '*';
                    }
                    else {
                        map[i - 1 - moveRow][bulletTemp] = ' ';
                        playerBullet = false;
                        moveRow = 0;
                    }
                }

                //condtions for tanks movement
                if (!tank) {
                    tankY = 1;
                    tankBulletY = 1;
                    tankX = rand() % (columns - 12) + 6;
                    tank = true;
                }
                else {
                    if (tankY < rows - 2) {
                        map[tankY][tankX] = ' ';
                        if (level == 1) {
                            if (obstacleSpeed % 7 == 0) {
                                tankY++;
                                //conditions for x axis movement of tank
                                if (tankXmovement) {
                                    tankX++;
                                    if (tankX == columns - 6) {
                                        tankXmovement = false;
                                    }
                                }
                                else {
                                    tankX--;
                                    if (tankX == 4) {
                                        tankXmovement = true;
                                    }
                                }
                            }
                        }
                        else if (level == 2) {
                            if (obstacleSpeed % 4 == 0) {
                                tankY++;
                                if (tankXmovement) {
                                    tankX++;
                                    if (tankX == columns - 6) {
                                        tankXmovement = false;
                                    }
                                }
                                else {
                                    tankX--;
                                    if (tankX == 4) {
                                        tankXmovement = true;
                                    }
                                }
                            }
                        }
                        if (tankHits == 0) {
                            map[tankY][tankX] = '|';
                            map[tankY][tankX + 1] = '#';
                            map[tankY][tankX - 1] = '#';
                            map[tankY][tankX + 2] = '0';
                            map[tankY][tankX - 2] = '0';
                            map[tankY - 1][tankX + 1] = '-';
                            map[tankY - 1][tankX - 1] = '-';
                            map[tankY - 1][tankX + 2] = '#';
                            map[tankY - 1][tankX - 2] = '#';
                            map[tankY - 2][tankX + 1] = '#';
                            map[tankY - 2][tankX - 1] = '#';
                            map[tankY - 2][tankX] = '#';
                            map[tankY - 2][tankX + 2] = '0';
                            map[tankY - 2][tankX - 2] = '0';
                            map[tankY - 1][tankX] = 'T';
                        }

                        else if (tankHits == 1) {
                            map[tankY][tankX] = '|';
                            map[tankY][tankX + 1] = '#';
                            map[tankY][tankX - 1] = '#';
                            map[tankY][tankX + 2] = '0';
                            map[tankY][tankX - 2] = '0';
                            map[tankY - 1][tankX + 1] = '-';
                            map[tankY - 1][tankX - 1] = '-';
                            map[tankY - 1][tankX + 2] = ' ';
                            map[tankY - 1][tankX - 2] = '#';
                            map[tankY - 2][tankX + 1] = ' ';
                            map[tankY - 2][tankX - 1] = '#';
                            map[tankY - 2][tankX] = '#';
                            map[tankY - 2][tankX + 2] = '0';
                            map[tankY - 2][tankX - 2] = '0';
                            map[tankY - 1][tankX] = 'T';
                        }

                        else if (tankHits == 2) {
                            map[tankY][tankX] = '|';
                            map[tankY][tankX + 1] = '#';
                            map[tankY][tankX - 1] = ' ';
                            map[tankY][tankX + 2] = '0';
                            map[tankY][tankX - 2] = ' ';
                            map[tankY - 1][tankX + 1] = ' ';
                            map[tankY - 1][tankX - 1] = '-';
                            map[tankY - 1][tankX + 2] = ' ';
                            map[tankY - 1][tankX - 2] = '#';
                            map[tankY - 2][tankX + 1] = ' ';
                            map[tankY - 2][tankX - 1] = '#';
                            map[tankY - 2][tankX] = '#';
                            map[tankY - 2][tankX + 2] = ' ';
                            map[tankY - 2][tankX - 2] = '0';
                            map[tankY - 1][tankX] = 'T';
                        }

                        else if (tankHits == 3) {
                            map[tankY][tankX] = '|';
                            map[tankY][tankX + 1] = '#';
                            map[tankY][tankX - 1] = ' ';
                            map[tankY][tankX + 2] = ' ';
                            map[tankY][tankX - 2] = ' ';
                            map[tankY - 1][tankX + 1] = ' ';
                            map[tankY - 1][tankX - 1] = '-';
                            map[tankY - 1][tankX + 2] = ' ';
                            map[tankY - 1][tankX - 2] = '#';
                            map[tankY - 2][tankX + 1] = ' ';
                            map[tankY - 2][tankX - 1] = ' ';
                            map[tankY - 2][tankX] = ' ';
                            map[tankY - 2][tankX + 2] = ' ';
                            map[tankY - 2][tankX - 2] = '0';
                            map[tankY - 1][tankX] = 'T';
                        }
                    }
                    else {
                        tank = false;
                    }
                }
                // conditions for tank bullets
                if (!tankBullet) {
                    tankBullet = true;
                    tankBulletY = tankY;
                    tankBulletX = tankX;
                }
                else {
                    if (tankBulletY < tankY + 11 && tankBulletY < rows - 1) {
                        map[tankBulletY][tankBulletX] = ' ';
                        if (level == 1) {
                            if (obstacleSpeed % 3 == 0) {
                                tankBulletY++;
                            }
                        }
                        else if (level == 2) {
                            if (obstacleSpeed % 2 == 0) {
                                tankBulletY++;
                            }
                        }
                        map[tankBulletY][tankBulletX] = '|';
                    }
                    else {
                        tankBullet = false;
                    }
                }

                //conditions for crates
                if (!crates) {
                    cratesY = 1;
                    cratesX = rand() % (columns - 2) + 1;
                    crates = true;
                }
                else {
                    if (cratesY < rows - 1) {
                        map[cratesY][cratesX] = ' ';
                        if (level == 1) {
                            if (obstacleSpeed % 3 == 0) {
                                cratesY++;
                            }
                        }
                        else if (level == 2) {
                            if (obstacleSpeed % 2 == 0) {
                                cratesY++;
                            }
                        }

                        map[cratesY][cratesX] = '#';
                    }
                    else {
                        crates = false;
                    }
                }

                //conditions for printing and moving obstacles
                if (!obstacle) {
                    obstacleY = 1;
                    obstacleX = rand() % (columns - 6) + 2;
                    if (score % 50 == 0) {
                        obstacle = true;
                    }
                }
                else {
                    if (obstacleY < rows - 1) {
                        map[obstacleY][obstacleX] = ' ';
                        if (level == 1) {
                            if (obstacleSpeed % 3 == 0) {
                                obstacleY++;
                            }
                        }
                        else if (level == 2) {
                            if (obstacleSpeed % 2 == 0) {
                                obstacleY++;
                            }
                        }
                        map[obstacleY][obstacleX] = '-';
                        map[obstacleY][obstacleX + 1] = '-';
                        map[obstacleY][obstacleX - 1] = '-';
                        map[obstacleY][obstacleX + 2] = '|';
                        map[obstacleY][obstacleX - 2] = '|';
                    }
                    else {
                        obstacle = false;
                    }
                }

                //condtions,,  if the bullet hits the obstacle
                if (map[cratesY + 1][cratesX] == '*') {
                    crates = false;
                    playerBullet = false;
                    cratesDestroy++;
                    if (cratesDestroy % 5 == 0)
                        lives++;
                    moveRow = 0;
                    score += 10;
                }
                if ((map[obstacleY + 1][obstacleX] == '*') || (map[obstacleY + 1][obstacleX + 1] == '*') || (map[obstacleY + 1][obstacleX + 2] == '*') || (map[obstacleY + 1][obstacleX - 1] == '*') || (map[obstacleY + 1][obstacleX - 2] == '*')) {
                    obstacle = false;
                    cratesDestroy++;
                    playerBullet = false;
                    moveRow = 0;
                    score += 20;
                }
                if ((map[tankY + 1][tankX] == '*') || (map[tankY + 1][tankX + 1] == '*') || (map[tankY + 1][tankX - 1] == '*') || (map[tankY + 1][tankX + 2] == '*') || (map[tankY + 1][tankX - 2] == '*')) {
                    tankHits++;
                    playerBullet = false;
                    moveRow = 0;
                    if (tankHits == 4) {
                        tank = false;
                        tanksDestroy++;
                        score += 80;
                        lives++;
                        tankHits = 0;
                        playerBullet = false;
                        moveRow = 0;
                    }
                }

                //decrement of lives, if the player hits the obstacle
                if (cratesY == yaxis && cratesX == xaxis) {
                    crates = false;
                    lives--;
                }
                if ((obstacleY == yaxis && obstacleX == xaxis) || (obstacleY == yaxis && obstacleX - 1 == xaxis) || (obstacleY == yaxis && obstacleX - 2 == xaxis) || (obstacleY == yaxis && obstacleX + 2 == xaxis)) {
                    lives--;
                    obstacle = false;
                }
                if ((tankY == yaxis && tankX == xaxis) || (tankY == yaxis && tankX + 1 == xaxis) || (tankY == yaxis && tankX - 1 == xaxis) || (tankY == yaxis && tankX - 2 == xaxis) || (tankY == yaxis && tankX + 2 == xaxis)) {
                    lives = lives - 2;
                    tank = false;
                }
                if (tankBulletY == yaxis && tankBulletX == xaxis) {
                    lives--;
                    tankBullet = false;
                }
            }
        }
    }

    // Printing array map
    setColor(7);
    for (int i = 0; i < rows; i++) {
        cout << setw(50);
        for (int j = 0; j < columns; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void Input(int rows, int columns, int& yaxis, int& xaxis, bool& gameOver, bool& playerBullet) {
    //movement of player
    if (_kbhit()) {
        int choice;
        switch (_getch()) {
        case '2':
            Instructions();
            break;
        case 'a':
        case 'A':
            if (xaxis == 1) {
                break;
            }
            else {
                xaxis--;
            }
            break;
        case 'd':
        case 'D':
            if (xaxis == columns - 2) {
                break;
            }
            else {
                xaxis++;
            }
            break;
        case 's':
        case 'S':
            if (yaxis == rows - 2) {
                break;
            }
            else {
                yaxis++;
            }
            break;
        case 'w':
        case 'W':
            if (yaxis == rows - 16) {
                break;
            }
            else {
                yaxis--;
            }
            break;
        case 'k':
        case 'K':
            if (playerBullet)
                break;
            bulletTemp = xaxis;
            playerBullet = true;
            break;
        case 32: // Space bar for jump
            if (yaxis < rows - 12) {
                break;
            }
            else {
                yaxis = yaxis - 4;
            }
            break;
        case 27: // ESC key
            cout << "\nDo you really want to quit the game?\nEnter 1 for YES\t\tEnter any other number to continue\n";
            cin >> choice;
            if (choice == 1)
                gameOver = true;
            break;
        }
    }
}

void Score(int& score, int& level)
{
    cout << "Score = " << score;
    cout << "\nTanks Destroyed = " << tanksDestroy;
    cout << "\nPrevious High Score : " << highScore;

    if (level == 1)
    {
        if (score >= 2500 || tanksDestroy == 5)
        {
            level = 2;
            tanksDestroy = 0;
            lives = lives + 2;
            speed = 8;
            system("cls");
            cout << "\nCongratulations you completed level 1\nCurrent Score: " << score << endl << "\nGet ready for level 2!!!\n";
            system("pause");
            system("cls");
            setCursorPosition(0, 0); // set cursor to 0
        }
    }

    score = score + 2;
    cout << "\nLevel = " << level << endl;
}

void Health(bool& gameOver) {
    char liveBar1 = 178, liveBar2 = 219;

    if (lives >= 6) {
        lives = 6;
    }
    setColor(7);
    cout << endl << "Health:    ";
    for (int i = 0; i < 18; i++) {
        cout << liveBar1;
    }
    cout << "\rHealth:    ";
    setColor(10);
    for (int i = 0; i < lives * 3; i++) {
        cout << liveBar2;
    }
    setColor(7);
    cout << endl;
    if (lives < 0) {
        gameOver = true;
    }
}

void readHighscore()
{
    ifstream highScoreFile("highscore.txt");
    if (highScoreFile.is_open())
    {
        highScoreFile >> highScore;
        highScoreFile.close();
    }
}

void updateHighscore(int score)
{
    if (score > highScore)
    {
        cout << "\nCongratulation you scored a new high score\n";
        system("pause");
        ofstream highScoreFile("highscore.txt");
        if (highScoreFile.is_open()) {
            highScoreFile << score;
            highScoreFile.close();
        }
    }
}

int main() {
    const int columns = COLUMNS;
    const int rows = ROWS;
    int yaxis = rows - 10;
    int xaxis = columns / 2;
    int score = 0, level = 1;
    bool gameOver = false, playerBullet = false, obstacle = false;
    bool tank = false, crates = false, tankBullet = false, tankXmovment = true;

    srand(time(0)); //for randomly spawning objects
    hideCursor(); //Hide cursor to reduce flickering

    int moveRow = 0;
    setup();
    Menu(gameOver);
    readHighscore();

    while (!gameOver)
    {
        Map(rows, columns, moveRow, yaxis, xaxis, gameOver, playerBullet, obstacle, tank, crates, tankBullet, score, level, tankXmovment);
        if (playerBullet)
            moveRow++;
        Input(rows, columns, yaxis, xaxis, gameOver, playerBullet);
        Health(gameOver);
        Score(score, level);
        Sleep(speed);
    }

    if (lives < 0) {
        system("cls");
        DeathScreen();
    }
    updateHighscore(score);
    system("pause");
    return 0;
}