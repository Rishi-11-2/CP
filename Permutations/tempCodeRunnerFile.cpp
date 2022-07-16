void permute(vector<int> &a, int idx)
// {
//     if (idx == a.size())
//     {
//         ans.push_back(a);
//         return;
//     }
//     for (int i = idx; i < a.size(); i++)
//     {
//         swap(a[i], a[idx]);
//         permute(a, idx + 1);
//         swap(a[i], a[idx]);
//     }
//     return;
// }