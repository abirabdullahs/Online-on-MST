# Bangladesh University of Engineering and Technology
**CSE208: Data Structure and Algorithms Sessional II**
**Online - 1 on Minimum Spanning Tree**

**Section:** C &nbsp;|&nbsp; **Time:** 30 Minutes

---

## Cutting Flight Routes

A country has **N** airports connected by **M** flight routes. Each route has an annual operating cost paid by the aviation authority. Due to budget cuts, the authority wants to shut down as many routes as possible to save money — but every airport must still be reachable from every other airport (possibly through intermediate stops).

Find the maximum number of routes that can be shut down and the maximum total annual savings. Also list the routes that must remain operational.

## Input Format

- First line: Two integers `N` (airports) and `M` (routes).
- Next `M` lines: Three integers `u v w` — a route between airport `u` and `v` with annual cost `w`.

## Output Format

- Line 1: Maximum number of routes shut down.
- Line 2: Maximum total annual savings.
- Line 3 onward: Remaining operational routes as `u v w`, one per line.
- If airports are not fully connected, print `Impossible`.

## Constraints

- 2 ≤ N ≤ 100,000
- N−1 ≤ M ≤ 100,000
- 1 ≤ w ≤ 10⁹
- Undirected, no self-loops.

## Requirement

- No STL graph libraries. You may use `sort()`, `vector`, and basic STL only.

## Samples

### Sample 1

**Input**
```
5 7
1 2 3
1 3 8
2 3 5
2 4 9
3 4 2
3 5 6
4 5 4
```

**Output**
```
Routes shut down: 3
Total savings: 23
Operational routes:
3 4 2
1 2 3
4 5 4
2 3 5
```

### Sample 2

**Input**
```
3 2
1 2 5
3 4 6
```

**Output**
```
Impossible
```

**Explanation:** Airport 3 and 4 form a disconnected component. Not all airports reachable.
