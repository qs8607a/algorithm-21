
ostream& output(vector<int> &out)
{
        ostream_iterator<int> os(cout, " ");
        cout << "after sort" << endl;
        for(vector<int>::const_iterator iter = out.begin(); iter != out.end(); iter++)
                        *os = *iter;
        cout << endl;
return cout;
}
