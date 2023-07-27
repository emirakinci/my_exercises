def calculations(file_name):
    galatasaray = []
    fener = []

    for element in file_name:
        element = element[:-1]
        elements = element.split(",")

        if elements[1] == "GS":
            galatasaray.append(elements[0])
            print("\n")
        else:
            fener.append(elements[0])

    with open("gs.txt", "r") as file1:
        for i in galatasaray:
            file1.writelines(i)
            file1.writelines("\n")
    with open("fb.txt", "r") as file2:
        for j in fener:
            file2.writelines(j)
            file2.writelines("\n")


def main():
    try:
        with open("players.txt", "r") as file:
            calculations(file)
            print("Processing")
    except FileNotFoundError:
        print("The file can not be found!!")


if __name__ == '__main_':
    main()
