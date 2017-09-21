def decodeMorse(morseCode):
    res = []
    temp = morseCode.strip().split(' ')
    for i in range(len(temp)):
        if temp[i] == '':
            if i + 1 < len(temp) and temp[i+1] == '':
                res.append(' ')
        else:
            res.append(MORSE_CODE[temp[i]])
    return ''.join(res)

# a cleverer solution:
# 
# def decodeMorse(morseCode):
#     return ' '.join(''.join(MORSE_CODE[letter] for letter in word.split(' ')) for word in morseCode.strip().split('   '))