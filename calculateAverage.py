'''
Author: LetMeFly
Date: 2025-10-31 18:13:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-31 18:33:16
'''
APrice = 916.59
AWeight = 1.0364
BPrice = 928.38
BWeight = 0.9986

AAll = APrice * AWeight
BAll = BPrice * BWeight
AllPrice = AAll + BAll
AllWeight = AWeight + BWeight
average = AllPrice / AllWeight

print(f'A: {APrice}/g * {AWeight} = {AAll}')
print(f'B: {BPrice}/g * {BWeight} = {BAll}')
print(f'Average: {APrice} / {AllWeight} = {average}/g')

weightFrom = 1.1

# range [start, to], step is step, end with to
def myRange(start: float, to: float, step: float):
    while start < to:
        yield start
        start += step
    yield to

for weight in myRange(weightFrom, AllWeight, 0.1):
    bChooseWeight = weight - AWeight
    choosePrice = AWeight * APrice + bChooseWeight * BPrice
    chooseAverage = choosePrice / weight
    print(f"A({AWeight}*{APrice}) + B({bChooseWeight:.4f}*{BPrice}) = {choosePrice:.4f} | /{weight:.4f} = {chooseAverage:.4f}")