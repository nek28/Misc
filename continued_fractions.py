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

        dashes -= diglen + 3

        for i in range(padding):
            print(' ', end='')

        print(str(dig),end='')
        
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

