#include <vector>
#include "../eigen/Eigen/Dense"
#include "types.hpp"

#ifndef DATA_H
#define DATA_H

namespace data {

struct  {
    const double radius{30}; //m
    const double azimuth{0.009 * 180/PI}; //degree
    const double velocity{1}; //m/s
} measure_stdv;

/* data from object with const vel=(vel_x=22 m/s, vel_y=0 m/s) - init_position=(x0=3000 m, y0=3000 m) - n_iteration=30 */
const std::vector<double> radius_measurement{4253.595724013049, 4342.068802974521, 4233.9360615137675, 4326.122630637821,
                             4314.813736298536, 4291.696443774744, 4386.953317943045, 4373.898542038088, 4368.300202072035,
                             4375.828318198833, 4417.793112804298, 4437.082112656981, 4413.619851092478, 4455.409912489576, 
                             4484.681824461126, 4528.837271571501, 4538.887046006761, 4516.171867459036, 4574.833461975275, 
                             4521.278325560268, 4496.1932814025095, 4616.230898951853, 4653.823675428388, 4600.2702736483125, 
                             4650.728094465856};

const std::vector<double> azimith_measurement{44.28431533243123, 45.59454604098485, 46.313436233024994, 44.994418718707216, 46.220464317398,
                            47.219014525167864, 46.012355394197094, 46.33581855596607, 48.14840470707183, 47.57430430517931, 47.19252854498331,
                            47.75720103950495, 47.210046243178596, 47.46922071792621, 47.249113401153494, 47.523091002105986, 48.54819419245274,
                            48.99163366938272, 48.741929087722916, 49.08227846497701, 48.6025016703138, 48.903561062733395, 49.39372823126081, 
                            49.791960204126845, 49.83346819018465};

const std::vector<double> velocity_measurement{20.21335251225024, 22.233628310848825, 21.331626673018604, 20.68171692414667, 21.693240081850426,
                            19.77996676782008, 20.52499065726545, 20.79144478246157, 22.73615195120146, 22.4609245962518, 21.32284914565772, 
                            21.223332454423463, 19.66283239701565, 22.165630179860873, 21.30942358054975, 21.897227489660303, 20.657089727951274, 
                            24.11172097535575, 21.2591283134228, 22.827589405934013, 21.065122814474073, 22.651845721102696, 20.65469277258423, 
                            21.933699936033594, 23.26809347577007};

/* Get number of radar data acording to radius_measurement global vector size */
int get_n_measurements() {
    int n = radius_measurement.size();
    return n;
};

/*
    Pack radius_measurement, azimith_measurement and velocity_measurement in zk matrix with (3, n_measurements) size.
    @ return zk
*/
Eigen::MatrixXd get_zk() {
    int n = radius_measurement.size();
    
    Eigen::MatrixXd zk;
    zk.resize(3, n);

    for (int i=0; i<n; i++) {
        zk(0,i) = radius_measurement.at(i);
        zk(1,i) = azimith_measurement.at(i);
        zk(2,i) = velocity_measurement.at(i);
        }

    return zk;
};

} // end of namespace data

#endif