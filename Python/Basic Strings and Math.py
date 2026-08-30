# int = string to integer
# float = convert string to number with decimal
# len gives number of characters in or allowed

#methods:
# vn.find() gives index of character in the variable
# 'blah' *in* vn checks if blah is in the variable, returns True or False
# vn.replace("to be replaced" , ''replaced with")

#maths
#div with ans whole no: 10 // 3 gives 3
#round() rounds up the ans
#abs() returns positive value even when ans is neg

        

#trn6
#a program that asks the user for a number and
#then prints out a list of all the divisors of that number
'''
a = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
b = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
print(list(set(a).intersection(set(b))))

x = 0
og_list= []
number = int(input("Give me a number and I tell you it's divisors! "))

while number > x:
    x += 1
    og_list.append(x)

divisor_list = []
for divisor in og_list:
    if number % divisor == 0:
        divisor_list.append(divisor)
        print(f'The divisors of {number} are: {divisor_list}')

    elif divisor_list == [1, number]:
        print('This is a prime!')'''

#trn7
'''user = str(input('Give me a word: '))

if user[::-1] == user:
    print('This is a palindrome.')
else:
    print('This no palindrome bruv.')'''



#trn1
'''phrase = 'Your name is blah blah.'
            0123...
print(phrase[3]) == gives "r", each ´number has a index
print (phrase[0:3]) == gives "You" but not index for 3(i.e. r)
print(phrase[-1]) == gives first index from end, here is "h".

phrase1_0 = phrase[:] ==> clones the 1st variable *phrase*. '''


#trn2
'''a = int(input('enter a number: '))
b = int(input('another number: '))
c = a-b

if c < 0:
    print('a is less than b')

else:
    print('a is greater than b')'''


#trn3
'''weight = float(input('your weight lbs: '))
in_kgs = weight / 2.15

print('Sup sucker. I know u weigh ' + str(in_kgs) + ' kgs. Do better. Eat more.!!')'''


#trn4: when u turn 100yr
'''name = str(input('Your name: '))
age = int(input('Your age: '))
turn = int(2024 + (100-age))

print("Hello, {},  u be 100 in {}".format(name, turn))'''

#trn5: even or odd
    #alt1
'''num1 = int(input("a number: "))
num2 = int(input("number too: "))

if num1 % num2 == 0:
    print('Tis but even number')
else:
    print('Odds be in your favour')

user_num = int(input("Enter a number: "))'''

    #alt2
'''def oddoreven(number):
    if number % 2 == 0 and number % 4 != 0:
        print(f"The number {number} is even.")
    elif number % 2 == 0 and number % 4 == 0:
        print(f"The number {number} is even and is divisible by 4.")
    else:
        print(f"The number {number} is odd.")

oddoreven(user_num)'''



