from array import array

alphabets = array("I", [0] * 26) # create an array of unsigned int of size 26 (number of alphabets in English)

string = "This is the sample       string that we shall process.............".lower() # convert to lower case

for each_char in string:
    if each_char.isalpha(): # only process if the character is an alphabet
        alphabets[ord(each_char)-97] += 1 # using the ord(), we can get the ASCII value of the character. 
                                          # And as we made sure that it would be an alphabet and also in lower case, 
                                          # its value must be 97 or greater. Substracting 97 from that wil give us 
                                          # the index for that particular alphabet.


occurrences = max(alphabets) # find the maximum value from 26 elements (constant)
which_alpha = chr(alphabets.index(occurrences) + 97) # get that character by adding 97 to the index of the maximum 
                                                     # from the array

print(f"{which_alpha} occurred {occurrences} times in the given string") # print the result
