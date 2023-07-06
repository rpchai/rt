#include <cmath>
#include <iostream>

using namespace std;
long long int power(long long int a, long long int b,long long int P)
{
	if (b == 1)
		return a;
	else
		return (((long long int)pow(a, b)) % P);
}
int main()
{
	long long int P, G, x, a, y, b, ka, kb;
    cout << "Enter the prime value: ";
    cin>>P;
    cout << "Enter the primitive root for P: ";
    cin>>G;
    cout << "Enter the private key for a: ";
    cin>>a;
	x = power(G, a, P); 
    cout << "Enter the private key of b: ";
    cin>>b;

	y = power(G, b, P); 
	ka = power(y, a, P); 
	kb = power(x, b, P);
	cout <<"\n"<<"The value of P : " << P << endl;
	cout <<"\n"<< "The value of G : " << G << endl;
	cout <<"\n"<< "The private key a for Alice : " << a << endl;
	cout <<"\n"<< "The private key b for Bob : " << b << endl;
	cout <<"\n"<< "The public key of a: " << x << endl;
	cout <<"\n"<< "The public key of b: " << y << endl;
	cout <<"\n"<< "Secret key for the Alice is : " << ka << endl;
	cout <<"\n"<< "Secret key for the Bob is : " << kb << endl;
	return 0;
}
