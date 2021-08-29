# include <vector>

int score(const std::vector<int> & dice){
    int rec[7] = {0, 0, 0, 0, 0, 0, 0};
    for (int i : dice)
        if (i > 0 && i < 7)
            ++rec[i];
    return 1000 * (rec[1] / 3) + 100 * (rec[1] % 3) + \
            600 * (rec[6] / 3) + \
            500 * (rec[5] / 3) + 50 * (rec[5] % 3) + \
            400 * (rec[4] / 3) + \
            300 * (rec[3] / 3) + \
            200 * (rec[2] / 3);
}