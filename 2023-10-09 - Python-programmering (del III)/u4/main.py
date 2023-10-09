""" 
" @brief Assignment 4 - Binary file I/O.
"""

def write_numbers(file_path, numbers):
    """ 
    " @brief Writes numbers in 16 bit binary form to file at specified path.
    "        Each number is written on a separate line, ordered in little endian.
    "
    " @param file_path Path to destination file.
    " @param numbers List holding the numbers to write.
    """
    with open(file_path, "wb") as file:
        for i in numbers:
            file.write(i.to_bytes(2, "little")) 
            file.write("\n".encode("utf-8"))    

def read_numbers(file_path):
    """ 
    " @brief Reads binary content from file at specified path
    "        and prints in the terminal.
    "
    " @param file_path Path to file to read from.
    """
    with open(file_path, "rb") as file:
        buffer = file.readlines()
        for line in buffer: 
            print(line)
            
def main():
    """ 
    " @brief Writes numbers 1 - 5 in binary form to "data.bin", ordered in little endian.
    """
    write_numbers("data.bin", [1, 2, 3, 4, 5]) 
    read_numbers("data.bin")                  

if __name__ == "__main__":
    main()