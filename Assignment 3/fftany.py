from math import pi
from math import fabs
from cmath import exp

#Helper Functions
def check_prime(n):
    if (n == 1):
        return False
    elif (n == 2):
        return True
    else:
        for x in range(2, n):
            if(n % x == 0):
                return False
        return True

def compleX(n):
    cn = exp((2*pi/n) * complex(0, 1))
    if (n == 4):
        cn = complex(0, 1)
    if (n == 2):
        cn = complex(-1, 0)
    return cn

def factor(n):
    for i in range(int(round(n/2)),0,-1):
        if n % i == 0:
            return (i, n/i)

#FFT Dyadic - referenced from book
def FFT_any(n, x):

    FFT = []

    n = int(round(n))

    for i in range(n):
        FFT.append(complex(0,0))

    if (check_prime(n)):
        for i in range(n):
            v = complex(0,0)

            for k in range(0,n):
                z = compleX(n) * x[k]
                z = pow(z,i*k)
                z = complex(z)
                v = v + complex(v.real, v.imag*-1)
            FFT[i] = v
        return FFT
    
    else:
        (f1,f2) = factor(n)
        A = []

        for i in range(f1):
            A.append([])
        
        for i in range(f1):
            N = []
            for k in range(int(round(f2))):
                N.append(x[i+k*f1])
            A[i] = FFT_any(f2,N)
        
        for i in range(n):
            v = complex(0,0)
            for k in range(f1):
                a = A[k][int(round(i%f2))] * pow(compleX(n),i*k)
                b = complex(a,i*k)
                v = v + complex(b.real, b.imag * -1)
            FFT[i] = v
        return FFT

#Main function


def main():

    Test = []
    for i in range(8):
        Test.append(complex((i+1), 0))

    result = FFT_any(8, Test)

    print("\nAny FFT: (referenced from book)")
    print("--------------------")
    print("Test List:")

    for i in Test:
        print(str(i))

    print("\nResult:")
    for i in result:
        print(str(i))


main()
