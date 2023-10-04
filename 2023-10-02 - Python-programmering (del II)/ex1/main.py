"""
" @brief Exercise 1 - File I/O and reversing lists.
"""

def file_retrieve(file_path):
    """
    " @brief Retrieves content of specified file.
    "
    " @param file_path
    "        Path to the file to read from.
    " @return
    "        List with content retrieved from the file.
    """
    buffer = []
    with open(file_path, "r") as file:
        return file.readlines()
    return buffer

def file_write(file_path, data):
    """
    " @brief Writes content stored in referenced list to file.
    "
    " @param file_path
    "        Path to the destination file.
    " @param data
    "        List containing the data to write.
    """
    with open(file_path, "w") as file:
        for i in data:
            file.write(str(i))
    
def main():
    """
    " @brief Retrieves content from "input.txt" and writes the
    "        content in reversed order to "output.txt".
    """
    data = file_retrieve("input.txt")
    file_write("output.txt", reversed(data))
    return 

if __name__ == "__main__":
    main()