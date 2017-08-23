forward = "Hello World!"
name = input("What is your name?")
print("Hi, " + name)
backward = ""
array_of_letters = []
backward_array = []
#print(forward[3])
for i in forward:
    array_of_letters.append(i)
#print(array_of_letters)
array_of_letters.__len__()

#print(array_of_letters[4])

for index, value in enumerate (array_of_letters):
    #print(str(index) + " " + str(value))
    # backward_array.append[array_of_letters[array_of_letters.__len__()-index]]
    #backward += array_of_letters[array_of_letters[value]]
    #print(index)
    #print(array_of_letters[array_of_letters.__len__() - index-1])
    backward += array_of_letters[array_of_letters.__len__() - index-1]
print(backward)
