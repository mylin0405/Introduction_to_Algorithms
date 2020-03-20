# CH3_Growth of functions
In this chapter, we introduce the related symbols O, Ω, Θ, o, ω used for  
describing the order of growth of functons. They can be used to characaterize  
the **running time** of an algorithm.
## Asymptotic nonation
### Big-O
Definition: For given a function g(n), we denote by O(g(n)) the set of functions
```c
O(g(n))={f(n): there exist positive constants c and no such that 0 <= f(n) <= c*g(n) for all n>=n0}
```
The definition implies that
* g(n) >= 0 and f(n) >= 0 for some n >= n0.
* g(n) is and asymptotic **upper** bound for f(n)
* lim f(n)/g(n) = 0 or a constant c , if the limit exists.  
  n→∞  
* Informally Speanking, O(g(n)) is the set of all functions with a **smaller** order of growth than  
    g(n) or the **same** order of growth as g(n), with a constant multiple.

Example: Claim f(n)= 8n^2 + 10n + 7 ...O(n^2)  
To prove the claim, we need to find some constant c and no such that f(n) <= c*n^2 for all n>=n0  
Proof: we have f(n)= 8n^2 + 10n + 7 <= 20n^2 for n>=5;
What is O(n^2)?
* The set of all functions that grow slower than or in the same order as n^2
* So: n, n^2, n^2+n...........are all in O(n^2) 

### 

