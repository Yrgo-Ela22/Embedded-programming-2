"""
" @brief Exercise 5 - User input and calculating the number of letters in a string.
"""

def num_letters(s):
    """ 
    " @brief Provides the number letters in specified string.
    "
    " @param s
    "        The string to check.
    " @return 
    "        The number of letters in the string.
    """
    num = 0
    for i in s:
        if i.isalpha():
            num += 1
    return num

def main():
    """ 
    " @brief Reads a line from the terminal and prints the number of entered letters.
    """
    s = input("Enter a sentence: ")
    print("Your sentence contains " + str(num_letters(s)) + " letters!")
    return 

if __name__ == "__main__":
    main()