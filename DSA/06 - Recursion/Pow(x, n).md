(https://www.geeksforgeeks.org/problems/powx-n/1)[Link]

```
class Solution {
public:
    double power(double b, int e) {
        if(e == 0) return 1;
        
        if(e < 0) return power(1 / b, -e);

        if(e % 2 == 0) return power(b * b, e / 2);

        else return b * power(b, e - 1);
    }
};
```
