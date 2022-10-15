x=23
print(x)
print(type(x))
print('Hello world')
print(16/4,16//4,16%4)
format(2.29)


#named indexes:
txt1 = "My name is {fname}, I'm {age}".format(fname = "John", age = 36)
#numbered indexes:
txt2 = "My name is {0}, I'm {1}".format("John",36)

print(txt1)
print(txt2)
list=[0,1,2,3,4,5,6]
list1=[45,26,78,25,36]
print(list1[1:3])
tup=(25,56,21,47,78,89,96,63,32)
print(tup[1:3])