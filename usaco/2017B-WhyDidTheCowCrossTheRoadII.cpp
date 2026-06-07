#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);
    int ans=0;
    string inp; cin >> inp;
    for(int i=0;i<25;i++) {
        auto iti = find(all(inp), alph[i]), itir = find(iti+1, inp.end(), alph[i]);
        int disti = distance(inp.begin(), iti), distir = distance(inp.begin(), itir);
        //cout << disti << " " << distir << endl;
        for(int j=i+1;j<26;j++) {
            auto itj = find(all(inp), alph[j]), itjr = find(itj+1, inp.end(), alph[j]);
            int distj = distance(inp.begin(), itj), distjr = distance(inp.begin(), itjr);
            if(disti < distj && (distir > distj && distir < distjr)) {ans++;}
            else if(distj < disti && (distjr > disti && distjr < distir)) {ans++;}

        }
    }
    cout << ans;
}