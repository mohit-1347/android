#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define q INT_MAX
#define d 256 // A prime number for hashing
#define MAX 20 // Maximum length of strings

// Function to search for pattern in text using Rabin-Karp algorithm
vector<int> search(char text[], char pattern[])
{
    vector<int> res; // Vector to store the indices where pattern is found

    int m = strlen(pattern); // Length of pattern
    int n = strlen(text);    // Length of text

    int p=0, t=0, h=1; // Initialize hash values

    // Calculate value of h for hashing = pow(d, m-1)%q
    for(int i=0; i<m-1; i++)
    {
        h = (h * d) % q;
    }

    // Calculate the hashing value for pattern, and for the first window in text
    for(int i=0; i<m; i++)
    {
        p = (d * p + pattern[i]) % q; // Hash value of pattern
        t = (d * t + text[i]) % q;    // Hash value of first window in text
    }

    // Slide the window size pattern over the text string
    for(int i=0; i<=n-m; i++)
    {
        // Check if hash for text window equals hash for pattern
        if(p == t)
        {
            // Check for every character to confirm match
            int j;
            for(j=0; j<m; j++)
            {
                if(text[i+j] != pattern[j]) break;
            }
            // If all characters match, pattern found at current index
            if(j == m)
            {
                cout<<"\nPattern found at index: "<<i;
                res.push_back(i);
            }
        }

        // Calculate hash value for next window in text
        if(i < n-m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if(t < 0)
            {
                t += q;
            }
        }
    }

    return res;
}

int main()
{
    char text[MAX], pattern[MAX];

    cout<<"\nEnter the strings: text, pattern"<<endl;

    cin>>text;
    cin>>pattern;

    vector<int> res = search(text, pattern);

    return 0;
}

