"""
" @brief Demonstration of input and output in Python.
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

def get_integer(space = "\n"):
    """
    " @brief Reads an integer from the terminal.
    "  
    " @param space
    "        Space to print after the integer is read
    "        (default = a new line).
    " @return
    "        An integer entered from the terminal.
    """
    while True:
        s = read_line(space)
        try: 
            return int(s) 
        except ValueError: 
            print("Invalid input, try again!\n")
            
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
            
def print_credentials(name, age, height): 
    """
    " @brief Prints the specified credentials in the terminal.
    " 
    " @param name
    "        The name to print.
    " @param age
    "        The age to print.
    " @param height
    "        The height to print.
    """
    print("--------------------------------------------------------------------------------")
    print("Name: " + str(name))
    print("Age: " + str(age))
    print("Height: " + str(height))
    print("--------------------------------------------------------------------------------\n")

def main():
    """
    " @brief Reads the name, age and height of the user and prints in the terminal.
    """
    print("Enter your name:")
    name = read_line()
    print("Enter your age:")
    age = get_integer()
    print("Enter your height:")
    height = get_float()
    print_credentials(name, age, height)

""" 
" @brief If this is the startup script, main is called to start the program.
"""
if __name__ == "__main__":
    main()