import random

num = random.randint(1,10)
count = 0

while True:
    user = int(input("Guess the secret number 1-10: "))
    count += 1
    if user == num:
        print("Correct.")
        print(f"Took {count} guesses.")
        cont = input("New game? y or n: ")
        if cont != 'y':
            print(f"Ended. {count} guesses.")
            break

    elif user != num:
        user = int(input("Wrong answer. Guess again: "))
        count += 1

        cont = input('Want to continue? y or n: ')

        if cont == 'n':
            print(f'You used {count} guess(es)')
            print('Program terminated.')
            break

        elif cont != 'y' and cont != 'n':
            print('Invalid syntax. Program terminated.')
            break
