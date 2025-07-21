#ifndef REWARD_H_
#define REWARD_H_

#include <vector>
#include <utility>
#include <limits>

/** 
 * class Reward: An abstract class that define many kinds of interfaces
 */
class Reward {
public:
    virtual int reward() const { return UNDEFINED_REWARD; };
    virtual int reward(const std::vector<std::pair<int,int>>& net) const { return UNDEFINED_REWARD; };
    virtual int reward(const std::vector<int>& net_x, const std::vector<int>& net_y) const { return UNDEFINED_REWARD; };
    virtual int reward(const std::vector<std::vector<std::pair<int,int>>>& list_of_net) const { return UNDEFINED_REWARD; };
    virtual ~Reward() = default;
private:
    const int UNDEFINED_REWARD = std::numeric_limits<int>::max();
};

class DummyReward1 : public Reward {
public:
    int reward() const;
};

class DummyReward2 : public Reward {
public:
    int reward() const;
};

/** 
 * class HPWLReward: Computes reward based on Half-Perimeter Wire Length (HPWL)
 * see https://arxiv.org/abs/2004.10746 3.3.1. WIRELENGTH 
 */
class HPWLReward : public Reward {
public:
    int reward(const std::vector<std::pair<int,int>>& net) const override;
    int reward(const std::vector<int>& net_x, const std::vector<int>& net_y) const override;
    int reward(const std::vector<std::vector<std::pair<int,int>>>& list_of_net) const override;
};

#endif // REWARD_H_