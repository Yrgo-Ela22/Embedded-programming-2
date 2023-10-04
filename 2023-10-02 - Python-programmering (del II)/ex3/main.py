"""
" @brief Exercise 3 - Storing even numbers in a list.
"""

def is_even(num):
    """ 
    " @brief Indicates if specified number is even.
    "
    " @param num
    "        The number to check.
    " @return
    "        True if the number is even, else false.
    """
    if (num % 2) == 0:
        return True 
    else:
        return False
    
def number_exists(data, num):
    """ 
    " @brief Indicates if specified number exists in the referenced list.
    "
    " @param data
    "        List holding numbers.
    " @param num
    "        The searched number.
    " @return 
    "        True if the number exists in the list, else false.
    """
    for i in data:
        if i == num:
            return True 
    return False
    
def get_even_numbers(min = 0, max = 10):
    """ 
    " @brief Provides a list containing all even numbers of
    "        numbers x + y in the range [min, max].
    "
    " @param min
    "        The minimum value to calculate with.
    " @param max
             The max value to calculate with.
    " @return 
    "        List containing even numbers.
    """
    data = []
    for x in range(min, max + 1):
        for y in range(min, max + 1):
            if is_even(x + y) and not number_exists(data, x + y):
                data.append(x + y)
    return data
    
def main():
    """ 
    " @brief Retrieves a list containing even numbers and prints in the terminal.
    """    
    data = get_even_numbers()
    for i in data:
        print(i)
    return 

if __name__ == "__main__":
    main()