#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define Version "0.1A"
vector<string> Effs;
/** @brief Init Function*/
void Init()
{
    cout << "Please wait..." << endl;
    FILE *f;
    // Effects
    f = fopen("J112Effects.txt", "r");
    rewind(f);
    for (int i = 1; i <= 27; i++)
    {
        char t[21];
        fscanf(f, "%s", t);
        Effs.push_back(t);
    }
    fclose(f);
    // Init
    cout << "Done!" << endl
         << endl
         << " ----   --    |   |  -    -   ----  -----" << endl
         << "/      /  \\   |\\  |  |    |  /        |" << endl
         << "-----  |--|   | \\ |  |    |  -----    |" << endl
         << "    /  |  |   |  \\|  |    |      /    |" << endl
         << "----   |  |   |   |   \\__/   ----     |" << endl
         << endl
         << "MCCB Version " << Version << endl
         << "Github: https://github.com/Sanust/MCCB" << endl
         << "BiliBili: https://space.bilibili.com/331907786" << endl
         << endl;
    // for (auto &&i : Effs)
    //     cout << i << endl;
    return;
}
/** @brief The Function of Creating "Effect" Command
 * @param g "give" or "clear"
 * @param s "show" or "don't show"
 * @param t time of the effect
 * @param v level of the effect
 * @param i id of the effect
 * @return The Command of "Effect"
 **/
string Effect(bool g, bool s, int t, int v, int i)
{
    string p, c;
    if (g)
    {
        cout << "Choose the options below" << endl
             << "p : The nearest player" << endl
             << "a : All of the players" << endl
             << "e : All of the entities" << endl
             << "r : A Random player" << endl
             << "s : The command executor" << endl
             << "z : None of the above" << endl
             << "Input here:";
        cin >> c;
        cout << endl;
        if (c == "z")
        {
            cout << endl
                 << "Input a player name here:" << endl;
            cin >> p;
            return "/effect " + p + " " + Effs[i] + " " + to_string(t) + " " + to_string(v) + (s ? " true" : " false");
        }
        else
        {
            if (c != "p" && c != "a" && c != "e" && c != "r" && c != "s")
                return "Input Error";
            else
                return "/effect @" + c + " " + Effs[i] + " " + to_string(t) + " " + to_string(v) + (s ? " true" : " false");
        }
    }
    else
    {
        cout << "Choose the options below" << endl
             << "p : The nearest player" << endl
             << "a : All of the players" << endl
             << "e : All of the entities" << endl
             << "r : A Random player" << endl
             << "s : The command executor" << endl
             << "z : None of the above" << endl
             << "Input here:";
        cin >> c;
        cout << endl;
        if (c == "z")
        {
            cout << endl
                 << "Input a player name here:" << endl;
            cin >> p;
            if (i == 0)
                return "/effect clear " + p;
            else
                return "/effect clear " + p + " " + Effs[i];
        }
        else
        {
            if (c != "p" && c != "a" && c != "e" && c != "r" && c != "s")
                return "Input Error";
            if (i == 0)
                return "/effect clear @" + c;
            else
                return "/effect clear @" + c + " " + Effs[i];
        }
    }
}
/** @brief Choose Function*/
void Choose()
{
    cout << "Choose A Command To Start!" << endl
         << "0 Effect" << endl
         << "Input The Id Of The Command..." << endl;
    int id;
    cin >> id;
    if (id == 0)
    {
        cout << "Input a 't' to give an effect, Or input an 'f' to clear (an) effect(s):" << endl;
        char t;
        cin >> t;
        if (t == 't')
        {
            int p = 0, l, t;
            char o;
            for (auto &&i : Effs)
            {
                cout << p << " " << i << endl;
                p++;
                if (p == 27)
                    break;
            }
            cout << "Input the Effect id:";
            cin >> p;
            cout << "Input the Effect Level:";
            cin >> l;
            cout << "Input the Effect time(0-1,000,000):";
            cin >> t;
            cout << "Input a 't' to show particles, Or input an 'f' to hide particles:";
            cin >> o;
            if (o == 't')
                cout << Effect(true, true, t, l, p) << endl;
            else if (o == 'f')
                cout << Effect(true, false, t, l, p) << endl;
            else
            {
                cout << "Wrong Input!" << endl;
                return;
            }
        }
        else if (t == 'f')
        {
            int p = 0;
            for (auto &&i : Effs)
            {
                cout << p << " " << i << endl;
                p++;
            }
            cout << "Input the Effect id (0 represents all of the above):";
            cin >> p;
            cout << Effect(false, false, 0, 0, p) << endl;
        }
        else
        {
            cout << "Wrong Input!" << endl;
            return;
        }
    }
    else
        cout << "Wrong Command Id" << endl;
    cout << endl;
    return;
}
/** @brief Main Function*/
int main()
{
    Init();
    while (true)
        Choose();
    return 0;
}