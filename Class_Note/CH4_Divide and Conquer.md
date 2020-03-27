# CH4_Divide and Conquer
In this chapter, we revisit and deepen our understanding on the divide-and-conquer approach for designing algorithms,  
and learn different method for solving recurrences characterizing running time of divide-and-conquer algorithms.

### Soving the maximun-subarray problem
Recall that the method of divide-and-conquer consists of, **at each level of the recursion **, the three steps:
1. divide a problem into subproblems.
2. conquer **(recursively)** the subproblems.
3. combine the solutions of the subproblems and obtain a solution for the original problem. 
We will use this design method to design an efficient algorithms to solve the following problem.

### The stack-buying problem
Suppose that you have the prices that a stack traded over a period of n consecutive days, as shown in Fig4.1(???) for n=17.  
You can buy after day 0; you can buy one unit of stack only one time and then sell it at a later date. The mission is that within n   
consecutive days you have to buy and sell the stack once, and you have to find a strategy to maximize the profit.
SO, you come up with 3 strategies.
1. Buy-low-and-sell-high: buy at the lowest price and sell at the highest price. But Fig4.1(???) tells us that it does not work, since  
   the lowest price occurs after day 7 while the highest price occurs after day 1.
2. Buy-low **or** Sell-high:
   (a) Buy-low: find the day with the lowest price, and walk toward its right to find the sell day.
   (b) Sell-high: find the day with the highest price, and walk toward its left to find the buy day.
   (c) Choose the larger one between Buy-low and Sell-high Fig4.2 tells us "Buy-low" doesn't always work.
3. A brute-force strategy: check all possible buy-and-sell combinations, i.e., check "n chooses 2" pairs, and find a "maximum"    combinations. This strategy always works.
It turns out that only the brute-force strategy can work, but the complxity is **Θ(n^2）**.It would take **Ω(n^2)** time to find the solution. Can we do better ?

