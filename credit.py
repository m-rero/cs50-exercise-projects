import sys


def main():
    cardNum = input("Number: ")

    cardLen = len(str(cardNum))

    evenSum = 0
    oddSum = 0
    ttlSum = 0
    mulSum = 0

    if cardLen != 13 and cardLen != 15 and cardLen != 16:
        print("INVALID")
        sys.exit()

    for i in range(-2, (-cardLen-1), -2):

        tempMul = int(cardNum[i]) * 2

        if tempMul >= 10:
            evenSum = evenSum + tempMul - 9
        else:
            evenSum = evenSum + tempMul

    for i in range(-1, (-cardLen-1), -2):
        tempOdd = int(cardNum[i])
        oddSum = oddSum + tempOdd

    ttlSum = evenSum + oddSum

    if ttlSum % 2 == 0:
        if int(cardNum[0]) == 3 and int(cardNum[1]) == 4 or int(cardNum[1]) == 7:
            print("AMEX")

        elif int(cardNum[0]) == 5 and int(cardNum[1]) == 1 or int(cardNum[1]) == 2 or int(cardNum[1]) == 3 or int(cardNum[1]) == 4 or int(cardNum[1]) == 5:
            print("MASTERCARD")

        elif int(cardNum[0]) == 4:
            print("VISA")

        else:
            print("INVALID")


if __name__ == "__main__":
    main()