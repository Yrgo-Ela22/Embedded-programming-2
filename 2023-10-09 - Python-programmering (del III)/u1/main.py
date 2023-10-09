""" 
" @brief Assignment 1 - Retrieving the shortest and longest line from a file.
"""

def file_retrieve(file_path):
    """ 
    " @brief Retrieves all lines of test from file at specified path.
    "
    " @param file_path Path to file to read from.
    "
    " @return List with retrieved content, if any.
    """
    buffer = []
    with open(file_path, "r") as file:
        buffer = file.readlines()
    return buffer

def get_shortest_word(words):
    """
    " @brief Provides the shortest word in referenced list.
    "
    " @param words List containing words.
    "
    " @return The shortest word in the list.
    """
    if len(words) == 0:
        return ""
    shortest_word = words[0] 
    for i in words:
        if len(i) < len(shortest_word):
            shortest_word = i
    return shortest_word

def get_longest_word(words):
    """
    " @brief Provides the longest word in referenced list.
    "
    " @param words List containing words.
    "
    " @return The longest word in the list.
    """
    if len(words) == 0:
        return ""
    longest_word = words[0]
    for i in words:
        if len(i) > len(longest_word):
            longest_word = i 
    return longest_word

def main():
    """ 
    " @brief Retrieves words from file "data.txt" and prints the longest and shortest word.
    """
    words = file_retrieve("data.txt")
    print(get_shortest_word(words))
    print(get_longest_word(words))

if __name__ == "__main__":
    main()