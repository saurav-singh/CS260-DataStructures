from math import pi
from math import fabs
from cmath import exp

#FFT Dyadic - referenced from book
def FFT_dyadic(n, x):

    FFT = []
    u = []
    v = []

    I = complex(0, 1)

    for i in range(n):
        FFT.append(complex(0, 0))

    if (n == 1):
        FFT[0] = x[0]
    else:
        even_arr = []
        odd_arr = []

        for i in range(0, n-1, 2):
            even_arr.append(x[i])
            odd_arr.append(x[i+1])

        u = FFT_dyadic((int)(n/2), even_arr)
        v = FFT_dyadic((int)(n/2), odd_arr)

        for i in range(n):
            u_index = round((i % (n/2)))
            v_index = round((i % (n/2)))
            FFT[i] = u[u_index] + exp((I * 2 * pi * i) / n) * v[v_index]

    return FFT

#Main function
def main():
    
    Test = []
    for i in range(8):
        Test.append(complex((i+1),0))

    result = FFT_dyadic(8,Test)

    print ("\nDyadic FFT: (referenced from book)")
    print ("--------------------")
    print ("Test List:")

    for i in Test:
        print (str(i))
    
    print ("\nResult:")
    for i in result:
        print (str(i))

main()