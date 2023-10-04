"""
" @brief Exercise 6 - Using a set to easily check if two strings are equal.
"""

def main():
    """ 
    " @brief Asks the user to enter to sentences. The sentences are stored
    "        with lowercase letters in a set. Since the set doesn't accept
    "        duplicate, only one element will be stored if the sentences
    "        are equal. A message regarding if the sentences are equal 
    "        is printed in the terminal.
    """
    s1 = input("Enter a first sentence: ")
    s2 = input("Enter a second sentence: ")
    set = { s1.lower(), s2.lower() } 
    if len(set) == 1:
        print("The sentences are identical!")
    else:
        print("The sentences are not equal!")
    return 

if __name__ == "__main__":
    main()