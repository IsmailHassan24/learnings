import cs50

while True:
    height = cs50.get_int("Height: ")
    if 1 <= height <= 8:
        break

for i in range(1, height+1):
    for k in range(height-i):
        print(" ", end="")
    for j in range(i):
        print("#", end="")

    print("  ", end="")

    for m in range(i):
        print("#", end="")
    print()
