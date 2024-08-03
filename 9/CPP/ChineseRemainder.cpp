#include <gmp.h>
#include <vector>
#include <iostream>
using namespace std;

// TO compile: g++ ChineseRemainder.cpp -lgmp
// Probably easier to write the C code lmao

int main() {
    vector<int> num = {3, 4, 5}; // Example moduli
    vector<int> rem = {2, 3, 1}; // Example remainders

    mpz_t result, prod, temp, inv, rem_temp, num_temp;
    mpz_inits(result, prod, temp, inv, rem_temp, num_temp, NULL);

    mpz_set_ui(prod, 1);
    for (int i = 0; i < num.size(); i++) {
        mpz_mul_ui(prod, prod, num[i]);
    }

    for (int i = 0; i < num.size(); i++) {
        mpz_set_ui(num_temp, num[i]);
        mpz_set_ui(rem_temp, rem[i]);

        mpz_divexact(temp, prod, num_temp);
        mpz_invert(inv, temp, num_temp);
        mpz_mul(temp, temp, inv);
        mpz_mul(temp, temp, rem_temp);
        mpz_add(result, result, temp);
    }

    mpz_mod(result, result, prod);

    cout << "The minimum x is " << mpz_get_ui(result) << endl;

    mpz_clears(result, prod, temp, inv, rem_temp, num_temp, NULL);
    return 0;
}