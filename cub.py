import cmath
import math
import sys

def get_float(msg, allow_zero):
    cof = None
    while cof is None:
        try:
            cof  = float(input(msg))
            if not allow_zero and abs(cof) < sys.float_info.epsilon:
                print("zero is not allowed")
                cof = None
        except ValueError as err:
            print(err)
    return cof

print("{0}x\N{SUPERSCRIPT THREE} + {1}x\N{SUPERSCRIPT TWO} + {2}x + {3} = 0".\
        format(chr(int("03B1", 16)), chr(int("03B2", 16)),\
        chr(int("03B3", 16)), chr(int("03B4", 16))))
al = get_float("enter {0}: ".format(chr(int("03B1", 16))), False)
bt = get_float("enter {0}: ".format(chr(int("03B2", 16))), True)
gm = get_float("enter {0}: ".format(chr(int("03B3", 16))), True)
dt = get_float("enter {0}: ".format(chr(int("03B4", 16))), True)

a = bt/al
b = gm/al
c = dt/al
y0 =  a/3

p = -(a**2/3)+b
q = 2*(a**3/27)-a*b/3+c

Q = (p/3)**3 + (q/2)**2
z1 = -q/2 + cmath.sqrt(Q)
z2 = -q/2 - cmath.sqrt(Q)
X = []
for k in range(3):
    r1, phi1 = cmath.polar(z1)
    root_r1, root_phi1 = r1**(1/3), (phi1+2*math.pi*k)/3
    r2, phi2 = cmath.polar(z2)
    root_r2, root_phi2 = r2**(1/3), (phi2+2*math.pi*k)/3
    u = cmath.rect(root_r1, root_phi1)
    v = cmath.rect(root_r2, root_phi2)
    y = u+v
    x = y-y0
    X.append(complex(round(x.real, 2), round(x.imag, 2)))
X = list(set(X))


def f(cof):
    if cof>0:
        return " + " + str(cof)
    elif cof<0:
        return " - " + str(abs(cof))
    return ""
bt = f(bt)
if bt != "":
    bt += "x\N{SUPERSCRIPT TWO}"
gm = f(gm)
if gm != "":
    gm += "x"
dt = f(dt)
x1 = X[0]
equation = ("{0}x\N{SUPERSCRIPT THREE}{1}{2}{3} = 0"
            " \N{RIGHTWARDS ARROW} x = {4}").format(al, bt, gm, dt, x1)
for i in range(1, len(X)):
    equation += " or x = {0}".format(X[i])
print()
print(equation)
print()
print(input("Press Enter to exit"))

