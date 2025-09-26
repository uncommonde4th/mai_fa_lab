#include <math.h>
#include "prime.h"

int is_prime(int n){
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n % 2 == 0) return 0;

        int k = (int) sqrt((double) n);
        for (int i = 3; i <= k; i += 2){
                if (n % i == 0){
                        return 0;
                }
        }
        return 1;
}

int find_prime(int n, int *res){
        if (n <= 0){
                return 1;
        }
        
        int count = 0;
        int prime = 1;

        while(count < n){
                prime++;
                if (is_prime(prime) == 1){
                        count++;
                }
        }
        *res = prime;

        return 0;
}
