// https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

int maximumFrequency(vector<int> &arr, int n) {
    unordered_map<int, int> ump;
    
    int maxFre = 0;
    int maxres = arr[0];

    for(int i=0; i<n; i++) {
        ump[arr[i]]++;
        maxFre = max(maxFre, ump[arr[i]]);
    }

    for(int i=0; i<arr.size(); i++) {
        if(maxFre == ump[arr[i]]) {
            maxres = arr[i];
            break;
        }
    }
    return maxres;
}




