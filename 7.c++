#include<iostream>
#include<math.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
bool isPrime(int number) {
    if (number <= 1)
        return false;
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0)
            return false;
    }

    return true;
}
int main() {
    double p, q;
    double n, phi; 
    double e;
    double track;
    double message, encrypted, decrypted;
    do {
        cout << "Enter a prime number (p): ";
        cin >> p;
    } while (!isPrime(p));

    do {
        cout << "Enter another prime number (q): ";
        cin >> q;
    } while (!isPrime(q));
    n = p * q;
    phi = (p - 1) * (q - 1);
    do {
        cout << "Enter a public key (e) such that 1 < e < " << phi << " and gcd(e, " << phi << ") = 1: ";
        cin >> e;
    } while (e <= 1 || e >= phi || gcd(e, phi) != 1);
   double d1=1/e;
   double d=fmod(d1,phi);
   cout << "Enter a message to encrypt: ";
   cin >> message;
   double c = pow(message,e);
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);
   cout<<"Original Message is  = "<<message;
   cout<<"\n"<<"prime number1 p= "<<p;
   cout<<"\n"<<"prime number2 q= "<<q;
   cout<<"\n"<<"n = pq = "<<n;
   cout<<"\n"<<"phi = "<<phi;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<d;
   cout<<"\n"<<"Encrypted message = "<<c;
   cout<<"\n"<<"Decrypted message = "<<m;
   return 0;
}
