# Define the function to perform all
# the operations
def scrambleWord(string: str) -> str:
    # Empty strings to perform 
    # operations on the word
    first = str()
    second = str()
    # Loop over each character in the string
    for c in string:
        # See if the ASCII of the character
        # is an even integer
        if ord(c) % 2:
            # Append to {first} string
            first += c
        else:
            # Append to {second} string
            second += c

    # Concatenate the two strings
    final = first + second
    # If newly formed string is the same
    # as the original...
    if final == string:
        # Change their direction
        final = second + first
    
    # Return the final output
    return final


# Input the word from the user
string = input("\nType a word:> ").lower()

# Call the function
final = scrambleWord(string)

# Print the original and the scrambled word
print(f"\nThe original word is = \t** {string} **")
print(f"The scrambled word is = ** {final} **\n")
