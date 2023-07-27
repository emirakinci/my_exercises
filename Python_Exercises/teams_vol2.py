def calculations_part(filename):
    galatasaray = []
    fenerbahce = []
    trabzon = []

    for element in filename:
        element = element[:-1]
        new_ = element.split(",")
        if new_[1] == "Galatasaray":
            galatasaray.append(new_[0])
        elif new_[1] == "Fenerbahce":
            fenerbahce.append(new_[0])
        else:
            trabzon.append(new_[0])
    with open("galatasaray.txt", "w") as file1:
        for i in galatasaray:
            file1.writelines(i)
            file1.writelines("\n")
    with open("fenerbahce.txt", "w") as file1:
        for i in fenerbahce:
            file1.writelines(i)
            file1.writelines("\n")
    with open("all.txt", "w") as file1:
        for i in trabzon:
            file1.writelines(i)
            file1.writelines("\n")
        for j in galatasaray:
            file1.writelines(j)
            file1.writelines("\n")
        for k in fenerbahce:
            file1.writelines(k)
            file1.writelines("\n")


def main():
    try:
        with open("exercise.txt", "r", encoding="utf-8") as file:
            calculations_part(file)
    except OSError:
        print("OUCH!!")


if __name__ == '__main__':
    main()
