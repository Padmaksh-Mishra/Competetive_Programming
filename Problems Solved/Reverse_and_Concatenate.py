TC = int(input())
while(TC>0):
    TC-=1
    n,k = map(int,input().split(" "))
    s = str(input())
    # s1 = s*(k-1)
    if(k>0):
        if((s) != (s[::-1])):
            print(2)
        else:
            print(1)
    else:
        print(1)
