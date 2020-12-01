# -*- coding: utf-8 -*-
"""1463.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1cVpNbX-sxexcGAOfOzSaP-Orj3LY-B4A
"""

def main() :
  N = int(input())
  
  dp = [0]*1000001
  dp[0] = 0
  dp[1] = 0
  dp[2] = 1
  dp[3] = 1

  for i in range(4, N+1) :
    if i%2 == 0 and i%3 == 0 :
      m = min(dp[int(i/2)], dp[int(i/3)])
      m = min(m, dp[i-1])
      dp[i] = 1+m
      continue
    elif i%2 == 0 :
      m = min(dp[int(i/2)], dp[i-1])
      dp[i] = 1+m
      continue
    elif i%3 == 0 :
      m = min(dp[int(i/3)], dp[i-1])
      dp[i] = 1+m
      continue
    else :
      m = dp[i-1]
      dp[i] = 1+m
    
  print(dp[N])
  return

main()
