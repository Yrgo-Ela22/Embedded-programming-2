"""
" @brief Exercise 7 - Entering data from the terminal and using multiple modules.
"""
import sys
import utils

def main():
    """ 
    " @brief Calculates the volume of a cube with length n, where n is entered
    "        from the terminal when running the program.
    """
    if len(sys.argv) > 1:
        try:
            length = float(sys.argv[1])
            print("Cube side length: " + str(length))
            print("Cube volume: " + str(utils.cube(length)))
        except ValueError:
            raise ValueError("Invalid cube side length " + str(sys.argv[1]) + "!")
    else:
        raise ValueError("Cube side length missing!")
    return 

if __name__ == "__main__":
    main()