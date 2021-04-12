#include <iostream>
#include <vector>
#include <unistd.h>

std::string str_multiply(std::string s, int t)
{
    std::string ret = "";

    if (t == 0)
    {
        return ret;
    }

    for (int i = 0; i < t; i++)
    {
        ret += s;
    }

    return ret;
}

void show_vec(std::vector<int> t)
{
    std::cout << "Tower is : ";

    for (int i = 0; i < t.size(); i += 1)
    {
        std::cout << t[i] << " ";
    }

    std::cout << "\n";
}

class TowerOfHanoi
{
private:
    int height;
    std::vector<std::vector<int>> moves;     // vector of vector<int>, keeps track of moves
    std::vector<int> tower1, tower2, tower3; // contains disks on towers

    void solve(int, int, int, int); // recursive algorithm for solving tower of hanoi
    void printtowers();

public:
    TowerOfHanoi(); // default contstrutor
    TowerOfHanoi(int);

    void visualize();
    void clearscreen();
    void debug();

    ~TowerOfHanoi();
};

TowerOfHanoi::TowerOfHanoi()
{
    // pass
}

TowerOfHanoi::TowerOfHanoi(int h)
{
    height = h;

    for (int i = 0; i < h; i += 1)
    {
        tower1.push_back(height - i);
    }
}

void TowerOfHanoi::solve(int n, int twr1, int twr2, int twr3)
{
    if (n == 1)
    {
        moves.push_back({1, twr1, twr3});
        return;
    }

    solve(n - 1, twr1, twr3, twr2);
    moves.push_back({n, twr1, twr3});
    solve(n - 1, twr2, twr1, twr3);
}

void TowerOfHanoi::visualize()
{
    clearscreen();

    std::vector<int> temp;
    int disk_move;

    printtowers();
    solve(height, 1, 2, 3);

    for (int j = 0; j < moves.size(); j++)
    {

        temp = moves[j];

        switch (temp[1])
        {
        case 1:
            disk_move = tower1.back();
            tower1.pop_back();
            break;

        case 2:
            disk_move = tower2.back();
            tower2.pop_back();
            break;

        case 3:
            disk_move = tower3.back();
            tower3.pop_back();
            break;

        default:
            break;
        }

        switch (temp[2])
        {

        case 1:
            tower1.push_back(disk_move);
            break;

        case 2:
            tower2.push_back(disk_move);
            break;
        case 3:
            tower3.push_back(disk_move);
            break;

        default:
            break;
        }

        printtowers();
    }
}

void TowerOfHanoi::printtowers()
{
    std::cout << "\n";

    for (int i = height > 3 ? height : 3; i > 0; i--)
    {

        std::cout << "   ";

        // tower1
        if (tower1.size() < i)
        {
            std::cout << str_multiply(" ", height - 1) << "|" << str_multiply(" ", height - 1);
        }
        else
        {
            std::cout << str_multiply(" ", height - tower1[i - 1]);
            std::cout << str_multiply("\u2586", 2 * tower1[i - 1] - 1);
            std::cout << str_multiply(" ", height - tower1[i - 1]);
        }

        std::cout << "   ";

        // tower2
        if (tower2.size() < i)
        {
            std::cout << str_multiply(" ", height - 1) << "|" << str_multiply(" ", height - 1);
        }
        else
        {
            std::cout << str_multiply(" ", height - tower2[i - 1]);
            std::cout << str_multiply("\u2586", 2 * tower2[i - 1] - 1);
            std::cout << str_multiply(" ", height - tower2[i - 1]);
        }

        std::cout << "   ";

        // tower3
        if (tower3.size() < i)
        {
            std::cout << str_multiply(" ", height - 1) << "|" << str_multiply(" ", height - 1);
        }
        else
        {
            std::cout << str_multiply(" ", height - tower3[i - 1]);
            std::cout << str_multiply("\u2586", 2 * tower3[i - 1] - 1);
            std::cout << str_multiply(" ", height - tower3[i - 1]);
        }

        std::cout << "\n";
    }

    std::cout << "\n";

    sleep(1);
    clearscreen();
}

void TowerOfHanoi::debug()
{
    std::cout << "disk | from | to \n";

    for (auto move : moves)
    {
        for (auto x : move)
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}

void TowerOfHanoi::clearscreen()
{
    std::cout << "\033[H\033[2J";
}

TowerOfHanoi::~TowerOfHanoi()
{
    // pass
}

void sayhello()
{
    std::cout << "Hello, World!\n";
    std::cout << "\u2586\n";
}
