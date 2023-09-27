"""
" @brief Demonstration of using lists in Python.
"""

def read_line(space = "\n"):
    """
    " @brief Reads a line of text from terminal.
    " 
    " @param space
    "        Space to print after the input is read
    "        (default = a new line).
    " @return
    "        A string with the entered text.
    """
    s = input()
    print(space, end="")
    return s
            
def get_float(space = "\n"):
    """
    " @brief Reads a floating point number from the terminal.
    " 
    " @param space
    "        Space to print after the number is read
    "        (default = a new line).
    " @return
    "        A floating-point number entered from the terminal.
    """
    s = read_line(space)
    s = s.replace(',', '.')
    while True:
        try:
            return float(s)
        except ValueError:
            print("Invalid input, try again!\n")
            
def get_sum(data):
    """ 
    " @brief Provides the sum of the numbers stored in referenced list.
    " 
    " @param data
    "        List containing numbers.
    " @return 
    "        The sum of the numbers.
    """
    sum = 0 
    for i in data:
        sum += i
    return sum

def get_average(data):
    """ 
    " @brief Provides the average of the numbers stored in referenced list.
    " 
    " @param data
    "        List containing numbers.
    " @return 
    "        The average of the numbers or 0 if the list is empty.
    """
    if (len(data) > 0):
        return get_sum(data) / len(data)
    else:
        return 0
    
def print_list(data):
    """
    " @brief Prints numbers stored in referenced list, along with the sum and 
    "        average of the stored numbers.
    "
    " @param data
    "        List storing the numbers to print.
    """
    print("--------------------------------------------------------------------------------")
    print("Numbers:\t", end="")
    for i in data:
        print(f"{i:.1f}", end=" ")      
    print("\nSum:\t\t" + str(f"{get_sum(data):.1f}"))
    print("Average:\t" + str(f"{get_average(data):.1f}"))
    print("--------------------------------------------------------------------------------\n")

def main():
    """
    " @brief Reads five floating-point numbers from the terminal and
    "        stores in a list. The numbers are printed along with the
    "        sum and average.
    """
    data = [] 
    for i in range(5):
        print("Enter a floating-point number:")
        data.append(get_float()) 
    print_list(data)
    return 

""" 
" @brief If this is the startup script, main is called to start the program.
"""
if __name__ == "__main__":
    main()