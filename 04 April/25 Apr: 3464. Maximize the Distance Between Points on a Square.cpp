using namespace std;

class Solution {
public:
    int maxDistance(int sideLength, vector<vector<int>>& points, int requiredPoints) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long perimeter = 4LL * sideLength;
        int numPoints = points.size();
        vector<long long> mappedPositions;
        mappedPositions.reserve(numPoints);

        for (auto& point : points) {
            mappedPositions.push_back(mapToPerimeter(sideLength, point[0], point[1]));
        }

        sort(mappedPositions.begin(), mappedPositions.end());

        long long low = 0, high = perimeter;
        while (low < high) {
            long long mid = (low + high + 1) / 2;
            if (isValidDistance(mid, requiredPoints, mappedPositions, perimeter)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return static_cast<int>(low);
    }

private:
    long long mapToPerimeter(int sideLength, int x, int y) {
        if (y == sideLength) return x;
        if (x == sideLength) return sideLength + (sideLength - y);
        if (y == 0) return 2LL * sideLength + (sideLength - x);
        return 3LL * sideLength + y;
    }

    bool isValidDistance(long long minDistance, int requiredPoints, vector<long long>& mappedPositions, long long perimeter) {
        int numPoints = mappedPositions.size();
        vector<long long> extendedPositions(2 * numPoints);

        for (int i = 0; i < numPoints; ++i) {
            extendedPositions[i] = mappedPositions[i];
            extendedPositions[i + numPoints] = mappedPositions[i] + perimeter;
        }

        for (int i = 0; i < numPoints; ++i) {
            if (canSelectRequiredPoints(i, minDistance, requiredPoints, mappedPositions, extendedPositions, perimeter)) {
                return true;
            }
        }
        return false;
    }

    bool canSelectRequiredPoints(int startIndex, long long minDistance, int requiredPoints, vector<long long>& mappedPositions, vector<long long>& extendedPositions, long long perimeter) {
        int selectedCount = 1;
        long long previousPosition = mappedPositions[startIndex];
        int currentIndex = startIndex;
        bool isValid = true;

        for (int i = 1; i < requiredPoints; ++i) {
            long long targetPosition = previousPosition + minDistance;
            int left = currentIndex + 1;
            int right = startIndex + mappedPositions.size();
            auto it = lower_bound(extendedPositions.begin() + left, extendedPositions.begin() + right, targetPosition);

            if (it == extendedPositions.begin() + right) {
                isValid = false;
                break;
            }
            selectedCount++;
            previousPosition = *it;
            currentIndex = it - extendedPositions.begin();
        }

        return isValid && selectedCount == requiredPoints && (previousPosition - mappedPositions[startIndex] <= perimeter - minDistance);
    }
};
