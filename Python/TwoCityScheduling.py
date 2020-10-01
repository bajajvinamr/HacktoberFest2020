'''
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].
Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.'''


class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        a = sorted(costs, key=lambda x: x[0]-x[1])
        cost =  0
        for i in range(len(a)//2):
            cost += a[i][0]
            
        for i in range(len(a)//2, len(a)):
            cost += a[i][1]
        return cost
