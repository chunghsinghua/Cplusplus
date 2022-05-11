int idx = N - 1;
while (d[idx] == 0)
    idx--;
while (idx >= 0)
    cout << d[idx--];
