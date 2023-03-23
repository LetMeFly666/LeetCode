from typing import overload     #line1
                                #line2
@overload                       #line3
def f(a: int) -> int:           #line4
    ...                         #line5
                                #line6
@overload                       #line7
def f(a: int, b: int) -> int:   #line8
    ...                         #line9
                                #line10
def f(a: int, *args) -> int:    #line11
    for i in args:              #line12
        a += i                  #line13
    return a                    #line14
                                #line15
print(f(1))
print(f(1, 2))