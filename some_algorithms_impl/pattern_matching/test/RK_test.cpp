#include<iostream>
#include<string>
#include"../RK_impl"
using namespace std;
int main(void)
{
    string P, T;
    P = "yqddcqvllzuifvgkqkca";
    T = "bnlhntyqddcqvllzuifvgkqkcabjgolkjyuyxmwedcvnxexvtksqeeqbrkrmukpaahphxvwpgxugpkikfnmezlcoaiwlydgrfctnrmnktqmkdvnjtcfsqfphqxpxenxykjymvvxkmnphijoylgvjmssigcjizexgcupsdmdgbvxkzygvylzqcijugoapjsunglbswcrobtkmjatfgcgtixldwrsbzxvomweljhkoanhomlfqhsonouyxporjqqnndpkpzxdjxeqgngujmblkbkurccmupotdhyoyfcwdifptzgyvwucypkffjtxwlmomtppscwlkqzmhldlvbaomdolfjdczinrjbajdxldwwsteeurxbrbmpgqqgldwnneesztynzpyvuilxyakj";
    cout << LONG_LONG_MAX;
    RK(P,T,1000000000,5);
    // cout << P.compare(0,P.size(),T,6,P.size());
    return 0;
}