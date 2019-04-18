import string
alphabet = string.ascii_lowercase


def print_rangoli(size):
    pattern = []
    for row in range(size):
        string_temp = "-".join(alphabet[row:size])
        string_temp = string_temp[:0:-1] + string_temp
        string_temp = string_temp.center(4*size-3,"-")
        pattern.append(string_temp)

    pattern = "\n".join(pattern[:0:-1]+pattern)
    print(pattern)
    # your code goes here


if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
