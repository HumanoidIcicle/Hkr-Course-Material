options = ("r", "p", "s")
running = True

while running:
    player = None
    computer = random.choice(options)

    while player not in options:
        player = input("Enter a choice (r, p, s): ")

    print(f"Player: {player}")
    print(f"Computer: {computer}")

    if player == computer:
        print("It's a tie!")
    elif player == "r" and computer == "s":
        print("You win!")
    elif player == "p" and computer == "r":
        print("You win!")
    elif player == "s" and computer == "p":
        print("You win!")
    else:
        print("You lose!")

    if not input("Play again? (y/n): ").lower() == "y":
        running = False

print("Thanks for playing!")
