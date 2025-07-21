#include "reward.h"
#include <stdlib.h>  // rand(), srand()
#include <stdio.h>
#include <time.h>    // time()
#include <vector>
#include <utility>
#include <algorithm> // min_element(), max_element()
#include <numeric>   // accumulate()

int DummyReward1::reward() const 
{
    return (int)(rand()) % 5;
}

int DummyReward2::reward() const
{
    return 5 + (int)(rand()) % 5;
}

/**
 * HPWLReward::reward() - Computes HPWL reward for a given net
 * @net: a list of points representing the pins' (x, y) coordinates in a net
 * 
 * Return: the HPWL of the bounding box formed by the given points
 *         (Lower HPWL indicates better placement)
 */
int HPWLReward::reward(const std::vector<std::pair<int,int>>& net) const
{
    if (net.empty()) return 0;

    int xmin = std::numeric_limits<int>::max();
    int xmax = std::numeric_limits<int>::min();
    int ymin = std::numeric_limits<int>::max();
    int ymax = std::numeric_limits<int>::min();

    for (const auto& p : net) {
        if (p.first < xmin) xmin = p.first;
        if (p.first > xmax) xmax = p.first;
        if (p.second < ymin) ymin = p.second;
        if (p.second > ymax) ymax = p.second;
    }

    int hpwl = (xmax - xmin) + (ymax - ymin);

    return -hpwl; // since HPWL is cost, the smaller the reward, the better
}

/**
 * HPWLReward::reward() - Computes HPWL reward for a given net
 * @net_x: a list of points representing the pins' x coordinates in a net
 * @net_y: a list of points representing the pins' y coordinates in a net
 * 
 * Return: the HPWL of the bounding box formed by the given points
 *         (Lower HPWL indicates better placement)
 */
int HPWLReward::reward(const std::vector<int>& net_x, const std::vector<int>& net_y) const
{
    if (net_x.empty() || net_y.empty() || net_x.size() != net_y.size())
        return 0;  // invalid input or empty => HPWL = 0

    int xmin = *std::min_element(net_x.begin(), net_x.end());
    int xmax = *std::max_element(net_x.begin(), net_x.end());
    int ymin = *std::min_element(net_y.begin(), net_y.end());
    int ymax = *std::max_element(net_y.begin(), net_y.end());

    int hpwl = (xmax - xmin) + (ymax - ymin);

    return -hpwl; // since HPWL is cost, the smaller the reward, the better
}

/**
 * HPWLReward::reward() - Computes the total HPWL reward for multiple nets
 * @list_of_net: a list of nets, each net is a list of (x, y) pin coordinates
 * 
 * Return: the sum of HPWL rewards for all nets
 */
int HPWLReward::reward(const std::vector<std::vector<std::pair<int,int>>>& list_of_net) const
{
    std::vector<int> net_rewards(list_of_net.size());
    std::transform(list_of_net.begin(), list_of_net.end(), net_rewards.begin(), 
        [this](const std::vector<std::pair<int,int>>& x) { return this->reward(x); });
    
    int hpwl = std::accumulate(net_rewards.begin(), net_rewards.end(), 0);

    return hpwl; // already negative
}