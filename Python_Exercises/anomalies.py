def algorithm_part(file_name):
    customer_info = []
    reliables = []
    unreliables = []
    for element in file_name:
        element = element[:-1]
        elements = element.split(",")
        customer_info.append(elements)

    for i in customer_info:
        if i[5] == '1' or i[5] == '':
            reliables.append(i)
        else:
            unreliables.append(i)
    minimum_reliable = float(reliables[0][3])
    total_r = 0
    for something in reliables:
        total_r += float(something[2])

    av_r = total_r / len(reliables)

    total_u = 0
    for anything in unreliables:
        total_u += float(anything[2])
    av_u = total_u / len(unreliables)

    print("The Reliable customers have an average of {} years higher than Unreliable ones".format(abs(av_r - av_u)))

    j = 1
    while j < len(reliables):
        if float(reliables[j][3]) < minimum_reliable:
            minimum_reliable = float(reliables[j][3])
        j += 1
    print(f"Minimum EnrollmentTime of the reliable customers: {minimum_reliable}")

    a = 0
    for x in reliables:
        if x[4] == "o":
            a += 1
    print(f"%{(a * 100) // len(reliables)} of the Reliable customers own the house where they live")

    for m in unreliables:
        if int(m[2]) > av_r and float(m[3]) > float(minimum_reliable) and m[4] == "o":
            with open("anomalies.txt", "w") as file2:
                file2.writelines(m)


def main():
    try:
        with open("customers.txt", "r") as file:
            algorithm_part(file)
    except OSError:
        print("Ouch! Error occurred")


if __name__ == "__main__":
    main()
