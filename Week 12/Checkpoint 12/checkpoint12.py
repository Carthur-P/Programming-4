def removeVowel(input):
    vowels = ["a", "i", "e", "o", "u"]
    noVowels = "".join([ i for i in input if i not in vowels])
    return noVowels

print removeVowel("Hello world")


#Question 2
vowels = ["a", "i", "e", "o", "u"]
weekDays = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]
noVowels = (["".join([i for i in d if i not in vowels]) for d in weekDays])

print noVowels


#Question 3
numList = [11, -17, 42, 8, -12, 9]
numChanges = [(x*2) if x>0 else (x*(x>=0)) for x in numList]
print(numChanges)

#Question 4
import random

class flashCards:
    def __init__(self, inputList):
        self.wordList = inputList

    def __iter__(self):
        return self

    def __next__(self):
        currentWord = self.wordList(random.randint(1,6))
        return currentWord

germanWords = flashCards(["die Kuh", "der Hund", "die Katze", "das Pferd", "die Ente"])
#for i in range(12):
    #print(next(germanWords))


#Question 5
def listReverser(inputList):
    for i in reversed(inputList):
        yield i


reverseAnimals = listReverser(["antelope", "burro", "cheetah", "donkey", "elephant"])
for a in reverseAnimals:
    print(a)

#line breaks
print ""
print ""
#Question 6
animals = ["antelope", "burro", "cheetah", "donkey", "elephant"]
reverseAnimals = [w for w in reversed(animals) if len(w)>=7]
for a in reverseAnimals:
    print(a)


#line breaks
print ""
print ""
#Question 7
reverseMonths = listReverser(["January", "February", "March", "April", "May", "June"])
for a in reverseMonths:
    print(a)

reversed = [w for w in reversed(reverseMonths) if len(w)>=7]
print reversed
#this does not work because it is an instance of the genorator rather than a sequence.
#If you created a variable like in wuestion 6 it would work fine
