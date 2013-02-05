istream&  input(istream &in, vector<int> &get)
{
        istream_iterator<int> begin(in);
        istream_iterator<int> end;
        ostream_iterator<int> out(cout, " ");
        get.clear();
        get.assign(begin, end);
        cout << "check the input " << endl;
        for(vector<int>::iterator index = get.begin(); index != get.end(); index++)
                                *out = *index;
        cout << endl;
        cout << "size of the vector" << endl;
        cout << get.size();
        cout << endl;
return in;
}
