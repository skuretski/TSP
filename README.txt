README

***************************************************************
This is an implementation of TSP using Christofides algorithm. 
It also uses path improvement with 2-OPT. By combining
Christofides with an upper bound of 3/2 and 2-OPT improvement,
we aim to provide a solution bounded above by 1.25. 

Christofides in a Nutshell
1. Find the minimum spanning tree (MST) of graph G.
2. Find the vertices with odd degree (O) from the MST.
3. Find the minimum cost perfect matching (P) from O.
4. Find G' which is MST union P.
5. Find the Euler tour (E) of G'.
6. Find the Hamiltonian cycle of E. 

2-OPT
1. Select edge (v1, v2) and (v3, v4).
2. Replace edges with best pair such that it minimizes tour length.   