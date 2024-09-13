import random

def guess_the_number():
    """A simple number guessing game."""

    secret_number = random.randint(1, 100)
    attempts = 0

    print("I'm thinking of a number between 1 and 100. Can you guess it?")

    while True:
        try:
            guess = int(input("Your guess: "))
        except ValueError:
            print("Please enter a valid number.")
            continue

        attempts += 1

        if guess < secret_number:
            print("Too low! Try again.")
        elif guess > secret_number:
            print("Too high! Try again.")
        else:
            print(f"Congratulations! You guessed the number in {attempts} attempts!")
            break

if __name__ == "__main__":
    guess_the_number()