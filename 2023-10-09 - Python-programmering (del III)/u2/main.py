""" 
" @brief Assignment 2 - Retrieving strings consisting of the first letters of all words in a list.
"""

def acronym(words):
    """ 
    " @brief Provides the acronym consisting of the first letter of all words in specified list.
    "
    " @param words List holding words.
    "
    " @return The acronym in uppercase.
    """
    str = ""
    for i in words:
        if len(i) > 0:
            str += i[0].upper() 
    return str    

def main():
    """ 
    " @brief Prints the acronyms from words ["As", "soon", "as", "possible"] and ["Work", "from" "home"].
    """
    print(acronym(["As", "soon", "as", "possible"])) 
    print(acronym(["Work", "from", "home"]))
    return 

if __name__ == "__main__":
    main()