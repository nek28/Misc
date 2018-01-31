def continued(A):
    # prints continued fraction to console, usually called through produce_cont
    size = len(A)
    padding = 0
    #DASHES-------------------------
    dashes = 0
    for dig in A:
        dashes += len(str(dig))
    dashes += size*3 - 3
    #-------------------------------
    for dig in A:
        diglen = len(str(dig))

        # The 3 is because of the two empty places around +, the plus itself and the length of the number
        # that's the indentation factor after each iteration
        dashes -= diglen + 3

        #prints the empty spaces before the beginning of the n-th line
        for i in range(padding):
            print(' ', end='')

        print(str(dig),end='')
        
        #does this for every number except the last one
        #(places the "+" and the 1 at the appropriate place for the next row
        if dashes > 0:
            print(' + ',end='')

            padding += diglen + 3

            for i in range(dashes//2):
                print(' ', end='')
            print('1')

            for i in range(padding):
                print(' ', end='')
            for i in range(dashes):
                print('-', end='')
            print()

def produce_cont(a,b):
    # uses Euclid's algorithm to find out quotiens after successive division
    # and produces the continued fraction form.
    if a < b:
        print("Invalid Input")
    else:
        A = []

        while a % b != 0:
            A.append(a//b)
            r = a % b
            a_n = b
            b = r
            a = a_n

        A.append(a//b)
                
        continued(A)

