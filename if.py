#if
# a=33;
# b=200
# if b>a:
#     print("b is greater than a")
# else:
#     print("a is greater than b")

#elif
a=33;
b=200
if b>a:
    print("b is greater than a")
elif a==b:
    print("a and b are equal")
else:
    print("a is greater than b")

#one line if/else
a=20
b=200
if a>b:print("a is greater than b")
print("A")if a>b else print("B")
print("A")if a>b else print ("=") if a==b else print("B")

#while loop
# i=1
# while i<6:
#     print(i)
#     i+=1

#break statement
i=0
while i<6:
    i+=1
    if i==3:
        break
    print(i)