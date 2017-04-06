#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 200000;
int app[maxn];
int app100000[151] = {0,
		62544,
		126749,
		191451,
		256368,
		321531,
		386841,
		452316,
		517825,
		583454,
		649195,
		714974,
		780781,
		846680,
		912596,
		978630,
		1044693,
		1110749,
		1176884,
		1243008,
		1309180,
		1375396,
		1441650,
		1507912,
		1574219,
		1640555,
		1706896,
		1773268,
		1839687,
		1906061,
		1972527,
		2038980,
		2105409,
		2171869,
		2238405,
		2304959,
		2371549,
		2438041,
		2504646,
		2571199,
		2637885,
		2704416,
		2771071,
		2837785,
		2904460,
		2971037,
		3037753,
		3104410,
		3171113,
		3237800,
		3304500,
		3371248,
		3438045,
		3504766,
		3571559,
		3638347,
		3705128,
		3772001,
		3838823,
		3905624,
		3972433,
		4039252,
		4106119,
		4172941,
		4239889,
		4306780,
		4373624,
		4440525,
		4507396,
		4574260,
		4641146,
		4708058,
		4775003,
		4841911,
		4908882,
		4975830,
		5042784,
		5109712,
		5176717,
		5243681,
		5310657,
		5377670,
		5444657,
		5511654,
		5578670,
		5645708,
		5712656,
		5779656,
		5846670,
		5913752,
		5980761,
		6047821,
		6114898,
		6181956,
		6249047,
		6316162,
		6383161,
		6450270,
		6517360,
		6584483,
		6651654,
		6718700,
		6785866,
		6852959,
		6920028,
		6987121,
		7054232,
		7121341,
		7188480,
		7255595,
		7322764,
		7389875,
		7457031,
		7524167,
		7591341,
		7658521,
		7725692,
		7792821,
		7860026,
		7927217,
		7994370,
		8061616,
		8128820,
		8195991,
		8263142,
		8330354,
		8397593,
		8464758,
		8531915,
		8599123,
		8666389,
		8733694,
		8800911,
		8868159,
		8935372,
		9002698,
		9069967,
		9137148,
		9204352,
		9271602,
		9338966,
		9406260,
		9473582,
		9540821,
		9608016,
		9675285,
		9742564,
		9809895,
		9877126,
		9944420,
		10011748};

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for(ll i = 1; i <= 100000; i++){
		for(ll j = i; j >= 1 and (i * i - j * j) <= 100000; j--){
			app[i * i - j * j]++;
		}
	}

	ll a, b;
	cin >> a >> b;

	ll res = 0;
	app[0] = 0;
	res = app100000[b / 100000];
	for(ll i = 0; i <= 100000; i++){
		if(app[i] >= 2){
			app[i] = app[i - 1] + 1;
			app[i - 1] = 0;
		} else {
			app[i] = app[i - 1];
			app[i - 1] = 0;
		}
		if(i == a - 1){
			res -= app[i];
		}
	}

	ll ga = b - b % 100000;

	ll j = 1;
	for(ll i = 1; i <= 7500000; i++){
		while(i * i - j * j > b){
			j++;
		}

		for(ll x = j; x <= i; x++){
			if(0 <= i * i - x * x - ga and i * i - x * x - ga <= b){
				app[i * i - x * x - ga]++;
			}
		}
	}
	for(ll i = 1; ga + i <= b; i++){
		if(app[i] >= 2){
			res++;
		}
	}

	cout << res;
}

