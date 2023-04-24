#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

int pcount = 16; // default value

int main()
{
    cout << "############ Players Draw ############" << endl;
    cout << endl;
    cout << "Set number of players" << endl; 
    cin >> pcount;

    string* players = new string[pcount];                 //filling array with players
    for (int i = 0; i < pcount; ++i)
    {
        cout << "Set nick of player number: " << i + 1 << endl;
        cin >> players[i];
        cout << endl;
    }

    string* draw = new string[pcount];
    srand(static_cast<int>(time(NULL)));
    for (int i = 0; i < pcount;)
    {
        draw[i] = players[rand() % pcount]; //randomizing players
        bool brepeat = false;
        for (int j = 0; j < i; ++j)
        {
            if (draw[j] == draw[i])
            {
                brepeat = 1;
                break;
            }
        }
        if (!brepeat) ++i;
    }
    for (int i = 0; i < pcount; i += 2) //printing pairs of players
    {
        cout << draw[i] << endl;
        if (i != pcount -1) cout << draw[i + 1] << endl;
        cout << endl;
    }
    return 0;
}