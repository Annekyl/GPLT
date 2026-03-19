a=int(input())
s=1
cnt=1
while(s%a!=0):
    s=s*10+1 
    cnt+=1

print(s//a,cnt)