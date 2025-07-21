#include "reward.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()
#include <cstdio>    // freopen()
#define DEBUG

int main()
{
    /* Save Output */
    #ifdef DEBUG
        std::cout << "[DEBUG] Redirect the Output to output_example.txt" << std::endl;
        freopen("output_example.txt", "w", stdout);
    #endif

    srand(time(NULL));

    /* Test 1: Undefined Reward */
    Reward* r = new Reward();
    std::cout << "Undefined Reward (Abstract Class Default Implementation)" << std::endl
              << r->reward() << std::endl; // expected: 2147483647 (undefined behavior)

    /* Test 2: Random Reward 1 */
    r = new DummyReward1();
    std::cout << "Random Reward 1" << std::endl
              << r->reward() << std::endl; // expected: random int in range [0, 5)

    /* Test 3: Random Reward 2 */
    r = new DummyReward2();
    std::cout << "Random Reward 2" << std::endl
              << r->reward() << std::endl; // expected: random int in range [5, 10)

    /* Dummy Net (list of points) using Inferface 1 */
    std::vector<std::pair<int,int>> net = {{0, 0}, {2, 3}, {5, 1}};

    /* Test 4: HPWLReward Inferface 1 */
    r = new HPWLReward();
    std::cout << "HPWL Net Reward (HPWL Interface 1)" << std::endl
              << r->reward(net) << std::endl; // expected: -8

    /* Dummy Net (list of points) using Inferface 2 */
    std::vector<int> net_x = {9, 1, 5};
    std::vector<int> net_y = {0, 3, 1};

    /* Test 5: HPWLReward Inferface 2 */
    r = new HPWLReward();
    std::cout << "HPWL Net Reward (HPWL Infertace 2)" << std::endl
              << r->reward(net_x, net_y) << std::endl; // expected: -11

    /* Dummy Netlist (list of list of points) using Inferface 3 */
    std::vector<std::vector<std::pair<int,int>>> list_of_net = 
        {
            {{1, 2}, {4, 5}},         // Net 1
            {{2, 8}, {5, 7}, {3, 6}}, // Net 2
            {{7, 1}, {9, 4}}          // Net 3
        };

    /* Test 6: HPWLReward Interface 3 */
    r = new HPWLReward();
    std::cout << "HPWL Netlist Reward (HPWL Interface 3)" << std::endl
              << r->reward(list_of_net) << std::endl; // expected: -16 (since -6-5-5 = -16)

    return 0;
}