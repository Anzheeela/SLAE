std::vector<double> linspace(double start, double end, int num) {
    std::vector<double> result;
    double step = (end - start) / (num - 1);
    
    for (int i = 0; i < num; ++i) {
        result.push_back(start + i * step);
    }
    
    return result;
}