int firstUniqChar(char* s) {
    int l = strlen(s);
    int a[26] = {0}; 
    int i=0;
    for (i=0;i<l;i++) 
    {
        a[s[i] - 'a']++;
    }
    for (i=0;i<l;i++)
    {
        if (a[s[i]-'a']==1) {
            return i; 
        }
    }
    return -1;
}
