n=int(input())
dp=[0,2,4,6]
if n<=3:
    print((1<<n)-dp[n])
else:
    for i in range(n-3):
        dp[1]=dp[2]*2+dp[1]
        dp[1],dp[2]=dp[2],dp[1]
        dp[2],dp[3]=dp[3],dp[2]
    print((1<<n)-dp[3])
