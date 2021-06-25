try:
    from collections import Counter
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int,input().split()))
        p = arr.copy()
        value_count = Counter(p)
        value_count = value_count.most_common()
        # print(value_count)
        value_count = sorted(value_count,  key = lambda x:(x[0]))
        find_last = 0
        for i in value_count:
            if i[1] > 1:
                find_last = i[0]
                break
        if(find_last == 0):
            p.sort()
            first = p[0]
            last = p[1]
            temp = [p[0]]
            for i in range(2 , n-1):
                temp.append(p[i])
            temp.append(last)
        else:
            arr.remove(find_last)
            arr.remove(find_last)
            if(len(arr) > 0):
                arr.sort()
                t1 = []
                t2 = []
                for i in arr:
                    if(i >= find_last):
                        t1.append(i)
                    else:
                        t2.append(i)
                temp = [find_last] + t1 + t2 + [find_last]
            else:
                temp = [find_last]  + [find_last]
            
        print(*temp)
        # print()
except EOFError:
    print(" ")