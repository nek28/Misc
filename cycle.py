class Perm:

    def __init__(self, *inp):
        self.range = []

        max_elem = max(inp)
        self.size = max_elem
        current_elem = inp[0]

        for i in range(max_elem):
            self.range.append(i+1)

        for i in range(1,len(inp)):
            self.range[current_elem-1] = inp[i]
            current_elem = inp[i]

        self.range[current_elem-1] = inp[0]

    def __repr__(self):
        rpr = ""
        for i in range(len(self)):
            rpr += "%d ---- %d\n" % (i+1, self.range[i])

        return rpr[:-1]

    def __len__(self):
        return self.size

    def extend(self, to_size):
        if len(self) < to_size:
            extension = list(range(len(self)+1, to_size+1))
            self.range.extend(extension)
            self.size = to_size

    def __mul__(self, other):
        c = Perm(1)
        common_length = max(len(self),len(other))
        
        self.extend(common_length)
        other.extend(common_length)
        c.extend(common_length)
        
        for i in range(len(c)):
            c.range[i] = other.range[self.range[i]-1]
        return c

    def cycle(self):
        cyc = ""
        def one_cyc(index):
            cyc_term = "Perm(" + str(index + 1)
            next_term = self.range[index]
            
            while next_term != (index + 1):
                cyc_term += ',' + str(next_term)
                next_term = self.range[next_term-1]

            return cyc_term + ')'

        cycles = 0
        for i in range(len(self)):
            if (i+1) != self.range[i] and not str(i+1) in cyc:
                if cycles == 0:
                    cyc += one_cyc(i)
                else:
                    cyc += "*" + one_cyc(i)
                cycles += 1

        return cyc
