"""
" @brief Exercise 2 - Addition and raising exceptions.
"""

def sumto(n):
    """ 
    " @brief Calculates the sum of all numbers from 1 - n.
    "        
    " @param n
    "        The number to calculate up to.
    " @return 
    "        The sum of numbers 1 + 2 ... + n.
    """
    if n < 0:
        raise ValueError("Cannot calculate up to a negative number!")
    sum = 0
    for i in range(1, n + 1):
        sum += i
    return sum

def main():
    """ 
    @ brief Calculates the sum of numbers 1 - n for different combinations.
    """
    print(sumto(2))
    print(sumto(6))
    return 

if __name__ == "__main__":
    main()