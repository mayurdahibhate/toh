#include "toh.hpp"

int main(int argc, char *argv[])
{
    int height = 3;

    // check if user has provided the height
    if (argc == 2)
    {
        height = (std::atoi(argv[1]) > 0) ? std::atoi(argv[1]) : 3;
    }

    TowerOfHanoi towerofhanoi(height);
    towerofhanoi.visualize();

    return 0;
}
