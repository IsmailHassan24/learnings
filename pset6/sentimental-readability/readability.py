import cs50


def main():
    text = cs50.get_string("Text: ")

    L = 100 * (letters(text) / words(text))
    S = 100 * (sentences(text) / words(text))
    index = round(0.0588 * (L) - 0.296 * (S) - 15.8)

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade ", index)


def letters(text):
    count = 0
    for i in range(len(text)):
        if text[i].isalpha():
            count += 1
    return count


def words(text):
    count = 0
    for i in range(len(text)):
        if text[i].isspace():
            count += 1
    return count + 1


def sentences(text):
    count = 0
    for i in range(len(text)):
        if text[i] in ['?', '.', '!']:
            count += 1
    return count


if __name__ == "__main__":
    main()
