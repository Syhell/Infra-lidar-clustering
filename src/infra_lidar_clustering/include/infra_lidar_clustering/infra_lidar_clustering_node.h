#ifdef INFR_LIDAR_CLUSTERING_NODE_H
#define INFR_LIDAR_CLUSTERING_NODE_H

#include "infra_lidar_clustering/infra_lidar_clustering.h"
#include <ros/ros.h>
#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/Marker.h>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

namespace infra_lidar_clustering_node
{
    class InfraLidarClusteringNode
    {
        public:
            LidarClusteringNode();
        private:
        ros::NodeHandle nh;
        ros::Publisher cluster_cloud_pub;
        ros::Subscriber point_cloud_sub;

        std::string sub_topic = "cliped_cloud";
        
        

    }
}




#endif //INFR_LIDAR_CLUSTERING_NODE_H