#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin>>t;
    // t = 1;
    while(t--){
        int n1,m1,n2,m2;
        cin>>n1>>m1>>n2>>m2;
        int a[n1][m1],b[n2][m2],c[n1][m2];
        if(m1!=n2){
            break;
        }

        for(int i=0;i<n1;i++){
            for(int j =0;j<m1;j++){
                cin>>a[i][j];
            }
        }

       for(int i=0;i<n2;i++){
          for(int j =0;j<m2;j++){
                cin>>b[i][j];
            }
        }
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                c[i][j] = 0;
                for(int k=0;k<n2;k++){
                       c[i][j] += a[i][k] * b[k][j];  
                }
            }
        }
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
