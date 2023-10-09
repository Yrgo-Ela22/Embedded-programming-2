""" 
" @brief Assignment 3 - Provides and prints content of lists with unique numbers from two lists.
"""

def notsame(list1, list2):
    """ 
    " @brief Provides a list holding all unique elements stored in specified lists.
    "
    " @param list1 The first list.
    " @param list2 The second list.
    "
    " @return A list containing the all unique elements in the two lists.
    """
    unique_list = []
    for i in list1:
        if i not in list2:
            unique_list.append(i)
    for i in list2:
        if i not in list1:
            unique_list.append(i)
    return unique_list

def main():
    """ 
    " @brief Retrieves lists holding unique numbers from two list 
    "        pairs and prints in the terminal.
    """
    print(notsame([1, 2, 3], [2, 3, 4])) 
    print(notsame([1, 2, 3], [4, 5, 6]))

if __name__ == "__main__":
    main()