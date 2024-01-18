// Container with Most Water
class Solution {
public:
    int getArea(int height1, int height2, int length) {
        if (height1 > height2) {
            return height2*length;
        }
        return height1*length;
    }

    int maxArea(vector<int>& height) {
        int startIndex = 0;
        int endIndex = height.size()-1;
        int largestArea = INT_MIN;
        while (startIndex <= endIndex) {
            int currentArea = getArea(height[startIndex], height[endIndex], endIndex-startIndex);
            if (largestArea < currentArea) {
                largestArea = currentArea;
            }
            if (height[startIndex] < height[endIndex]) {
                startIndex++;
            } else {
                endIndex--;
            }
        }
        return largestArea;
    }
};