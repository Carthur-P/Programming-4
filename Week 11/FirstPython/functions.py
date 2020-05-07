import random

def oddString(message):
    outputMessage = ""
    for i in range(len(message)):
        if((i % 2) != 0):
            outputMessage += message[i]
    return outputMessage

def getMaxMin():
    num = []
    for i in range(10):
        num.append(random.randrange(100))
    print(max(num))
    print(min(num))

print(oddString("Hello Carthur"))
getMaxMin()