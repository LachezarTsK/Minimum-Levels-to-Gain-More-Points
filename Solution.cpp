
#include <vector>
using namespace std;

class Solution {

    static const int NOT_POSSIBLE_FOR_FIRST_PLAYER_TO_WIN = -1;

public:
    int minimumLevels(const vector<int>& possible) const {
        int totalPointsForAllLevels = 0;
        for (const auto& value : possible) {
            totalPointsForAllLevels += (value == 1) ? 1 : -1;
        }

        int minLevelsForFirstPlayerToWin = 0;

        for (int i = 0; i < possible.size() - 1; ++i) {
            minLevelsForFirstPlayerToWin += (possible[i] == 1) ? 1 : -1;

            if (minLevelsForFirstPlayerToWin > totalPointsForAllLevels - minLevelsForFirstPlayerToWin) {
                return i + 1;
            }
        }
        return NOT_POSSIBLE_FOR_FIRST_PLAYER_TO_WIN;
    }
};
