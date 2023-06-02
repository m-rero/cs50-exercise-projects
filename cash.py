
from cs50 import get_float

moedas = 0

while True:
    troco = get_float("Troco devido em moedas: ")
    if troco > 0:
        break
    else:
        continue

while troco > 0.95:

    moedas += 1
    troco -= 1

while (0.95 > troco and troco > 0.45):

    moedas += 1
    troco -= 0.50

while (troco  <= 0.45 and troco > 0.24):

    moedas += 1
    troco -= 0.25

while (troco <= 0.24 and troco > 0.09):

    moedas += 1
    troco -= 0.10

while (troco <= 0.09 and troco >= 0.05):

    moedas += 1
    troco -= 0.5


print (f"{moedas}")