

def main():

    s = input("Texto: ");
    letters = 0;
    words = 0;
    setences = 0;

    for i in range(len(s)):
        
        if s[i].isalpha() != 0:
           letters += 1

        if s[i] == ' ':
           words += 1

        if s[i] == '.' or s[i] == '!' or s[i] == '?':
            setences += 1

#printf("%i\n", words);
#printf("%i\n", letters);
#printf("%i\n", setences);

    L = letters/(words / 100)
    S =  setences/(words / 100)

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index > 16:
        print("Grade: 16+\n")

    elif index < 1:
        print("Before Grade 1\n")


    else:
        print("Grade: " + str(index))
        
if __name__ == "__main__":
    main()
