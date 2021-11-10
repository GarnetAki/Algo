#include <bits/stdc++.h>

using namespace std;
vector <vector <long long>> a;

void check_left(int j, long long key){
  if(a[a[j][1]][0]>key && a[j][1]!=0){
    cout << "NO";
    exit(0);
  }
  if(a[a[j][2]][0]>key && a[j][2]!=0){
    cout << "NO";
    exit(0);
  }
  if(a[a[j][1]][1] || a[a[j][1]][2])check_left(a[j][1], key);
  if(a[a[j][2]][1] || a[a[j][2]][2])check_left(a[j][2], key);
}

void check_right(int j, long long key){
  if(a[a[j][1]][0]<key && a[j][1]!=0){
    cout << "NO";
    exit(0);
  }
  if(a[a[j][2]][0]<key && a[j][2]!=0){
    cout << "NO";
    exit(0);
  }
  if(a[a[j][1]][1] || a[a[j][1]][2])check_right(a[j][1], key);
  if(a[a[j][2]][1] || a[a[j][2]][2])check_right(a[j][2], key);
}

int main()
{
  freopen("check.in", "r", stdin);
  freopen("check.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  a.resize(n+1, vector<long long>(3));

  if(n==0)cout<<"YES";
  if(n==1)cout<<"YES";
  else{
    for(int i=1; i<n+1; ++i){
      int help1, help2, help3;
      cin >> help1 >> help2 >> help3;
      a[i][0]=help1;
      a[i][1]=help2;
      a[i][2]=help3;
    }
    for(int i=1; i<n+1; ++i){
      if(a[a[i][1]][0]>a[i][0] && a[i][1]!=0 || a[a[i][2]][0]<a[i][0] && a[i][2]!=0){
        cout << "NO";
        exit(1);
      }
      if(a[a[i][1]][1]!=0 || a[a[i][1]][2]!=0)check_left(a[i][1], a[i][0]);
      if(a[a[i][2]][1]!=0 || a[a[i][2]][2]!=0)check_right(a[i][2], a[i][0]);
    }
    cout << "YES";
  }
  
  return 0;
}