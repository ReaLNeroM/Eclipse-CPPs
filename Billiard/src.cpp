#include <bits/stdc++.h>

typedef long long ll;

<<<<<<< HEAD
=======
ll y, x, posy, posx, vx, vy;
>>>>>>> 290768e0263d5026839c9405fc99c0085a7040b2
ll l_a = 1, l_b = 0, d_a = 0, d_b = 1;
ll gcd = -1;

void extended(ll a, ll b){
	if(b == 0){
		gcd = a;
<<<<<<< HEAD
		//std::cout << l_a << ' ' << l_b << ' ' << a << std::endl;
=======
>>>>>>> 290768e0263d5026839c9405fc99c0085a7040b2
		return;
	}

	ll nl_a, nl_b, nd_a, nd_b;

	nl_a = d_a;
	nl_b = d_b;

	nd_a = l_a - a/b * d_a;
	nd_b = l_b - a/b * d_b;

	l_a = nl_a;
	l_b = nl_b;
	d_a = nd_a;
	d_b = nd_b;

	extended(b, a % b);
}

<<<<<<< HEAD
int main(){
	std::ios::sync_with_stdio(false);

	ll y, x, posy, posx, vx, vy;
	std::cin >> x >> y >> posx >> posy >> vx >> vy;

	if(vy == 0 and vx == 0){
		std::cout << -1 << '\n';
		return 0;
	}
	if(vx == 0){
=======
std::vector<ll> solve(ll a1, ll m1, ll a2, ll m2){
	extended(y, x);

	if(a2 % gcd == a1 % gcd){
		ll lcm = y / gcd * x;

		ll start = (l_a * a2) % m2 * m1;
		start   += (l_b * a1) % m1 * m2;
		return {(start + y * x) % (y * x) / gcd, lcm};
	} else {
		return {-1, 0};
	}
}

void solve_for_0(){
	if(vy == 0 and vx == 0){
		std::cout << -1 << '\n';
	} else if(vx == 0){
>>>>>>> 290768e0263d5026839c9405fc99c0085a7040b2
		if(posx == x or posx == 0){
			if(vy == 1){
				std::cout << posx << ' ' << y << '\n';
			} else if(vy == -1){
				std::cout << posx << ' ' << 0 << '\n';
			}
<<<<<<< HEAD
			return 0;
		} else {
			std::cout << -1 << '\n';
			return 0;
		}
	}
	if(vy == 0){
=======
		} else {
			std::cout << -1 << '\n';
		}
	} else if(vy == 0){
>>>>>>> 290768e0263d5026839c9405fc99c0085a7040b2
		if(posy == y or posy == 0){
			if(vx == 1){
				std::cout << x << ' ' << posy << '\n';
			} else if(vx == -1){
				std::cout << 0 << ' ' << posy << '\n';
			}
<<<<<<< HEAD
			return 0;
		} else {
			std::cout << -1 << '\n';
			return 0;
		}
	}
	ll resy = -1, resx = -1;

	ll alpha1;
	if(vy == 1){
		alpha1 = y - posy;
	} else if(vy == -1){
		alpha1 = posy;
	}

	ll alpha2;
	if(vx == 1){
		alpha2 = x - posx;
	} else if(vx == -1){
		alpha2 = posx;
=======
		} else {
			std::cout << -1 << '\n';
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> x >> y >> posx >> posy >> vx >> vy;

	if(vy == 0 or vx == 0){
		solve_for_0();
		return 0;
	}

	ll alpha1 = posy;
	ll alpha2 = posx;

	if(vy == 1){
		alpha1 = y - posy;
	}
	if(vx == 1){
		alpha2 = x - posx;
>>>>>>> 290768e0263d5026839c9405fc99c0085a7040b2
	}

	ll beta1 = y;
	ll beta2 = x;

<<<<<<< HEAD
	extended(y, x);

	if(std::abs(alpha1 - alpha2) % gcd == 0){
		l_a *= (alpha1 - alpha2) / gcd;
		l_b *= (alpha1 - alpha2) / gcd;

		ll time = alpha1 - beta1 * l_a;
		if(time < 0){
			time += y * x;
		}

		std::vector<ll> updated = {posy + time * vy, posx + time * vx};
=======
	ll resy = -1, resx = -1;
	std::vector<ll> bounce_time = solve(alpha1, beta1, alpha2, beta2);

	if(bounce_time[0] != -1){
		ll converted = (bounce_time[0] % bounce_time[1] + bounce_time[1]) % bounce_time[1];
		std::vector<ll> updated = {posy + converted * vy, posx + converted * vx};
>>>>>>> 290768e0263d5026839c9405fc99c0085a7040b2

		if((updated[0] / y) % 2 == 0){
			resy = 0;
		} else {
			resy = y;
		}
		if((updated[1] / x) % 2 == 0){
			resx = 0;
		} else {
			resx = x;
		}
	}

	if(resy == -1){
		std::cout << -1 << '\n';
	} else {
		std::cout << resx << ' ' << resy << '\n';
	}
<<<<<<< HEAD
}
=======
}
>>>>>>> 290768e0263d5026839c9405fc99c0085a7040b2
