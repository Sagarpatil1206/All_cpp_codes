def fact(n):
    if n<=1: 
        return n
    else:
        return(fact(n-1)*fact(n-2))