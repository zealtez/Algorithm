/*Pseudo*/

int n;
int cache[100],S[100];

int lis(int start){
  int &ret = cache[start];
  if(ret != -1) return ret;
  ret = 1;
  for(int next = start+1; next<n; ++next)
    if(S[start]<S[next])
      ret = max(ret,lis(next)+1);
  return ret;
}
///////////////////////////////////////O(N^2)

int dp[101], S[101];

for(int i = 1; i<N; i++){
  dp[i] = 1;
  for(int j = 0; j<i; j++){
    if(S[i]>S[j] && dp[i] < dp[j]+1)
      dp[i] = dp[j]+1;
  }
}


////////////////////////////////////////O(N^2)
