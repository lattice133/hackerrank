import textwrap


def wrap(string, max_width):
    index = 0
    length = (len(string)//max_width)
    letter =[]
    if length == 0:
        return string
    for i in range(length):
        letter.append(string[(i*max_width):((i+1)*max_width)])
    if( (i+1)*max_width < len(string)):
        letter.append(string[((i+1)*max_width):])

    return '\n'.join(letter)


if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)