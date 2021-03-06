﻿#include "pch.h"

/*
풀이 :
	양의 정수 n에 대해 d(n) = n + (n의 각 자리수)
	가령 d(75) = 75 + 7 + 5 = 87
	33으로 시작한다면 다음 수는 33+3+3=39,
	다음 수는 39+3+9=51,
	다음 수는 51+5+1=57이다.
	이를 이용하여 {33, 39, 51, 57, ...} 의 수열을 만들 수 있다.

	n은 d(n)의 생성자이다. 33은 39의 생성자이다.
	101은 91(91+9+1=101)과 100(100+1+0+0)으로 2개의 생성자가 있다.
	이때 셀프 넘버란 '생성자가 없는 수'를 의미한다.
	100보다 작은 셀프 넘버는 1, 3, 5, 7, 9, 20, 31, ... 로 총 13개가 있다.
	10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하시오.

	생성자가 없다 = d(n)의 규칙으로 생성되지 않는 수
	(N은 10,000)
	1부터 N까지 d(n)의 규칙을 적용했을 때 등장한 수는
	boolean 배열에서 true로 체크해준다. => O(N)
	단, 가장 큰 수는 9999+9+9+9+9=10035이니 boolean은 check[10036]
	이후 1부터 N까지 boolean 배열을 돌며
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std;

int makeNum(int n) {
	int sum = n;
	int tmp = n;
	while (tmp >= 1) {
		sum += tmp % 10;
		tmp = floor(tmp / 10);
	}
	return sum;
}

int main()
{
	bool check[10036] = { false, };
	int N = 10000;
	for (int i = 1; i <= N; i++) {
		check[makeNum(i)] = true;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == false)
			cout << i << endl;
	}
	return 0;
}
