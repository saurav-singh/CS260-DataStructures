
#
# Group project: Depth First Search problem
# Date: 03/13/2019
#
#
import copy

#performs depth-first search, starting at the vertex v of graph L, recording visited in mark
def dfs(v):
    global mark, L, dfnum, count
    print(vertices[v],)
    mark[v] = True
    dfnum[v] = count
    count = count + 1
    for w in L[v]:
        if not mark[w]:
            dfs(w)

#Test code

#Based on Fig. 6.38

vertices = ['a','b','c','d','e','f']
n = len(vertices)
global mark, L, dfnum, count
mark = [False]*n
L= [[1,3,5],[2,5],[3],[1],[3,5],[3]] #a->0, b->1,...,f->5
dfnum = ['a','b','c','d','e','f']
count = 0

print("Resulting directed graph after dfs is as below:")

for v in range(n):
    mark[v] = False

for v in range(n):
    if not mark[v]:
        dfs(v)

print("\n")
print("Depth-first numbering:")
for v in vertices:
	print(v,)

print("\n")
for num in dfnum:
	print(num,)

