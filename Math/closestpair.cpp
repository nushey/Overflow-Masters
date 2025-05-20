vec<pair<long double, long double>>
closestPair(vector<pair<long double, long double>> coord,
            int n)
{
    sort(ALL(coord));
    set<pair<long double, long double>> s;
    long double squaredDistance = LLONG_MAX;
    vec<pair<long double, long double>> ans;
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        long double D = ceil(sqrt(squaredDistance));
        while (coord[i].first - coord[j].first >= D)
        {
            s.erase({coord[j].second, coord[j].first});
            j += 1;
        }

        auto start = s.lower_bound({coord[i].second - D,
                                    coord[i].first});
        auto end = s.upper_bound({coord[i].second + D,
                                  coord[i].first});

        for (auto it = start; it != end; ++it)
        {
            long double dx = coord[i].first - it->second;
            long double dy = coord[i].second - it->first;
            long double preDist = min(squaredDistance, dx * dx + dy * dy);
            if (preDist < squaredDistance)
            {
                pair<long double, long double> one = {it->second, it->first};
                pair<long double, long double> two = {coord[i].first, coord[i].second};
                ans = {one, two};
                squaredDistance = preDist;
            }
        }

        // Insert the point as {y-coordinate, x-coordinate}
        s.insert({coord[i].second, coord[i].first});
    }
    return ans;
}