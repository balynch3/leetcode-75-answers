// Can Place Flowers
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int flowerIndex = 0; flowerIndex < flowerbed.size(); flowerIndex++) {
            bool leftFree = (flowerIndex == 0) || flowerbed[flowerIndex-1] == 0;
            bool rightFree = (flowerIndex == flowerbed.size()-1) || flowerbed[flowerIndex+1] == 0;
            if (leftFree && rightFree && flowerbed[flowerIndex] == 0) {
                n--;
                flowerbed[flowerIndex] = 1;
            }
        }
        cout << n << endl;
        return n<=0;
    }
};