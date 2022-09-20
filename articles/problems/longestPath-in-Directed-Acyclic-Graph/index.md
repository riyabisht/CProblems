---
title: Longest Path in a Directed Acyclic Graph
hide:  
  - navigation
tags:
  - dfs
  - recursion
---

## Problem Statement

- Given weighted Directed Acyclic Graph (DAG) and a source vertex `s` in it.
- find the longest distance from `s` to all other vertices in the given graph.

## Example

![img](img/LongestPath-DAG.png)

`0=r, 1=s, 2=t, 3=x, 4=y, 5=z`

Following are longest distances from source vertex 1
`INF 0 2 9 8 10`

## Solutions

### Topological sorting

- find topological sorting of graph and store it in a stack
- intialise distances to all vertices as minus infinite and distance to source as 0
- Do following for every vertex u in topological order.
- Do following for every adjacent vertex `v` of `u`
    - `if (dist[v] < dist[u] + weight(u, v)) dist[v] = dist[u] + weight(u, v)`

Below is the implementation of the above approach:

```cpp
{{ include_file('longest_path_DAG.cpp') }}
```

```txt
{{ include_file('longest_path_DAG_in.txt') }}
```

#### Notes

- Time Complexity: $O(E+V)$
- Auxiliary Space: $O(V)$
- $E$ - total no. of edges
- $V$ - total no. of vertices

## References ans External Links

- <https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/>
