
public class Solution {

    private static final int NOT_POSSIBLE_FOR_FIRST_PLAYER_TO_WIN = -1;

    public int minimumLevels(int[] possible) {
        int totalPointsForAllLevels = 0;
        for (int value : possible) {
            totalPointsForAllLevels += (value == 1) ? 1 : -1;
        }

        int minLevelsForFirstPlayerToWin = 0;

        for (int i = 0; i < possible.length - 1; ++i) {
            minLevelsForFirstPlayerToWin += (possible[i] == 1) ? 1 : -1;

            if (minLevelsForFirstPlayerToWin > totalPointsForAllLevels - minLevelsForFirstPlayerToWin) {
                return i + 1;
            }
        }
        return NOT_POSSIBLE_FOR_FIRST_PLAYER_TO_WIN;
    }
}
