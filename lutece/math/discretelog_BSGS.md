# 离散对数
$a\perp p$，求$x$满足$a^{x}\equiv b \pmod{p}$
将$x$分解，$$x=A*\lceil{\sqrt{p}}\rceil-B$$
得到$$a^{A*\lceil{\sqrt{p}}\rceil-B}\equiv b \pmod{p}$$
然后移项$$a^{A*\lceil{\sqrt{p}}\rceil}\equiv b*a^B \pmod{p}$$
其中$0\leq {A,B} \leq \lceil{\sqrt{p}}\rceil$
然后可以通过枚举$B$，得到$ b*a^B$，存入哈希表，然后枚举$A$查表，从而找到可以当作答案的$A,B$.
两个枚举过程都是$O({\sqrt{p}})$