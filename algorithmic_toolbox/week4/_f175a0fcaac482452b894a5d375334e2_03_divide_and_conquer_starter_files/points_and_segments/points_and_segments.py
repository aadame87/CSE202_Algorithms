#!/usr/bin/env python2

from collections import defaultdict
import sys

#def fast_count_segments(starts, ends, points):
#    cnt = [0] * len(points)
    #write your code here
#    return cnt

def fast_count_segments(S, P):

    D = defaultdict(list)
    for i, p in enumerate(P):
        D[p].append(i)

    L = [(p, 'p') for p in P]
    res = [0 for _ in range(len(P))]

    for a, b in S:
        L.append((a, 'l'))
        L.append((b, 'r'))

    L.sort(cmp=compare_func)

    stack = []
    for point, label in L:
        if label == 'l':
            stack.append(point)
        elif label == 'r':
            stack.pop()
        else:
            indices = D[point]
            for i in indices:
                res[i] = len(stack)
    return res

def compare_func(x, y):
    a, b = x[0], y[0]
    if a == b:
        a, b = x[1], y[1]
    return cmp(a, b)

#def naive_count_segments(starts, ends, points):
#    cnt = [0] * len(points)
#    for i in range(len(points)):
#        for j in range(len(starts)):
#            if starts[j] <= points[i] <= ends[j]:
#                cnt[i] += 1
#    return cnt

#if __name__ == '__main__':
#    input = sys.stdin.read()
#    data = list(map(int, input.split()))
#    n = data[0]
#    m = data[1]
#    starts = data[2:2 * n + 2:2]
#    ends   = data[3:2 * n + 2:2]
#    points = data[2 * n + 2:]
#    #use fast_count_segments
#    cnt = naive_count_segments(starts, ends, points)
#    for x in cnt:
#        print(x, end=' ')
if __name__ == '__main__':
    s, p = [int(_) for _ in sys.stdin.readline().split()]
    S = [(int(a), int(b)) for a, b in [sys.stdin.readline().split() for _ in range(s)]]
    P = [int(_) for _ in sys.stdin.readline().split()]

    for i in fast_count_segments(S, P):
        print i,
