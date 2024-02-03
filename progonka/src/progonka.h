#pragma once
#include<iostream>
#include<vector>

// template<typename A>
// struct ArgumentGetter;

// template<typename R, typename Arg>
// struct ArgumentGetter<R(Arg)> {
//     using Argument = Arg;
// };

// template<typename T>
// using Dif = decltype(std::declval<T>() - std::declval<T>());

// template<typename RealType> 
// decltype(auto) integrate(   
//     const typename & diag_1, 
//     const typename ArgumentGetter<vector>::Argument& diag_2,  
//     const typename ArgumentGetter<vector>::Argument& diag_3
//                         ) {
//                             Dif<RealType> polusum = (end + start) / 2;
//                             Dif<RealType> poluraz = (end - start) / 2;
//                             RealType gauss_sum = 0.;

//                             for (auto i = 0; i < N; i++) {
//                                 gauss_sum += poluraz * func(polusum + poluraz * node.p[i]) * node.w[i];
//                             }

//                             return gauss_sum;
//                         };

template<typename xType>
class three_matrix {
    private:
    std::vector<xType> diag_1;
    std::vector<xType> diag_2;
    std::vector<xType> diag_3;
    std::vector<xType> f;

    public:
    double progonka(std::vector<xType>& diad_1, std::vector<xType>& diad_2, std::vector<xType>& diad_3, std::vector<xType>& f) {
        auto N = diad_2.size();
        std::vector<xType> p;
        std::vector<xType> q;
        std::vector<xType> x;
        p[1] = -diag_1[0] / diad_2[0];
        q[1] = f[0] / diad_2[0];

        for(int i = 1; i <= N; i++) {
            p[i + 1] = -diad_1[i] / (diad_3[i] * p[i] + diad_2[i]);
            q[i + 1] = (f[i] - diad_3[i] * q[i]) / (diag_3[i] * p[i] + diag_2[i]);   
        }

        for(int n = 1; n <= N-1; n++) {
            x[n] = (f[n] - diad_3[n] * q[n]) / (diad_3[n] * p[n] + diag_2[n]);
        }
        return x;
    }

};

