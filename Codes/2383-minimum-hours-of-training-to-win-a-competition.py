'''
Author: LetMeFly
Date: 2023-03-13 12:03:58
LastEditors: LetMeFly
LastEditTime: 2023-03-13 12:06:33
'''
from typing import List


class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]) -> int:
        ans = 0
        for i in range(len(experience)):
            if initialEnergy <= energy[i]:
                ans += energy[i] + 1 - initialEnergy
                initialEnergy = energy[i] + 1
            if initialExperience <= experience[i]:
                ans += experience[i] + 1 - initialExperience
                initialExperience = experience[i] + 1
            initialEnergy -= energy[i]
            initialExperience += experience[i]
        return ans