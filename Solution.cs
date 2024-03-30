
using System;

public class Solution
{
    private static readonly int NOT_POSSIBLE_FOR_FIRST_PLAYER_TO_WIN = -1;

    public int MinimumLevels(int[] possible)
    {
        int totalPointsForAllLevels = 0;
        foreach (int value in possible)
        {
            totalPointsForAllLevels += (value == 1) ? 1 : -1;
        }

        int minLevelsForFirstPlayerToWin = 0;

        for (int i = 0; i < possible.Length - 1; ++i)
        {
            minLevelsForFirstPlayerToWin += (possible[i] == 1) ? 1 : -1;

            if (minLevelsForFirstPlayerToWin > totalPointsForAllLevels - minLevelsForFirstPlayerToWin)
            {
                return i + 1;
            }
        }
        return NOT_POSSIBLE_FOR_FIRST_PLAYER_TO_WIN;
    }
}
