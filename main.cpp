#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.

long arrayManipulationslow(int n, vector<vector<int>> queries)
{
    vector<long> vect(n);
    int num_rows = queries.size();
    for(int i=0; i<num_rows; ++i)
    {
        for(int j=queries[i][0]-1; j<=queries[i][1]-1; ++j)
        {
            vect[j] += queries[i][2];
        }
    }
    long max_num = 0;
    for(int i=0; i<n; ++i)
    {
        max_num = max(max_num, vect[i]);
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    return max_num;
}
long arrayManipulation(int n, vector<vector<int>> queries)
{
    vector<long> vect(n+1);
    int num_rows = queries.size();
    for(int i=0; i<num_rows; ++i)
    {
        vect[(queries[i][0]) - 1] += queries[i][2];
        vect[(queries[i][1])]     += -queries[i][2];
    }
    long max_num = 0;
    cout<<vect[0]<<" ";
    for(int i=1; i<n; ++i)
    {
        vect[i] += vect[i-1];
        max_num = max(max_num, vect[i]);
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    return max_num;

}

int main()
{
    /*
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    */
    srand(time(0));  // Initialize random number generator.
    int n = 25;
    int q = 10;
    while(true)
    //for(int x =0; x<10; ++x)
    {

        vector<vector<int>> queries(q);

        int r = 0;
        int c = 0;
        int k = 0;
        for (int i=0; i<q; ++i)
        {
            while (r==0 || r==n)
            {
                r = (rand()%n + 1); //1-->n
            }
            cout<<"r = "<<r<<", ";
            while (c<=r)
            {
                c = (rand()%n + 1); //1-->n
            }
            cout<<"c = "<<c<<endl;
            k = rand();
            queries[i].resize(q);
            queries[i][0]=r;
            queries[i][1]=c;
            queries[i][2]=k;
            r=0;
            c=0;
        }


        //vector<vector<int>> queries{{1, 5, 3}, {4, 8, 7}, {6, 9, 1}};
        //cout<<queries.size();
        int res1 = arrayManipulationslow(n, queries);
        cout<<res1<<endl;
        int res2 = arrayManipulation(n, queries);
        cout<<res2<<endl;
        cout<<"=============================================="<<endl;
        if (res1!=res2)
            break;
    }


    //cout << result << "\n";


    //fout.close();

    return 0;
}

/*
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
*/
