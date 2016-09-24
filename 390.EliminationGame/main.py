class Solution(object):
    def remove_left(self, m):
        t = 0
        for i, v in enumerate(m):
            if v is True and t%2 == 0:
                m[i] = False
            if v is True:
                t += 1

    def remove_right(self, m, n):
        t = 0
        for i in xrange(n-1, -1, -1):
            v = m[i]
            if v is True and t%2 == 0:
                m[i] = False
            if v is True:
                t += 1
    
    def true_count(self, m):
        t = 0
        for v in m:
            if v is True:
                t += 1
        return t 

    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        m = [True] * n
        i = 0
        while self.true_count(m) != 1:
            if i%2 == 0:
                self.remove_left(m)
            else:
                self.remove_right(m, n)
            i += 1

        for i, v in enumerate(m):
            if v:
                return i+1
        
def remove_left(l):
    llen = len(l)
    if llen == 2:
        return [l[1]]
    return [l[i] for i in xrange(1, llen, 2)]

def remove_right(l):
    llen = len(l)
    if llen == 2:
        return [l[0]]
    r = [l[i] for i in xrange(llen-2, -1, -2)]
    r.reverse()
    return r


def main():
    l = range(31)
    del l[0]
    print l
    l = remove_left(l)
    print l
    l = remove_right(l)
    print l
    l = remove_left(l)
    print l
    l = remove_right(l)
    print l

def main1():
    l = range(32)
    del l[0]
    print l
    print(Solution().lastRemaining(31))

if __name__ == '__main__':
    main1()
