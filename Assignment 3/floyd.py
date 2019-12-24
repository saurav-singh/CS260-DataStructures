#!usr/bin/env python
#
# Group project: Floyd's algorithm
# Date: 03/13/2019
#
# It should be noted that this implementation follows the one in the textbook

"""{Shortest Paths Program: shortest takes an nXn matric C of arc costs and produces nXn matrix A of lengths of shortst paths and an nXn matrix P giving a point in the "middle" of each shortest path}"""

def shortest(A,C,P):
    n = len(A)
    for i in range(n):
        for j in range(n):
            A[i][j] = C[i][j]
	    P[i][j] = 0
    for i in range(n):
    	A[i][i] = 0
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if (A[i][k] + A[k][j]) < A[i][j]:
                    A[i][j] = A[i][k] + A[k][j]
                    P[i][j] = k



#Procedure to print shortest path.
def path(i,j,P):
    k = P[i][j]
    if k == 0:
        return
    path(i,k,P)
    print(k)
    path(k,j,P)

#Problem 6 of review 2
test = float("inf")
n = 6
C = [[test for x in range(n)] for x in range(n)]

#It should be noted that compared to the review problem, the index for
#everything starts at 0

C[0][1] = 4
C[0][2] = 1
C[0][3] = 5
C[0][4] = 8
C[0][5] = 10
C[2][1] = 2
C[3][4] = 2
C[4][5] = 1

A = [[test for x in range(n)] for x in range(n)]
P = [[test for x in range(n)] for x in range(n)]

print("\n")
print("Initial Matrix C:")
for node in C:
    print(node)

shortest(A,C,P)

print("\n")
print("Matrix P:")
for node in P:
	print(node)

print("\n")
print("Matrix A:")
for node in A:
	print(node)

print("\n")
print("Resulting shortest Paths:")
print("0->1")
path(0,1,P)
print("\n")
print("0->2")
path(0,2,P)
print("\n")
print("0->3")
path(0,3,P)
print("\n")
print("0->4")
path(0,4,P)
print("\n")
print("0->5")
path(0,5,P)
