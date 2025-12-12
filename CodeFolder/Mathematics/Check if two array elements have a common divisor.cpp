void generate(){
    for(int i=2; i<200003; i++){
        if(next_prime[i] > 0)
            continue;

        for(int j=i; j<200003; j += i){
            if(next_prime[j] == 0)
                next_prime[j] = i;
        }
    }
}

bool check(vector<int> &v, map<int, int> &m){
    for(auto number : v){
        int num = number;

        while(num > 1){
            int x = next_prime[num];

            if(m[x] > 0)
                return true;

            m[x]++;

            while(num % x == 0)
                num /= x;
        }
    }

    return false;
}