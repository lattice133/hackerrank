
def minion_game(string):
    # your code goes here
    length = len(string)


    # Calculate the score of player A
    playerA = {}
    for wordlength in range(length):
        for startpos in range(length-wordlength):
            if string[startpos] in "AEIOUaeiou":
                continue
            if string[startpos:(startpos + wordlength+1)] in playerA:
                playerA[string[startpos:(startpos + wordlength + 1)]] = playerA[string[startpos:(startpos + wordlength + 1)]] + 1
            else:
                playerA[string[startpos:(startpos + wordlength + 1)]] = 1

    playerAscore = sum(list(playerA.values()))


    # Calculate the score of player B
    playerB = {}
    for wordlength in range(length):
        for startpos in range(length-wordlength):
            if string[startpos] not in "AEIOUaeiou":
                continue
            if string[startpos:(startpos + wordlength+1)] in playerB:
                playerB[string[startpos:(startpos + wordlength + 1)]] = playerB[string[startpos:(startpos + wordlength + 1)]] + 1
            else:
                playerB[string[startpos:(startpos + wordlength + 1)]] = 1

    playerBscore = sum(list(playerB.values()))

    # Print
    if playerAscore > playerBscore:
        print("Stuart", playerAscore)
    elif playerAscore < playerBscore:
        print("Kevin",playerBscore)
    else:
        print("Draw")

if __name__ == '__main__':
    s = input()
    minion_game(s)