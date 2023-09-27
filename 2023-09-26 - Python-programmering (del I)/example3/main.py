"""
" @brief Demonstration of file I/O in Python.
"""

def file_write(file_path, data):
    """ 
    " @brief Writes content in referenced list to file at specified path.
    "     Potential previous content is overwritten.
    " 
    " @param file_path
    "        The path to the file.
    " @param data
    "        List containing the data to write.
    """
    with open(file_path, "w") as file:
        file.write("--------------------------------------------------------------------------------\n")
        for i in data:
            file.write(str(i) + "\n")
        file.write("--------------------------------------------------------------------------------\n\n")
    return

def file_append(file_path, data):
    """ 
    " @brief Append content in referenced list to file at specified path.
    "        Potential previous content is retrieved.
    " 
    " @param file_path
    "        The path to the file.
    " @param data
    "        List containing the data to write.
    """
    with open(file_path, "a") as file:
        file.write("--------------------------------------------------------------------------------\n")
        for i in data:
            file.write(str(i) + "\n")
        file.write("--------------------------------------------------------------------------------\n\n")
    return

def file_read(file_path):
    """ 
    " @brief Reads content stored in file at specified path.
    " 
    " @param file_path
    "        The path to the file.
    """
    with open(file_path, "r") as file:
        buffer = file.readlines()
        for i in buffer:
            print(i, end="")

def file_retrieve(file_path):
    """ 
    " @brief Retrieves content stored in file at specified path and stores
    "        each line as text in a list.
    " 
    " @param file_path
    "        The path to the file.
    " @return
    "        A list storing every line retrieved from file.
    """
    data = []
    with open(file_path, "r") as file:
        data = file.readlines()
    return data
        
def main():
    """
    " @brief Writes numbers stored in a list to file "data.txt".
    "        The file is then read and the content is printed
    "        in the terminal.
    """
    data = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    file_append("data.txt", data)
    data = file_read("data.txt")
    return

""" 
" @brief If this is the startup script, main is called to start the program.
"""
if __name__ == "__main__":
    main()