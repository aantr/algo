# python 3.10

def find_ban_words(text: str):
    ans = []
    for i in ['чай', 'чая', 'чаю', 'чайный', 'чайного', 'чайному', 'чайным', 'чайным']:
        if i in text:
            ans.append('чай')
            break
    for i in ['горячий и вкусный кофе', 'горячий кофе', 'горячего кофе']:
        if i in text:
            ans.append('горячий кофе')
            break
    return ', '.join(sorted(ans))


if __name__ == "__main__":
    input_str = input()
    # Необходимо преобразовать список в строку перед выводом.
    print(find_ban_words(input_str))
